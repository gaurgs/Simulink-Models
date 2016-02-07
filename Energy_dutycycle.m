snrdb = -16:0.5:-4;          % SNR values for AWGN channel
M = 2;                  % modulation index for psk
hpsk = comm.PSKModulator('ModulationOrder',M,...
    'BitInput',false,...
    'PhaseOffset',0);   	% M-psk modulator
nSample = 1000;         	% samples in signal
pde = zeros(1,numel(snrdb)); 	% array for Pd
L = numel(snrdb);
dutycycle=0.5;
				% Loop for SNR
hWait = waitbar(0,'please wait...');
for i = 1:L  			% for all snr values
    d = 0;              	% detection counter set to zeros
    % Loop for 1000 tests
    for j = 1:1000      	% 1000 simulations
        Signal = randi(M,nSample/2,1)-1;  % random binary signal  (bits = log2(M))
        n=randn(nSample-1,1);
        p=length(n);
        infoSignal=zeros(p);
        for k=1:p
            if p<=500
            infoSignal(k)=Signal(k);
            else
                infoSignal(k)=n(k);
            end
        end
        v=sum(abs(infoSignal.^2))./500;
        rxSignal=infoSignal+n;
%         txSignal = step(hpsk,infoSignal);   % M-psk signal
%         rxSignal = awgn(txSignal,snrdb(i)); % AWGN channel
        pf = 0.01;      % probabity of false detection
        snr = 10^(snrdb(i)/20);
        nvar = 1/snr;   % noise variance
%         thresh=(qfuncinv(pf)*sqrt(2*nSample)+ nSample)*(nSample*v*(nvar*dutycycle+1));
       thresh = sqrt(2*nSample*nvar^4)*qfuncinv(pf)+nSample*nvar^2; % threshold value
       energy = sum(abs(rxSignal).^2);     % energy of signal
        if energy > thresh % if energy is greater than threshold then signal is present
            d = d+1;
        end
    end
    pde(i) = d/1000; % avg over 1000 simulation
    waitbar(i/L,hWait);
end
close(hWait);
% Plot result  (SNR Vs Pd)
figure()
plot(snrdb,pde,'b');
xlabel('SNR (dB)');
ylabel('P_d');
title('Energy Detection');
grid on;

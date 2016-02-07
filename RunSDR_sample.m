
snrdb = -12:1:8;          % SNR values for AWGN channel
nSample = 1000;         	% samples in signal
pf=0.01;
for i = 1:length(snrdb)  			% for all snr values
    d=0;
     for j=1:1000
        snrdB=snrdb(i);
        model='SDR_sample';
        simout=sim(model);
        nvar=1/snrdB;
        [m,n]=size(Rx);
        thresh = sqrt(2*nSample*nvar^4)*qfuncinv(pf)+nSample*nvar^2; % threshold value
        energy = sum(abs(Rx(1:nSample,1)).^2);     % energy of signal
        if energy > thresh % if energy is greater than threshold then signal is present
            d = d+1;
        end
        
     end
fprintf('%f', snrdB);
pde(i) = d/1000; % avg over 1000 simulation
end    
% Plot result  (SNR Vs Pd)
figure()
plot(snrdb,pde,'b');
xlabel('SNR (dB)');
ylabel('P_d');
title('Energy Detection');
grid on;

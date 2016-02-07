clc;
clear all;
T=1;                    % Signaling interval: Duration of a bit
Ts=1/20;                % Sampling interval
Tsim=24000*T;           % Simulation time in bits
EbNo_vector=[0:1:8];    % Eb/No values

fprintf('\nEb/No(dB)\t  BER\n')
for i=1:length(EbNo_vector)
    EbNo=EbNo_vector(i);
    sim('Intdmb');
    ber(i)=errors(1);
    fprintf('%f\t%e\n', EbNo, ber(i));
end

% Plot the simulated bit error rate in a semilogarithmic graph
semilogy(EbNo_vector,ber,'-b*');grid on;axis tight;hold on
% Plot the theoretical BER in the same semilogarithmic graph
semilogy(EbNo_vector,0.5*erfc(sqrt(10.^(EbNo_vector/10))),'-g')
legend('Simulated','Theoretical')
title('Simulation results of BPSK modulation over an AWGN channel')
ylabel('BER')
xlabel('E_b/N_0 (dB)')
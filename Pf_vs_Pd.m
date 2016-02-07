clc
close all
clear all
L = 1000;

%-----SNR in decibels-----%
snr_dB = -10;
%-----Linear Value of SNR-----%
snr = 10.^(snr_dB./10); 


%-----Probability of False Alarm-----%
Pf = 0.01:0.01:1; 

%% Simulation to plot Probability of Detection (Pd) vs. Probability of False Alarm (Pf) %

for m = 1:length(Pf)
    Detect = 0;
    for kk=1:10000 % Number of Monte Carlo Simulations
        
        %-----AWGN noise with mean 0 and variance 1-----%
        Noise = randn(1,L); 
        %-----Real valued Gaussian Primary User Signal------% 
        Signal = sqrt(snr).*randn(1,L); 
        Recv_Sig = Signal + Noise; % Received signal at SU
        Energy = abs(Recv_Sig).^2; % Energy of received signal over N samples
        
        %-----Computation of Test statistic for energy detection-----%
        Test_Statistic =(1/L).*sum(Energy);
        
        %-----Theoretical value of Threshold-----%
        Threshold(m) = (qfuncinv(Pf(m))./sqrt(L))+ 1;
        
        if(Test_Statistic >= Threshold(m))  % Check whether the received energy is greater than threshold, if so, increment Pd (Probability of detection) counter by 1
           Detect = Detect+1;
        end
end
Pd(m) = Detect/kk;
end
plot(Pf, Pd)
hold on
%% Theroretical expression of Probability of Detection

Threshold = (qfuncinv(Pf)./sqrt(L))+ 1;
Pd_the = qfunc(((Threshold - (snr + 1)).*sqrt(L))./(sqrt(2).*(snr + 1)));
plot(Pf, Pd_the, 'r')
grid on
title('ROC plot for Probability of False Alarm vs Probability of Detection for SNR = -10 dB');
xlabel('Probability Of False Alarm');
ylabel('Probability Of Detection');
legend('Simulation','Theory');
hold on




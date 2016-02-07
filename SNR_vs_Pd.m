%%

clc
close all
clear all
L = 1000;

snr_dB=-20:1:0;
snr= 10.^(snr_dB./10);

for i=1:length(snr_dB)
    Detect=0;
    Pf=0.2;
     for kk=1:10000 % Number of Monte Carlo Simulations
        
        %-----AWGN noise with mean 0 and variance 1-----%
        Noise = randn(1,L); 
        %-----Real valued Gaussian Primary User Signal------% 
        Signal = sqrt(snr(i)).*randn(1,L); 
        Recv_Sig = Signal + Noise; % Received signal at SU
        Energy = abs(Recv_Sig).^2; % Energy of received signal over N samples
        
        %-----Computation of Test statistic for energy detection-----%
        Test_Statistic =(1/L).*sum(Energy);
        
        %-----Theoretical value of Threshold-----%
        Threshold = (qfuncinv(Pf)./sqrt(L))+ 1;
        
        if(Test_Statistic >= Threshold)  % Check whether the received energy is greater than threshold, if so,(Probability of detection) counter by 1
           Detect = Detect+1;
        end
end
        Pd(i) = Detect/kk;
        Pm(i)=1-Pd(i)
        Pd_the(i) = qfunc(((Threshold - (snr(i) + 1)).*sqrt(L))./(sqrt(2).*(snr(i) + 1)));
        Pm_the(i)=1-Pd_the(i)

   
end
 plot(snr_dB,Pd);
 hold on
 plot(snr_dB,Pd_the,'r');
 grid on
 title('ROC curve for SNR vs Probability of Detection for Pf=0.2')
 xlabel('Signal To Noise Ratio (dB)');
 ylabel('Probability Of Detection');
 legend('Simulation','Theory');
 
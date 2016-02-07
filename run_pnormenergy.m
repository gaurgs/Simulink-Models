 clc;
 clear;
 pf = 0:0.01:0.1;
 pnorm=1:0.5:5;
%  for k=1:length(pnorm)
%      p=pnorm(k);
     for i=1:length(pf)
         Pf=pf(i);
         model='pnormenergy';
         %     model='SDR';
         %     model='SDR_fading';
         %     model='SDR_Lowpass';
         simout=sim(model);
         [m,n]=size(Stat);
         count=0;
         for j=1:m
             if Stat(j,1)==1
                 count=count+1;
             end
         end
         pde(i)=count/1000;
     end
%      fprintf('%f', p);
     
%  end
 fprintf('%f', pde);

% Plot result  (SNR Vs Pd)
% figure()
plot(pf,pde,'--*r');
% xlabel('pf');
% ylabel('P_d');
% title('Energy Detection');
% grid on;
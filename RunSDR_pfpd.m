 clc;
 pf = 0.01:0.05:1;
for i=1:length(pf)
    Pf=pf(i);
    model='pnormenergy';
%      model='SDR';
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
    fprintf('%f\t%e\n', Pf, pde(i));
end
 
% Plot result  (SNR Vs Pd)
figure()
plot(pf,pde,'--*r');
xlabel('pf');
ylabel('P_d');
title('Energy Detection');
grid on;
 clc;
 clear;
  snrdb = -20:1:0;
% snrdb=0:1:10;

 pnorm=1:0.5:5;
 for k=1:length(pnorm)
     p=pnorm(k);
for i=1:length(snrdb)
    snrdB=snrdb(i);
%      model='SDR';
     model='pnormenergy';
%        model='SDR_sample';
    simout=sim(model);
    [m,n]=size(Stat);
    count=0;
    for j=1:m
        if Stat(j,1)==1
            count=count+1;
        end
    end
    pde(k,i)=count/1000;
      fprintf('%f\t%e\n', snrdB, pde(i));
end
 fprintf('%f', p);
 end
% Plot result  (SNR Vs Pd)
figure()
plot(snrdb,pde,'--*r');
xlabel('SNR (dB)');
ylabel('P_d');
title('Energy Detection');
grid on;
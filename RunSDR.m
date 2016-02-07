 clc;
 clear;
  snrdb = -20:1:0;
% snrdb=0:1:10;
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
    pde(i)=count/1000;
      fprintf('%f\t%e\n', snrdB, pde(i));
end
 
% Plot result  (SNR Vs Pd)
figure()
plot(snrdb,pde,'--*r');
xlabel('SNR (dB)');
ylabel('P_d');
title('Energy Detection');
grid on;
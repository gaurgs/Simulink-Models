function [d] = counter( count )
[m n]=size(count);
m
d=0;
 for j=1:m
            if(count(m,1)==1)
                 d=d+1;
            end
 end
 fprintf('%f',d);
end


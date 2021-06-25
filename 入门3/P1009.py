from functools import reduce
from itertools import accumulate
from operator import add
print(reduce(add,
    [reduce(lambda x,y: x*y,range(1,i+1)) 
    for i in range(1,int(input())+1)]))

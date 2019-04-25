import random
count=0
num=100000000#随机数个数
for i in range(num):
    x= random.random()#随机数
    y= random.random()#随机数
    if x**2+y**2<1:
        count+=1
PI=4*count/num
print(PI)

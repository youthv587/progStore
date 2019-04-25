//判断输入的数是否为斐波那契数列中的数
def fibonacci(x):
    if(x==1):
        print("1是斐波那契数列中的第1或第2个数")
    else:
        num=2
        a=1
        b=1
        c=2
        while (c<=x):
            c=a+b
            a=b
            b=c
            num+=1
        if(c==x):
            print(x,"是斐波那契数列中的第",num,"个数")
        else:
            print(x,"不是斐波那契数列中的数")
        
x=int(input("请输入斐波那契数列中的数："));
fibonacci(x)

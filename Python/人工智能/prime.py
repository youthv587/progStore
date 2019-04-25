print ("100以内的质数：")
i = 2
while(i < 100):
   j = 2
   while(j*j<=i ):
      if not(i%j): break
      j = j + 1
   if (j*j> i) : print (i)
   i = i + 1

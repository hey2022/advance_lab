import subprocess
import random
n=int(input())
c=int(input())
subprocess.run("rm ./txsv.txt", shell=True)
file = open("./txsv.txt",'w')
file.write(str(n)+"\n")
if(c==1):
    r1=[i for i in range(1, n+1)]
    print("shuffle...",end='')
    random.shuffle(r1)
    print("OK")
    for i in r1:
        file.write(i)
elif(c==2):
    r1=[]
    for i in range(1,n+1):
        r1.append(i)
    for i in range(n//2):
        x=random.randint(1,n-2)
        s=r1[x]
        if(random.randint(0,1)):
            r1[x]=r1[x-1]
            r1[x-1]=s
        else:
            r1[x]=r1[x+1]
            r1[x+1]=s
        if (i % 100 == 0):
            print(i)
    for i in r1:
        r+=str(i)+" "
else:
    for i in range(n,0,-1):
        r+=str(i)+" "
file.write(r)
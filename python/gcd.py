#GCD for two numbers

def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a%b)

#a,b are two numbers to which we need to find GCD
#Input is given in the same line seperated by space
a,b=map(int,input().split())

print(gcd(a,b))

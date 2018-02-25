mod = 1000000007
def e1(n):
    return 5*n*n

def e2(n):
    if n%2==0:
            return 2*n*n + n*n/2
    else:
        return 2*n*n + (n*n+1)/2

def e3(n):
    if n%2==0:
        return n*n+(n*n/4)+n/2-1
    else:
        return n*n+((n+1)/2)**2

def val1(n,c):
    return ((pow(c,e1(n),mod)+pow(c,e2(n),mod)+2*pow(c,e3(n),mod))*250000002) % mod

t = int(raw_input())
for _ in range(t):
    n,c = map(int,raw_input().split())
    print(val1(n,c))

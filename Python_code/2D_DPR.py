import sys
from Data import data


objets = []

def max(a,b,n):
    if a>=b:
        return a
    else:
        return b

def f(n,p,v):
    if n==0:
        return 0
    else:
        if (p-data[n].poid)>=0 and (v-data[n].volume)>=0:
            return max(f(n-1,p,v),f( n-1 , p - data[n].poid , v - data[n].volume ) + data[n].valeur ,n)
        else:
            return f(n-1,p,v)


def execute(n,pmax,vmax):
    valeur = f(n,pmax,vmax)
    print("la valeur optimum est : {}".format(valeur))

execute(int(sys.argv[1]),int(sys.argv[2]),int(sys.argv[3]))
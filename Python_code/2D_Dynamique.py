import sys
from Data import data,makearray

table = makearray(4,80,50)

def max(a,b):
    if a>=b:
        return a
    else:
        return b

def f(n,p,v):
    if n<=0 or p<=0 or v<=0:
        return 0
    else:
        return table[n][p][v]

def Dynamique(n,p,v):
    for i in range(1,n+1):
        for j in range(p+1):
            for k in range(v+1):
                table[i][j][k] = max(f(i-1,j,k) , f( i-1 , j - data[i].poid , k - data[i].volume ) + data[i].valeur)
    
    return f(n,p,v)



def execute(n,pmax,vmax):
    valeur = Dynamique(n,pmax,vmax)
    print("la valeur optimum est : {}".format(valeur))

execute(int(sys.argv[1]),int(sys.argv[2]),int(sys.argv[3]))

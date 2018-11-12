import sys

class objet():
    def __init__(self,val,gain):
        self.val = val
        self.gain = gain


objets = { 1: objet(2,6),
            2: objet(4,4),
            3: objet(3,1),
            4: objet(2,2)  }

def max(a,b,n):
    if a>=b:
        return a
    else:
        return b 

def f(N,Vmax):
    if N==0:
        return 0
    else:
        if (Vmax-objets[N].val)>=0:
            return max(f(N-1,Vmax),f( N-1 , Vmax-objets[N].val )+ objets[N].gain ,N)
        else:
            return f(N-1,Vmax)


def execute(n,pmax):
    valeur = f(n,pmax)
    print("la valeur optimum est : {}".format(valeur))

execute(int(sys.argv[1]),int(sys.argv[2]))
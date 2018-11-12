from objet import objet

# l'objet est de format : poid, volume * 100, valeur
data = {
    1: objet(2,2,6),
    2: objet(3,1,8),
    3: objet(4,3,14),
    4: objet(2,4,6),
    5: objet(7,20,13),
}

def makearray(n,pmax,vmax):
    distance = [[[0 for k in range(vmax+1)] for j in range(pmax+1)] for i in range(n+1)]
    for i in range(n):
        for j in range(pmax):
            for k in range(vmax):
                distance[i][j][k] = 0
    return distance
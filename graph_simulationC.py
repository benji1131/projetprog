# -*- coding: utf-8 -*-
"""
Created on Wed Dec  1 13:48:48 2021

@author: gremi
"""
import numpy as np
import matplotlib.pyplot as plt

#import données
data_covid = np.genfromtxt('covid.csv', delimiter = ',', dtype = 'float64')

#crée nos listes de données
s = []      #Saint
v =  []
c = []      #Contaminé
inf = []    #Infecté
r = []      #Retablis
d = []      #dead
pop_tot = []#population totale
cs = []
es = []
cv = []
ev = []
n = 90   #nombre d'itération


#remplis les listes (y axis)
for i in range(n):
    s.append(data_covid[i,0])
    v.append(data_covid[i,1])
    c.append(data_covid[i,2])
    inf.append(data_covid[i,3])
    r.append(data_covid[i,4])
    d.append(data_covid[i,5])
    pop_tot.append(data_covid[i,6])
    cs.append(data_covid[i,7])
    es.append(data_covid[i,8])
    cv.append(data_covid[i,9])
    ev.append(data_covid[i,10])

#crée notre x axis
temp = np.linspace(0,n,n)




# Plot les courbes sur un graph
plt.plot(temp, s, color='b', label='Saint')
#plt.plot(temp, c, color='orange', label='Contaminé')
plt.plot(temp, inf, color='r', label='Infecté')
plt.plot(temp, r, color='cyan', label='Rétabli')
#plt.plot(temp, v, color='y', label='vaccin')
plt.plot(temp, d, color='black', label='Mort')
#plt.plot(temp, pop_tot, color='gray', label='Population Totale')



plt.title('Evolution de la Pandémie (Covid)')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")

plt.show()

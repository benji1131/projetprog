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
c = []      #Contaminé
inf = []    #Infecté
r = []      #Retablis
immun = []  #Immunisé
d = []      #dead
v = []      #Vacciné
pop_tot = []#population totale
n = 10      #nombre d'itération


#remplis les listes (y axis)
for i in range(n):
    s.append(data_covid[i,1])
    c.append(data_covid[i,2])
    inf.append(data_covid[i,3])
    r.append(data_covid[i,4])
    immun.append(data_covid[i,5])
    d.append(data_covid[i,6])
    v.append(data_covid[i,7])
    pop_tot.append(data_covid[i,8])

#crée notre x axis
temp = np.linspace(0,n,n)  

# Plot les courbes sur un graph
plt.plot(temp, s, color='b', label='Saint')
plt.plot(temp, c, color='orange', label='Contaminé')
plt.plot(temp, inf, color='r', label='Infecté')
plt.plot(temp, r, color='cyan', label='Rétabli')
plt.plot(temp, immun, color='y', label='Immunisé')
plt.plot(temp, d, color='black', label='Mort')
plt.plot(temp, v, color='g', label='Vacciné')
plt.plot(temp, pop_tot, color='gray', label='Population Totale')



plt.title('Evolution de la Pandémie (Covid)')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper left')

plt.show()
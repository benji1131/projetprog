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
e = []      #Contaminé
i = []    #Infecté4
q = []      #quarantaine
r = []      #Retablis
d = []      #dead
v = []  #Immunisé
pop_tot = []#population totale
n = 90     #nombre d'itération


#remplis les listes (y axis)
for i in range(n):
    s.append(data_covid[i,0])
    e.append(data_covid[i,1])
    i.append(data_covid[i,2])
    q.append(data_covid[i,3])
    r.append(data_covid[i,4])
    d.append(data_covid[i,5])
    v.append(data_covid[i,6])
    pop_tot.append(data_covid[i,7])

#crée notre x axis
temp = np.linspace(0,n,n)

# Plot les courbes sur un graph
plt.plot(temp, s, color='b', label='Saint')
plt.plot(temp, e, color='orange', label='Contaminé')
plt.plot(temp, i, color='r', label='Infecté')
plt.plot(temp, q, color='violet', label='quarantine')
plt.plot(temp, r, color='cyan', label='Rétabli')
plt.plot(temp, d, color='black', label='Mort')
plt.plot(temp, v, color='y', label='Immunisé')
plt.plot(temp, pop_tot, color='gray', label='Population Totale')



plt.title('Evolution de la Pandémie (Covid)')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper left')

plt.show()

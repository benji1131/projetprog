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
v = []
cs = []
cv = []
c = []
is = []
iv = []
i_ = []    #Infecté4
rs = []
rv = []
r = []      #Retablis
d = []      #dead

pop_tot = []#population totale
n = 120   #nombre d'itération


#remplis les listes (y axis)
for i in range(n):
    s.append(data_covid[i,0])
    v.append(data_covid[i,1])
    cs.append(data_covid[i,2])
    cv.append(data_covid[i,3])
    c.append(data_covid[i,4])
    is.append(data_covid[i,5])
    iv.append(data_covid[i,6])
    i_.append(data_covid[i,7])
    rs.append(data_covid[i,8])
    rv.append(data_covid[i,9])
    r.append(data_covid[i,10])
    d.append(data_covid[i,11])

    pop_tot.append(data_covid[i,12])

#crée notre x axis
temp = np.linspace(0,n,n)

# Plot les courbes sur un graph
'''plt.plot(temp, s, color='b', label='Saint')
plt.plot(temp, e, color='orange', label='Contaminé')
plt.plot(temp, i_, color='r', label='Infecté')
plt.plot(temp, q, color='violet', label='quarantine')
plt.plot(temp, r, color='cyan', label='Rétabli')
plt.plot(temp, d, color='black', label='Mort')
'''
plt.plot(temp, v, color='y', label='Vacciné')
#plt.plot(temp, pop_tot, color='gray', label='Population Totale')



plt.title('Evolution de la Pandémie (Covid)')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper left')

plt.show()

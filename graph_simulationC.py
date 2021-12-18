# -*- coding: utf-8 -*-
"""
Created on Wed Dec  1 13:48:48 2021

@author: gremi
"""
import numpy as np
import matplotlib.pyplot as plt

#import données
data_covid = np.genfromtxt('covid.csv', delimiter = ',', dtype = 'float64')
data_covid2 = np.genfromtxt('covid2.csv', delimiter = ',', dtype = 'float64')
data_covid3 = np.genfromtxt('covid3.csv', delimiter = ',', dtype = 'float64')
data_covid4 = np.genfromtxt('covid4.csv', delimiter = ',', dtype = 'float64')
data_covid5 = np.genfromtxt('covid5.csv', delimiter = ',', dtype = 'float64')
data_covid6 = np.genfromtxt('covid6.csv', delimiter = ',', dtype = 'float64')
data_covid7 = np.genfromtxt('covid7.csv', delimiter = ',', dtype = 'float64')

#crée nos listes de données
s1 = []          #Saint
v1 =  []
c1 = []          #Contaminé
inf1 = []        #Infecté
r1 = []          #Retablis
d1 = []          #dead
pop_tot1 = []    #population totale
cs1 = []
es1 = []
cv1 = []
ev1 = []

s2 = []
v2 =  []
c2 = []
inf2 = []
r2 = []
d2 = []
pop_tot2 = []
cs2 = []
es2 = []
cv2 = []
ev2 = []

s3 = []
v3 =  []
c3 = []
inf3 = []
r3 = []
d3 = []
pop_tot3 = []
cs3 = []
es3 = []
cv3 = []
ev3 = []

s4 = []
v4 =  []
c4 = []
inf4 = []
r4 = []
d4 = []
pop_tot4 = []
cs4 = []
es4 = []
cv4 = []
ev4 = []

s5 = []
v5 =  []
c5 = []
inf5 = []
r5 = []
d5 = []
pop_tot5 = []
cs5 = []
es5 = []
cv5 = []
ev5 = []

s6 = []
v6 =  []
c6= []
inf6 = []
r6 = []
d6 = []
pop_tot6 = []
cs6 = []
es6 = []
cv6 = []
ev6 = []

s7 = []
v7 =  []
c7 = []
inf7 = []
r7 = []
d7 = []
pop_tot7 = []
cs7 = []
es7 = []
cv7 = []
ev7 = []

n = 90   #nombre d'itération


#remplis les listes (y axis)
for i in range(n):
    s1.append(data_covid[i,0])
    v1.append(data_covid[i,1])
    c1.append(data_covid[i,2])
    inf1.append(data_covid[i,3])
    r1.append(data_covid[i,4])
    d1.append(data_covid[i,5])
    pop_tot1.append(data_covid[i,6])
    cs1.append(data_covid[i,7])
    es1.append(data_covid[i,8])
    cv1.append(data_covid[i,9])
    ev1.append(data_covid[i,10])


    s2.append(data_covid2[i,0])
    v2.append(data_covid2[i,1])
    c2.append(data_covid2[i,2])
    inf2.append(data_covid2[i,3])
    r2.append(data_covid2[i,4])
    d2.append(data_covid2[i,5])
    pop_tot2.append(data_covid2[i,6])
    cs2.append(data_covid2[i,7])
    es2.append(data_covid2[i,8])
    cv2.append(data_covid2[i,9])
    ev2.append(data_covid2[i,10])

    s3.append(data_covid3[i,0])
    v3.append(data_covid3[i,1])
    c3.append(data_covid3[i,2])
    inf3.append(data_covid3[i,3])
    r3.append(data_covid3[i,4])
    d3.append(data_covid3[i,5])
    pop_tot3.append(data_covid3[i,6])
    cs3.append(data_covid3[i,7])
    es3.append(data_covid3[i,8])
    cv3.append(data_covid3[i,9])
    ev3.append(data_covid3[i,10])

    s4.append(data_covid4[i,0])
    v4.append(data_covid4[i,1])
    c4.append(data_covid4[i,2])
    inf4.append(data_covid4[i,3])
    r4.append(data_covid4[i,4])
    d4.append(data_covid4[i,5])
    pop_tot4.append(data_covid4[i,6])
    cs4.append(data_covid4[i,7])
    es4.append(data_covid4[i,8])
    cv4.append(data_covid4[i,9])
    ev4.append(data_covid4[i,10])

    s5.append(data_covid5[i,0])
    v5.append(data_covid5[i,1])
    c5.append(data_covid5[i,2])
    inf5.append(data_covid5[i,3])
    r5.append(data_covid5[i,4])
    d5.append(data_covid5[i,5])
    pop_tot5.append(data_covid5[i,6])
    cs5.append(data_covid5[i,7])
    es5.append(data_covid5[i,8])
    cv5.append(data_covid5[i,9])
    ev5.append(data_covid5[i,10])

    s6.append(data_covid6[i,0])
    v6.append(data_covid6[i,1])
    c6.append(data_covid6[i,2])
    inf6.append(data_covid6[i,3])
    r6.append(data_covid6[i,4])
    d6.append(data_covid6[i,5])
    pop_tot6.append(data_covid6[i,6])
    cs6.append(data_covid6[i,7])
    es6.append(data_covid6[i,8])
    cv6.append(data_covid6[i,9])
    ev6.append(data_covid6[i,10])

    s7.append(data_covid7[i,0])
    v7.append(data_covid7[i,1])
    c7.append(data_covid7[i,2])
    inf7.append(data_covid7[i,3])
    r7.append(data_covid7[i,4])
    d7.append(data_covid7[i,5])
    pop_tot7.append(data_covid7[i,6])
    cs7.append(data_covid7[i,7])
    es7.append(data_covid7[i,8])
    cv7.append(data_covid7[i,9])
    ev7.append(data_covid7[i,10])
"""On a importé toutes les donnée car celles-ci nous ont permi de tester différent graphique et de selectioonner
les plus importants"""

#crée notre x axis"""
temp = np.linspace(0,n,n)

"""
------------------------------------------------------------------------------
Premier plots: Comparaisons de l'évolution en fonction des gestes barrières
------------------------------------------------------------------------------
"""
#Saines
plot1 = plt.figure(1)
plt.plot(temp, s1, color='b', label='Sans Geste Barrière')
plt.plot(temp, s4, color='orange', label='Avec port du masque')
plt.plot(temp, s5, color='r', label='Confinement')

#params
plt.title('Evolution des Personnes Saines')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot1.png')

#infectée
plot2 = plt.figure(2)
plt.plot(temp, inf1, color='b', label='Sans Geste Barrière')
plt.plot(temp, inf4, color='orange', label='Avec port du masque')
plt.plot(temp, inf5, color='r', label='Confinement')

#params
plt.title('Evolution des Personnes Infectées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot2.png')

#décédées
plot3 = plt.figure(3)
plt.plot(temp, d1, color='b', label='Sans Geste Barrière')
plt.plot(temp, d4, color='orange', label='Avec port du masque')
plt.plot(temp, d5, color='r', label='Confinement')

#params
plt.title('Evolution des Personnes Décédées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot3.png')

#comparaison entre controle (sans geste barrière) et avec les gestes barrière

#1ère comparaison entre control et masque
plot4 = plt.figure(4)
plt.plot(temp, s1, color='deepskyblue', label='Saint(Controle)')
plt.plot(temp, inf1, color='blue', label='Infecté (Controle)')
plt.plot(temp, d1, color='darkviolet', label='Mort (Controle)')

plt.plot(temp, s4, color='yellow', label='Saint (Masque)')
plt.plot(temp, inf4, color='darkorange', label='Infecté (Masque)')
plt.plot(temp, d4, color='red', label='Mort (Masque)')


#params
plt.title('Population Controle VS Population Port du Masque' )
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot4.png')

#2ème comparaison entre controle et confinement
plot5 = plt.figure(5)
plt.plot(temp, s1, color='deepskyblue', label='Saint(Controle)')
plt.plot(temp, inf1, color='blue', label='Infecté (Controle)')
plt.plot(temp, d1, color='darkviolet', label='Mort (Controle)')


plt.plot(temp, s5, color='yellow', label='Saint (Confinement)')
plt.plot(temp, inf5, color='darkorange', label='Infecté (Confinement)')
plt.plot(temp, d5, color='red', label='Mort (Confinement)')

#params
plt.title('Population Controle VS Population Confinement' )
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot5.png')

#Les graphs sont ok !

"""
------------------------------------------------------------------------------
Second plots: Comparaisons de l'évolution en fonction de la Vaccination
------------------------------------------------------------------------------
"""
#Saines
plot6 = plt.figure(6)
plt.plot(temp, s1, color='b', label='Sans vaccination')
plt.plot(temp, s2, color='orange', label='Début de la vaccination')
plt.plot(temp, s3, color='r', label='30% déjà vacciné')

#params
plt.title('Evolution des Personnes Saines')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot6.png')

#infectée
plot7 = plt.figure(7)
plt.plot(temp, inf1, color='b', label='Sans vaccination')
plt.plot(temp, inf2, color='orange', label='Début de la vaccination')
plt.plot(temp, inf3, color='r', label='30% déjà vacciné')

#params
plt.title('Evolution des Personnes Infectées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot7.png')

#Rétablis
plot8 = plt.figure(8)
plt.plot(temp, r1, color='b', label='Sans vaccination')
plt.plot(temp, r2, color='orange', label='Début de la vaccination')
plt.plot(temp, r3, color='r', label='30% déjà vacciné')

#params
plt.title('Evolution des Personnes Rétablies')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot8.png')

#décédées
plot9 = plt.figure(9)
plt.plot(temp, d1, color='b', label='Sans vaccination')
plt.plot(temp, d2, color='orange', label='Début de la vaccination')
plt.plot(temp, d3, color='r', label='30% déjà vacciné')

#params
plt.title('Evolution des Personnes Décédées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot9.png')

"""
------------------------------------------------------
Troisième Plots: Comparaisons de l'évolution en fonction des Variants
-----------------------------------------------------
"""

#Saines
plot10 = plt.figure(10)
plt.plot(temp, s1, color='b', label='Controle')
plt.plot(temp, s6, color='orange', label='Variant Alpha')
plt.plot(temp, s7, color='r', label='Variant Delta')

#params
plt.title('Evolution des Personnes Saines')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot10.png')

#Infectées
plot11 = plt.figure(11)
plt.plot(temp, inf1, color='b', label='Controle')
plt.plot(temp, inf6, color='orange', label='Variant Alpha')
plt.plot(temp, inf7, color='r', label='Variant Delta')

#params
plt.title('Evolution des Personnes Infectées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot11.png')

#Décédés
plot12 = plt.figure(12)
plt.plot(temp, d1, color='b', label='Controle')
plt.plot(temp, d6, color='orange', label='Variant Alpha')
plt.plot(temp, d7, color='r', label='Variant Delta')

#params
plt.title('Evolution des Personnes Décédées')
plt.xlabel('Temps (jour)')
plt.ylabel('Pourcentage de la Population')
plt.legend(loc = 'upper right', fontsize = "x-small")
plt.savefig('plot12.png')


#Show all
plt.show()

#final

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


#crée notre x axis"""
temp = np.linspace(0,n,n)

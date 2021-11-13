import numpy as np
import math
import random
from random import *
import matplotlib.pyplot as plt

#------------------------------------------------------------------------------
def infection(): #sans geste barrières
    n = random()
    if n < 0.4:  #valeur qui montre bien la propagation du virus plutot virulant
        return 1 #pour dire infecté
    else:
        return 0 #pour dire saint

def infection2(): #avec geste barrières
    n = random()
    if n < 0.3:  #valeur plus petite car les gestes barrières sont inclus dans le modèle
        return 1 #pour dire infecté
    else:
        return 0 #pour dire saint
#------------------------------------------------------------------------------
def couleur_valeur(valeur): #dans le graph, je veux une certaine couleur pour une certaine valeur
    if valeur == 0:
        couleur = "w" #saint blanc

    elif valeur ==1:
        couleur = "r" #infecté red

    else:
        couleur = "m" #retablis magenta

    return couleur

#------------------------------------------------------------------------------
#1.Sans gestes barrière

#Grille de 100 "personnes"
population = np.zeros([100,100])

#random patient zéro
#infecte0_x = math.floor(random()*100)
#infecte0_y = math.floor(random()*100)
#print(infecte0_x, infecte0_y)

#patient zero dans population
#population[infecte0_x,infecte0_y] = 1
population[50,50] = 1


#Epidemie
#choisir condition d'arret de la boucle
for w in range(100):
    population_copy = np.copy(population) #crée copy pour chercher les valeurs des infecté sans les modifs
    for i in range(1,100):
        for j in range (1,100):
            if population_copy[i,j] == 1:
                population[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!
                for x in range(-1,2):
                    for y in range(-1,2):
                        if population[i+x,j+y] == 2 :
                            pass
                        else:
                            population[i+x,j+y] = infection()

    print(population)
#------------------------------------------------------------------------------
#2. Avec gestes Barrière


population2 = np.zeros([100,100])


population2[50,50] = 1


#Epidemie
#choisir condition d'arret de la boucle
for w in range(100):
    population2_copy = np.copy(population2) #crée copy pour chercher les valeurs des infecté sans les modifs
    for i in range(1,100):
        for j in range (1,100):
            if population2_copy[i,j] == 1:
                population2[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!
                for x in range(-1,2):
                    for y in range(-1,2):
                        if population2[i+x,j+y] == 2 :
                            pass
                        else:
                            population2[i+x,j+y] = infection2()

    print(population2)
#------------------------------------------------------------------------------
#faire les plots !!
#Comment animer tout ca ?
#ajouter count infecté et rétablis à chaque instant

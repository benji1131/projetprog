import numpy as np
import math
import random
from random import *
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib.animation import FuncAnimation
import matplotlib.animation as animation
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
#1.Sans gestes barrière

#Grille de 25^2 "personnes"
population = np.zeros([25,25])


population[12,12] = 1
list_pop = []


for w in range(40):
    population_copy = np.copy(population) #crée copy pour chercher les valeurs des infecté sans les modifs
    list_pop.append(population.copy())
    for i in range(1,24):
        for j in range (1,24):

            if population_copy[i,j] == 1:
                population[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!

                for x in range(-1,2):
                    for y in range(-1,2):

                        if population[i+x,j+y] == 2 :
                            pass

                        else:
                            population[i+x,j+y] = infection()

#Plot
#Paramètres
n_frames = 40           #nbr de "plots" qui s'affiches
c = mpl.colors.ListedColormap(['white', 'red', 'blue', 'black']) #couleurs
n = mpl.colors.Normalize(vmin=0,vmax=3)#répartir couleurs selon valeurs

fig1 = plt.figure()
fig1.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel du COVID Sans Geste Barrière")


#---

plot1 = plt.matshow(list_pop[0], fignum=0, cmap=c, norm=n)

def init1():
    plot1.set_data(list_pop[0])
    return plot1

def update1(j):
    plot1.set_data(list_pop[j])
    return plot1

anim1 = FuncAnimation(fig1, update1, init_func = init1, frames=n_frames, interval =300, blit=False)



#------------------------------------------------------------------------------
#2. Avec gestes Barrière


population2 = np.zeros([25,25])


population2[12,12] = 1


list_popu = []

for w in range(40):
    population2_copy = np.copy(population2)#crée copy pour chercher les valeurs dess infecté sans les modifs
    list_popu.append(population2.copy())
    for i in range(1,24): #pour eviter les problème de bords
        for j in range (1,24):
            if population2_copy[i,j] == 1:
                population2[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!
                for x in range(-1,2):
                    for y in range(-1,2):
                        if population2[i+x,j+y] == 2 :
                            pass
                        else:
                            population2[i+x,j+y] = infection2()

#Plot
#Paramètres
n_frames = 40           #nbr de "plots" qui s'affiches
c = mpl.colors.ListedColormap(['white', 'red', 'blue', 'black']) #couleurs
n = mpl.colors.Normalize(vmin=0,vmax=3)#répartir couleurs selon valeurs

fig2 = plt.figure()
fig2.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel du COVID Avec Gestes Barrière")

#---

plot2 = plt.matshow(list_popu[0], fignum=0, cmap=c, norm=n)


def init2():
    plot2.set_data(list_popu[0])
    return plot2

def update2(j):
    plot2.set_data(list_popu[j])
    return plot2

anim2 = FuncAnimation(fig2, update2, init_func = init2, frames=n_frames, interval =300, blit=False)
plt.show()


#------------------------------------------------------------------------------
#3. Avec vaccination (10%) séléctionné aléatoirement
population3 = np.zeros([25,25])

#30% vacciné aléatoirement

for i in range(0,25):
        for j in range (0,25):
            n = random()
            if n < 0.1:
                population3[i,j] = 3


population3[12,12] = 1 #patient 0

list_popu3 = []

for w in range(40):
    population3_copy = np.copy(population3)#crée copy pour chercher les valeurs dess infecté sans les modifs
    list_popu3.append(population3.copy())
    for i in range(1,24):
        for j in range (1,24):
            if population3_copy[i,j] == 1 :
                population3[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!
                for x in range(-1,2):
                    for y in range(-1,2):
                        if population3[i+x,j+y] == 2 or population3[i+x,j+y]==3 :
                            pass
                        else:
                            population3[i+x,j+y] = infection2()

#Plot
#Paramètres
n_frames = 40           #nbr de "plots" qui s'affiches
c = mpl.colors.ListedColormap(['white', 'red', 'blue', 'black']) #couleurs
n = mpl.colors.Normalize(vmin=0,vmax=3)#répartir couleurs selon valeurs


fig3 = plt.figure()

fig3.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel du COVID avec 10% Vaccination")


#---
plot3 = plt.matshow(list_popu3[0], fignum=0, cmap=c, norm=n)


def init3():
    plot3.set_data(list_popu3[0])
    return plot3

def update3(j):
    plot3.set_data(list_popu3[j])
    return plot3

anim3 = FuncAnimation(fig3, update3, init_func = init3, frames=n_frames, interval =300, blit=False)


#------------------------------------------------------------------------------

#ajouter count infecté et rétablis à chaque instant
#-----------------------------------------------------------------------------






#-----------------------------------------------------------------------------
#show les 3 les 1 à coté des autres ? en même temps ? avec les titles à mettre en place
#faire attention aux conditions des bornes !


#note faire qqch avec limites des graph !
#Mais ca marche !! continue comme ca !! :)
# :)
#Courage :) !!

#peut faire un plt.ion pour modifier la valeurs de notre propagation en directe !
#------------------------------------------------------------------------------------------
#mettre tout ensemble

#Subplot ca marche pas avec matshow et animé ...
def init_overall():
    plot_overall[0].set_data(list_pop[0])
    plot_overall[1].set_data(list_popu[0])
    plot_overall[2].set_data(list_popu3[0])
    plot_overall[3].set_data(list_popu3[0])

    return plot_overall

def update_overall(j):
    plot_overall[0].set_data(list_pop[j])
    plot_overall[1].set_data(list_popu[j])
    plot_overall[2].set_data(list_popu3[j])
    plot_overall[3].set_data(list_popu3[j])

    return plot_overall

plot_overall = [plt.matshow(list_pop[0], fignum=0, cmap=c, norm=n),plt.matshow(list_popu[0], fignum=0, cmap=c, norm=n),plt.matshow(list_popu3[0], fignum=0, cmap=c, norm=n),plt.matshow(list_popu3[0], fignum=0, cmap=c, norm=n)]

# create a figure with 4 subplots

fig, ax = plt.subplots(1,4)
# fig.suptitle('Using matshow to plot a previously created 2D-histogram')

ax[0].matshow(list_pop[0], cmap=c, norm=n)
ax[0].set_title('matshow')

ax[1].matshow(list_popu[0], cmap=c, norm=n)
ax[1].set_title('matshow (explicit extent)')

ax[2].mathsow(list_popu3[0],cmap=c, norm=n)
ax[2].set_title('imshow')

ax[3].mathsow(list_popu3[0], cmap=c, norm=n)
ax[3].set_title('imshow')



anim = FuncAnimation(fig, update_overall, init_func = init_overall, frames=n_frames, interval =300, blit=False)
plt.show()

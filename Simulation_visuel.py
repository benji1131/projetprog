import numpy as np
import secrets
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib import animation #if save the gif
from matplotlib.animation import FuncAnimation


#-----------------------------------------------------------------------------
#faire une classe pour tou ca !!
class Population:
    def __init__(self, population_nbr, pourcentage_propa, pourcentage_mort,frames, pourcentage_vacc):
        self.population_nbr = population_nbr
        self.population = np.zeros([population_nbr, population_nbr])    # matrice qui représente notre population
        self.population[population_nbr//2,population_nbr//2] = 1          #patient 0
        self.list_population = []                                       #Initialise la list
        self.list_poss = [-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10] #dans carré de largeur 10 pour voyage
        self.propagation = pourcentage_propa
        self.pourcentage_mort = pourcentage_mort
        self.pourcentage_vacc = pourcentage_vacc
        self.frames = frames


    """Soit chaque cellule comporte une valeurs représenté dans les graphs par une couleurs symbolique
    Ces valeurs/couleurs représente les statut médicale de la personne (Saint S, Contamine C, Infecté I, Rétablis R)"""

    def infection(self, pourcentage_propa, pourcentage_mort):
        n =secrets.randbelow(101)/100
        if n < pourcentage_propa and n > pourcentage_mort:  #valeur qui montre bien la propagation du virus plutot virulant
            return 1    #pour dire infecté
        elif n < pourcentage_mort:
            return 5    #pour dire dead
        else:
            return 0    #pour dire saint

    def vaccination(self): #10% vaccination pour voir l'effet
        for i in range(0,50):
            for j in range (0,50):
                n = secrets.randbelow(11)/10
                if n < self.pourcentage_vacc:
                    self.population[i,j] = 6 # Réparti aléatoirement les personnes vaccinée dans la matrice

    def voisinage(self, population_nbr):
        for w in range(self.frames):
            population_copy = np.copy(self.population)#crée copy pour chercher les valeurs dess infecté sans les modifs
            self.list_population.append(self.population.copy())
            for i in range(1,population_nbr-1):
                for j in range (1, population_nbr-1):
                    if population_copy[i,j] == 1 :
                        self.population[i,j] = 2  #valeur = 2
                        for x in range(-1,2):
                            for y in range(-1,2):
                                if self.population[i+x,j+y] == 2 or self.population[i+x,j+y]==3 or self.population[i+x,j+y] == 4 or self.population[i+x,j+y] == 5 or self.population[i+x,j+y] ==6:
                                    pass
                                else:
                                    self.population[i+x,j+y] = self.infection(self.propagation, self.pourcentage_mort)
                    if population_copy[i,j] == 2:
                        self.population[i,j] = 3
                    if population_copy[i,j] == 3:
                        self.population[i,j] = 4


    def voyages(self, population_nbr):

        for w in range(self.frames):
            population_copy = np.copy(self.population)#crée copy pour chercher les valeurs dess infecté sans les modifs
            self.list_population.append(self.population.copy())
            for i in range(1,population_nbr-1): #pour eviter les problème de bords
                for j in range (1,population_nbr-1):
                    if population_copy[i,j] == 1:
                       self.population[i,j] = 2  #valeur = 2 --> Retablis voir si on veut le moment d'incubation !!
                       for count in range(5): #soit une personne voit en moyenne 5 mêmes personnes par jour qui n'habitent pas à coté de chez lui
                            x = secrets.choice(self.list_poss)
                            y = secrets.choice(self.list_poss)

                            if ((i+x < 1 or i+x > population_nbr-1) or (j+y < 1 or j+y > population_nbr-1)):
                                pass

                            elif(self.population[i+x,j+y]== 2 or self.population[i+x,j+y]==3 or self.population[i+x,j+y] == 4 or self.population[i+x,j+y] == 5 or self.population[i+x,j+y] ==6):
                                pass

                            else:
                                self.population[i+x,j+y] = self.infection(self.propagation, self.pourcentage_mort)
                    if population_copy[i,j] == 2:
                        self.population[i,j] = 3
                    if population_copy[i,j] == 3:
                        self.population[i,j] = 4

#-----------------------------------------------------------------------------
#paramètre pour les animations
c = mpl.colors.ListedColormap(['white', 'red',"darkorange","orange",'blue', 'black','cyan']) #couleurs white Saint, red Infecté, blue Retablis, black Dead, cyan Vacciné donc immunisé
n = mpl.colors.Normalize(vmin=0,vmax=6)



#----------------------------------------------------------------------------
#Figure 1. Sans geste barrière ni vaccination
def initialisation_graph():
    plot1.set_data(cas_1.list_population[0])
    return plot1

def update(j):
    plot1.set_data(cas_1.list_population[j])
    return plot1

cas_1 = Population(50, 0.45, 0.01,70,0.1)
cas_1.voisinage(50)
fig1 = plt.figure()

fig1.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel Sans gestes Barrières")

plot1 = plt.matshow(cas_1.list_population[0], fignum=0, cmap=c, norm=n)

anim1= FuncAnimation(fig1, update, init_func = initialisation_graph, frames=cas_1.frames, interval =300, blit=False, repeat =True)
plt.show()

#save image
#writer= animation.PillowWriter(fps=70)
#anim1.save(r'C:\Users\gremi\Desktop\Prog_pour_Ingenieur\projet\projetprog\site\graph\animation1.gif', writer= writer)


#----------------------------------------------------------------------------
#Figure 2. Avec geste barrière mais pas vaccination
def initialisation_graph2():
    plot2.set_data(cas_2.list_population[0])
    return plot2

def update2(j):
    plot2.set_data(cas_2.list_population[j])
    return plot2

cas_2 = Population(50, 0.36, 0.01,70,0.1)
cas_2.voisinage(50)
fig2 = plt.figure()

fig2.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel Avec gestes Barrières")

plot2 = plt.matshow(cas_2.list_population[0], fignum=0, cmap=c, norm=n)

anim2= FuncAnimation(fig2, update2, init_func = initialisation_graph2, frames=cas_2.frames, interval =300, blit=False, repeat =True)
plt.show()

#anim2.save(r'C:\Users\gremi\Desktop\Prog_pour_Ingenieur\projet\projetprog\Animated_plots\animation2.gif', writer= writer)

#----------------------------------------------------------------------------
#Figure 3. Avec geste barrière et 10% vaccination
def initialisation_graph3():
    plot3.set_data(cas_3.list_population[0])
    return plot3

def update3(j):
    plot3.set_data(cas_3.list_population[j])
    return plot3

cas_3 = Population(50, 0.36, 0.01,70,0.1)
cas_3.vaccination()#Vaccination ne marche pas !!
cas_3.voisinage(50)
fig3 = plt.figure()

fig3.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel Avec gestes Barrières et 10% Vaccination")

plot3 = plt.matshow(cas_3.list_population[0], fignum=0, cmap=c, norm=n)

anim3= FuncAnimation(fig3, update3, init_func = initialisation_graph3, frames=cas_3.frames, interval =300, blit=False, repeat =True)
plt.show()

#anim3.save(r'C:\Users\gremi\Desktop\Prog_pour_Ingenieur\projet\projetprog\Animated_plots\animation3.gif', writer= writer)

#----------------------------------------------------------------------------
#Figure 4. Soit les gens bougent dans la ville mais peuvent infecter 5 personnes (les amis/collegues qu'ils cottoyent régulièrement)
def initialisation_graph4():
    plot4.set_data(cas_4.list_population[0])
    return plot4

def update4(j):
    plot4.set_data(cas_4.list_population[j])
    return plot4

cas_4 = Population(50, 0.45, 0.01,70,0.1)
cas_4.voyages(50)
fig4 = plt.figure()

fig4.patch.set_facecolor('lightgrey')
plt.axis("off")
plt.title("Propagation Visuel Avec gestes Barrières et Trajets")

plot4 = plt.matshow(cas_4.list_population[0], fignum=0, cmap=c, norm=n)

anim4= FuncAnimation(fig4, update4, init_func = initialisation_graph4, frames=cas_4.frames, interval =300, blit=False,repeat =True)
plt.show()

#anim4.save(r'C:\Users\gremi\Desktop\Prog_pour_Ingenieur\projet\projetprog\Animated_plots\animation4.gif', writer= writer)

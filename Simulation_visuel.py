import numpy as np
from matplotlib import pyplot as plt
import turtle
#Création visuelle de la propagation d'une épidemie
#Pygame marche pas, du coup je fais avec quel site ?


#idee 2: faire une grille avec à chaque changement
#une proba de contaminer les carré autour qui n'on pas déjà été infecté

#1. Faire une grille:




#------------------------------------------------------------------------
# 1.Création de la fenetre

#taille fenetre

#couleur fenetre



#2. Création des personnes movement, position, couleur suivant le statut
class Personne:
    def __init__(self,x,y,vx,vy, statut):
        self.x = x
        self.y = y

    def mouvement(self):
        #attention de pas dépasser la fenetre
        #attention à quand ca change de direction -> changement de vitesse
        #condition vx^2 + vy^2 = vitesse
        #condition de mouvement selon statu ! infecté/dead bouge plus
        if self.x =
        if self.y =
        if self.statut =
        if self.statut =
        else pass


    def apparance(self):
        #pygame.circle(surface, color, center, radius) -> color change suivant le statut ! C(255, 255, 0),I(255, 0, 0),S(0, 0, 255),R(0, 255, 0),D(0, 0, 0)
        # I = S = R = D = C = ??


#3. condition pour changer de statut
def infection:
    if certain temps dans certaine zone -> Saint becomes infectée

#4. run the file




Grille avec des carré qui changent de couleur avec le temps
    funcanimation ou alors turtle ou pygame mais marche pas !!

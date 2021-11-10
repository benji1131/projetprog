import numpy as np
from matplotlib import pyplot as plt
import pygame
#Création visuelle de la propagation d'une épidemie
#------------------------------------------------------------------------
# 1.Création de la fenetre
pygame.init()
#taille fenetre
fenetre = pygame.display.set_mode([800,600])
#couleur fenetre
fenetre.fill((255, 255, 255))#--> tester les tailles

# Run until the user asks to quit
running = True
while running:
    # Did the user click the window close button?
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False




#2. Création des personnes movement, position, couleur suivant le statut
class Personne:
    def__init__(self,x,y,vx,vy):
        self.x = x
        self.y = y

    def mouvement(self):
        #attention de pas dépasser la fenetre
        #attention à quand ca change de direction -> changement de vitesse
        #condition vx^2 + vy^2 = vitesse
        #condition de mouvement selon statu ! infecté bouge plus, dead bouge plus


    def apparance(self):
        #pygame.circle(surface, color, center, radius) -> color change suivant le statut ! C,I,S,R,D
        # I = S = R = D = C = ??
        pygame.cricle(fenetre,[S,C,I,D,R], (self.x,self.y), TESTER)

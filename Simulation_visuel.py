import numpy as np
from matplotlib import pyplot as plt

#Création visuelle de la propagation d'une épidemie
#Pygame marche pas, du coup je fais avec quel site ?
#------------------------------------------------------------------------
# 1.Création de la fenetre
pygame.init()
#taille fenetre
fenetre = pygame.display.set_mode([800,600])
#couleur fenetre
fenetre.fill((255, 255, 255))#--> tester les tailles


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
        pygame.cricle(fenetre,[S,C,I,D,R], (self.x,self.y), TESTER_radius)

#3. condition pour changer de statut
def infection:
    if certain temps dans certaine zone -> Saint becomes infectée

#4. run the file

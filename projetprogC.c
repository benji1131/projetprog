
//---------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//-----------------------------------------------------------------------------------------------
// STRUCTURE
struct pays{
  char* nom;
  int population;
  int pourcentage_vaccine;
  int densite_pop;
};

//------------------------------------------------------------------------------------------------
//Ce qu'on peut choisir
// -> pays
// -> commencer patient zéros ou alors état actuelle/moment du semestre
// -> taux de confinement


//..........................................................................................
//.........................................................................................
// Notes
  // R + V = Herve
  //rate epidemic R0 < 1
                //R0 > 1 epidemic


//-----------------------------------------------------------------------------------------------
// FONCTIONS

// soit trois type de personne: Saint S, Retablis R, Infecté I, (Dead D?), (Vacciné ?) -> somme = 1 (pourcentage)
// durée ou on peut infecter les gens
// virulence: 1 infecté peut contaminer cb de personne ?

// taux de mortalité <3% (entre (15-30)/100) (moyenne) ->applique que aux personnes non vaccinées
// pourcentage de gens qui rechoppe le covid


// definir condition de propagation

void propagation(Ben){
  //1 individus cb de personne il peut toucher
  // mettre une proba aléatoire de grand porteur
  // temps ou t es infectueux
  // taux vaccination / taux des gens deja rétablis
  // confinement -> ! personne malade mais non déclarée !! ne sont pas confinée
  // densité popo
}

//------------------------------
//((((void pourcentage_vacine(){
  //evolution de ce pourcentage dans le temps

  //-> Simule ou estime ?
//})))))
//------------------------------

void temp_retablissement(){
  //aléatoire selon moyenne de temp_retablissement
  // mortatlité -> si pas rétablis !!
  // vacciné/remalade retablisssement plus rapide et PAS mortalité


}


void population(lola){
  //nbr_initale_inf t=0
  //nbr infecte après temps t
  // en pourcentage 1 = M + R + V + S + D
  //renvois malade / rétablis / vacciné / Saint/ dead


}


void fichier (){
  //plus tard


}


void variant_potentiels(){
  //proba new variant
  //return nbr potentiel de variant
  //-> Somme personne qui ont été infecte apres temps t / proba de mutation pour avoir variant
  //-> se renseigner
}

//-----------------------------------------------------------------------------------------------
//Fichiers




//-----------------------------------------------------------------------------------------------
//ETAPE1

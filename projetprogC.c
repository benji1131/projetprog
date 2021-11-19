
//---------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//--------------------------------------------------------------------------------------------

void simulation_covid(struct pays, s, c, i, r, d, Re0, gesteBarriere, confinement){
  //Paramètre constantes
  double incidence = pays.incidence ; // taux d'incidence
  // double Re0 = ; // taux de propagation (change tous les 7 jours)
  int lambda = 17 ; //nbr de jour malade -> infecte/lamba donne à tout instant (15-20 covid)
  int incub = 5 ;   //incub est la durée, en jours, de la période d’incubation.
                  //-> estimée à 3-5 jours mais peut aller jusqu’à 14 jours.
  int tau1 = 6 * 30 ; //6mois immunisé si chopé le covid [jours]
  int tau2 = 12 * 30 ;   // 12 mois immunisé si vacciné [jours]
  double mu = 0,03 ; // taux de mortalité en suisse

  if(gesteBarriere == True){
    double Re -= Re0 * 0,7 ; // les gestes barrières réduisent de 30% le taux de propagation
  }
  else {
    double Re = Re0 ;
  }

  if (confinement == True){
    double Re -= Re0 * 0,26 ; // le confinement réduit le taux de propagation de 84 %
  }
  else {
    double Re = Re0 ;
  }

  double beta = incidence * Re ; //

  // Initialisation des valeurs -->TABLEAU !!!!!!!!!!!-> par pays : I,C,
  // int s0 = &pays.population - 1 ; //saines
  // int c0 = 1 ; // contaminées
  // int i0 = 0 ;  // infectées après période d'incubation
  // int r0 = 0 ; //rétablies-> = 0 ca on veut  voir 'évolution' de ce facteur au temps t
  // int d0 = 0 ; // mort initalisé a 0 pour avoir la valeur
  // int immun  = pays.vaccine ;  //!!!!! à travailer dans notre tableau
  int population_totale = s + c + i + r + immun - d ;

  //Soit variation des valeurs selon le modèle SIR étendu
  // Population totale diminue avec cet Simulation
  int ds_/dt = - beta * i * s + r / tau1 + immun / tau2 ;
  int dc_/dt = beta * i * s – c / incub ;
  int di_/dt = c / incub - i / lambda - mu * i ;
  int dr_/dt = i / lambda - r / tau1 ;
  int dd_/dt = mu * i ;
  int dimmun_/dt = imun - imun / tau2 ;
   // changement des valeurs à mettre dans matrices pour les graphs

   population_totale -= dd_/dt ;

   printf ("%d %d %d %d %d %d", ds_/dt, dc_/dt, di_/dt, dr_/dt, dd_/dt, dimmun_/dt)
}


//-----------------------------------------------------------------------------------------------
// STRUCTURE
struct pays{
  char* nom;
  int population;
  int vaccine;
  int densite_pop;
  double r0;
  int incidence ;
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
                //R = R(0)*x -> x = susceptible population -> (saint + %petit personne vaccinées/retablies)


//-----------------------------------------------------------------------------------------------
// FONCTIONS

// soit trois type de personne: Saint S, Retablis R, Infecté I, (Dead D?), (Vacciné ?) -> somme = 1 (pourcentage)
// durée ou on peut infecter les gens
// virulence: 1 infecté peut contaminer cb de personne ?

// taux de mortalité <3% (entre (15-30)/100) (moyenne) ->applique que aux personnes non vaccinées
// pourcentage de gens qui rechoppe le covid






//------------------------------
//((((void pourcentage_vacine(){
  //evolution de ce pourcentage dans le temps

  //-> Simule ou estime ?
//})))))
//------------------------------

void retablissement(){
  //aléatoire selon moyenne de temp_retablissement
  // mortatlité -> si pas rétablis !!
  // vacciné/remalade retablisssement plus rapide et PAS mortalité

  return infcté-retablis /unitétmeps
}


void population(struct pays nom, double time){ oublie j ai fais la focntion selon le modèle de SIR
  int saine = nom.population - 1;
  int infectee = 1 ;
  int immunise = 0 ;
  int dead = 0 ;
  int vaccine = 0 ;
  for (int i = 0; i < time; i++) {
    infectee = infectee * propagation(infectee, immunise, nom) ;

    }
  }


        for (int w = 0; w < 5)
    }
  }


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




//-------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  totale  = []
  infecte = []   // axes y
  retablis= [] // si pas immun -> peut redevenir saint
  dead    = []  // si pas retablis
  immun   = []  // (infecté + retablis) + dead
  sain =[] //  pas touche
  temps   = []  // axe x --> definie selon boucle for








  return 0;
}

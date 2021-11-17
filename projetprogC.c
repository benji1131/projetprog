
//---------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//--------------------------------------------------------------------------------------------

void simulation_covid(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx,){
  //Paramètre constantes
  double beta = $$$$$$$$ ; //taux d'incidence => $
  double lambda = 17 ; //nbr de jour malade -> infecte/lamba donne à tout instant (15-20 covid)
  double incub = 4 ;   //incub est la durée, en jours, de la période d’incubation.
                  //-> estimée à 3-5 jours mais peut aller jusqu’à 14 jours.
  double tau1 = 6 * 30 ; //6mois immunisé si chopé le covid [jours]
  double tau2 = 12 * 30 ;   // 12 mois immunisé si vacciné [jours]
  double mu_sans_gestes = 0,03; //mu > 0 prop virulence de l’agent contaminant. 2 à 3personne sans gestes, mais valeur de 0-0.1 -> 0.03?
  doube mu_avec_geste = 0,02; //On met dans la fonction ou alors dans le int ? pour faire les deux cas de figure

  // Initialisation des valeurs -->TABLEAU !!!!!!!!!!!-> par pays : I,C,
  int s0 = ; //saint
  int c0 = ; // contamine
  int i0 = ;  // infecté après période d'incubation
  int r0 = 0; //rétabli-> = 0 ca on veut  voir 'évolution' de ce facteur au temps t
  int d0 = 0; // mort initalisé a 0 pour avoir la valeur
  double immun0  = pourcentage_vacine * population_totale;  //!!!!! à travailer dans notre tableau
  double pourcentage_vaccine = ;
  int population_totale = ;

  //Soit variation des valeurs selon le modèle SIR étendu
  // Population totale diminue avec cet Simulation
  double ds_/dt = – beta * i0 * s0   + r0 / tau1  + immun/tau2;
  double dc_/dt = beta * i0 * s0 – c0 / incub;
  double di_/dt = c0 / incub – i0 / lambda – mu*i0;
  double dr_/dt = i0 / lambda- r0/tau1;
  double dd_/dt = mu * i0;
  double dimmun_/dt = imun0 - imun0/tau2;
   // changement des valeurs à mettre dans matrices pour les graphs
   xxxxxxxxxxxxxxxxxxxxxxxxxx


   population_totale = population_totale - d0;
}


//-----------------------------------------------------------------------------------------------
// STRUCTURE
struct pays{
  char* nom;
  int population;
  int pourcentage_vaccine;
  int densite_pop;
  double r0;
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

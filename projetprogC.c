
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


// re suisse = (1.15 - 1.35) varie

// definir condition de propagation

int propagation(Ben, int infecte, double * pays){ // par personnes comment propage

  srand(time(NULL));
  double = randomDomain = RAND_MAX +1.0;
  double r0 = 115+(rand()/randomDomain * 20)/100;

  double superpropagateur_prob = rand()/randomDomain * 100;

  if(superporgpagateur_prob <=1){
    return 10 + rand()/randomDomain*10;
  }
  else{
    return rand()/randomDomain * 3; //->0,73 à 2,8 selon gestes barrière moyenne de 1,18
  }

    return return nbr_personne_inf_par_1_personne_infectee_de_base; // 1 personne infecte 0.5pers
//-> cb une personne infecte de personne selon temps t

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

void retablissement(){
  //aléatoire selon moyenne de temp_retablissement
  // mortatlité -> si pas rétablis !!
  // vacciné/remalade retablisssement plus rapide et PAS mortalité

  return infcté-retablis /unitétmeps
}


void population(struct pays nom, double time){
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

#include <stdio.h>
#include <math.h>

struct Parametre{
	//paramètre situation initale
	char* nom;
	int population0;

	//paramètres du modèle
	double upsilon;
	double alpha;
	double beta ;
	double gamma ;
	double delta ;
	double mah ;
	double mah1 ;
	double k ;
	double k1 ;
	double mu ;


};


void simulation_covid2(double *population, struct Parametre nom, double s, double e, double i,double q, double r, double d, double v, int t){

	double upsilon = nom.upsilon ; // vaccine inefficacy -> (1-upsilon) = vaccine efficiency
	double alpha = nom.alpha ; //vaccination rate
	double beta = nom.beta ; //tranmsission rate divided by total amount of population
	double gamma = nom.gamma ;//average latent time
	double delta = nom.delta ;// average quarantine time
	double mu = nom.mu; // natural mortality and birth rate
	double k = nom.k; //mortality rate by virus
	double k1 = nom.k1;
	double mah = nom.mah;	//recovery rate4
	double mah1 = nom.mah1;
	double population_totale = nom.population0;



	/*delta = rate de perte immun -> assume de environ 10 mois
		upsilon = vaccination

     double r0 =beta * new_people *gamma *(mu + alpha * upsilon)/(mu * (mu + gamma) * (mu + delta) * (mu + alpha)); XXXXX

	*/
	// time dépendant factors
	double k_t = k * exp(- k1 * t);
	double mah_t = mah * (1 - exp(- mah1 * t));

	// soit evolution de la population (dev taylor)

	double S = s - s * beta * i/population_totale - s * alpha - s * mu + mu * population_totale ;
	double E = e +(- e * gamma + beta * s * i / population_totale + upsilon * beta * v * i / population_totale + beta * s * i / population_totale - mu * e);
	double I = i +( e * gamma - delta * i  - mu * i - mu * s);
	double Q = q +( delta * i - mah_t * q - k_t * q - mu * q) ;
	double R = r +(mah_t * q  - mu * r);
	double D = d +(k_t* q);
	double V = v + (alpha * s - upsilon * beta * v * i / population_totale - mu * v);

	population_totale = S+E+I+Q+R+V ;

	population[0] = S ;
	population[1] = E ;
	population[2] = I ;
	population[3] = Q ;
	population[4] = R ;
	population[5] = D ;
	population[6] = V ;
	population[7] = population_totale;

}

/*
3 scénario différent
- simulation d'une épidémie à ses début
- simulation avec un taux de vaccination qui varie
- simulation avec un variant légèrement plus puissant

-> pk pas faire en sorte que le prof choissisent parmis une certaine range ou on aura testé les graphs ?
*/




double fichier(char * filename, double * S, double * E, double * I, double * Q, double * R, double * D, double * V, double * population_totale, int t){

	FILE * fichier = fopen (filename, "w") ;

	if (fichier == NULL) {
		printf("Ouverture impossible\n") ;
		return 1 ;
	}
	for (int i = 0; i <= t; i++) {
			fprintf(fichier, "%.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f ", S[i], E[i], I[i], Q[i], R[i], D[i],V[i], population_totale[i]);
			fprintf(fichier, "\n");
	}
	fclose(fichier) ;
	return 0 ;
}
/*
 1.suisse:
 new people = 64300/364 = 177 personne/jour (2020)
 mu =
 k =
 r0 = 	-> date ( )


 2.arabie saoudite:
 new_people: 2300 persons/day
 mu = 0,0035 --> vérifier avec graph -> divise par 100?
 k = 2.13
 alpa = 3.5×10−4  day −1
 ro =

 3.Chine
 *


paramètre globaux :
gamma = 1/5.5 jours
upsilon = 0.05 pour moderna ou pfiser à vérifier
delta = 1/3.8 jours
mah = 1/10 jours
rho = 1/15 jours

paramètre à faire varier :
*
- alpha
- r0 qui permet de calculer beta !
- r0_1 = 1 -->beta1 =...
- r0_2 = 2.5 --> beta2 = ...





 */

int main(int argc, char const *argv[]) {

//intitialisation des valeurs
	double S = 8427000 ;
	double E = 3 ;
	double I = 3 ;
	double Q = 1 ;
	double R = 0 ;
	double D = 0 ;
	double V = 0 ;
	double pop_tot = S + E + I + Q + R + V ;
	//double R0 = 1 ;
	int t = 120 ;
// Structure

	//double beta = R0 *(mu * (mu + gamma) * (mu + delta) * (mu + alpha) /(new_people *gamma *(mu + alpha * upsilon)) -> a faire avec les valeur de la structure et un tableau

	//dernier test qui marchait pas avant de changer la formukestruct Parametre figure_1 = {"Début du Covid (Arabie Saoudite)", 34810000, 0.05, 0.00035, 0.00000000343, 0.182, 0.26, 0.066667, 0.00003, 2300, 0.014, 0.1};
	struct Parametre figure1= {"spain", 8427000, 0.05,0.000035, 1.073, 0.776, 0.61,0.062, 0.017, 0.171, 0.970, 0.000035};

	double s_t[t] ;
	double e_t[t] ;
	double i_t[t] ;
	double q_t[t] ;
	double r_t[t] ;
	double d_t[t] ;
	double v_t[t] ;
	double population_totale[t] ;

	s_t[0] = S ;
	e_t[0] = E ;
	i_t[0] = I ;
	q_t[0] = Q ;
	r_t[0] = R ;
	d_t[0] = D ;
	v_t[0] = V;
	population_totale[0] = pop_tot ;

	for (int i = 1; i < t ; i ++) {

		double population[t] ;

		simulation_covid2(population, figure1, S, E, I, Q, R, D, V, i);

		S = population[0] ;
		E = population[1] ;
		I = population[2] ;
		Q = population[3] ;
		R = population[4] ;
		D = population[5] ;
		V = population[6] ;
		pop_tot = S + E + I + Q + R + V ;

		s_t[i] = S ;
		e_t[i] = E ;
		i_t[i] = I ;
		q_t[i] = Q ;
		r_t[i] = R ;
		d_t[i] = D ;
		v_t[i] = V;
		population_totale[i] = pop_tot ;
	}

	fichier("covid.csv", s_t, e_t, i_t, q_t, r_t, d_t, v_t, population_totale, t-1) ; // dans fichier . saint-e-inf-quar-rétab-dead-vacc-totale

	return 0;

}

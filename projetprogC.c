#include <stdio.h>
#include <math.h>


struct pays{
	char* nom;
	int population;
	double vaccine;
	double beta ;
	double gamma ;
	double delta ;
	double lamda0 ;
	double lambda1 ;
	double k0 ;
	double k1 ;
	double tau ;

};

void simulation_population_Q(double *population, struct pays nom, double s, double c, double i, double r, double d, int t){

	double lambda0 = nom.lambda0 ;
	double lambda1 = nom.lambda1 ;
	double k0 = nom.k0 ;
	double k1 = nom.k1 ;
	double beta = nom.beta ;
	double gamma = nom.gamma ;
	double delta = nom.delta ;
	double tau = nom.tau ;

	double population_totale = s + e + i + r ;
	// 2 facteurs sont dépendant du temps//
	double k_t = k0*exp(-k1*t); //mortality rate //faudra rajouter un facteur temps dans la fonction qui varie en fct de loop
	double lamda_t = lambda0*(1-exp(-lambda1*t)); //recovery rate

/*
beta = Infection rate
gamma = incubation rate
delta = quarantine rate
lambda = recovery rate
k = mortality rate
tau = length of protection
*/

	double S = s - (beta*s*i)/population_totale;
	double E = e - e*gamma + (beta*s*i)/population_totale;
	double I = i + e*gamma - delta *i;
	double Q = q + delta * i - lambda_t *q -k_t*q;
	double R = r + lambda_t * q  ;
	double D = d + k_t*q;


	population[0] = S ;
	population[1] = E ;
	population[2] = I ;
	population[3] = R ;
	population[4] = D ;
	population[5] = population_totale ;

}

struct Parametre{
	int population;
	double upsilon;
	double alpha;
	double beta ;
	double gamma ;
	double delta ;
	double rho ;
	double mu ;
	double new_people ;
	double k ;
	double mah ;

};


void simulation_covid2(double *population, struct pays nom, double s, double c, double i, double r, double d, int t){

	double upsilon = nom.upsilon ; // vaccine inefficacy -> (1-upsilon) = vaccine efficiency
	double alpha = nom.alpha ; //vaccination rate
	double beta = nom.beta ; //tranmsission rate divided by total amount of population
	double gamma = nom.gamma ;//average latent time
	double delta = nom.delta ;// average quarantine time
	double rho = nom.rho; //average days until death
	double mu = nom.mu; // natural death
	double new_people = nom.new_people; // birth and new résident
	double k = nom.k; //mortality rate
	double mah = nom.mah;	//average days until recovery


	/*delta = rate de perte immun -> assume de environ 10 mois
		upsilon = vaccination


	*/

	double S = s*(1 - beta * i - alpha - mu )+ new_people;
	double E = e - e * gamma + beta * s * i + upsilon * beta * v * i + beta * s * i - mu * e;
	double I = i + e * gamma - delta * i  - mu * i;
	double Q = q + delta * i - (1-k) * mah * q - k * rho * q - mu * q ;
	double R = r + (1-k) * mah * q  - mu * r;
	double D = k * rho * q ;
	double V = v + apha * s - upsilon * beta * v * i - mu * v;
	double pop_totale = S+E+I+Q+R+D+V ;
	double r0 =beta * birth *gamma *(mu + alpa * upsilon)/(mu * (mu + gamma) * (mu + delta) * (mu + alpha));

	population[0] = S ;
	population[1] = E ;
	population[2] = I ;
	population[3] = Q ;
	population[4] = R ;
	population[5] = D ;
	population[6] = V ;
	population[7] = population_totale ;
	population[8] = r0;
}
/*
3 scénario différent
- simulation d'une épidémie à ses début
- simulation avec un taux de vaccination qui varie
- simulation avec un variant légèrement plus puissant

-> pk pas faire en sorte que le prof choissisent parmis une certaine range ou on aura testé les graphs ?
*/




double fichier(char * filename, double * S, double * C, double * I, double * R, double * D,double * V, double * population_totale, double * r0, int t){

	FILE * fichier = fopen (filename, "w") ;

	if (fichier == NULL) {
		printf("Ouverture impossible\n") ;
		return 1 ;
	}
	for (int i = 0; i <= t; i++) {
			fprintf(fichier, "%.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f ", S[i], E[i], I[i], R[i], D[i],V[i], population_totale[i], r0[i] );
			fprintf(fichier, "\n");
	}
	fclose(fichier) ;
	return 0 ;
}

int main(int argc, char const *argv[]) {

	struct pays suisse = {"Suisse", 8603900 , 0, 1} ;

	double S = 0.7  ;
	double C = 0.2 ;
	double I = 0.1 ;
	double R = 0 ;
	double IMMUN = suisse.vaccine ;
	double D = 0 ;
	double pop_tot = S + C + I + R + IMMUN ;
	double Re = 1 ;
	int t = 28 ;

	double saines[t] ;
	double contaminees[t] ;
	double infectees[t] ;
	double retablies[t] ;
	double immunisees[t] ;
	double decedees[t] ;
	double population_totale[t] ;

	saines[0] = S ;
	contaminees[0] = C ;
	infectees[0] = I ;
	retablies[0] = R ;
	immunisees[0] = I ;
	decedees[0] = D ;
	population_totale[0] = pop_tot ;

	for (int i = 1; i < t ; i ++) {

		double population [t] ;

		simulation_population(population, suisse, S, C, I, R, D, IMMUN, Re, t) ;

		S = population[0] ;
		C = population[1] ;
		I = population[2] ;
		R = population[3] ;
		D = population[4] ;
		IMMUN = population[5] ;
		pop_tot = S + C + I + R + IMMUN ;

		saines[i] = S ;
		contaminees[i] = C ;
		infectees[i] = I ;
		retablies[i] = R ;
		immunisees[i] = IMMUN ;
		decedees[i] = D ;
		population_totale[i] = pop_tot ;

	fichier("covid.csv", saines, contaminees, infectees, retablies, immunisees, decedees, population_totale, t-1) ;

	return 0;
}

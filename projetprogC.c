#include <stdio.h>


struct pays{
	char* nom;
	int population;
	double vaccine;
	double incidence ;
};

void simulation_population(double *population, struct pays nom, double s, double c, double i, double r, double d, double immun, double Re, int t){

	int lambda = 17 ;
	double incub = 5 ;
	int tau1 = 6 * 30 ;
	int tau2 = 12 * 30 ;
	double mu = 0.03 ;
	double incidence = nom.incidence ;
	double beta = incidence * Re ;
	double population_totale = s + c + i + r + immun ;

	double S = s - beta * i * s + r / tau1 + immun / tau2 ;
	double C = c + beta * i * s - c / incub ;
	double I = i + c / incub - i / lambda - mu * i ;
	double R = r + i / lambda - r / tau1 ;
	double D = d + mu * i ;
	double IMMUN = immun - immun / tau2 ;

	//if (S <= 0) S = 0 ;
	//if (C >= nom.population) C = 1 ;
	//if (C <= 0) C = 0;

	population[0] = S ;
	population[1] = C ;
	population[2] = I ;
	population[3] = R ;
	population[4] = D ;
	population[5] = IMMUN ;
	population[6] = population_totale ;

}

int fichier(char * filename, int * values, int x, int y){

	FILE * fichier = fopen (filename, "w") ;

	if (fichier == NULL) {
		printf("Ouverture impossible\n") ;
		return 1 ;
	}
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (j > 0) fprintf(fichier, ",") ;
			fprintf (fichier, "%d", values) ;
		}
		fprintf(fichier, "\n") ;
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


		printf ("S = %.5f, C = %.5f, I = %.5f, R = %.5f, D = %.5f, IMMUN = %.5f, pop_tot = %.5f\n", S, C, I, R, D, IMMUN, pop_tot) ;

	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f saines\n", i, saines[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f contaminees\n", i, contaminees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f infectees\n", i, infectees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f retablies\n", i, retablies[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f immunisees\n", i, immunisees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f decedees\n", i, decedees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f population_totale\n", i, population_totale[i]);
	}





	return 0;
}

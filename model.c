#include <stdio.h>
#include <math.h>

struct pays{
	char* nom;
	int population; // nombre totale de population
	double vaccine; // nombre de personne vacciné
	double Re0 ;
	double alpha ; // taux de vaccination
};

struct Geste_barriere{
	char* nom ;
	double diminution ;
};

struct Variant{
	char* nom ;
	double augmentation ;
};

double Re(struct pays nom, struct Geste_barriere mesures, struct Variant variant){

	double Re = nom.Re0 * (1 - mesures.diminution + variant.augmentation) ;

	return Re ;
}

void simulation_population(double *population, struct pays nom, double s, double sv, double cs, double cv, double is, double iv, double rs, double rv , double d, double Re0, int t){

	int lambda = 17 ;
	double incub = 5 ;
	int tau1 = 3 * 30 ;
	int tau2 = 6 * 30 ;
	double mu1 = pow(1,-5) ;
	double mu2 = pow(2,-6) ;
	double Rev = 0.7 * Re0 ;
	double beta1 = Re0 / lambda  ;
	double beta2 = beta1 * 0.05;
	double alpha = nom.alpha ;
	double V = sv + cs + iv + rv ;
	double population_totale = s + cs + is + rs + V ;

	double S = s - beta1 * is * s + rs / tau1 - alpha * s ;
	double Sv = sv - beta2  * iv * sv + alpha * s + rv / tau2 ;
	double Cs = cs + beta1 * is * s - cs / incub ;
	double Cv = cv + beta2 * iv * sv - cv / incub ;
	double Is = is + cs / incub - is / lambda - mu1 * is ;
	double Iv = iv + cv / incub - iv / lambda - mu2 * iv ;
	double Rs = rs + is / lambda - rs / tau1 ;
	double Rv = rv + iv / lambda - rv / tau2 ;
	double D = d + mu1 * is + mu2 * iv ;

	double C = Cs + Cv ;
	double I = Is + Iv ;
	double R = Rs + Rv ;

	population[0] = S ;
	population[1] = Sv ;
	population[2] = Cs ;
	population[3] = Cv ;
	population[4] = C ;
	population[5] = Is ;
	population[6] = Iv ;
	population[7] = I ;
	population[8] = Rs ;
	population[9] = Rv ;
	population[10] = R ;
	population[11] = D ;
	population[12] = V ;
	population[13] = population_totale ;

}

double fichier(char * filename, double * S, double * V, double * C, double * I, double * R, double * D, double * pop_tot, int t){

	FILE * fichier = fopen (filename, "w") ;

	if (fichier == NULL) {
		printf("Ouverture impossible\n") ;
		return 1 ;
	}
	for (int i = 0; i <= t; i++) {
			fprintf(fichier, "%.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f ", S[i], V[i], C[i], I[i], R[i], D[i], pop_tot[i]) ;
			fprintf(fichier, "\n");
	}
	fclose(fichier) ;
	return 0 ;
}


int main(int argc, char const *argv[]) {

	struct pays suisse = {"Suisse", 8603900 , 0, 1.2, 0.0019} ;

	struct Geste_barriere port_du_masque = {"masque", 0.3} ;
	struct Geste_barriere confinement = {"quarantaine", 0.8} ;

	struct Variant alpha = {"alpha", 0.5};
	struct Variant delta = {"delta", 0.7};
	struct Variant omicron = {"omicron", 0.9};

	double Cs = 0.03 ;
	double Cv = 0 ;
	double C = Cs + Cv ;
	double Is = 0 ;
	double Iv = 0 ;
	double I = Is + Iv ;
	double Rs = 0 ;
	double Rv = 0 ;
	double R = Rs + Rv ;
	double D = 0 ;

	double S = (suisse.population - suisse.vaccine) / suisse.population - Cs - Is ;
	double Sv = suisse.vaccine / suisse.population - Cv - Iv;
	double V = Sv + Cv + Iv + Rv ;
	double pop_tot = S + V + Cs + Is + Rs ;
	int t = 14 ;
	double Re0 = suisse.Re0 ;

	double saines[t] ;
	double vacc_s[t] ;
	double cont_s[t] ;
	double cont_v[t] ;
	double contaminees[t] ;
	double inf_s[t] ;
	double inf_v[t] ;
	double infectees[t] ;
	double ret_s[t] ;
	double ret_v[t] ;
	double retablies[t] ;
	double decedees[t] ;
	double vaccinees[t] ;
	double population_totale[t] ;

	saines[0] = S ;
	vacc_s[0] = Sv ;
	cont_s[0] = Cs ;
	cont_v[0] = Cv ;
	contaminees[0] = C ;
	inf_s[0] = Is ;
	inf_v[0] = Iv ;
	infectees[0] = I ;
	ret_s[0] = Rs ;
	ret_v[0] = Rv ;
	retablies[0] = R ;
	decedees[0] = D ;
	vaccinees[0] = V ;
	population_totale[0] = pop_tot ;

	for (int i = 1; i < t ; i ++) {

		double population [t] ;

		simulation_population(population, suisse, S, Sv, Cs, Cv, Is, Iv, Rs, Rv, D, Re0, t) ;

		S = population[0] ;
		Sv = population[1] ;
		Cs = population[2] ;
		Cv = population[3] ;
		C = population[4] ;
		Is = population[5] ;
		Iv = population[6] ;
		I = population[7] ;
		Rs = population[8] ;
		Rv = population[9] ;
		R = population[10] ;
		D = population[11] ;
		V = population[12] ;
		pop_tot = population[13] ;

		saines[i] = S ;
		vacc_s [i] = Sv ;
		cont_s[i] = Cs ;
		cont_v[i] = Cv ;
		contaminees[i] = C ;
		inf_s[i] = Is ;
		inf_v[i] = Iv ;
		infectees[i] = I ;
		ret_s[i] = Rs ;
		ret_v[i] = Rv ;
		retablies[i] = R ;
		decedees[i] = D ;
		vaccinees[i] = V ;
		population_totale[i] = pop_tot ;


		printf ("S = %.5f, Vs = %.5f, Cs = %.5f, Cv = %.5f, C = %.5f, Is = %.5f, Iv = %.5f, I = %.5f, Rs = %.5f, Rv = %.5f, R = %.5f, D = %.5f, V = %.5f, pop_tot = %.5f\n", S, Sv, Cs, Cv, C, Is, Iv, I, Rs, Rv, R, D, V, pop_tot) ;

	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f saines\n", i, saines[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f vaccinees saines\n", i, vacc_s[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f contaminees saines\n", i, cont_s[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f contaminees vacc\n", i, cont_v[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f contaminees\n", i, contaminees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f infectees saines\n", i, inf_s[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f infectees vacc\n", i, inf_v[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f infectees\n", i, infectees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f retablies saines\n", i, ret_s[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f retablies vacc\n", i, ret_v[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f retablies\n", i, retablies[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f decedees\n", i, decedees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f vaccinees\n", i, vaccinees[i]);
	}
	printf ("\n") ;

	for (int i = 0 ; i < t; i++) {
		printf ("jour : %d = %.5f population_totale\n", i, population_totale[i]);
	}

	fichier("covid.csv", saines, vaccinees, contaminees, infectees, retablies, decedees, population_totale, t-1) ;

	return 0;
}

#include <stdio.h>
#include <math.h>

struct pays{
	char* nom;
	int population; // nombre totale de population
	double vaccine; // nombre de personne vacciné
	double Re0 ;	// taux de reproduction
	double alpha ; 	// taux de vaccination
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

void simulation_population(double *population, struct pays nom, double s, double cs, double cv, double is, double iv, double r , double d, double v, double Re0){

	int lambda = 17 ;			// temps d'infection en jours
	double incub = 5 ;			// temps d'incubations en jours
	int tau = 4 * 30 ;			// période d'immunité
	double mu1 = pow(1,-5) ; 	// taux de mortalité
	double mu2 = pow(2,-6) ;	// taux de mortalité pour personne immunisée
	double beta1 = Re0/17  ; 	// beta = Re0 / lambda -> taux de contamination
	double beta2 = beta1 * 0.05;// on multiplie par 0.05 cas on assume une immunité de 95%
	double alpha = nom.alpha ;	// taux de vaccination -> estimé selon régression linéaire



	double S = s - beta1 * (is + iv) * s + r / tau - alpha * s ;
	double Cs = cs + beta1 * (iv +is) * s - cs / incub ;
	double Cv = cv + beta2 * (is + iv) * r - cv / incub ;
	double Is = is + cs / incub - is / lambda - mu1 * is/100 ;
	double Iv = iv + cv / incub - iv / lambda - mu2 * iv/100 ;
	double R = r + is / lambda + iv / lambda - r / tau + alpha * s;
	double D = d + mu1 * is/100 + mu2 * iv/ 100 ;
	double V = v + alpha * s ;

	double C = Cs + Cv ;
	double I = Is + Iv ;

	double population_totale = S + C + I + R;


	population[0] = S ;
	population[1] = Cs ;
	population[2] = Cv ;
	population[3] = C ;
	population[4] = Is ;
	population[5] = Iv ;
	population[6] = I ;
	population[7] = R ;
	population[8] = D ;
	population[9] = V ;
	population[10] = population_totale;

}


double fichier(char * filename, double * S, double * V, double * C, double * I, double * R, double * D, double * pop_tot, double *cs, double *es, double *cv, double *ev, int t){

	FILE * fichier = fopen (filename, "w") ;

	if (fichier == NULL) {
		printf("Ouverture impossible\n") ;
		return 1 ;
	}
	for (int i = 0; i <= t; i++) {
			fprintf(fichier, "%.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f, %.5f ", S[i], V[i], C[i], I[i], R[i], D[i], pop_tot[i], cs[i], es[i], cv[i], ev[i]);
			fprintf(fichier, "\n");
	}
	fclose(fichier) ;
	return 0 ;
}


int main(int argc, char const *argv[]) {


	struct pays suisse1 = {"Suisse", 8603900 , 0, 1.5, 0} ; //situation 1 , 4 , 5 , 6 , 7
	struct pays suisse2 = {"Suisse", 8603900 , 0, 1.5, 0.0019} ; //Situation 2
	struct pays suisse3 = {"Suisse", 8603900 , 0.30, 1.5, 0.0019} ; // Situation 3


	struct Geste_barriere rien = {"rien", 0} ;
	struct Geste_barriere port_du_masque = {"masque", 0.3} ;
	struct Geste_barriere confinement = {"quarantaine", 0.8} ;

	struct Variant aucun = {"null", 0};
	struct Variant alpha = {"alpha", 0.5};
	struct Variant delta = {"delta", 0.7};


	int t = 90 ;


// ce qui varie	 S V RE ALPHA
/*
 * dans 1,2,3 : %Vacciné et alpha varie
 * 		-Sans vaccins %vacciné = 0 et alpha = 0
 *     	-vaccin ( début à %vacciné: zéros (2), début à 30 (3) ->  avec alpha = 0.0019)
 *
 * Dans 4,5 :
 * 		- Avec Geste Barrières : Re varie
 * 							- Masque
 * 							- Confinnement
 *
 * Dans 6,7 :
 * 		-  Variants :	Re varie
 * 					- Alpha
 * 					- Delta
 *
 * */

 // Condition initilae qui varies

	//Situation 1-3
	double S1 = 1- suisse1.vaccine -0.3;		//le 0.3 vient de la propo de population initale qui est contaminée
	double V1 = suisse1.vaccine;
	double R01 = suisse1.Re0 ;
	double R1 = suisse1.vaccine;

	double S2 = 1-suisse2.vaccine-0.3;
	double V2 = suisse2.vaccine;
	double R2 = suisse2.vaccine;
	double R02 = suisse2.Re0 ;

	double S3 = 1-suisse3.vaccine-0.3;
	double V3 = suisse3.vaccine;
	double R3 = suisse3.vaccine;
	double R03 = suisse3.Re0 ;

	//Situation 4-5
	double S4 = 1- suisse1.vaccine - 0.3;
	double V4 = suisse1.vaccine;
	double R4 = suisse1.vaccine ;
	double R04 = Re(suisse1,port_du_masque,aucun) ;

	double S5 = 1- suisse1.vaccine - 0.3;
	double V5 = suisse1.vaccine;
	double R5 = suisse1.vaccine ;
	double R05 = Re(suisse1,confinement,aucun) ;

	//Situation 6,7
	double S6 = 1- suisse1.vaccine - 0.3;
	double V6 = suisse1.vaccine;
	double R6 = suisse1.vaccine ;
	double R06 = Re(suisse1,rien,alpha) ;

	double S7 = 1- suisse1.vaccine - 0.3;
	double V7 = suisse1.vaccine;
	double R7 = suisse1.vaccine ;
	double R07 = Re(suisse1,rien,delta) ;

//Initialisation des listes

// Situation 1-3 : Effet de la vaccination sur la population. Faire varier alpha et %vacciné
	// Situation 1 : sans vaccination

	//Cond. initiale
	double Cs1 = 0.30;
	double Cv1 = 0 ;
	double C1 = Cs1 + Cv1;
	double Is1 = 0 ;
	double Iv1 = 0 ;
	double I1 = Is1 + Iv1;
	double D1 = 0 ;

	double pop_totale1 = S1 + C1 + I1 + R1 ;
	// Listes
	double s1 [t] ;
	double cs1[t] ;
	double cv1[t] ;
	double c1[t] ;
	double inf_s1[t] ;
	double inf_v1[t] ;
	double inf1[t] ;
	double r1[t] ;
	double d1[t] ;
	double v1[t] ;
	double pop_tot1[t] ;

	s1[0] = S1 ;
	cs1[0] = Cs1 ;
	cv1[0] = Cv1 ;
	c1[0] = C1 ;
	inf_s1[0] = Is1 ;
	inf_v1[10] = Iv1 ;
	inf1[0] = I1 ;
	r1[0] = R1 ;
	d1[0] = D1 ;
	v1[0] = V1 ;
	pop_tot1[0] = pop_totale1 ;

	// Situation 2: Début de la vaccination avec alpha = 0.0019
	//Cond. initiale
	double Cs2 = 0.30;
	double Cv2 = 0 ;
	double C2 = Cs2 + Cv2;
	double Is2 = 0 ;
	double Iv2 = 0 ;
	double I2 = Is2 + Iv2;
	double D2 = 0 ;

	double pop_totale2 = S2 + C2 + I2 + R2 ;

	// Listes
	double s2[t] ;
	double cs2[t] ;
	double cv2[t] ;
	double c2[t] ;
	double inf_s2[t] ;
	double inf_v2[t] ;
	double inf2[t] ;
	double r2[t] ;
	double d2[t] ;
	double v2[t] ;
	double pop_tot2[t] ;

	s2[0] = S2 ;
	cs2[0] = Cs2 ;
	cv2[0] = Cv2 ;
	c2[0] = C2 ;
	inf_s2[0] = Is2 ;
	inf_v2[10] = Iv2 ;
	inf2[0] = I2 ;
	r2[0] = R2 ;
	d2[0] = D2 ;
	v2[0] = V2 ;
	pop_tot2[0] = pop_totale2 ;

	// Situation 3: Vaccination déja en place à 40% avec alpha = 0.0019
	//Cond. initiale
	double Cs3 = 0.30;
	double Cv3 = 0 ;
	double C3 = Cs3 + Cv3;
	double Is3 = 0 ;
	double Iv3 = 0 ;
	double I3 = Is3 + Iv3;
	double D3 = 0 ;

	double pop_totale3 = S3 + C3 + I3 + R3 ;
	// Listes
	double s3[t] ;
	double cs3[t] ;
	double cv3[t] ;
	double c3[t] ;
	double inf_s3[t] ;
	double inf_v3[t] ;
	double inf3[t] ;
	double r3[t] ;
	double d3[t] ;
	double v3[t] ;
	double pop_tot3[t] ;

	s3[0] = S3 ;
	cs3[0] = Cs3 ;
	cv3[0] = Cv3 ;
	c3[0] = C3 ;
	inf_s3[0] = Is3 ;
	inf_v3[10] = Iv3 ;
	inf3[0] = I3 ;
	r3[0] = R3 ;
	d3[0] = D3 ;
	v3[0] = V3 ;
	pop_tot3[0] = pop_totale3 ;

// Situation 4 et 5 : effet des gestes barrière et confinement

	// Situation 4: port du masque et effet sur la population
	//Cond. initiale
	double Cs4 = 0.30;
	double Cv4 = 0 ;
	double C4 = Cs4 + Cv4;
	double Is4 = 0 ;
	double Iv4 = 0 ;
	double I4 = Is4 + Iv4;
	double D4 = 0 ;

	double pop_totale4 = S4 + C4 + I4 + R4 ;
	// Listes
	double s4[t] ;
	double cs4[t] ;
	double cv4[t] ;
	double c4[t] ;
	double inf_s4[t] ;
	double inf_v4[t] ;
	double inf4[t] ;
	double r4[t] ;
	double d4[t] ;
	double v4[t] ;
	double pop_tot4[t] ;

	s4[0] = S4 ;
	cs4[0] = Cs4 ;
	cv4[0] = Cv4 ;
	c4[0] = C4 ;
	inf_s4[0] = Is4 ;
	inf_v4[10] = Iv4 ;
	inf4[0] = I4 ;
	r4[0] = R4 ;
	d4[0] = D4 ;
	v4[0] = V4 ;
	pop_tot4[0] = pop_totale4 ;

	// Situation 5: Confienment et effet sur la population
	//Cond. initiale
	double Cs5 = 0.30;
	double Cv5 = 0 ;
	double C5 = Cs5 + Cv5;
	double Is5 = 0 ;
	double Iv5 = 0 ;
	double I5 = Is5 + Iv5;
	double D5 = 0 ;

	double pop_totale5 = S5 + C5 + I5 + R5 ;
	// Listes
	double s5[t] ;
	double cs5[t] ;
	double cv5[t] ;
	double c5[t] ;
	double inf_s5[t] ;
	double inf_v5[t] ;
	double inf5[t] ;
	double r5[t] ;
	double d5[t] ;
	double v5[t] ;
	double pop_tot5[t] ;

	s5[0] = S5 ;
	cs5[0] = Cs5 ;
	cv5[0] = Cv5 ;
	c5[0] = C5 ;
	inf_s5[0] = Is5 ;
	inf_v5[10] = Iv5 ;
	inf5[0] = I5 ;
	r5[0] = R5 ;
	d5[0] = D5 ;
	v5[0] = V5 ;
	pop_tot5[0] = pop_totale5 ;

// Situation 6 et 7 : effet des variants
	// Situation 6: variant alpha
	//Cond. initiale
	double Cs6 = 0.30;
	double Cv6 = 0 ;
	double C6 = Cs6 + Cv6;
	double Is6 = 0 ;
	double Iv6 = 0 ;
	double I6 = Is6 + Iv6;
	double D6 = 0 ;

	double pop_totale6 = S6 + C6 + I6 + R6 ;
	// Listes
	double s6[t] ;
	double cs6[t] ;
	double cv6[t] ;
	double c6[t] ;
	double inf_s6[t] ;
	double inf_v6[t] ;
	double inf6[t] ;
	double r6[t] ;
	double d6[t] ;
	double v6[t] ;
	double pop_tot6[t] ;

	s6[0] = S6 ;
	cs6[0] = Cs6 ;
	cv6[0] = Cv6 ;
	c6[0] = C6 ;
	inf_s6[0] = Is6 ;
	inf_v6[10] = Iv6 ;
	inf6[0] = I6 ;
	r6[0] = R6 ;
	d6[0] = D6 ;
	v6[0] = V6 ;
	pop_tot6[0] = pop_totale6 ;

	// Situation 7: variant delta
	//Cond. initiale
	double Cs7 = 0.30;
	double Cv7 = 0 ;
	double C7= Cs7 + Cv7;
	double Is7 = 0 ;
	double Iv7 = 0 ;
	double I7 = Is7 + Iv7;
	double D7 = 0 ;

	double pop_totale7 = S7 + C7 + I7 + R7 ;
	// Listes
	double s7[t] ;
	double cs7[t] ;
	double cv7[t] ;
	double c7[t] ;
	double inf_s7[t] ;
	double inf_v7[t] ;
	double inf7[t] ;
	double r7[t] ;
	double d7[t] ;
	double v7[t] ;
	double pop_tot7[t] ;

	s7[0] = S7 ;
	cs7[0] = Cs7 ;
	cv7[0] = Cv7 ;
	c7[0] = C7 ;
	inf_s7[0] = Is7 ;
	inf_v7[10] = Iv7 ;
	inf7[0] = I7 ;
	r7[0] = R7 ;
	d7[0] = D7 ;
	v7[0] = V7 ;
	pop_tot7[0] = pop_totale7 ;


	for (int i = 1; i < t ; i ++) {

		double population1[t] ;

		simulation_population(population1, suisse1, S1, Cs1, Cv1, Is1, Iv1, R1, D1, V1, R01) ;

		S1 = population1[0] ;
		Cs1 = population1[1] ;
		Cv1 = population1[2] ;
		C1 = population1[3] ;
		Is1 = population1[4] ;
		Iv1 = population1[5] ;
		I1 = population1[6] ;
		R1 = population1[7] ;
		D1 = population1[8] ;
		V1 = population1[9] ;
		pop_totale1 = population1[10] ;

		s1[i] = S1 ;
		cs1[i] = Cs1 ;
		cv1[i] = Cv1 ;
		c1[i] = C1 ;
		inf_s1[i] = Is1 ;
		inf_v1[i] = Iv1 ;
		inf1[i] = I1 ;
		r1[i] = R1 ;
		d1[i] = D1 ;
		v1[i] = V1 ;
		pop_tot1[i] = pop_totale1 ;

		double population2[t] ;

		simulation_population(population2, suisse2, S2, Cs2, Cv2, Is2, Iv2, R2, D2, V2, R02) ;
		S2 = population2[0] ;
		Cs2 = population2[1] ;
		Cv2 = population2[2] ;
		C2 = population2[3] ;
		Is2 = population2[4] ;
		Iv2 = population2[5] ;
		I2 = population2[6] ;
		R2 = population2[7] ;
		D2 = population2[8] ;
		V2 = population2[9] ;
		pop_totale2 = population2[10] ;

		s2[i] = S2 ;
		cs2[i] = Cs2 ;
		cv2[i] = Cv2 ;
		c2[i] = C2 ;
		inf_s2[i] = Is2 ;
		inf_v2[i] = Iv2 ;
		inf2[i] = I2 ;
		r2[i] = R2 ;
		d2[i] = D2 ;
		v2[i] = V2 ;
		pop_tot2[i] = pop_totale2 ;

		double population3[t];

		simulation_population(population3, suisse3, S3, Cs3, Cv3, Is3, Iv3, R3, D3, V3, R03) ;
		S3 = population3[0] ;
		Cs3 = population3[1] ;
		Cv3 = population3[2] ;
		C3 = population3[3] ;
		Is3 = population3[4] ;
		Iv3 = population3[5] ;
		I3 = population3[6] ;
		R3 = population3[7] ;
		D3 = population3[8] ;
		V3 = population3[9] ;
		pop_totale3 = population3[10] ;

		s3[i] = S3 ;
		cs3[i] = Cs3 ;
		cv3[i] = Cv3 ;
		c3[i] = C3 ;
		inf_s3[i] = Is3 ;
		inf_v3[i] = Iv3 ;
		inf3[i] = I3 ;
		r3[i] = R3 ;
		d3[i] = D3 ;
		v3[i] = V3 ;
		pop_tot3[i] = pop_totale3 ;


		double population4[t] ;

		simulation_population(population4, suisse1, S4, Cs4, Cv4, Is4, Iv4, R4, D4, V4, R04) ;
		S4 = population4[0] ;
		Cs4 = population4[1] ;
		Cv4 = population4[2] ;
		C4 = population4[3] ;
		Is4 = population4[4] ;
		Iv4 = population4[5] ;
		I4 = population4[6] ;
		R4 = population4[7] ;
		D4 = population4[8] ;
		V4 = population4[9] ;
		pop_totale4 = population4[10] ;

		s4[i] = S4 ;
		cs4[i] = Cs4 ;
		cv4[i] = Cv4 ;
		c4[i] = C4 ;
		inf_s4[i] = Is4 ;
		inf_v4[i] = Iv4 ;
		inf4[i] = I4 ;
		r4[i] = R4 ;
		d4[i] = D4 ;
		v4[i] = V4 ;
		pop_tot4[i] = pop_totale4 ;


		double population5[t] ;

		simulation_population(population5, suisse1, S5, Cs5, Cv5, Is5, Iv5, R5, D5, V5, R05) ;
		S5 = population5[0] ;
		Cs5 = population5[1] ;
		Cv5 = population5[2] ;
		C5 = population5[3] ;
		Is5 = population5[4] ;
		Iv5 = population5[5] ;
		I5 = population5[6] ;
		R5 = population5[7] ;
		D5 = population5[8] ;
		V5 = population5[9] ;
		pop_totale5 = population5[10] ;

		s5[i] = S5 ;
		cs5[i] = Cs5 ;
		cv5[i] = Cv5 ;
		c5[i] = C5 ;
		inf_s5[i] = Is5 ;
		inf_v5[i] = Iv5 ;
		inf5[i] = I5 ;
		r5[i] = R5 ;
		d5[i] = D5 ;
		v5[i] = V5 ;
		pop_tot5[i] = pop_totale5 ;


		double population6[t] ;

		simulation_population(population6, suisse1, S6, Cs6, Cv6, Is6, Iv6, R6, D6, V6, R06) ;
		S6 = population6[0] ;
		Cs6 = population6[1] ;
		Cv6 = population6[2] ;
		C6 = population6[3] ;
		Is6 = population6[4] ;
		Iv6 = population6[5] ;
		I6 = population6[6] ;
		R6 = population6[7] ;
		D6 = population6[8] ;
		V6 = population6[9] ;
		pop_totale6 = population6[10] ;

		s6[i] = S6 ;
		cs6[i] = Cs6 ;
		cv6[i] = Cv6 ;
		c6[i] = C6 ;
		inf_s6[i] = Is6 ;
		inf_v6[i] = Iv6 ;
		inf6[i] = I6 ;
		r6[i] = R6 ;
		d6[i] = D6 ;
		v6[i] = V6 ;
		pop_tot6[i] = pop_totale6 ;

		double population7[t] ;

		simulation_population(population7, suisse1, S7, Cs7, Cv7, Is7, Iv7, R7, D7, V7, R07) ;
		S7 = population7[0] ;
		Cs7 = population7[1] ;
		Cv7 = population7[2] ;
		C7 = population7[3] ;
		Is7 = population7[4] ;
		Iv7 = population7[5] ;
		I7 = population7[6] ;
		R7 = population7[7] ;
		D7 = population7[8] ;
		V7 = population7[9] ;
		pop_totale7 = population7[10] ;

		s7[i] = S7 ;
		cs7[i] = Cs7 ;
		cv7[i] = Cv7 ;
		c7[i] = C7 ;
		inf_s7[i] = Is7 ;
		inf_v7[i] = Iv7 ;
		inf7[i] = I7 ;
		r7[i] = R7 ;
		d7[i] = D7 ;
		v7[i] = V7 ;
		pop_tot7[i] = pop_totale7 ;

	}





	printf ("ok") ;


// Les différents fichiers
	fichier("covid.csv", s1, v1, c1, inf1, r1, d1, pop_tot1, cs1, inf_s1, cv1, inf_v1, t-1) ;
	fichier("covid2.csv", s2, v2, c2, inf2, r2, d2, pop_tot2, cs2, inf_s2, cv2, inf_v2, t-1) ;
	fichier("covid3.csv", s3, v3, c3, inf3, r3, d3, pop_tot3, cs3, inf_s3, cv3, inf_v3, t-1) ;
	fichier("covid4.csv", s4, v4, c4, inf4, r4, d4, pop_tot4, cs4, inf_s4, cv4, inf_v4, t-1) ;
	fichier("covid5.csv", s5, v5, c5, inf5, r5, d5, pop_tot5, cs5, inf_s5, cv5, inf_v5, t-1) ;
	fichier("covid6.csv", s6, v6, c6, inf6, r6, d6, pop_tot6, cs6, inf_s6, cv6, inf_v6, t-1) ;
	fichier("covid7.csv", s7, v7, c7, inf7, r7, d7, pop_tot7, cs7, inf_s7, cv7, inf_v7, t-1) ;

	return 0;
}

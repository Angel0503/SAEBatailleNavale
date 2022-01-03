/*
Programme : main
But : {BUT PROGRAMME}
Date de dernière modification : {DATE}
Auteur : Esteban Dujardin
Remarques : *Code Conforme aux spécification internes données en cours
*/
	#include "BNavale.h"
	#include <iostream>
	using namespace std;

	const unsigned int NB_CASES = 10;

	// TYPES DES SOUS-PROGRAMMES
	//-----------------------------------

	//DÉCLARATION DES SOUS-PROGRAMMES
    //-----------------------------------

	//PROGRAMME PRINCIPAL
	int main(void) {
			
	// TYPES DU PROGRAMME PRINCIPAL
	//-------------------------------------------

    // VARIABLES POUR LE PROGRAMME PRINCIPAL
	//-------------------------------------------
	// unsigned int tour;

	char tabPlateau[NB_CASES][NB_CASES] = {{'*','A','B','C','D','E','F','G','H','I'},
										  {'1','*','*','*','*','*','*','*','*','*'},
										  {'2','*','*','*','*','*','*','*','*','*'},
										  {'3','*','*','*','*','*','*','*','*','*'},
										  {'4','*','*','*','*','*','*','*','*','*'},
										  {'5','*','*','*','*','*','*','*','*','*'},
										  {'6','*','*','*','*','*','*','*','*','*'},
										  {'7','*','*','*','*','*','*','*','*','*'},
										  {'8','*','*','*','*','*','*','*','*','*'},
										  {'9','*','*','*','*','*','*','*','*','*'},};
	// TRAITEMENTS
	//-------------------------------------------
	// genererBateau();
	// coordLettre();
	// tour = 1;
	afficher(tabPlateau,10);
	
	return 0;
	} 
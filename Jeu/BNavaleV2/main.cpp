/*
Programme : NOM PROGRAMME
But : BUT PROGRAMME
Date de création : DATE
Date de dernière modification : DATE
Auteur : -Esteban Dujardin
         -Garcia Angel
Remarques : *Code Conforme aux spécification internes données en cours
*/

#include "BNavale.h"
#include <iostream>
using namespace std;

const unsigned int NB_CASES = 10;

// TYPES DES SOUS-PROGRAMMES
//-----------------------------------

// VARIABLES POUR LE PROGRAMME PRINCIPAL
	//-------------------------------------------
	unsigned int touche;
	bool gagner;
	string toucher;
	string manquer;
	unsigned int compteTir;
	string choix;

	// unsigned int tour;

    char tabPlateau[NB_CASES][NB_CASES] = {{' ','A','B','C','D','E','F','G','H','I'},
											{'1',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'2',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'3',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'4',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'5',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'6',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'7',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'8',' ',' ',' ',' ',' ',' ',' ',' ',' '},
											{'9',' ',' ',' ',' ',' ',' ',' ',' ',' '},};

//PROGRAMME PRINCIPAL
int main(void) {

   // TYPES DU PROGRAMME PRINCIPAL
   //-------------------------------------------

   // VARIABLES POUR LE PROGRAMME PRINCIPAL
   //-------------------------------------------
   coords coordBateau[4];
   unsigned int tour;

   // TRAITEMENTS
   //-------------------------------------------
   // Générer le bateau
   genererBateau(coordBateau);

   //Initialiser le compteur de tour
   tour = 1;

   //Afficher les règles et le plateau de jeu
   affichage(coordBateau, tabPlateau, NB_CASES);

   //Initialiser du nombre de touche, du booléen de victoire,
   //et des indicateurs toucher et manquer.
   touche = 0;
   gagner = false;
   toucher = 'O';
   manquer = '.';

   // Saisie-Vérif
   do
	{
		compteTir++;
		cout << "Votre " << compteTir << "eme tir (ex. A3) ou abandonner (@@) ?" << endl;
		cin >> choix;
	} while (choix != "@@" && verifCoup(choix));


   return 0;
}

// DÉFINITION DES SOUS-PROGRAMMES
//---------------------------------

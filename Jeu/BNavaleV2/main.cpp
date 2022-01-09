/*
Programme : NOM PROGRAMME
But : BUT PROGRAMME
Date de création : DATE
Date de dernière modification : DATE
Auteurs : -Esteban Dujardin
         -Garcia Angel
Remarques : *Code Conforme aux spécification internes données en cours
*/

#include "BNavale.h"
#include <iostream>
using namespace std;

//PROGRAMME PRINCIPAL
int main(void) {

   // TYPES DU PROGRAMME PRINCIPAL
   //-------------------------------------------

   // VARIABLES POUR LE PROGRAMME PRINCIPAL
   //-------------------------------------------
   const unsigned int NB_CASES = 10; //Nombre de case de tabPlateau
   unsigned int tour; //Nombre de tour
   unsigned int nbTouche; //Nombre de fois que le joueur à touché le bateau
   char toucher; //Caractère qui apparaitra sur tabPlateau quand le bateau est touché
	char manquer; //Caractère qui apparaitra sur tabPlateau quand le bateau est loupé
   string choix; //Ce que le joueur saisie
	bool gagner; // Contient si le joueur a gagné ou pas
	

   char tabPlateau[NB_CASES][NB_CASES] = {
      {' ','A','B','C','D','E','F','G','H','I'},
		{'1',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'2',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'3',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'4',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'5',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'6',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'7',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'8',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'9',' ',' ',' ',' ',' ',' ',' ',' ',' '},
      }; //Plateau de jeu

   coords coordBateau[4];//Tableau de coordonnée du bateau

   // TRAITEMENTS
   //-------------------------------------------
   //tabPlateau, nbCases, coordBateau >> Initialiser la partie >> tabPLateau, nbCases, tour, coordBateau 
   //coordBateau >> Génération du bateau >> coordBateau
   genererBateau(coordBateau);

   //coordBateau, tabPlateau, nbcases >> Afficher les règles et le plateau de jeu
   affichage(coordBateau, tabPlateau, NB_CASES);

   //Initialiser les variables >> tour, nbTouche, gagner, toucher, manquer
   tour = 1;

   nbTouche = 0;

   gagner = false;

   toucher = 'O';
   manquer = '.';
   
   //tabPlateau, nbcases, tour, coordBateau, nbTouche, gagner, manquer, toucher >> Jouer la partie >> tour, tabPlateau, gagner
   while(true) {
      //tour >> SaisieVerif >> choix
      do {
         cout << endl << "Votre " << tour << "eme tir (ex. A3) ou abandonner (@@) ?" << endl;
         cin >> choix;
      } while (verifCoup(choix) != true);

      //choix >> Condition de sortie numéro 1 (le joueur abandonne)
      if (choix == "@@"){
         break;
      }

      //choix, toucher, manquer, nbTouche, tabPlateau >> Gérer si touché >> nbTouche
      if (estTouche(choix, coordBateau)) {
         if (tabPlateau[toInt(choix[1])][coordChiffre(choix[0])] != toucher) {
            nbTouche ++;
            afficherCoup(toucher,tabPlateau,choix);
         }
      }
      else {
         afficherCoup(manquer,tabPlateau,choix);
      }

      //nbTouche, gagner >> Condition de sortie numéro 2 (le joueur gagne)
      if(nbTouche == 4) {
         gagner = true;
         break;
      }

      //tour >> Incrémenter le compteur de tour >> tour
      tour ++;

      affichage(coordBateau, tabPlateau, NB_CASES);
   }

   //tabPlateau, tour, gagner, nbcases, coordBateau, nbTouche >> Finaliser la partie
   if(gagner) {
      //tabPlateau, tour, nbcases, coordBateau >> Affichage de victoire >> ecran
      affichage(coordBateau, tabPlateau, NB_CASES);
      //Afficher message de victoire
      cout << endl << "BATEAU COULE en " << tour << " tirs";
   }
   else{
      //tour, nbTouche >> Afficher message d'abandon >> ecran
      cout << "ABANDON bateau touche " << nbTouche << " fois sur " << tour;
   }
   return 0;
}

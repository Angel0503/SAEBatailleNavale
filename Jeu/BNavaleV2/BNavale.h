/**  MODULE BNavale
     permettant la manipulation de nombres RATIONNELS
     Implémentation proche d'un Type Abstrait de Données (TAD) 
     ----------------------------------------------------------------------
But :
    En tant que TAD, il met à disposition :
    - Un type [***], composé :
        [***]

    - Une constante [***]
    - Des primitives (= sous-programmes) permettant de :
        ...faire des calculs entre fractions : [***]
        ...comparer des fractions : [***]
        ...afficher à l'écran [***] ou saisir [***] au clavier

    Afin de se rapprocher de l'usage mathématique, toutes les primitives de calcul mathématique :
    - attendent en paramètre donnée des fractions irréductibles
    - produisent des fractions irréductibles.
    L'utilisation du type Fraction impose par ailleurs que le numérateur soit porteur du signe de la fraction et que le dénominateur est > 0.
---------

 Date de dernière modification : [jj/mm/aa]
 Auteurs : -Esteban Dujardin
          -Garcia Angel
 Remarques : Code conforme aux spécification précisées dans le sujet.
*/

#ifndef BNAVALE_H
#define BNAVALE_H

using namespace std;
#include <string>
// Types

struct coords
{
    unsigned int coordX; // Coordonnée en x de la variable.
    unsigned int coordY; // Coordonnée en y de la variable.
};

// Sous-programmes

void genererBateau(coords tableau[]);
// But : Génère les 4 pièces du bateau

void affichage(coords coordBateau[], char tabPlateau[][10], unsigned int nbCases);
// But : Efface l'écran, affiche les règles, affiche les coordonnées du bateau puis affiche la plateau de jeu

bool estTouche(string choix, coords coordBateau[]);
// But : Retourne vrai si les coordonnées de la variable choix touche le bateau, sinon retourne faux

void afficherCoup(char symboleCoup, char tab[][10], string coordonnees);
// But : Met le bon symbole à des coordonnées données sur un tableau donnée

char coordLettre(int coord);
// But : Permet de transformer un entier compris entre 1 et 9 en lettre compris entre 'A' et 'I'

unsigned int coordChiffre(char choix);
// But : Permet de transformer une lettre comprise entre 'a' et 'i' (majuscule aussi) en un entier compris entre 1 et 9

unsigned int toInt(char caractere);
// But : transformer un carcatère contenant un chiffre en entier non signé

bool verifCoup(string xy);
// But : Vérifie que le coup xy est correct et retourne vrai sinon affiche en quelle(s) coordonnée(s) se trouve(nt) l’erreur/les erreurs

#endif // BNAVALE_H

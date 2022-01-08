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
 Auteur : -Esteban Dujardin
          -Garcia Angel
 Remarques : Code conforme aux spécification précisées dans le sujet.
*/

#ifndef BNAVALE_H
#define BNAVALE_H

#include <iostream>
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
// But : Générer le bateau à trouver en fonction de ses coordonnées.

char coordLettre(int coord);
// But : Modifie le premier chiffre des coordonnées en le changeant en lettre.

int coordChiffre(char choix);
// But : Modifie la première lettre des coordonnées en la changeant en chiffre.

void affichage(coords coordBateau[], char tabPlateau[][10], unsigned int nbCases);
// But : Affiche les règles du jeu ainsi que le plateau de jeu

void afficherCoup(char symboleCoup, char tab[][10], coords coordonnees);
// But : Affiche le symbole du tir symbole coup (manqué ou touché) dans le tableau
// tab à double dimension à partir des coordonnées.

bool estTouche(string choix, coords coordChiffreBateau[]);
// But : Retourne vrai si le bateau est touché et retourne faux si les coordonnées ne sont pas les bonnes.

bool verifCoup(string xy);
// But : Vérifie si les coordonnées sont bien entrées

#endif // BNAVALE_H

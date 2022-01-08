/**  CORPS MODULE [NomModule]  
     ------------------------ */

// Inclusions

#include "BNavale.h"
#include <iostream>
using namespace std;
#include "game-tools.h"

// Types - variables - Constantes propres au corps

// Définition des sous-programmes utilisés dans le corps

void afficherPlateau(char tabPlateau[][10], unsigned int nbCases);
// But : Affiche le plateau du jeu

// Corps des sous-programmes déclarés dans BNavale.h
void genererBateau(coords coordBateau[])
{

    // VARIABLES
    unsigned int posX;
    unsigned int posY;

    unsigned int coefX;
    unsigned int coefY;

    unsigned int direction;

    coords coordPiece;
    // Générer la première pièce du bateau
    // Generation  posX et posY >> posX, posY 

    posX = random(1,9);
    posY = random(1,9);

    //posX, posY >> Initialisation coordPiece >> coordPiece
    coordPiece.coordX = posX;
    coordPiece.coordY = posY;

    // Générer la direction du bateau >> direction

    direction = random(1,8);

    // Générer les autres pièces du bateaux en fonction de la direction et des coordonnées de la pièce (coordPiece)

    // Initialiser les différents coefficients et les bornes >> coefX, coefY, borneX, borneY

    coefX = 0;
    coefY = 0;

    // Modification des coefficients en fonction de la direction

    switch (direction)
    {
    case 1:
        coefX = -1;
        break;
    case 2:
        coefY = 1;
        break;

    case 3:
        coefX = -1;
        coefY = 1;
        break;

    case 4:
        coefX = -1;
        coefY = 1;
        break;

    case 5:
        coefX = 1;
        break;

    case 6:
        coefY = -1;
        break;

    case 7:
        coefX = 1;
        coefY = 1;
        break;

    case 8:
        coefX = 1;
        coefY = -1;
        break;
    
    default:
        break;
    }

    // Placer le reste du bateau

    for (unsigned int i = 0; i <= 3; i++)
    {
        // Placer les coordonnées de la pièce (coordPiece) dans le tableau coordBateau
        coordBateau[i].coordX = coordPiece.coordX;
        coordBateau[i].coordY = coordPiece.coordY;

        // coordPiece, coefX, coefY >> Modifier coordPiece pour obtenir d'autre coordonnées >> coordPiece, coefX, coefY
        coordPiece.coordX += coefX;
        coordPiece.coordY += coefY;

        // coefX, coefY >> Modifier les coefficients s'ils sont arrivé à leurs bornes >> coefX, coefY
        
        // coefX, borneX >> Vérification coefX >> coefX, borneX
        if (coordPiece.coordX == 0 || coordPiece.coordX == 9)
        {
            coefX *= -1;
            coordPiece.coordX = coordBateau[0].coordX;
        }

        // coefY >> Vérification coefY >> coefY
        if (coordPiece.coordY == 0 || coordPiece.coordY == 9)
        {
            coefY *= -1;
            coordPiece.coordY = coordBateau[0].coordY;
        }
    }  
}

void affichage(coords coordBateau[], char tabPlateau[][10], unsigned int nbCases)
{
    effacer();

    //Afficher règles
    cout << "B A T A I L L E  N A V A L E" << endl;
    cout << "Le joueur doit couler un bateau de 4 cases" << endl;
    cout << "(il est soit positionne en vertical, horizontal ou diagonal)." << endl;

    //Afficher les coordonnées du bateau
    cout << "Bateau : ";
    for (int i = 0; i <= 3; i++)
    {
        cout << "(";
        cout << coordBateau[i].coordX;
        cout << ",";
        cout << coordBateau[i].coordY;
        cout << ")";
    }
    cout << endl;

    //Afficher le plateau de jeu
    afficherPlateau(tabPlateau, nbCases);
}

char coordLettre(int coord) {
    switch (coord)
    {
    case 1:
        return 'A';
        break;
    case 2:
        return 'B';
        break;
    case 3:
        return 'C';
        break;
    case 4:
        return 'D';
        break;
    case 5:
        return 'E';
        break;
    case 6:
        return 'F';
        break;
    case 7:
        return 'G';
        break;
    case 8:
        return 'H';
        break;
    case 9:
        return 'I';
        break;
    default:
        return 'Z';
        break;
    }
}

int coordChiffre(char choix) {
    switch (toupper(choix))
    {
    case 'A':
        return 1;
        break;
    case 'B':
        return 2;
        break;
    case 'C':
        return 3;
        break;
    case 'D':
        return 4;
        break;
    case 'E':
        return 5;
        break;
    case 'F':
        return 6;
        break;
    case 'G':
        return 7;
        break;
    case 'H':
        return 8;
        break;
    case 'I':
        return 9;
        break;
    default:
        return 0;
        break;
    }
}

void afficherCoup(char symboleCoup, char tab[][10], coords coordonnees)
{
    tab[coordonnees.coordX][coordonnees.coordY] = symboleCoup;
}

bool estTouche(string choix, coords coordChiffreBateau[])
{   
    unsigned int part1Choix;
    unsigned int part2Choix;

    int cpt{};

    bool verifX{false};
    bool verifY{false};

    //Transformer choix
    part1Choix = coordChiffre(choix[0]);
    part2Choix = static_cast<unsigned int>(choix[1]);

    //Savoir si le bateau est touché
    while(true){
        if (cpt == 4){
            break;
        }

        if (part1Choix == coordChiffreBateau[cpt].coordX){
            verifX = true;
            if (part2Choix == coordChiffreBateau[cpt].coordY){
                verifY = true;
            }
        }

        if(verifX && verifY) {
            break;
        }

        cpt ++;
    }
    //Retourner si le bateau est touché
    if (verifX && verifY){
        return true;
    }
    else{
        return false;
    }
}

bool verifCoup(string xy)
{
    bool verif;

    switch (toupper(xy[0]))
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
        verif = true;
        break;
    default:
        verif = false;
        cout << "Erreur en 'X' !";
        break;
    }

    switch (toupper(xy[1]))
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        verif = true;
        break;
    default:
        verif = false;
        cout << "Erreur en 'Y' !";
        break;
    }
    return verif;
}

// Corps des sous-programmes déclarés dans ce corps

void afficherPlateau(char tabPlateau[][10], unsigned int nbCases)
{
    for (unsigned int i = 0; i < nbCases; i++)
            {
                cout << endl << "| ";
                for (unsigned int j = 0; j < nbCases; j++)
                {   
                cout << tabPlateau[i][j] << " | ";
                }
                cout << endl;
                cout << "-----------------------------------------";
            }
}


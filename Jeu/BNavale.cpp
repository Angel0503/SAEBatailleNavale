/**  CORPS MODULE Bataille Navale  
     ------------------------ */

#include "BNavale.h"
#include "game-tools.h"
#include <iostream>
using namespace std;

unsigned int genererBateau(coords coordPiece, unsigned int direction)
{

    // VARIABLES
    unsigned int posX;
    unsigned int posY;

    unsigned int coefX;
    unsigned int coefY;

    const unsigned int LG_TAB = 4;
    coords coordChiffreBateau[LG_TAB];

    // Générer la première pièce du bateau
    // posX, posY >> coordPiece

    posX = random(1,9);
    posY = random(1,9);

    coordPiece.coordX = posX;
    coordPiece.coordY = posY;

    // Générer la direction du bateau >> direction

    direction = random(1,8);

    // Générer les autres pièces du bateaux en fonction de la direction et des coordonnées de la pièce (coordPiece)

    // Initialiser les différents coefficients et les bornes >> coefX, coefY, borneX, borneY

    coefX = 0;
    coefY = 0;

    // Modification des coefficients et des bornes en fonction de la direction

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
        // Placer les coordonnées de la pièce (coordPiece) dans le tableau coordChiffreBateau
        coordChiffreBateau[i] = coordPiece;

        // coordPiece, coefX, coefY >> Modifier coordPiece pour obtenir d'autre coordonnées >> coordPiece, coefX, coefY
        coordPiece.coordX += coefX;
        coordPiece.coordY += coefY;

        // coefX, coefY >> Modifier les coefficients s'ils sont arrivé à leurs bornes >> coefX, coefY
        
        // coefX, borneX >> Vérification coefX >> coefX, borneX
        if (coordPiece.coordX == 0 || coordPiece.coordX == 9)
        {
            coefX *= -1;
            coordPiece.coordX = coordChiffreBateau[0].coordX;
        }

        // coefY >> Vérification coefY >> coefY
        if (coordPiece.coordY == 0 || coordPiece.coordY == 9)
        {
            coefY *= -1;
            coordPiece.coordY = coordChiffreBateau[0].coordY;
        }

    }  
    return 0;
}

char coordLettre(int coord) {
    switch (coord)
    {
    case 1:
        return 'A';
    case 2:
        return 'B';
    case 3:
        return 'C';
    case 4:
        return 'D';
    case 5:
        return 'E';
    case 6:
        return 'F';
    case 7:
        return 'G';
    case 8:
        return 'H';
    case 9:
        return 'I';
    default:
        break;
    }
    return 0;
}

void afficher(char tab[][10], unsigned int nbCases)
{
    cout << "B A T A I L L E  N A V A L E" << endl;
    cout << "Le joueur doit couler un bateau de 4 cases" << endl;
    cout << "(il est soit positionne en vertical, horizontal ou diagonal)." << endl;

    cout << "Bateau : ";
    for (int i = 0; i <= 4; i++)
    {
        cout << "(" << "A" << "," << "3" << ")  ";
    }
    
    cout << endl;

    for (unsigned int i = 0; i < nbCases; i++)
		{
            cout << endl << "| ";
			for (unsigned int j = 0; j < nbCases; j++)
            {
                if (tab[i][j] == true)
                {
                    cout << " " << " | ";
                }
                else 
                {
                    cout << tab[i][j] << " | ";
                }
            }
            cout << endl;
            cout << "-----------------------------------------";
		}
}
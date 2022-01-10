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
    unsigned int posX; //Un entier générer aléatoirement compris en 1 et 9
    unsigned int posY; //Un entier générer aléatoirement compris en 1 et 9

    unsigned int coefX; //Coefficient de déplacement X
    unsigned int coefY; //Coefficient de déplacement Y

    unsigned int direction; //Direction du bateau

    // Génération aléatoire première pièce bateau et sa direction >> coordPiece, direction
    // Première piece bateau >> coordPiece

    // Génération position x et y
    posX = random(1,9);
    posY = random(1,9);

    // Direction du placement du bateau >> direction
    direction = random(1,8);

    //direction, posX, posY >> Gestion des coins >> direction
    if(direction == 4 || direction == 8) {
        if(posX < 4 && posY < 4) {
            direction --;
        }
        else if(posX > 6 && posY > 6) {
            direction --;
        }
    }
    else if(direction == 3 || direction == 7){
        if(posX < 4 && posY > 6){
            direction ++;
        }
        else if(posX > 6 && posY < 4){
            direction ++;
        }
    }

    // direction, coordBateau, posX, posY >> Générer le reste du bateau >> coordBateau
    // direction >> Initialiser les coefficients de déplacements et les modifier si nécessaire >> coefX, coefY

    //Initialiser coefficients de déplacement >> coefX, coefY
    coefX = 0;
    coefY = 0;

    // coefX, coefY >> Modification des coefficients >> coefX, coefY
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
        coefY = -1;
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

    // coordBateau, posX, posY >> Mettre la premiere piece >> coordBateau
    coordBateau[0].coordX = posX;
    coordBateau[0].coordY = posY;

    //direction, coordBateau, posX, posY > Générer le reste du bateau > coordBateau
    for (unsigned int i = 1; i <= 3; i++)
    {
        // coefX, coefY, posX, posY, coordBateau >> Modifier les coefficients s'ils sont à la limite du plateau >> coefX, coefY, posX, posY
        // coefX, coefY, posX, posY, coordBateau, direction >> angle haut gauche >> coefX, coefY, posX, posY
        if(posX == 1 && posY == 1){
            switch (direction)
            {
            case 1:
                coefX *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 3:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 6:
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }
        //& angle haut droit
        else if(posX == 1 && posY == 9){
            switch (direction)
            {
            case 1:
                coefX *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 2:
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 4:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }
        //& angle bas gauche
        else if(posX == 9 && posY == 1){
            switch (direction)
            {
            case 5:
                coefX *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 6:
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 8:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }
        //& angle bas droit
        else if(posX == 9 && posY == 9){
            switch (direction)
            {
            case 2:
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 5:
                coefX *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 7:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }
        //& coté gauche
        else if(posY == 1){
            switch(direction){
                case 3:
                    coefX *= -1;
                    coefY *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
                case 6:
                    coefY *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
                case 8:
                    coefX *= -1;
                    coefY *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
            }
        }
        //& coté droit
        else if(posY == 9){
            switch (direction)
            {
            case 2:
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 4:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 7:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }
        //&coté haut
        else if(posX == 1){
            switch(direction){
                case 1:
                    coefX *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
                case 3:
                    coefX *= -1;
                    coefY *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
                case 4:
                    coefX *= -1;
                    coefY *= -1;
                    posX = coordBateau[0].coordX;
                    posY = coordBateau[0].coordY;
                    break;
            }
        }
        //& coté bas
        else if(posX == 9){
            switch (direction)      
            {
            case 5:
                coefX *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 7:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            case 8:
                coefX *= -1;
                coefY *= -1;
                posX = coordBateau[0].coordX;
                posY = coordBateau[0].coordY;
                break;
            }
        }

        //posX, posY, coefX, coefY >> Modifier coordPiece >> coefX, coefY
        posX += coefX;
        posY += coefY;

        // coordBateau, posX, posY >> Placer les coordonnées du bateau dans coordBateau >> coordBateau
        coordBateau[i].coordX = posX;
        coordBateau[i].coordY = posY;        
    }  
}

void affichage(coords coordBateau[], char tabPlateau[][10], unsigned int nbCases)
{
    effacer();

    //Afficher règles
    cout << "B A T A I L L E  N A V A L E" << endl;
    cout << "Le joueur doit couler un bateau de 4 cases" << endl;
    cout << "(il est soit positionne en vertical, horizontal ou diagonal)." << endl;

    //coordBateau >> Afficher les coordonnées du bateau
    cout << "Bateau : ";
    for (int i = 0; i <= 3; i++)
    {
        cout << "(";
        cout << coordLettre(coordBateau[i].coordX);
        cout << ",";
        cout << coordBateau[i].coordY;
        cout << ")   ";
    }
    cout << endl;

    //tabPlateau, nbCases >> Afficher le plateau de jeu
    afficherPlateau(tabPlateau, nbCases);
}

bool estTouche(string choix, coords coordChiffreBateau[])
{   
    int cpt; //Un compteur

    bool verifX; //Contient si la vérification de la coordonnée X est vérifiée ou non
    bool verifY; //Contient si la vérification de la coordonnée Y est vérifiée ou non

    unsigned int part1Choix; //Premier caractère de la variable choix transformé en entier
    unsigned int part2Choix; //Deuxième caractère de la variable choix transformé en entier

    //Initialiser les variables >> cpt, verifX, verifY
    cpt = 0;

    verifX = false;
    verifY = false;

    //choix >> Transformer variable choix >> part1Choix, part2Choix
    part1Choix = coordChiffre(choix[0]);
    part2Choix = toInt(choix[1]);

    //part1Choix, part2Choix, cpt >> Savoir si le bateau est touché >> verifX, verifY
    while(true){
        if (cpt == 4){
            break;
        }

        if (part1Choix == coordChiffreBateau[cpt].coordX){
            verifX = true;
            if (part2Choix == coordChiffreBateau[cpt].coordY){
                verifY = true;
                break;
            }
            else {
                verifX = false;
            }
        }

        //Incrémenter cpt
        cpt ++;
    }
    //verifX, verifY >> Retourner si touché ou non
    if (verifX && verifY){
        return true;
    }
    else{
        return false;
    }
}

void afficherCoup(char symboleCoup, char tab[][10], string coordonnees)
{   
    tab[toInt(coordonnees[1])][coordChiffre(coordonnees[0])] = symboleCoup;
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

unsigned int coordChiffre(char choix) {
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

unsigned int toInt(char caractere) {
    switch(caractere){
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return 0;
            break;
    }
}

bool verifCoup(string xy)
{
    bool verifX;
    bool verifY;
    //xy >> Cas d'abandon >> verif
    if(xy == "@@") {
        return true;
    }

    //xy >> Vérification de x >> verif
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
        verifX = true;
        break;
    default:
        verifX = false;
        cout << "Erreur en 'X' !" << endl;
        break;
    }

    //xy >> Vérification de y >> verif
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
        verifY = true;
        break;
    default:
        verifY = false;
        cout << "Erreur en 'Y' !" << endl;
        break;
    }

    //verif >> retourne verif 
    if(verifX && verifY){
        return true;
    }
    else{
        return false;
    }
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


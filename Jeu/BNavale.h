/**  MODULE Bataille Navale
     permettant la manipulation de nombres RATIONNELS
     Implémentation proche d'un Type Abstrait de Données (TAD) 
     ----------------------------------------------------------------------
But :
    En tant que TAD, il met à disposition :
    - Un type Fraction, composé :
        ...d'un numérateur, entier portant le signe de la fraction
        ...d'un dénominaeur > 0

    - Une constante FRACTIONNULLE = 0/1
    - Des primitives (= sous-programmes) permettant de :
        ...faire des calculs entre fractions : addition, soustraction, multiplication, division
        ...comparer des fractions : égal, supérieur, inférieur
        ...afficher à l'écran une fraction ou saisir une fraction au clavier

    Afin de se rapprocher de l'usage mathématique, toutes les primitives de calcul mathématique :
    - attendent en paramètre donnée des fractions irréductibles
    - produisent des fractions irréductibles.
    L'utilisation du type Fraction impose par ailleurs que le numérateur soit porteur du signe de la fraction et que le dénominateur est > 0.
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

struct coords
{
    unsigned int coordX;
    unsigned int coordY;
};

coords genererBateau();
// But : Générer le bateau à trouver en fonction de ses coordonnées.

char coordLettre(int coord);
// But : Modifie le premier chiffre des coordonnées en le changeant en lettre.

void afficher(char tab[][10], unsigned int nbCases);
// But : Affiche un tableau de caractères de nbCases cases.
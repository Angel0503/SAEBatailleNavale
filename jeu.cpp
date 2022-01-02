#include <iostream>
#include <string>
using namespace std;

int main(void) {

    int touche;
    bool gagner;
    char toucher;
    char manquer;
    string choix;
    while(true) {

        touche = 0;
        gagner = false;
        toucher = 'O';
        manquer = '.';


        //A changer le while est pas bon
        do {
            cout << endl << endl << "Choisissez votre coup : ";
            cin >> choix;
        }while(choix < 1 and choix > 9);

    }




    return 0;
}
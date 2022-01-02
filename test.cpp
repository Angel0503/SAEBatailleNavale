#include <iostream>

using namespace std;

char coordLettre(int coord);

int main(void) {
    /*
    char test;
    test = coordLettre(3);
    cout << test;
    */

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
}
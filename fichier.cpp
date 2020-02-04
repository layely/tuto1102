#include<iostream>
#include<fstream>

using namespace std;

void first_test() {
    ifstream entree("commandes.txt", ios::in);
    char commande = 'W';
    char operande1, operande2;
    entree >> commande;
    while (!entree.eof()) {
        entree >> operande1 >> operande2;
        cout << commande << " " << operande1 << " " << operande2 << endl;
        entree >> commande;
    }
    entree.close();
}

int main() {
    first_test();
    return 0;
}
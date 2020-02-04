#include "pch.h"
#include <iostream>
using namespace std;

struct un16bits
{
	unsigned short a00 : 1; // Le premier champ d'un struct est à l'adresse la plus basse.
	unsigned short a01 : 1;
	unsigned short a02 : 1;
	unsigned short a03 : 1;
	unsigned short a04 : 1;
	unsigned short a05 : 1;
	unsigned short a06 : 1;
	unsigned short a07 : 1;
	unsigned short a08 : 1;
	unsigned short a09 : 1;
	unsigned short a10 : 1;
	unsigned short a11 : 1;
	unsigned short a12 : 1;
	unsigned short a13 : 1;
	unsigned short a14 : 1;
	unsigned short a15 : 1; // Le dernier champ d'un struct est à l'adresse la plus haute.
};

union unUnion
{
	un16bits	B;
	unsigned short US;
	short S;
};

void afficher(un16bits V)
{
	cout << V.a15 << V.a14 << V.a13 << V.a12
		<< V.a11 << V.a10 << V.a09 << V.a08
		<< V.a07 << V.a06 << V.a05 << V.a04
		<< V.a03 << V.a02 << V.a01 << V.a00;
}

int main()
{
	unUnion U;

	U.S = 64 + 32 + 1; // 97
	cout << "U.US = " << U.US << endl;
	cout << "U.S  = " << U.S << endl;
	cout << "U.B  = "; afficher(U.B); cout << endl << endl;

	U.S = -32768;
	cout << "U.US = " << U.US << endl;
	cout << "U.S  = " << U.S << endl;
	cout << "U.B  = "; afficher(U.B); cout << endl << endl;

	U.S = -2765;
	cout << "U.US = " << U.US << endl;
	cout << "U.S  = " << U.S << endl;
	cout << "U.B  = "; afficher(U.B); cout << endl << endl;

	U.S = 0; // Mettre tous les bits à 0.
	U.B.a15 = 1;
	U.B.a10 = 1;
	U.B.a02 = 1;
	cout << "U.US = " << U.US << endl;
	cout << "U.S  = " << U.S << endl;
	cout << "U.B  = "; afficher(U.B); cout << endl << endl;


	cout << " Operation de decalage signe vers la droite." << endl;
	U.S = -80;
	cout << "U.S       = "; afficher(U.B); cout << endl;
	U.S = U.S >> 4;
	cout << "U.S >> 4  = "; afficher(U.B); cout << endl << endl;

	cout << " Operation de decalage signe vers la gauche." << endl;
	U.S = -80;
	cout << "U.S       = "; afficher(U.B); cout << endl;
	U.S = U.S << 5;
	cout << "U.S << 5  = "; afficher(U.B); cout << endl << endl;

	cout << " Operation de decalage non signe vers la droite." << endl;
	U.US = 62000;
	cout << "U.US      = "; afficher(U.B); cout << endl;
	U.US = U.US >> 4;
	cout << "U.US >> 4 = "; afficher(U.B); cout << endl << endl;

	cout << " Operation de decalage non signe vers la gauche." << endl;
	U.US = 62000;
	cout << "U.US      = "; afficher(U.B); cout << endl;
	U.US = U.US << 5;
	cout << "U.US << 5 = "; afficher(U.B); cout << endl << endl;

	// À répétition
	cout << " Operations de decalage non signe vers la gauche - une suite pour observer le comportement." << endl;
	unsigned short A = 62019;
	U.US = A;
	cout << endl << "A      = "; afficher(U.B); cout << endl << endl;
	for (long K = 1; K < 9; K++)
	{
		U.US = A << K;
		cout << "A << " << K << " = "; afficher(U.B); cout << endl << endl;
	}


	// À répétition
	cout << " Operations de decalage non signe vers la droite - une suite pour observer le comportement." << endl;
	A = 62019;
	U.US = A;
	cout << endl << "A      = "; afficher(U.B); cout << endl << endl;
	for (long K = 1; K < 9; K++)
	{
		U.US = A >> K;
		cout << "A >> " << K << " = "; afficher(U.B); cout << endl << endl;
	}


	// À répétition
	cout << " Operations de decalage signe vers la gauche - une suite pour observer le comportement." << endl;
	short B = 62019;
	U.S = B;
	cout << endl << "B      = "; afficher(U.B); cout << endl << endl;
	for (long K = 1; K < 9; K++)
	{
		U.US = B << K;
		cout << "B << " << K << " = "; afficher(U.B); cout << endl << endl;
	}


	// À répétition
	cout << " Operations de decalage non signe vers la droite - une suite pour observer le comportement." << endl;
	B = 62019;
	U.S = B;
	cout << endl << "B      = "; afficher(U.B); cout << endl << endl;
	for (long K = 1; K < 9; K++)
	{
		U.US = B >> K;
		cout << "B >> " << K << " = "; afficher(U.B); cout << endl << endl;
	}


	/*
		Créer des exemples pour démontrer le fonctionnement des opérateurs bit-à-bit.
	*/

	// Le ET bit-à-bit : &          (Appuyez sur le shift et, en même temps, la touche "7" sur le 
	//                               clavier principal).


	// Le OU bit-à-bit : |          (Appuyez sur le shift et, en même temps, la touche  
	//                               immédiatement à gauche du "1" sur le clavier principal).


	// La négation bit-à-bit : ~     (Utiliser la touche AltCar (à droite de la barre d'espacement) 
	//                                et, en même temps, la touche du ";").


	// Le OU EXCLUSIF bit-à-bit : ^  (Appuyez sur la touche "^" puis appuyez sur la barre d'espacement).



}
/*
Pour vos exemples, vous aurez besoin de deux ou trois variables de 16 bit, selon le cas, disons 
de type unsigned short.
Pour bien voir l'effet de ces opération, il serait préférable d'afficher vos variables en binaire.
Ce sera plus facile pour vous de voir les ralations qui sont, en effet, au niveau des bits.

Vous aurez des expressions de la forme :
		R = P & Q ;
		R = P | Q ;
		R = ~ P ;
		R = P ^ Q ;

Quand on dit "de la forme", on veut juste dire 
	<variable> = <variable> <opérateur> <variable> ;

où <variable> est soit le nom d'une variable, un champ d'un union, un champ d'un struct,
un élément d'un tableau, etc.

*/
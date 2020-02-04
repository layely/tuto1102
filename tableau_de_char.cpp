#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	cout << endl << endl << "Zone de T " << endl;
	char T[10] = { 'B', 'o', 'n', 'j', 'o', 'u', 'r' };

	cout << T;

	cout << endl << endl;

	cout << endl << endl << "Zone de D " << endl;

	char D[3][3] = { { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' } };

	cout << D;

	cout << endl << endl;

	cout << D[0] << endl;
	cout << D[1] << endl;
	cout << D[2] << endl;

	cout << endl << endl << "Zone de E " << endl;

	char E[3][4] = { { 'a', 'b', 'c', '\0' }, { 'd', 'e', 'f', '\0' }, { 'g', 'h', 'i', '\0' } };

	cout << E;

	cout << endl << endl;

	cout << E[0] << endl;
	cout << E[1] << endl;
	cout << E[2] << endl;

	cout << endl << endl << "Zone de G " << endl;

	short G[5] = { 1, 2, 3, 4, 5 };

	cout << G;

	cout << endl << endl;

	for (long K = 0; K < 5; K++)
		cout << G[K];

	cout << endl << endl << "Les adresses" << endl;

	cout << "&T = " << &T << "   =   " << unsigned long(&T) << endl;
	cout << "&D = " << &D << "   =   " << unsigned long(&D) << endl;
	cout << "&E = " << &E << "   =   " << unsigned long(&E) << endl;
	cout << "&G = " << &G << "   =   " << unsigned long(&G) << endl << endl ;


	cout << "&D[0] = " << &D[0] << "   =   " << unsigned long(&D[0]) << endl;
	cout << "&D[1] = " << &D[1] << "   =   " << unsigned long(&D[1]) << endl;
	cout << "&D[2] = " << &D[2] << "   =   " << unsigned long(&D[2]) << endl;

	//	system("pause");


}

/*
	'\0' est le caractère #0, le caractère NUL.
	Pour les chaines de caractères, le caractère NUL sert de terminateur, c'est-à-dire un genre
	de sentinelle pour indiquer la fin de la chaine. Certaines fonctions d'affichage de tableaux 
	de caractères acceptent	l'adresse du premier caractère comme point de départ et affichent les
	caractères les uns après les autres jusqu'à temps qu'elles rencontrent le caractère NUL.

	La présence du caractère NUL dans E et son absence dans D expliquent la différence de 
	comportement entre ces deux tableaux.

	Avant l'avènement du type string, le traitement de chaines de caractères était fait
	à l'aide de tableaux de char. Parce que leur usage était particulier, les tableaux de
	char (char[]) sont traités différemment des autres genres de tableaux. Même les tableaux 
	de type char[][] sont traités différemment des tableaux char[].

	E est de type char[][]. cout << E a affiché une adresse !
	G est de type short[].  cout << G a affiché une adresse !

	Par contre, T est de type char[]. cout << T a affiché le contenu du tableau.
	E[0] est de type char[]. cout << E[0] a affiché le contenu de la rangée E[0].
	Dans les deux cas, on n'a pas eu à écrire de boucle pour faire l'affichage des 
	caractères individuels (par exemple, pour G, on a dû écrire une boucle.)

	Faisons rouler nos "rrrrrrrr".
	===============================

	Remplacez la déclaration du tableau T ci-dessus par la déclaration suivante.
		char T[10] = { 'B', 'o', 'n', 'j', 'o', 'u', 'r' , 'r' , 'r' , 'r' };
	Compilez. Exécutez.

	Y a-t-il eu un changement de comportement ? Explications ?



	Rappel : zone d'initialisation des tableaux.
	============================================
	Quand il y a moins d'initialisateurs qu'il y a d'éléments, les cases restantes sont 
	initialisées à 0 (tous les bits de ces cases sont mis à 0).

	Pour les types entiers (short, long, long long et leur unsigned), cela veut dire que 
	ces valeurs seront 0.
	Pour les float et double, ces valeurs seront aussi 0.
	Pour les bool, ces valeurs seront des false (codé 0).
	Pour les char et unsigned char, ces valeurs seront des NUL (codé 0).


	Question
	===========================================

	Pourquoi, lorsqu'on fait 

		cout << D[0] << endl;
		cout << D[1] << endl;
		cout << D[2] << endl;

	a-t-on cet affichage bizarre (regardez la sortie du programme) ?

*/
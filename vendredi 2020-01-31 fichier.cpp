#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream entree("donnees.txt", ios::in);
	cout << endl << endl << "=========== 1er exercice ==========================" << endl << endl;
	/*
		Lire des nombres d'un fichier et les écrire un par ligne à l'écran.
	*/
	long valeur = 99999; // Pour les besoins de la démonstration, si jamais 99999 apparaît
						 // on saura qu'on a un problème de lecture.
	entree >> valeur;
	while (valeur != -1) // Rappel est une sentinelle. C'est la dernière valeur dans le fichier.
	{
		cout << valeur << endl;
		entree >> valeur;
	}
	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 2e  exercice ============================" << endl << endl;
	/*
		Lire des lettres d'un fichier et les écrire une par ligne à l'écran.
	*/
	// Réouverture du conduit sur un autre fichier.
	entree.open("lettres.txt", ios::in);

	char lettre = 'W';
	entree >> lettre;
	while (lettre != 'F') // Dans le 2e exercice, le caractère 'F' est la sentinelle.
	{
		cout << lettre << endl;
		entree >> lettre;
	}

	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 3e exercice - version 1 =================" << endl << endl;
	/*
		Lire des lettres d'un fichier et les écrire trois par ligne à l'écran avec
		un espace entre chaque lettre.
		La dernière ligne pourrait n'avoir que une ou deux lettres.
	*/
	// Réouverture du conduit sur le dernier fichier.
	entree.open("lettres.txt", ios::in);
	long compteur = 0;
	entree >> lettre;
	while (lettre != 'F') // Dans le 3e exercice, le caractère 'F' est la sentinelle.
	{
		cout << lettre << ' ';	// Note : Il y aura un espace après le 3e caractère de la ligne.
		compteur++;				// On tient le compte de combien de caractères ont été affichés.
		if (compteur % 3 == 0)
			cout << endl;
		entree >> lettre;
	}

	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 3e exercice - version 2 =================" << endl << endl;
	/*
		Lire des lettres d'un fichier et les écrire trois par ligne à l'écran avec
		un espace entre chaque lettre.
		La dernière ligne pourrait n'avoir que une ou deux lettres.
	*/
	// Réouverture du conduit sur le dernier fichier.
	entree.open("lettres.txt", ios::in);
	compteur = 0;
	entree >> lettre;
	while (lettre != 'F') // Dans le 3e exercice, le caractère 'F' est la sentinelle.
	{
		cout << lettre;		    // Note : Il n'y aura d'espace après le 3e caractère de la ligne.
		compteur++;				// On tient le compte de combien de caractères ont été affichés.
		if (compteur % 3 == 0)
			cout << endl;
		else
			cout << " ";
		entree >> lettre;
	}

	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 3e exercice - version 3 =================" << endl << endl;
	/*
		Lire des lettres d'un fichier et les écrire trois par ligne à l'écran avec
		un espace entre chaque lettre.
		La dernière ligne pourrait n'avoir que une ou deux lettres.
	*/
	// Réouverture du conduit sur le dernier fichier.
	entree.open("lettres.txt", ios::in);
	compteur = 0;
	entree >> lettre;
	while (lettre != 'F') // Dans le 3e exercice, le caractère 'F' est la sentinelle.
	{
		cout << lettre;		    // Note : Il n'y aura d'espace après le 3e caractère de la ligne.
		compteur++;				// On tient le compte de combien de caractères ont été affichés.
		if (compteur == 3)
		{
			cout << endl;
			compteur = 0;
		}
		else
			cout << " ";
		entree >> lettre;
	}

	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 4e exercice - version 1 =================" << endl << endl;
	/*
		Lire des comandes de permutations et les écrire à l'écran.
		Exception : la dernière commande est F et ne sera pas écrite à l'écran.
	*/
	// Réouverture du conduit sur un nouveau fichier (commandes de permutations).
	entree.open("commandes.txt", ios::in);
	char commande = 'X', operande1 = 'Y', operande2 = 'Z';
	entree >> commande;
	while (commande != 'F') // Dans le 4e exercice, le caractère 'F' est la sentinelle.
	{
		entree >> operande1 >> operande2;

		cout << commande << " " << operande1 << " " << operande2 << endl;

		entree >> commande;
	}
	entree.close();
	cout << endl << endl;
	system("pause");


/*

AJOUT - Ce qui suit n'a pas été fait au labo. C'est pour vous donner des <<idées>> sur ce qu'on peut faire.

*/
	cout << endl << endl << "=========== 4e exercice - version 2 =================" << endl << endl;
	/*
		Lire des comandes de permutations et les écrire à l'écran.
		Exception : la dernière commande est F et ne sera pas écrite à l'écran.
	*/
	// Réouverture du conduit du fichier de commandes de permutations.
	entree.open("commandes.txt", ios::in);

	entree >> commande;
	while (commande != 'F') // Dans le 4e exercice, le caractère 'F' est la sentinelle.
	{
		entree >> operande1 >> operande2;

		cout << commande << " " << operande1 << " " << operande2 << endl;

		switch (commande)
		{
		case 'R':
		case 'r':
			cout << "permuter_rangees( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'C':
		case 'c':
			cout << "permuter_colonnes( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'V':
		case 'v':
			cout << "permuter_groupes_verticaux( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'H':
		case 'h':
			cout << "permuter_groupes_horizontaux( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		}
		entree >> commande;
	}
	entree.close();
	cout << endl << endl;
	system("pause");

	cout << endl << endl << "=========== 4e exercice - version 3 =================" << endl << endl;
	/*
		Lire des comandes de permutations et les écrire à l'écran.
		Exception : la dernière commande est F et ne sera pas écrite à l'écran.
	*/
	// Réouverture du conduit du fichier de commandes de permutations.
	entree.open("commandes.txt", ios::in);

	entree >> commande;
	while (commande != 'F') // Dans le 4e exercice, le caractère 'F' est la sentinelle.
	{
		entree >> operande1 >> operande2;

		switch (commande)
		{
		case 'R':
		case 'r':
			cout << "permuter_rangees( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'C':
		case 'c':
			cout << "permuter_colonnes( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'V':
		case 'v':
			cout << "permuter_groupes_verticaux( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		case 'H':
		case 'h':
			cout << "permuter_groupes_horizontaux( " << operande1 << ", " << operande2 << " )" << endl;
			break;
		}
		entree >> commande;
	}
	entree.close();
	cout << endl << endl;
	system("pause");



}
// INFO1101_estSudoku.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"

#include <iostream>
using namespace std;

const int TAILLE = 9;


bool sont_rangees_OK(int grille[][TAILLE])
{
	bool VERIFICATION = true;

	// Tâche : Vérifications des rangées
	for (int rangee = 0; rangee < TAILLE; rangee++)
	{
		// Mettre les compteurs à zéro avant de vérifier UNE rangée.
		int frequence[TAILLE] = { 0 };

		// Pour la rangée, nous allons compter la fréquence des chiffres 1 à 9. 
			// Le chiffre #K est associé au compteur #(K-1) d'où (grille[rangee][colonne]) - 1.
		for (int colonne = 0; colonne < TAILLE; colonne++)
			++frequence[(grille[rangee][colonne]) - 1];

		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans une rangée.
		for (int K = 0; K < TAILLE; K++)
			if (frequence[K] != 1)
			{
				VERIFICATION = false;
				cout << "La rangee " << rangee << " est fautive." << endl;
				break; // Une erreur dans la rangée suffit pour dire que la rangée est fautive.
			}
	}//fin de Vérifications des rangées.
	return VERIFICATION;

}
bool sont_colonnes_OK(int grille[][TAILLE])
{
	bool VERIFICATION = true;

	// Tâche : Vérifications des colonnes
	for (int colonne = 0; colonne < TAILLE; colonne++)
	{
		// Mettre les compteurs à zéro avant de vérifier UNE colonne.
		int frequence[TAILLE] = { 0 };

		// Pour la colonne, nous allons compter la fréquence des chiffres 1 à 9. 
			// Le chiffre #K est associé au compteur #(K-1) d'où (grille[rangee][colonne]) - 1.
		for (int rangee = 0; rangee < TAILLE; rangee++)
			++frequence[(grille[rangee][colonne]) - 1];

		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans une colonne.
		for (int K = 0; K < TAILLE; K++)
			if (frequence[K] != 1)
			{
				VERIFICATION = false;
				cout << "La colonne " << colonne << " est fautive." << endl;
				break; // Une erreur dans la colonne suffit pour dire que la colonne est fautive.
			}
	}//fin de Vérifications des colonnes.
	return VERIFICATION;
}

bool sont_blocs_OK(int grille[][TAILLE])
{

	// Mettre les compteurs à zéro avant de vérifier les blocs.
	int frequence[TAILLE][TAILLE] = { 0 };
	// La rangée #K de frequence[][] contient les compteurs pour le bloc #K.

	// Le chiffre #K est associé au compteur (colonne) #(K-1) d'où (grille[rangee][colonne]) - 1.

	// On fait l'acquisition des fréquences pour tous les blocs avant de vérifier.
	for (int rangee = 0; rangee < TAILLE; rangee++)
		for (int colonne = 0; colonne < TAILLE; colonne++)
		{
			short numero_de_bloc = ((rangee / 3) * 3) + colonne / 3; // Voir la formule de l'énoncé du labo #1.
			++frequence[numero_de_bloc][(grille[rangee][colonne]) - 1];
		}

	bool VERIFICATION = true;

	for (short bloc = 0; bloc < TAILLE; bloc++)
	{
		// vérifier que chaque chiffre n'apparaît qu'exactement une seule fois (ni plus, ni moins)
		// dans un bloc.
		for (int K = 0; K < TAILLE; K++)
			if (frequence[bloc][K] != 1)
			{
				VERIFICATION = false;
				cout << "Le bloc " << bloc << " est fautif." << endl;
				break; // Une erreur dans le bloc suffit pour dire que le bloc est fautif.
			}

	}//fin de Vérifications des blocs.
	return VERIFICATION;
}

bool EstSudoku(int grille[][TAILLE])
{
	bool rangees_OK = sont_rangees_OK(grille);
	bool colonnes_OK = sont_colonnes_OK(grille);
	bool blocs_OK = sont_blocs_OK(grille);

	return rangees_OK && colonnes_OK && blocs_OK;

} // fin -  EstSudoku( )


int main()
{
	int sudoku1[TAILLE][TAILLE] =
	{ { 1, 3, 8,   4, 2, 7,   6, 9, 5 },
	  { 2, 4, 7,   5, 6, 9,   8, 3, 1 },
	  { 5, 9, 6,   3, 8, 1,   4, 2, 7 },

	  { 8, 1, 9,   2, 7, 5,   3, 4, 6 },
	  { 4, 7, 2,   8, 3, 6,   1, 5, 9 },
	  { 6, 5, 3,   9, 1, 4,   7, 8, 2 },

	  { 9, 2, 1,   6, 4, 3,   5, 7, 8 },
	  { 3, 6, 5,   7, 9, 8,   2, 1, 4 },
	  { 7, 8, 4,   1, 5, 2,   9, 6, 3 } };

	cout << endl << endl << "Sudoku #1" << endl;
	if (EstSudoku(sudoku1))
		cout << "1-Est Sudoku = la reponse attendue." << endl;
	else
		cout << "1- N'est pas Sudoku => fonction fautive" << endl;



	int sudoku2[TAILLE][TAILLE] =
	{ { 3, 1, 5,   7, 8, 9,   6, 4, 2 },
	  { 7, 9, 4,   1, 2, 6,   3, 5, 8 },
	  { 2, 8, 6,   4, 3, 5,   1, 9, 7 },

	  { 1, 6, 2,   3, 5, 7,   9, 8, 4 },
	  { 5, 7, 3,   8, 9, 4,   2, 1, 6 },
	  { 9, 4, 8,   2, 6, 1,   7, 3, 5 },

	  { 8, 5, 1,   6, 7, 3,   4, 2, 9 },
	  { 4, 2, 7,   9, 1, 8,   5, 6, 3 },
	  { 6, 3, 9,   5, 4, 2,   8, 7, 1 } };

	cout << endl << endl << "Sudoku #2" << endl;
	if (EstSudoku(sudoku2))
		cout << "2- Est Sudoku = la reponse attendue." << endl;
	else
		cout << "2- N'est pas Sudoku => fonction fautive" << endl;


	int sudoku3[TAILLE][TAILLE] =
	{ { 3, 1, 5,   7, 8, 9,   6, 4, 2 },
	  { 7, 9, 4,   1, 2, 6,   3, 5, 8 },
	  { 1, 6, 2,   3, 5, 7,   9, 8, 4 },

	  { 5, 7, 3,   8, 9, 4,   2, 1, 6 },
	  { 9, 4, 8,   2, 6, 1,   7, 3, 5 },
	  { 2, 8, 6,   4, 3, 5,   1, 9, 7 },

	  { 8, 5, 1,   6, 7, 3,   4, 2, 9 },
	  { 4, 2, 7,   9, 1, 8,   5, 6, 3 },
	  { 6, 3, 9,   5, 4, 2,   8, 7, 1 } };

	cout << endl << endl << "Sudoku #3" << endl;
	if (EstSudoku(sudoku3))
		cout << "3- Est Sudoku => fonction fautive. " << endl;
	else
		cout << "3- N'est pas Sudoku = la reponse attendue." << endl;


	int sudoku4[TAILLE][TAILLE] =
	{ { 3, 1, 5,   7, 8, 6,   9, 4, 2 },
	  { 7, 9, 4,   1, 2, 3,   6, 5, 8 },
	  { 2, 8, 6,   4, 3, 1,   5, 9, 7 },

	  { 1, 6, 2,   3, 5, 9,   7, 8, 4 },
	  { 5, 7, 3,   8, 9, 2,   4, 1, 6 },
	  { 9, 4, 8,   2, 6, 7,   1, 3, 5 },

	  { 8, 5, 1,   6, 7, 4,   3, 2, 9 },
	  { 4, 2, 7,   9, 1, 5,   8, 6, 3 },
	  { 6, 3, 9,   5, 4, 8,   2, 7, 1 } };

	cout << endl << endl << "Sudoku #4" << endl;
	if (EstSudoku(sudoku4))
		cout << "4- Est Sudoku => fonction fautive." << endl;
	else
		cout << "4- N'est pas Sudoku = la reponse attendue." << endl;

	int sudoku5[TAILLE][TAILLE] =
	{ { 1, 3, 8,   4, 2, 7,   6, 9, 5 },
	  { 2, 6, 7,   5, 6, 9,   8, 3, 1 },
	  { 5, 9, 4,   3, 8, 1,   4, 2, 7 },

	  { 8, 1, 9,   2, 7, 5,   3, 4, 6 },
	  { 4, 7, 2,   8, 3, 6,   1, 5, 9 },
	  { 6, 5, 3,   9, 1, 4,   7, 8, 2 },

	  { 9, 2, 1,   6, 4, 3,   5, 7, 8 },
	  { 3, 6, 5,   7, 9, 8,   2, 1, 4 },
	  { 7, 8, 4,   1, 5, 2,   9, 6, 3 } };

	cout << endl << endl << "Sudoku #5" << endl;
	if (EstSudoku(sudoku5))
		cout << "5- Est Sudoku => fonction fautive." << endl;
	else
		cout << "5- N'est pas Sudoku = la reponse attendue." << endl;


	int sudoku6[TAILLE][TAILLE] =
	{ { 3, 1, 5,   7, 8, 9,   6, 4, 2 },
	  { 7, 9, 4,   1, 2, 6,   3, 5, 8 },
	  { 2, 8, 6,   4, 3, 5,   1, 9, 7 },

	  { 1, 6, 2,   3, 5, 7,   9, 8, 4 },
	  { 5, 7, 3,   8, 9, 4,   2, 1, 6 },
	  { 9, 4, 8,   2, 6, 4,   3, 3, 5 },

	  { 8, 5, 1,   6, 7, 7,   1, 2, 9 },
	  { 4, 2, 7,   9, 1, 8,   5, 6, 3 },
	  { 6, 3, 9,   5, 4, 2,   8, 7, 1 } };

	cout << endl << endl << "Sudoku #6" << endl;
	if (EstSudoku(sudoku6))
		cout << "6- Est Sudoku => fonction fautive." << endl;
	else
		cout << "6- N'est pas Sudoku = la reponse attendue." << endl;

	int sudoku7[TAILLE][TAILLE] =
	{ { 1, 3, 8,   4, 2, 7,   6, 9, 5 },
	  { 2, 4, 7,   5, 6, 9,   8, 3, 1 },
	  { 5, 9, 6,   3, 8, 1,   4, 2, 7 },

	  { 8, 1, 9,   2, 7, 5,   3, 4, 6 },
	  { 4, 7, 2,   8, 3, 6,   1, 5, 9 },
	  { 6, 5, 3,   9, 1, 4,   7, 8, 2 },

	  { 9, 2, 1,   6, 4, 3,   5, 7, 8 },
	  { 3, 6, 5,   7, 6, 8,   2, 1, 4 },
	  { 7, 8, 4,   1, 5, 2,   9, 6, 3 } };

	cout << endl << endl << "Sudoku #7" << endl;
	if (EstSudoku(sudoku7))
		cout << "7- Est Sudoku => fonction fautive." << endl;
	else
		cout << "7- N'est pas Sudoku = la reponse attendue." << endl;

	int sudoku8[TAILLE][TAILLE] =
	{ { 4, 1, 5,   7, 8, 9,   6, 4, 2 },
	  { 7, 9, 4,   1, 2, 6,   3, 5, 8 },
	  { 2, 8, 6,   4, 3, 5,   1, 9, 7 },

	  { 1, 6, 2,   3, 5, 7,   9, 8, 4 },
	  { 5, 7, 3,   8, 9, 4,   2, 1, 6 },
	  { 9, 4, 8,   2, 6, 1,   7, 3, 5 },

	  { 8, 5, 1,   6, 7, 3,   4, 2, 9 },
	  { 4, 2, 7,   9, 1, 8,   5, 6, 3 },
	  { 6, 3, 9,   5, 4, 2,   8, 7, 1 } };

	cout << endl << endl << "Sudoku #8" << endl;
	if (EstSudoku(sudoku8))
		cout << "8- Est Sudoku => fonction fautive." << endl;
	else
		cout << "8- N'est pas Sudoku = la reponse attendue." << endl;

	int sudoku9[TAILLE][TAILLE] =
	{ { 1, 3, 8,   4, 2, 7,   6, 9, 5 },
	  { 2, 5, 7,   5, 6, 9,   8, 3, 1 },
	  { 5, 9, 6,   3, 8, 3,   4, 2, 7 },

	  { 8, 1, 9,   2, 7, 5,   3, 8, 6 },
	  { 4, 7, 2,   8, 3, 6,   1, 5, 9 },
	  { 6, 5, 3,   9, 1, 4,   7, 8, 2 },

	  { 9, 2, 2,   6, 4, 3,   5, 7, 8 },
	  { 3, 6, 5,   7, 9, 8,   2, 1, 4 },
	  { 7, 8, 4,   1, 5, 2,   9, 6, 3 } };

	cout << endl << endl << "Sudoku #9" << endl;
	if (EstSudoku(sudoku9))
		cout << "9- Est Sudoku => fonction fautive." << endl;
	else
		cout << "9- N'est pas Sudoku = la reponse attendue." << endl;



	return 0;
} // fin -  main( )


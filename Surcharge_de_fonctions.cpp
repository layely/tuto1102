#include "pch.h"
#include <iostream>
using namespace std;

long long carre(long long N)					// signature : carre(long long)
{
	cout << "long long" << endl;
	return N * N;
}

unsigned long long carre(unsigned long long N)	// signature : carre(unsigned long long)
{
	cout << "unsigned long long" << endl;
	return N * N;
}

long carre(long N)								// signature : carre(long)
{
	cout << "long" << endl;
	return N * N;
}

unsigned long carre(unsigned long N)			// signature : carre(unsigned long)
{
	cout << "unsigned long" << endl;
	return N * N;
}

long carre(int N)								// signature : carre(int)
{
	cout << "long" << endl;
	return N * N;
}

unsigned long carre(unsigned int N)				// signature : carre(unsigned int)
{
	cout << "unsigned long" << endl;
	return N * N;
}

short carre(short N)							// signature : carre(short)
{
	cout << "short" << endl;
	return N * N;
}

unsigned short carre(unsigned short N)			// signature : carre(unsigned short)
{
	cout << "unsigned short" << endl;
	return N * N;
}

float carre(float N)							// signature : carre(float)
{
	cout << "float" << endl;
	return N * N;
}

double carre(double N)							// signature : carre(double)
{
	cout << "double" << endl;
	return N * N;
}


int main()
{

	unsigned long long ULL = 10;
	long long LL = 10;
	unsigned long UL = 10;
	long L = 10;
	unsigned int UI = 10;
	int I = 10;
	unsigned short US = 10;
	short S = 10;
	float F = 10;
	double D = 10;

	ULL = carre(ULL);
	LL = carre(LL);
	UL = carre(UL);
	L = carre(L);
	UI = carre(UI);
	I = carre(I);
	US = carre(US);
	S = carre(S);
	F = carre(F);
	D = carre(D);


}
  

/*
On dit qu'une fonction est surcharg�e lorsqu'il y a plusieurs 
d�finitions de fonctions avec le m�me "nom". Toutefois, il faut
qu'elles aient des signatures diff�rentes pour que le compilateur 
puisse bien faire son travail.

Dans les exemples ci-dessus, chacune des d�finitions a une signature
qui lui est propre.

Rappel : La signature est compos�e du nom de la fonction et des 
types et modes de passage des param�tres formels.

Pour un appel donn�e, le compilateur g�n�re les signatures probables.
Si l'une des signatures probables se trouvent dans la table de symboles
le compilateur la fonction associ�e. 

Par contre, si deux des signatures probables se trouvent dans la table 
de symboles, cela constituera une ambigu�t� et un message d'erreur est 
g�n�r� et la version ex�cutable ne sera pas g�n�r�e.

Dans l'�ventualit� o� aucune des signatures probables n'existe dans la
table de symboles, une message d'erreur sera g�n�r� par le compilature 
nous annon�ant que la fonction est non d�finie. La version ex�cutable 
ne sera pas g�n�r�e.

*/

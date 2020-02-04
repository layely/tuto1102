
#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

typedef long unTemps;

const short uneGrilleDimension = 12;
typedef short uneGrille[uneGrilleDimension][uneGrilleDimension];

typedef float *floatPtr;



int main()
{
	long X = 123;
	unTemps Y = 765;

	cout << "Type de X = " << typeid(X).name() << endl;
	cout << "Type de Y = " << typeid(Y).name() << endl << endl;

	short grille[9][9] = { 0 };
	uneGrille G = { 0 };

	cout << "Type de grille = " << typeid(grille).name() << endl;
	cout << "Type de G      = " << typeid(G).name() << endl << endl;

	cout << " grille = " << endl;
	for (short R = 0; R < 9; R++)
	{
		for (short C = 0; C < 9; C++)
			cout << grille[R][C] << "   ";
		cout << endl;
	}

	cout << endl << " G = " << endl;
	for (short R = 0; R < uneGrilleDimension; R++)
	{
		for (short C = 0; C < uneGrilleDimension; C++)
			cout << G[R][C] << "   ";
		cout << endl;
	}


	cout << endl;

	float *ptr = NULL;
	floatPtr PTR = NULL;

	cout << "Type de ptr      = " << typeid(ptr).name() << endl;
	cout << "Type de PTR      = " << typeid(PTR).name() << endl << endl;

	time_t debut;
	clock_t fin;

	cout << "Type de debut     = " << typeid(debut).name() << endl;
	cout << "Type de fin       = " << typeid(fin).name() << endl << endl;
	cout << "Type de long long = " << typeid(long long).name() << endl << endl;

	return 0;
}
/*
typedef sert à créer des noms de types. Disons que typedef sert à créer un synomyme 
pour un type existant (dont on fait usage).

Le but derrière la création de typedef est double : 1) améliorer l'auto-documentation 
(rendre le code plus comprenable) et 2) réduire les probabilités de faire des erreurs.

Pour ce qui est de l'auto-documentation, il faudra tout de même utiliser de noms qui 
portent un sens et dont on pourra aisément se rappeler. Dans les les exemples ci-dessus,
il y a "uneGrille". Ceci est plus lisible que ts33.

Pour ce qui est de réduire les erreurs, p.ex., en utilisant uneGrille, on n'a pas à 
se rappeler que le tableau est 3x3 et de type de base short, le compilateur sait tout ça.

On a déjà rencontré des typdef mais sans vous le dire expressément. Des exemples : time_t,
clock_t, long long.

Le type time_t est associé à la fonction time() qui nous retourne le nombre de secondes
écoulées depuis 00:00:00, le premier janvier 1970. C'est en fait la même chose que le 
long long. En utilisant time_t, on utilise automatiquement le bon type pour recevoir la réponse.

clock_t est associé à la fonction clock() qui retourne le temps écoulé entre le démarrage 
de votre programme et l'appel à la fonction. C'est en fait le type long.

long long est le synonyme du type __int64 (_ _ int64) un nom de type qui était spécifique 
à Microsoft. Si vous voulez, __int64 est le nom interne que Microsoft donne à long long.


Une autre possibilité 1) d'améliorer l'auto-documentation 
(rendre le code plus comprenable) et 2) de réduire les probabilités de faire des erreurs
est d'utiliser des constantes. Lorsque bien utilisées, elles nous évitent d'avoir à se 
rappeler des petits détails et facilitent aussi la tâche de modifier le code lorsqu'il 
est nécessaire de le faire. Dans l'exemple ci-dessus, si vous changer la valeur de
uneGrilleDimension à 12, vous verrez que le type unegrille sera modifié automatiquement.
De plus, la double boucle d'affichage pour G a aussi été automatiquement modifiée.

Ceci fait partie des approches qui facilitent le travail et réduisent les probabilités 
de faire des erreurs.

Comme la constante uneGrilleDimension est étroitement liée au type uneGrille, il va de soi
qu'on les place ensemble dans le code. De plus, comme leur usage est plutôt répartie sur
le code, il serait préférable de les rendre visible partout en les déclarant au niveau 
du fichier.

*/
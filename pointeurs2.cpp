// pointeurs2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
using namespace std;

long X = 123;  // Dans la zone des variables statiques.
void f()
{
	static long P = 234; // Dans la zone des variables statiques.
	long Q = 678;
	long *E = &X;
	long *F = &P;
	long *G = &Q;
	long *H = new long; // Sur le monceau (on parle de l'espace obtenue par "new long".)
	cout << "E = " << E << "  =  " << unsigned long(E) << "  pointe a un statique" << endl;
	cout << "F = " << F << "  =  " << unsigned long(F) << "  pointe a un statique" << endl;
	cout << "G = " << G << "  =  " << unsigned long(G) << "  pointe sur la pile" << endl;
	cout << "H = " << H << "  =  " << unsigned long(H) << "  pointe sur le monceau" << endl;
	// delete E;
	// delete F;
	// delete G ;
	// delete H ;
}

int main()
{
	cout << endl << "Adresses dans f()" << endl << endl;

	f();

	cout << endl << "Adresses dans main()" << endl << endl ;

	static long U = 678;// Dans la zone des variables statiques.
	long V = 345; // Sur la pile du programme.

	long *I = &X;
	long *J = &U;
	long *K = &V;

	long *L = new long; // Sur le monceau (on parle de l'espace obtenue par "new long".)

	cout << "I = " << I << "  =  " << unsigned long(I) << "  pointe a un statique " << endl;
	cout << "J = " << J << "  =  " << unsigned long(J) << "  pointe a un statique " << endl;
	cout << "K = " << K << "  =  " << unsigned long(K) << "  pointe sur la pile " << endl;
	cout << "L = " << L << "  =  " << unsigned long(L) << "  pointe sur le monceau " << endl;
	/*
	L'emploi du "cast" unsigned long() permet de voir les adresses exprimées en "décimal"
	plutôt qu'en "hexadécimal".
	*/
 

//	delete I;
//	delete J;
//	delete K;
//	delete L;

}

/*
Que faire avec ce programme ? 

Dans un premier temps, le faire exécuter à plusieurs fois.

Pouy aller plus rondement, vous pouvez utiliser les abrégés.
Ctrl+F5			pour exécuter sans débogage (F5 est la touche de fonction F5 dans la rangée 
				des touches au-dessus de la rangée des chiffres sur le clavier principal.)

Regardez les valeurs d'adresses. Comparez les adresses "statique", "sur pile" et "sur le monceau".
Vous devriez voir que pour une exécution donnée, les variables "statiques" sant dans une zone séparée
de la zone des variables "sur pile" ou de celle des variables "sur monceau".

Est-ce que les zones sont toujours dans le même ordre d'une exécution à l'autre ?

Dans une deuxième temps, essayez le programme en faisant exécuter un des delete (enlever le //
en avant d'UNE des instruction delete.)

Dans chacun des huit cas (il y a 8 delete), est-ce que la compilation fonctionne ?
Dans chacun des huit cas, est-ce que l'exécution va bien ?

Dans le cas où ça ne va pas bien, qu'elle en est la raison ?


Dans un troisième temps, dans main(), mettez l'appel de f() en commentaires.
Enlevez les // devant les quatre delete qu'il y a dans la fonction f().
Assurez-vous d'avoir des // devant les quatre delete de la fonction main().
Compilez. Exécutez.
Que se passe-t-il ?



Commentaires : 

On va souhaiter que vous voyez la différence entre une erreur de compilation 
et une erreur d'exécution.

On va souhaiter que vous avez noté qu'il est possible d'avoir des erreurs qui
ne se manifestent pas à tout coup.

Avez-vous noté que d'une fois à l'autre, les adresses ne sont pas nécessairement les mêmes ?

Avez-vous noté dans quel ordre sont positionnés en mémoire les zones des 
variables statiques, de la pile et du monceau ?
	Avec trois zones, il y a six permutations possibles.
	petites adresses < statique < pile     < monceau  < grandes adresses
	petites adresses < statique < monceau  < pile     < grandes adresses
	petites adresses < pile     < statique < monceau  < grandes adresses
	petites adresses < pile     < monceau  < statique < grandes adresses
	petites adresses < monceau  < statique < pile     < grandes adresses
	petites adresses < monceau  < pile     < statique < grandes adresses

	Y a-t-il une permutation privilégiée ou non ?

Avez-vous compris pourquoi vous avez eu des erreurs d'exécution ?


*/
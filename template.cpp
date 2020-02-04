#include "pch.h"
#include <iostream>
using namespace std;
template <typename unType>
unType carre(unType N)
{
	cout << typeid(unType).name() << endl;
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

	// On peut "forcer" le choix du type employé.
	cout << endl << endl << "Autre syntaxe" << endl << endl;
	ULL = carre<long>(ULL);
	LL = carre<unsigned long>(LL);
	UL = carre<short>(UL);
	L = carre<unsigned long>(L);
	UI = carre<short>(UI);
	I = carre<unsigned short>(I);
	US = carre<double>(US);
	S = carre<double>(S);
	F = carre<double>(F);
	D = carre<float>(D);
}


/*

Un template (modèle) de fonction est un générateur simple de code.

On se rappellera que le compilateur analyse chaque appel pour voir quelle fonction est 
véritablement appelée. Pour chaque appel, le compilateur génère les signatures probables 
en se servant des types des paramètres actuels. Ensuite, il compare les signatures 
probables d'un appel avec les signatures de fonctions qui sont dans la table de symboles.

Si l'intersection de ces deux ensembles de signatures contient deux signatures ou plus, 
ceci constitue une ambiguïté. Le compilateur va générer un message d'erreur et la version 
exécutable n'est pas produite.

Si l'intersection de ces deux ensembles de signatures contient une seule signature, alors 
le compilateur sait quelle version de la fonction utiliser.

Si l'intersection de ces deux ensembles de signatures est vide, alors le compilateur va 
regarder si il y a un template qui pourrait générer une des signatures probables. Si la 
réponse est non, alors le compilateur va générer un message à l'effet qu'il n'y a pas de 
définitions et la version exécutable n'est pas produite.

S'il y a un template avec le même nom que la fonction, alors le compilateur va essayer 
la chose suivante. Pour simplifier la présentation, on va utiliser notre exemple ci-dessus 
pour le premier appel.

Appel : carre(ULL)

ULL est de type unsigned long long.
deux signatures probables :
	carre( unsigned long long )
et	carre( unsigned long long& )

Le template:
	template <typename unType>
	unType carre(unType N)
	{
		cout << typeid(unType).name() << endl;
		return N * N;
	}

Pour que la signature produite par le template ressemble à une des deux signatures 
probables, il faudrait que "unType" soit remplacé par "unsigned long long". Le 
compilateur peut lire le type du paramètre actuel et l'utiliser pour la génération 
du code pour une nouvelle version surchargée de la fonction.

Le compilateur fait essentiellement quelque chose similaire à ce qui suit.

1) Trouver le type du paramètre actuel.
		unsigned long long

2) Faire un copier-coller de la définition du template (sans la ligne template <...>).

	unType carre(unType N)
	{
		cout << typeid(unType).name() << endl;
		return N * N;
	}

3) Rechercher et remplacer "unType" par "unsigned long long".

	unsigned long long carre(unsigned long long N)
	{
		cout << typeid(unsigned long long N).name() << endl;
		return N * N;
	}

4) Le compilateur génère la signature de cette fonction.

	carre(unsigned long long N)

5) Il vérifie si cette signature correspond à une des signature probables.

	C'est bien le cas.

6) La signature de cette nouvelle fonction surchargée est entrée dans la table de 
   symboles et la version exécutable de la fonction est générée et mise dans le 
   fichier exécutable.

Le compilateur continue son travail.



Dans le cas où on a imposé le choix du type, alors le code est généré en utilsant
le type choisi. Par exemple :

Appel : carre<long>(ULL)

	ULL est de type "unsigned long long" MAIS le type imposé est "long".

La suite est plus courte que la version précéente.

1) Le compilateur fait un copier-coller de la définition.

	unType carre(unType N)
	{
		cout << typeid(unType).name() << endl;
		return N * N;
	}

2) Rechercher et remplacer "unType" par "long".

	long carre(long N)
	{
		cout << typeid(long).name() << endl;
		return N * N;
	}

3) Le compilateur génère la signature de cette fonction.

	carre(long N)

4) La signature de cette nouvelle fonction surchargée est entrée dans la table de 
   symboles et la version exécutable de la fonction est générée et mise dans le 
   fichier exécutable.


Le compilateur continue son travail.


P.S. Jetez un coup d'oeil aux avertissements lorsque vous générer la solution.
*/

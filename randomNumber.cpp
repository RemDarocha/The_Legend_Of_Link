# include <iostream>
# include <windows.h>
# include <time.h>

#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

int randomNumber()
{
	int nombre_aleatoire = 0;

	nombre_aleatoire = rand_a_b(1,11);
    //cout << "le numero aleatoire est : " << nombre_aleatoire << endl;
	return nombre_aleatoire;
}

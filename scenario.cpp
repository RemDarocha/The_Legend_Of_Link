#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>


using namespace std;

void Afficher(string text)
    {
        for(int x=0; x < text.length(); x++)
        {
            cout << text[x];
            Sleep(15);
        };
        cout << endl;
    }

void Scenario(const char* scenar)
{
    ifstream fichier(scenar, ios::in);
    if (fichier)
    {
        string ligne;
        while(!fichier.eof())
        {
            getline(fichier, ligne);
            Afficher(ligne);

        }
        fichier.close();
    }
    else
    {
        std::cout << "Erreur de lecture du fichier." << std::endl;
    }
}


# include <iostream>
# include <windows.h>
# include <conio.h> // touches du clavier
# include <stdlib.h> // exit
# include <time.h>
# include <string>
# include <cstdio>

#include <MMSystem.h>

#pragma comment(lib, "winmm.lib")

# include "personnage.h"
# include "randomNumber.h"
# include "scenario.h"
# include "combatLoup.h"
# include "combatEpouvantail.h"
# include "combatCyclope.h"
# include "combatGanon.h"


#define ENTREE_TOUCHE 13
#define ECHAP_TOUCHE 27

using namespace std;
using namespace Personnages;


int main()
{
    Personnage Zelda("Zelda","Boule de feu", "Eclair", "Cataclysm", 80, 100, 220, 360);
    Personnage Epouvantail("Epouvantail","Retour", "Retour", "Retour", 10, 10, 10, 300);
    Personnage Loup("Loup","Morsure", "Griffe", "Furie", 20, 40, 80, 300);
    Personnage Cyclope("Cyclope","Coup de boule", "Charge", "Lancer de roche", 20, 50, 120, 400);
    Personnage Ganon("Ganon","Pyrokinésie", "Boule d'énergie", "Enfer de magie noire", 70, 110, 300, 500);


    PlaySound("zelda_theme.wav", NULL, SND_ASYNC);

    Scenario("scenario\\dessin_debut.txt");
    cout << endl;
    cout << endl;

   Scenario("scenario\\debut_scenario.txt");



    Afficher("Quand vous serez prete a combattre appuyez sur la touche ENTREE..");
    cout << endl;

    int touche = 0;

    switch((touche=getch())) {
        case ENTREE_TOUCHE:
            PlaySound(NULL, 0, 0);
            //PlaySound("zelda_victory.wav", NULL, SND_SYNC);
            PlaySound("zelda_combat.wav", NULL, SND_ASYNC|SND_LOOP);
        break;
    }

    Afficher("Vous disposez de trois attaques : Boule de feu (80dmg), Eclair (100 dmg) et Cataclysm (220 dmg).");
    cout << endl;
    Afficher("Sachez que chaque attaque a son taux de reussite.. jouez intelligemment !");
    cout << endl;

    combatEpouvantail();
    cout << endl;

//Début de l'aventure et arrivée dans la forêt
    PlaySound(NULL, 0, 0);
    PlaySound("zelda_victory.wav", NULL, SND_SYNC);
    PlaySound("zelda_theme.wav", NULL, SND_ASYNC);

    Scenario("scenario\\foret_loups.txt");

    Afficher("Appuyez sur la touche ENRTREE pour lancer le combat..");
    cout << endl;

    switch((touche=getch())) {
        case ENTREE_TOUCHE:
            PlaySound(NULL, 0, 0);
            //PlaySound("zelda_victory.wav", NULL, SND_SYNC);
            PlaySound("zelda_combat.wav", NULL, SND_ASYNC|SND_LOOP);
        break;
    }


    combatLoup();
    cout << endl;

//Suite du combat et de la forêt, approche du cyclope
    Scenario("scenario\\pont_cyclope.txt");

    Afficher("Appuyez sur la touche ENRTREE pour lancer le combat..");
    cout << endl;

    switch((touche=getch())) {
        case ENTREE_TOUCHE:
            PlaySound(NULL, 0, 0);
            //PlaySound("zelda_victory.wav", NULL, SND_SYNC);
            PlaySound("zelda_combat.wav", NULL, SND_ASYNC|SND_LOOP);
        break;
    }


    combatCyclope();
    cout << endl;

//Arivée au château de Ganon
    Scenario("scenario\\chateau_ganon.txt");

    Afficher("Appuyez sur la touche ENRTREE pour lancer le combat..");
    cout << endl;

    switch((touche=getch())) {
        case ENTREE_TOUCHE:
            PlaySound(NULL, 0, 0);
            //PlaySound("zelda_victory.wav", NULL, SND_SYNC);
            PlaySound("zelda_combat.wav", NULL, SND_ASYNC|SND_LOOP);
        break;
    }

    combatGanon();
    cout << endl;

    Scenario("scenario\\dessin_fin.txt");

    Afficher("'appuyez sur ECHAP pour quitter le jeu'");

    // switch touches du clavier
    int touche2 = 0;
        switch((touche2=getch())) {
            case ECHAP_TOUCHE:
                return 0;
            break;

        }
}

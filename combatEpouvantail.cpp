# include <iostream>
# include <windows.h>
# include <conio.h> // touches du clavier
# include <stdlib.h> // exit
# include <time.h>
# include <string>

# include "personnage.h"
# include "randomNumber.h"
# include "scenario.h"

# include <cstdio>

using namespace std;
using namespace Personnages;

int combatEpouvantail ()
{
    srand(time(NULL));

    Personnage Zelda("Zelda","Boule de feu", "Eclair", "Cataclysm", 80, 100, 220, 360);
    Personnage Epouvantail("Epouvantail","Retour", "Retour", "Retour", 10, 10, 10, 300);

    string reponse =" ";

    do
    {
        Afficher("Quelle attaque voulez vous utiliser : ");
        Afficher(Zelda.getNomAttack1() + ", " + Zelda.getNomAttack2() + " ou " + Zelda.getNomAttackUltime() + " ?" );

        getline(cin, reponse);

        if (reponse == Zelda.getNomAttack1())
        {
            int NumeroRandom = randomNumber();
            int attaqueAvecRandom;

            attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttack1(), Zelda.getDegatsAttack1(), NumeroRandom, Epouvantail);

            if (NumeroRandom < 9)
            {
                char lesPV[1024];
                sprintf(lesPV, "%d", Epouvantail.getPV());
                Afficher(std::string ( "Votre attaque reussie, ses PV ne sont plus que de ") + lesPV);

            }
            else
            {
                char lesPV[1024];
                sprintf(lesPV, "%d", Epouvantail.getPV());
                Afficher(std::string ("Dommage votre attaque echoue, les points de vie de ") + Epouvantail.getNom() + std::string (" sont toujours de ") + lesPV);
            }

            if (Epouvantail.getPV() !=0)
            {
                int attaqueEpouvantail;
                attaqueEpouvantail = Epouvantail.Attaquer(Epouvantail.getNomAttack2(), Epouvantail.getDegatsAttack2(), randomNumber(), Zelda);

                char lesPV[1024];
                sprintf(lesPV, "%d", Zelda.getPV());

                Afficher(std::string ("L'epouvantail vous attaque a son tour, il vous reste : ") + lesPV + std::string ("PV") );
            }

        }
        else if (reponse == Zelda.getNomAttack2())
        {
            int NumeroRandom = randomNumber();
            int attaqueAvecRandom;

            attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttack2(), Zelda.getDegatsAttack2(), NumeroRandom, Epouvantail);

            char lesPV[1024];
            sprintf(lesPV, "%d", Epouvantail.getPV());

            if (NumeroRandom < 6)
            {
                Afficher( std::string("Votre attaque reussie, ses PV ne sont plus que de ") + lesPV );
            }
            else
            {
               Afficher (std::string ("Dommage votre attaque echoue, les points de vie de ") + Epouvantail.getNom() + std::string(" sont toujours de ") + lesPV);
            }


            if (Epouvantail.getPV() !=0)
            {
                int attaqueEpouvantail;
                attaqueEpouvantail = Epouvantail.Attaquer(Epouvantail.getNomAttack2(), Epouvantail.getDegatsAttack2(), randomNumber(), Zelda);

                char lesPV[1024];
                sprintf(lesPV, "%d", Zelda.getPV());

                Afficher(std::string("L'epouvantail vous attaque a son tour, il vous reste : ") + lesPV + std::string("PV"));
            }

        }
        else if (reponse == Zelda.getNomAttackUltime())
        {
            int NumeroRandom = randomNumber();
            int attaqueAvecRandom;

            attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttackUltime(), Zelda.getDegatsAttackUltime(), NumeroRandom, Epouvantail);

            char lesPV[1024];
            sprintf(lesPV, "%d", Epouvantail.getPV());

            if (NumeroRandom < 3)
            {
                Afficher(std::string("Votre attaque reussie, ses PV ne sont plus que de ") + lesPV);
            }
            else
            {
               Afficher(std::string("Dommage votre attaque echoue, les points de vie de ") + Epouvantail.getNom() + std::string(" sont toujours de ") + lesPV);
            }


            if (Epouvantail.getPV() !=0)
            {
                int attaqueEpouvantail;
                attaqueEpouvantail = Epouvantail.Attaquer(Epouvantail.getNomAttack2(), Epouvantail.getDegatsAttack2(), randomNumber(), Zelda);

                char lesPV[1024];
                sprintf(lesPV, "%d", Zelda.getPV());

                Afficher (std::string("L'epouvantail vous attaque a son tour, il vous reste : ") + lesPV + "PV");
            }

        }
        else
        {
            Afficher("Veuillez saisir un nom d'attaque correct");
        }
    } while (Epouvantail.getPV()!=0);

}

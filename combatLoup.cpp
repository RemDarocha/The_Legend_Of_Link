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

int combatLoup ()
{
    srand(time(NULL));

    Personnage Zelda("Zelda","Boule de feu", "Eclair", "Cataclysm", 80, 100, 220, 360);
    Personnage Loup("Loup","Morsure", "Griffe", "Furie", 20, 40, 80, 300);

    //
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

                attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttack1(), Zelda.getDegatsAttack1(), NumeroRandom, Loup);

                if (NumeroRandom < 9)
                {
                    char lesPV[1024];
                    sprintf(lesPV, "%d", Loup.getPV());
                    Afficher(std::string ( "Votre attaque reussie, ses PV ne sont plus que de ") + lesPV);

                }
                else
                {
                    char lesPV[1024];
                    sprintf(lesPV, "%d", Loup.getPV());
                    Afficher(std::string ("Dommage votre attaque echoue, les points de vie de ") + Loup.getNom() + std::string (" sont toujours de ") + lesPV);
                }

             }


            else if (reponse == Zelda.getNomAttack2())
            {
                int NumeroRandom = randomNumber();
                int attaqueAvecRandom;

                attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttack2(), Zelda.getDegatsAttack2(), NumeroRandom, Loup);

                char lesPV[1024];
                sprintf(lesPV, "%d", Loup.getPV());

                if (NumeroRandom < 6)
                {
                    Afficher( std::string("Votre attaque reussie, ses PV ne sont plus que de ") + lesPV );
                }
                else
                {
                   Afficher (std::string ("Dommage votre attaque echoue, les points de vie de ") + Loup.getNom() + std::string(" sont toujours de ") + lesPV);
                }
            }
            else if (reponse == Zelda.getNomAttackUltime())
            {
                int NumeroRandom = randomNumber();
                int attaqueAvecRandom;

                attaqueAvecRandom = Zelda.Attaquer(Zelda.getNomAttackUltime(), Zelda.getDegatsAttackUltime(), NumeroRandom, Loup);

                char lesPV[1024];
                sprintf(lesPV, "%d", Loup.getPV());

                if (NumeroRandom < 3)
                {
                    Afficher(std::string("Votre attaque reussie, ses PV ne sont plus que de ") + lesPV);
                }
                else
                {
                   Afficher(std::string("Dommage votre attaque echoue, les points de vie de ") + Loup.getNom() + std::string(" sont toujours de ") + lesPV);
                }
            }
            else
            {
                Afficher("Veuillez saisir un nom d'attaque correct");
            }

            int NumeroRandom = randomNumber();

            if (Loup.getPV() !=0)
                {
                    if (NumeroRandom <=10)
                    {
                        if (NumeroRandom < 6)
                        {
                            if (NumeroRandom < 3)
                            {
                                int lesPremiersPV = Zelda.getPV();
                                int attaqueLoup;
                                attaqueLoup = Loup.Attaquer(Loup.getNomAttackUltime(), Loup.getDegatsAttackUltime(), randomNumber(), Zelda);

                                char lesPV[1024];
                                sprintf(lesPV, "%d", Zelda.getPV());

                                if (lesPremiersPV == Zelda.getPV())
                                {
                                    Afficher(std::string("Le loup vous attaque avec ") + Loup.getNomAttackUltime() + std::string(" mais vous esquivez, vos PV restent a :") + lesPV + std::string("PV"));
                                }
                                else
                                {
                                    Afficher(std::string ("Le Loup vous attaque a son tour avec ") + Loup.getNomAttackUltime() + std::string( " il vous reste : ") + lesPV + std::string ("PV"));

                                }


                            }
                            else
                            {
                                int lesPremiersPV = Zelda.getPV();
                                int attaqueLoup;
                                attaqueLoup = Loup.Attaquer(Loup.getNomAttack2(), Loup.getDegatsAttack2(), randomNumber(), Zelda);

                                char lesPV[1024];
                                sprintf(lesPV, "%d", Zelda.getPV());

                                if (lesPremiersPV == Zelda.getPV())
                                {
                                    Afficher(std::string("Le loup vous attaque avec ") + Loup.getNomAttack2() + std::string(" mais vous esquivez, vos PV restent a :") + lesPV + std::string("PV"));
                                }
                                else
                                {
                                    Afficher(std::string ("Le Loup vous attaque a son tour avec ") + Loup.getNomAttack2() + std::string( " il vous reste : ") + lesPV + std::string ("PV"));

                                }

                            }
                        }
                        else
                        {
                            int lesPremiersPV = Zelda.getPV();
                            int attaqueLoup;
                            attaqueLoup = Loup.Attaquer(Loup.getNomAttack1(), Loup.getDegatsAttack1(), randomNumber(), Zelda);

                            char lesPV[1024];
                            sprintf(lesPV, "%d", Zelda.getPV());

                                if (lesPremiersPV == Zelda.getPV())
                                {
                                    Afficher(std::string("Le loup vous attaque avec ") + Loup.getNomAttack1() + std::string(" mais vous esquivez, vos PV restent a :") + lesPV + std::string("PV"));
                                }
                                else
                                {
                                    Afficher(std::string ("Le Loup vous attaque a son tour avec ") + Loup.getNomAttack1() + std::string( " il vous reste : ") + lesPV + std::string ("PV"));

                                }
                        }
                    }


                }

        } while ((Loup.getPV()!=0) && (Zelda.getPV()!=0));

        if (Loup.getPV()<= 0)
        {
            PlaySound(NULL, 0, 0);
            PlaySound("zelda_victory.wav", NULL, SND_SYNC);
            PlaySound("zelda_theme.wav", NULL, SND_ASYNC);

            //Si victoire du combat contre les loups
            Scenario("scenario\\victoire_loups.txt");
        }
        else if (Zelda.getPV() <= 0)
        {
            PlaySound(NULL, 0, 0);
            PlaySound("zelda_loose.wav", NULL, SND_SYNC);
            PlaySound("zelda_theme.wav", NULL, SND_ASYNC);

            //Si défaite du combat contre les loups
            Scenario("scenario\\defaite_loups.txt");
        }



}

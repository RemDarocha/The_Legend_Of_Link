# ifndef _PERSONNAGE_H
# define _PERSONNAGE_H
# include<string>

namespace Personnages
{
    class Personnage
    {
    public :
        Personnage(
                  std::string nom,
                  std::string attaque1,
                  std::string attaque2,
                  std::string attaqueUltime,
                  int degatsAttaque1,
                  int degatsAttaque2,
                  int degatsAttaqueUltime,
                  int pointsDeVie


                  );

        int Attaquer(std::string attaque, int degats, int numRandom, Personnage & persoVise) const;
        int Subir(int degats);
        bool EstUnNomValide(std::string attaque) const;

        int getDegatsAttack1() const;
        int getDegatsAttack2() const;
        int getDegatsAttackUltime() const;
        int getPV() const;
        std::string getNom() const;
        std::string getNomAttack1() const;
        std::string getNomAttack2() const;
        std::string getNomAttackUltime() const;


    private :

        int degatsAttaque1, degatsAttaque2,degatsAttaqueUltime, pointsDeVie;
        std::string nom, attaque1, attaque2, attaqueUltime;

    };

}

#endif // _PERSONNAGE_H


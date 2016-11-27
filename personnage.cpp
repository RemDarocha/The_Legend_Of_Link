# include "personnage.h"
# include "randomNumber.h"

# include<iostream>
# include<string>

using namespace std;

namespace Personnages
{

    Personnage::Personnage(
                          std::string nom,
                          std::string attaque1,
                          std::string attaque2,
                          std::string attaqueUltime,
                          int degatsAttaque1,
                          int degatsAttaque2,
                          int degatsAttaqueUltime,
                          int pointsDeVie
                          )
    {
      this -> nom = nom;
      this -> attaque1 = attaque1;
      this -> attaque2 = attaque2;
      this -> attaqueUltime = attaqueUltime;
      this -> degatsAttaque1 = degatsAttaque1;
      this -> degatsAttaque2 = degatsAttaque2;
      this -> degatsAttaqueUltime = degatsAttaqueUltime;
      this -> pointsDeVie = pointsDeVie;
    }

    int Personnage::getDegatsAttack1() const
    {
    return degatsAttaque1;
    }
    int Personnage::getDegatsAttack2() const
    {
      return degatsAttaque2;
    }
    int Personnage::getDegatsAttackUltime() const
    {
      return degatsAttaqueUltime;
    }
    int Personnage::getPV() const
    {
      return pointsDeVie;
    }


    int Personnage::Subir(int degats)
    {

        if (degats >= pointsDeVie)
        {
            pointsDeVie = 0;
        }
        else
        {
            pointsDeVie = pointsDeVie - degats;
        }
        return pointsDeVie;
    }


    std::string Personnage::getNom() const
    {
      return nom;
    }
    std::string Personnage::getNomAttack1() const
    {
      return attaque1;
    }
    std::string Personnage::getNomAttack2() const
    {
      return attaque2;
    }
    std::string Personnage::getNomAttackUltime() const
    {
      return attaqueUltime;
    }



    bool Personnage::EstUnNomValide(std::string attaque) const
    {
        return (attaque == getNomAttack1() || attaque == getNomAttack2() || attaque == getNomAttackUltime());

    }

    int Personnage::Attaquer(string attaque, int degats, int numRandom, Personnage & persoVise) const
    {
        if (numRandom < 9 && attaque == getNomAttack1())
        {
            persoVise.Subir(degats);
            return degats;
        }
        else if (numRandom < 6 && attaque == getNomAttack2())
        {
            persoVise.Subir(degats);
            return degats;
        }
        else if (numRandom < 3 && attaque == getNomAttackUltime())
        {
            persoVise.Subir(degats);
            return degats;
        }
        else
        {
            return 0;

        }
    }
}




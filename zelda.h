# ifndef _ZELDA_H
# define _ZELDA_H
# include<string>

namespace zelda
{
    class Zelda
    {
    public :
        Zelda(
              //int bouleDeFeuID,
              //int eclairID,
              //int cataclysmID,
              string bouleDeFeu ="Boule de feu",
              string eclair = "Eclair",
              string cataclysm = "Cataclysm"
              int degatBouleDeFeu,
              int degatEclair,
              int degatCataclysm

              );

        void Attaquer(string attaque) const;

    private :

        int degatBouleDeFeu, degatEclair,degatCataclysm;
        string bouleDeFeu, eclair, cataclysm;

    };

}

#endif // _ZELDA_H

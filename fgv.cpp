#include <iostream>
#include <fstream>
#include <cstring>
#include "fgvheader.h"

//KÉSZ

Sztring::Sztring(char const *szoveg)
{
    hossz = strlen(szoveg);
    //adat = new char[50];
    strcpy(adat, szoveg);
}
//KÉSZ
Sztring::Sztring(Sztring const & orig)
{
    hossz = orig.getHossz();
    //adat = new char[50];
    strcpy(adat, orig.adat);
}

//KÉSZ
Sztring& Sztring::operator=(Sztring const & orig)
{
    if (this != &orig)
    {
        strcpy(adat, orig.adat);
    }
    /*if (this != &orig)
    {
        delete[] adat;
        hossz = orig.hossz;
        adat = new char[hossz+1];
        strcpy(adat, orig.adat);
    }*/
    return *this;
}
//KÉSZ
size_t Sztring:: size() const
{
    return hossz;
}
//KÉSZ
char const & Sztring::operator[] (size_t idx) const
{
    return adat[idx];
}

//KÉSZ
Sztring Sztring::operator+(Sztring const & rhs) const
{
    Sztring uj;
    //delete[] uj.adat;
    uj.hossz = this->hossz + rhs.hossz;
    //uj.adat = new char[uj.hossz + 1];
    strcpy(uj.adat, this->adat);
    strcat(uj.adat, rhs.adat);
    return uj;
}
bool Sztring:: operator== (Sztring & rhs) const{
     return strcmp(this->adat,rhs.getAdat()) == 0;
}
void Sztring::setAdat(char * uj)
{
    strcpy(adat, uj);
    //delete[] this->adat;
    //this->adat =uj;
}
//KÉSZ
std::ostream& operator<<(std::ostream & os, const Sztring & s)
{
    for (size_t i = 0; i != s.size(); ++i)
        os << s[i];

    return os;
}
//KÉSZ
std::istream& operator>>(std::istream & is, Sztring & s)
{
    /*char * beolvas = new char[20];
    is>>beolvas;
    s.setHossz(strlen(beolvas));
    s.setAdat(beolvas);*/
    char * beolvas = new char[20];
    is>>beolvas;
    //std::cout<<beolvas;
    s.setAdat(beolvas);
    //is >> s.getAdat();
    s.setHossz(strlen(s.getAdat()));
    delete[] beolvas;
   // s.setHossz(i);

    return is;
}//KÉSZ
Lista::Lista()
{
    this->meret = 0;
    this->tomb = nullptr;

}
//KÉSZ
Lista::~Lista()
{
    for (size_t s = 0; s <this->meret; s++) delete this->tomb[s];
    delete [] tomb;
}

//KÉSZ
void Szemely::kiir(std::ostream& os)
{
    os<<this->getNev()<<std::endl;
    os<<this->getVnev()<<std::endl;
    os<<this->getKnev()<<std::endl;
    os<<this->getTipus()<<std::endl;
    os<<this->getIszam()<<std::endl;
    os<<this->getVaros()<<std::endl;
    os<<this->getUtca()<<std::endl;
    os<<this->getHszam()<<std::endl;
    os<<this->getMszam()<<std::endl;
    os<<this->getPszam()<<std::endl;
    os<<std::endl;


};
//KÉSZ
void Ceg::kiir(std::ostream& os)
{
    os<<this->getTipus()<<std::endl;
    os<<this->getNev()<<std::endl;
    os<<this->getIszam()<<std::endl;
    os<<this->getVaros()<<std::endl;
    os<<this->getUtca()<<std::endl;
    os<<this->getHszam()<<std::endl;
    os<<this->getMszam()<<std::endl;
    os<<this->getAlapitas()<<std::endl;
    os<<this->getDszam()<<std::endl;
    os<<std::endl;


};
/*
* kiir egy adatot egy os re
* a kiir fgv-t használja mi az adat virtuális tagja, és így az adat* típusú heterogén kollekció adatait különbözõ módon írja ki
*/
std::ostream& operator<< (std::ostream& os, Adat* kiirando)
{

    kiirando->kiir(os);

    return os;

}
std:: ostream& operator<< (std::ostream& os, Lista& listam)
{
    if (!listam.getMeret()) os<<"Nincs egy nevjegye sem"<<std::endl;
    for (size_t s = 0; s< listam.getMeret(); s++)
    {
        os<<listam[s];
    }

    return os;
};

Adat* Lista:: operator[] (size_t i)
{
    return this->tomb[i];
}

/*
* a listához új rekordot ad, ezt használja a fõmenu ujrekord függvénye
*KESZ
*/
void Lista::ujrekord (Adat* hozzaad)
{
    Adat** uj = new Adat*[this->meret+1];

    if (this->meret != 0){
        for (size_t s = 0; s < this->meret; s++){
            uj[s]= this->tomb[s];
        }
    }

    uj[this->meret] = hozzaad;
    delete[] this->tomb;
    this->tomb = uj;
    this->meret = this->meret +1;
   /*if (this->meret == 0){
    uj[0]= hozzaad;

    this->tomb = uj;
   } else {
       for (size_t s = 0; s < this->meret; s++){
        uj[s]= this->tomb[s];
         //delete this->tomb[s];
        }


       }

        uj[this->meret] = hozzaad;
        delete[] this->tomb;
        this->tomb = uj;

   this->meret = this->meret +1;*/

}

void Lista::torol(Sztring& torolni)
{
    for (size_t s = 0; s < this->meret; s++) {
        if (this->tomb[s]->getNev()== torolni) {
            if (this->meret>1){
                Adat** uj = new Adat*[this->meret-1];
                size_t i = 0;
                for (size_t t = 0; t < this->meret; t++){
                    if (s == t){
                        delete this->tomb[t];
                    } else {
                        uj[i] = this->tomb[t];
                        i++;
                    }
                }
                delete[] this->tomb;
                this->tomb = uj;
            } else {
                delete this->tomb[0];
                delete[] this->tomb;
                this->tomb = nullptr;
            }
            this->meret--;
        }
    }

    /*try{

 // vegiggyaloglok a tombon
         for (size_t s =0; s < this->meret; s++){
// megnézem, hogy egyezik-e a nev
          if ( this->tomb[s]->getNev()== torolni){
            // ha nem egy elemu, akkor uj tombot kell neki foglalnom
            if (this->meret>1){
                    // lefoglalom az uj tombot eggyel kisebbre
                    Adat** uj = new Adat*[this->meret-1];
                        // egyesevel attoltom a tagokat az uj tombbe
                        for (size_t t = 0; t < this->meret; t++){

                            if (s == t){
                                delete this->tomb[t];
                                 t++;
                            }  // kivéve amit torolni akarok
                            uj[t] = this->tomb[t];
                            delete[] this->tomb;
                        }
                        // torlom a regi tombot
                       delete[] this->tomb;
                        // az uj tombot berakom a listaba
                        this->tomb = uj;

            }  else {

               // delete this->tomb[0];
              delete[] this->tomb;
              this->tomb = nullptr;
            }
            this->meret--;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl<<""<<std::endl;

    }*/



}

/*
* Indexelõ operátor a Lista használatához
KÉSZ
*/
// megadott nev alajan keres a listán, visszaadja az elso talalatot vagy hibat dob
void Lista::keres (Sztring& keresettneve){
	// vegiggyaloglok a tombon
         for (size_t s =0; s < this->meret; s++){
// megnézem, hogy egyezik-e a nev
          //if ( this->tomb[s]->getNev()== keresettneve )
          std::cout<<tomb[s]<<std::endl;


		}
}
void kereses(Lista& listam){
    try {
    if (listam.getMeret() == 0) throw std::exception();
    Sztring s1;
    std::cout<<"Milyen rekordot keres? Adja meg a nevet!"<<std::endl;
    std::cin>>s1;
    listam.keres(s1);

    }  catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl<<"nulla elemu lista"<<std::endl;

    }

}

/*
* egy bizonyos nevû adatot torol a listáról
* KÉSZ
*/
void torles(Lista& listam)
{
    try {
    if (listam.getMeret() == 0) throw std::exception();
    Sztring s1;
    /*
    int i1;
    std::cout<<"Ceget(0) vagy szemely (1) szeretne torolni?"<<std::endl;
    std::cin>>i1;
    */
    std::cout<<"Milyen rekordot szeretne torolni? Ceg eseten adja meg a nevet, szemely esetén a becenevet"<<std::endl;
    std::cin>>s1;
    listam.torol(s1);
    std::cout<<"Rekord torolve"<<std::endl;
    }  catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl<<"torles sikertelen"<<std::endl;

    }




}


/*
*a fõmenü egy almenüje, kezeli a felhasználói bemenetet, és a megfelelõ függvények meghívásával létrehoz egy új bejegyzést a listában
* KÉSZ
*/

void ujrekord(Lista& listam)
{
    int i1;
    Sztring s1,s2,s3,s4;
    Adat* hozzaad = nullptr;
    std::cout<<"Ceget (0) vagy szemelyt (1) szeretne felvenni?"<<std::endl;
    std::cin>>i1;
    if (i1 == 1)
    {
        hozzaad = new Szemely;
    } else {
        hozzaad = new Ceg;
    }
    hozzaad->setTipus(i1);
 if (i1 == 1)
    {
        std::cout<<"Vezeteknev?"<<std::endl;
        std::cin>>s1;
        hozzaad->setVnev(s1);

        std::cout<<"Keresztnev?"<<std::endl;
        std::cin>>s2;
        hozzaad->setKnev(s2);

        std::cout<<"Becenev?"<<std::endl;
        std::cin>>s3;
        hozzaad->setNev(s3);


        std::cout<<"Privat telefonszam?"<<std::endl;
        std::cin>>i1;
        hozzaad->setPszam(i1);

    }
    else
    {
        std::cout<<"Nev?"<<std::endl;
        std::cin>>s1;
        hozzaad->setNev(s1);

        std::cout<<"Alapitas eve?"<<std::endl;
        std::cin>>i1;
        hozzaad->setAlapitas(i1);

        std::cout<<"Dolgozok szama?"<<std::endl;
        std::cin>>i1;
        hozzaad->setDszam(i1);

    }



    std::cout<<"Iranyitoszam?"<<std::endl;
    std::cin>>i1;
    hozzaad->setIszam(i1);

    std::cout<<"Varos?"<<std::endl;
    std::cin>>s1;
    hozzaad->setVaros(s1);

    std::cout<<"Utca?"<<std::endl;
    std::cin>>s4;
    hozzaad->setUtca(s4);

    std::cout<<"Hazszam?"<<std::endl;
    std::cin>>i1;
    hozzaad->setHszam(i1);

    std::cout<<"Telefonszam?"<<std::endl;
    std::cin>>i1;
    hozzaad->setMszam(i1);


// ha a tipus 0, a cégekhez tartozó infókat kérjük be, ha 1 a személyekhez


    listam.ujrekord(hozzaad);
    std::cout<<"Uj nevjegy letrehozva"<<std::endl;

}


#include <iostream>
#include <fstream>
#include <cstring>
#include "fgvheader.h"

       Sztring::Sztring(char const *szoveg) {
            hossz = strlen(szoveg);
            adat = new char[hossz+1];
            strcpy(adat, szoveg);
        }


        Sztring::~Sztring() {
            delete[] adat;
        }

        Sztring::Sztring(Sztring const & orig) {
            hossz = orig.hossz;
            adat = new char[hossz+1];
            strcpy(adat, orig.adat);
        }


        Sztring& Sztring::operator=(Sztring const & orig) {
            if (this != &orig) {
                delete[] adat;
                hossz = orig.hossz;
                adat = new char[hossz+1];
                strcpy(adat, orig.adat);
            }
            return *this;
        }

        size_t Sztring:: size() const {
            return hossz;
        }

       char const & Sztring::operator[] (size_t idx) const {
            return adat[idx];
        }

        char & Sztring::operator[] (size_t idx) {
            return adat[idx];
        }


        Sztring Sztring::operator+(Sztring const & rhs) const {
            Sztring uj;
            delete[] uj.adat;
            uj.hossz = this->hossz + rhs.hossz;
            uj.adat = new char[uj.hossz + 1];
            strcpy(uj.adat, this->adat);
            strcat(uj.adat, rhs.adat);
            return uj;
        }


std::ostream& operator<<(std::ostream & os, const Sztring & s) {
    for (size_t i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}



 void Szemely::kiir(std::ostream& os){
    os<<this->getTipus()<<std::endl;
    os<<this->getNev()<<std::endl;
    os<<this->getIszam()<<std::endl;
    os<<this->getVaros()<<std::endl;
    os<<this->getUtca()<<std::endl;
    os<<this->getHszam()<<std::endl;
    os<<this->getMszam()<<std::endl;
    os<<this->getBnev()<<std::endl;
	os<<this->getPszam()<<std::endl;
	os<<std::endl;

};
 void Ceg::kiir(std::ostream& os){
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
std::ostream& operator<< (std::ostream& os, Adat* kiirando){

 kiirando->kiir(os);
 return os;

 }

/*
* a listához új rekordot ad, ezt használja a fõmenu ujrekord függvénye
*/

void Lista::ujrekord (Adat* hozzaad){
	 Adat* uj = new Adat[++meret];
	 for (size_t s =0; s <= meret; s++){
		 uj[s] = this[s];
	 }
	 uj[meret] = hozzaad;
	 Adat* temp = this->eleje;
	 delete[] temp;
	 this->eleje = uj;

	}

void Lista::torol(Sztring torolni){
};

/*
* Indexelõ operátor a Lista használatához
*/
Adat* Lista:: operator[] (size_t i) {
	return this->eleje[i];
	}
void Lista ::torol (Sztring torolni)
/*
* beolvassa az adatokat a backupfile.txt fájlból és eltárolja õket egy Lista-ban
*/
void Lista::beolvas(ifstream backupfile ) {
    backupfile.open ("backup.txt");
    if (!backupfile) {
    std::cerr << "Nincs mentett telefonkönyved!";
    } else {
        while (getline(backupfile,temp)) {
			//becenévvel hozom  létre az új személyt
               Adat ujarc = new Adat(temp);
                // soronként beolvasom az attribútumokat
				getline(backupfile,ujarc->nev.vezeteknev);

    }
    backupfile.close();
  }
}

/*
* egy bizonyos nevû adatot torol a listáról
* KÉSZ
*/
void torles(Lista& listam){
	Sztring s1;
	std::cout<<"Milyen rekordot szeretne torolni? Adja meg a szemelyhez tartozo becvenevet!"<<std::cout;
	std::cin>>s1;
	if(listam.torol(s1)) std::cout<<"rekord torolve"<<std::endl;
	else throw (std::exeption("nincs ilyen rekord"));


}
/*
* egy std::ostream típusú objektumra írja a lista tartalmát
* KÉSZ
*/
void Lista::listazas(std::ostream& os){
 	for (size_t size = 0; size<= this->meret ; size++){
		os<<this->eleje[size];

		}

}
/*
*a fõmenü egy almenüje, kezeli a felhasználói bemenetet, és a megfelelõ függvények meghívásával létrehoz egy új bejegyzést a listában
* KÉSZ
*/

void ujrekord(Lista& listam) {
	int i1;
	std::cout<<"Ceget (0) vagy szemelyt (1) szeretne felvenni?"<<std::endl;
	std::cin>>i1;
	Sztring s1;
	std::cout<<"Nev?"<<std::endl;
	std::cin>>s1;
	if (i1){
		Adat* hozzaad = new Szemely(s1);

	} else {
		Adat* hozzaad = new Ceg(s1);
		}
	hozzad->setTipus(i1);

	std::cout<<<<"Iranyitoszam?"<<std::endl;
	std::cin>>i1;
	hozzaad->setIszam(i1);
	std::cout<<"Varos?"<<std::endl;
	std::cin>>s1;
	hozzaad->setVaros(s1);
	std::cout<<"Utca?"<<std::endl;
	std::cin>>s1;
	hozzaad->setUtca(s1);
	std::cout<<"Hazszam?"<<std::endl;
	std::cin>>i1;
	hozzaad->setHszam(i1);

	listam.ujrekord(hozzaad);

	std::cout<<"Uj nevjegy letrehozva"<<std:endl<<listam[vege]<<std:endl;
}

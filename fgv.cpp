#include <iostream>
#include <fstream>
#include <cstring>
#include "fgvheader.h"

       Sztring::Sztring(char const *szoveg = "") {
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


        Sztring::Sztring & operator=(Sztring const & orig) {
            if (this != &orig) {
                delete[] adat;
                hossz = orig.hossz;
                adat = new char[hossz+1];
                strcpy(adat, orig.adat);
            }
            return *this;
        }

        Sztring::size_t size() const {
            return hossz;
        }

       Sztring:: char const & operator[] (size_t idx) const {
            return adat[idx];
        }

        Sztring::char & operator[] (size_t idx) {
            return adat[idx];
        }


        Sztring::Sztring operator+(Sztring const & rhs) const {
            Sztring uj;
            delete[] uj.adat;
            uj.hossz = this->hossz + rhs.hossz;
            uj.adat = new char[uj.hossz + 1];
            strcpy(uj.adat, this->adat);
            strcat(uj.adat, rhs.adat);
            return uj;
        }


std::ostream & operator<<(std::ostream & os, const Sztring & s) {
    for (size_t i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}



Szemely:: void kiir(std::ostream& os){
    os<<this->nev<<std::endl();
    os<<this->iranyitoszam<<std::endl();
    os<<this->varos<<std::endl();
    os<<this->utca<<std::endl();
    os<<this->hazszam<<std::endl();
    os<<this->munkahelyiszam<<std::endl();
    os<<this->becenev<<std::endl();
	os<<this->privatszam<<std::endl();string

};
Ceg:: void kiir(std::ostream& os){
    os<<this->nev<<std::endl();
    os<<this->iranyitoszam<<std::endl();
    os<<this->varos<<std::endl();
    os<<this->utca<<std::endl();
    os<<this->hazszam<<std::endl();
    os<<this->munkahelyiszam<<std::endl();
    os<<this->alapitasiev<<std::endl();
	os<<this->dolgozokszama<<std::endl();

};

Szemely:: ~Szemely(){
	nev.~Sztring();
    varos.~Sztring();
    utca.~Sztring();
    becenev.~Sztring();

}
Ceg:: ~Ceg(){
	nev.~Sztring();
    varos.~Sztring();
    utca.~Sztring();
}


Lista::size_t ujrekord (Adat* hozzad){
	 Adat* uj = new Adat[++meret];
	 for (size_t s =0, s< meret; s++){
		 uj[s] = this[s];
	 }
	 uj[meret] = hozzaad;
	 Adat* temp = this->eleje;
	 delete[] temp;
	 this->eleje = uj;
	 return this-> meret;
	}

/*
* Indexelõ operátor a Lista használatához
*/
Lista:: Adat* operator[] (size_t i) {
	return this->eleje[i];
	}
Lista :: void torol (Sztring torolni)
/*
* beolvassa az adatokat a backupfile.txt fájlból és eltárolja õket egy Lista-ban
*/
 Lista::void beolvas(ifstream backupfile ) {
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
*
*/

 Lista::void mentes(ofstream backupfile){
	 backupfile.open("backup.txt");
	 for( size_t i=0; i<= this->meret;i++){

	 }

	 }


 /*
* kiir egy adatot egy os re
*/
std::ostream& operator<< (std::ostream& os, Adat* kiirando){

 kiirando.kiir(os);
 return os;

 }
/*
* kiirja egy os-re a megadott szemely* attribútumait
*/

 void kereses(Lista listam){

}
/*
*
*/
void torles(Lista listam){
	Sztring s1;
	std::cout<<"Milyen rekordot szeretne torolni? Adja meg a szemelyhez tartozo becvenevet!"<<std::cout;
	std::cin>>s1;
	if(listam.torol(s1)) std::cout<<"rekord torolve"<<std::endl;
	else throw (std::exeption("nincs ilyen rekord"));


}
/*
*
*/
void listazas(Lista listam){

}
/*
*a fõmenü egy almenüje, kezeli a felhasználói bemenetet, és a megfelelõ függvények meghívásával létrehoz egy új bejegyzést a listában
* KÉSZ
*/

void ujrekord(Lista listam) {
	std::cout<<"Mi legyen az uj szemely beceneve?"<<std::endl;
	Sztring s1;
	std::cin>>s1;
	Adat* hozzaad = new Adat(s1);
	size_t vege = listam.ujrekord(hozzaad);

	Sztring s2;
	std::cout<<"Mi legyen az uj szemely vezetekneve?"<<std::endl;
	std::cin>>s1;
	std::cout<<"Mi legyen az uj szemely keresztneve?"<<std::endl;
	std::cin>>s2;

	setNev.listam[vege](s1,s2);

	int i1, i2;
	std::cout<<"Mi legyen az uj szemely cime?"<<std::endl<<"Iranyitoszam?"<<std::endl;
	std::cin>>i1;
	std::cout<<"Varos?"<<std::endl;
	std::cin>>s1;
	std::cout<<"Utca?"<<std::endl;
	std::cin>>s2;
	std::cout<<"Hazszam?"<<std::endl;
	std::cin>>i2;

	setCim.listam[vege](i1, s1,s2,i2);

	std::cout<<"Uj nevjegy letrehozva"<<std:endl<<listam[vege]<<std:endl;
}

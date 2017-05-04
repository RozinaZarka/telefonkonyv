#ifndef FGVHEADER_H_INCLUDED
#define FGVHEADER_H_INCLUDED
#include <fstream>
#include <iostream>
#include <cstring>


class Sztring {
    private:
        size_t hossz;   // lezáró nulla nélkül
        char* adat;     // lezáró nullával együtt

    public:
        Sztring(char const *szoveg = "");
        ~Sztring() ;
        Sztring(Sztring const & orig) ;
        Sztring & operator=(Sztring const & orig);
        size_t size() const ;
        char const & operator[] (size_t idx) const ;
        char & operator[] (size_t idx) ;
        Sztring operator+(Sztring const & rhs) const;
};

std::ostream & operator<<(std::ostream & os, const Sztring & s);


class Adat {
  Sztring nev;
  Sztring varos;
  Sztring utca;
  int hazszam;
  int iranyitoszam;
  int munkahelyiszam;

public:
    Adat(Sztring s1 = "",Sztring s2 = "",Sztring s3 = "",int i1 =0,int i2 =0,int i3 =3): nev(s1), varos(s2), utca(s3), hazszam(i1), iranyitoszam(i2), munkahelyiszam(i3) {}
    Sztring getVaros() { return this->varos; }
    Sztring getUtca() { return this->utca; }
    Sztring getNev() { return this->nev; }
    int getIszam() { return this->iranyitoszam; }
    int getHszam() { return this->hazszam; }

	void setNev(Sztring s) {this->nev = s;}
	void setVaros(Sztring s) {this->varos = s;}
	void setUtca(Sztring s) {this->utca = s;}
	void setHszam(int i) {this->hazszam = i;}
	void setIszam(int i) {this->iranyitoszam = i;}
	void setMszam(int i) {this->munkahelyiszam = i;}
    virtual void kiir(std::ostream& os) =0;
	virtual ~Adat()=0;


  };

 class Szemely: public Adat{
	 Sztring becenev;
	 int privatszam;

	 public:
     virtual void kiir(std::ostream& os);
 };

 class Ceg : public Adat{
	 int alapitasiev;
	 int dolgozokszama;
public:
    virtual void kiir(std::ostream& os);

};

class Lista {
  Adat* eleje;
  size_t meret;
public:
	Lista();
	void beolvas (std::ifstream backupfile);
	void mentes (std::ofstream backupfile);
	void torol(Sztring torolni);
	size_t getMeret() {return this->meret;}
	size_t ujrekord (Adat* hozzad);
	~Lista();
	// viszaadja az új rekord indexét

  };


std::ostream& operator<< (std::ostream& os, Adat& kiirando);




void ujrekord(Lista listam);

void kereses( Lista listam);

void torles(Lista listam);

void listazas(Lista listam);




#endif // FGVHEADER_H_INCLUDED

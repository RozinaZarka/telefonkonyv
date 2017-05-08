#ifndef FGVHEADER_H_INCLUDED
#define FGVHEADER_H_INCLUDED
#include <fstream>
#include <iostream>
#include <cstring>


class Sztring
{
private:
    size_t hossz;   // lezáró nulla nélkül
    char* adat;     // lezáró nullával együtt

public:
    Sztring(char const *szoveg = "");
    ~Sztring()
    {
        delete[] adat;
    }
    char* getAdat()
    {
        return this->adat;
    }
    size_t getHossz() const
    {
        return this->hossz;
    }

    void setHossz(size_t s)
    {
        this->hossz =s;
    }
    void setAdat(char * uj);
    Sztring(Sztring const & orig) ;
    Sztring & operator=(Sztring const & orig);
    size_t size() const ;
    char const & operator[] (size_t idx) const ;
    char & operator[] (size_t idx)
    {
        return adat[idx];
    }
    Sztring operator+(Sztring const & rhs) const;
    bool operator== (Sztring & rhs) const;
};

std::ostream & operator<<(std::ostream & os, const Sztring & s);
std::istream & operator>>(std::istream & os, const Sztring & s);



class Adat
{
    Sztring nev;
    int tipus; // 0 vagy 1 : Személy vagy cég
    Sztring varos;
    Sztring utca;
    int hazszam;
    int iranyitoszam;
    int munkahelyiszam;

public:

    Sztring getVaros()
    {
        return this->varos;
    }
    Sztring getUtca()
    {
        return this->utca;
    }


    int getIszam()
    {
        return this->iranyitoszam;
    }
    int getHszam()
    {
        return this->hazszam;
    }
    int getTipus()
    {
        return this->tipus;
    }
    int getMszam()
    {
        return this->munkahelyiszam;
    }

    void setTipus(int i)
    {
        this->tipus = i;
    }

    void setVaros(Sztring s)
    {
        this->varos = s;
    }
    void setUtca(Sztring s)
    {
        this->utca = s;
    }
    void setHszam(int i)
    {
        this->hazszam = i;
    }
    void setIszam(int i)
    {
        this->iranyitoszam = i;
    }
    void setMszam(int i)
    {
        this->munkahelyiszam = i;
    }
    virtual void kiir(std::ostream& os) {};
    virtual void setDszam(int i) {} ;
    virtual int getDszam() {return 0 ;}
    virtual void setAlapitas(int i) {};
    virtual int getAlapitas() {return 0 ;}
    virtual void setPszam(int i) {};
    virtual int getPszam() {return 0 ;}
    virtual void setVnev(Sztring s) {} ;
    virtual Sztring getVnev() {return 0 ;}

    virtual void setKnev(Sztring s) {} ;
    virtual Sztring getKev() {return 0 ;}
    void setNev(Sztring s)
    {
        this->nev = s;
    }
    Sztring getNev()
    {
        return this->nev;
    }
    virtual ~Adat() {};



};

class Szemely: public Adat
{
    Sztring vezeteknev;
    Sztring keresztnev;
    int privatszam;

public:

    void setPszam(int i)
    {
        this->privatszam = i;
    }
    int getPszam()
    {
        return this->privatszam;
    }

    void setVnev(Sztring s)
    {
        this->vezeteknev = s;
    }
    Sztring getVnev()
    {
        return this->vezeteknev;
    }
     void setKnev(Sztring s)
    {
        this->keresztnev = s;
    }
    Sztring getKnev()
    {
        return this->keresztnev;
    }
    void kiir(std::ostream& os);
    ~Szemely() {};
};

class Ceg : public Adat
{

    int alapitasiev;
    int dolgozokszama;
public:

    void setDszam(int i)
    {
        this->dolgozokszama = i;
    }
    int getDszam()
    {
        return this->dolgozokszama;
    }
    void setAlapitas(int i)
    {
        this->alapitasiev = i;
    }
    int getAlapitas()
    {
        return this->alapitasiev;
    }

    void kiir(std::ostream& os);
    ~Ceg() {};

};

class Lista
{
    Adat** tomb;
    size_t meret;
public:
    Lista();
    void beolvas (std::ifstream backupfile);
    void torol(Sztring& torolni);
    size_t getMeret()
    {
        return this->meret;
    }
    Adat** getTomb ()
    {
        return this->tomb;
    }
    // viszaadja az új rekord indexét
    void ujrekord (Adat* hozzad);
    Adat* operator[] (size_t i);
    void keres (Sztring& keresettneve);
    //void beolvas(std::ifstream backupfile )
    ~Lista();


};


std::ostream& operator<< (std::ostream& os, Adat* kiirando);
std:: ostream& operator<< (std::ostream& os, Lista& lista);

void ujrekord(Lista& listam);

void torles(Lista& listam);
void kereses(Lista& listam);






#endif // FGVHEADER_H_INCLUDED

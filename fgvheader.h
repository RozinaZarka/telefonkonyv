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
    void setHossz(size_t s)
    {
        this->hossz =s;
    }
    Sztring(Sztring const & orig) ;
    Sztring & operator=(Sztring const & orig);
    size_t size() const ;
    char const & operator[] (size_t idx) const ;
    char & operator[] (size_t idx)
    {
        return adat[idx];
    }
    Sztring operator+(Sztring const & rhs) const;
};

std::ostream & operator<<(std::ostream & os, const Sztring & s);
std::istream & operator>>(std::istream & os, const Sztring & s);



class Adat
{

    int tipus; // 0 vagy 1 : Személy vagy cég
    Sztring nev;
    Sztring varos;
    Sztring utca;
    int hazszam;
    int iranyitoszam;
    int munkahelyiszam;

public:
    Adat(Sztring s1 = "" ):nev(s1) {};
    Sztring getVaros()
    {
        return this->varos;
    }
    Sztring getUtca()
    {
        return this->utca;
    }
    Sztring getNev()
    {
        return this->nev;
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
    void setNev(Sztring s)
    {
        this->nev = s;
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
    virtual void kiir(std::ostream& os) =0;
    virtual void setDszam(int i) {} ;
    virtual int getDszam() {};
    virtual void setAlapitas(int i) {};
    virtual int getAlapitas() {} ;
    virtual void setPszam(int i) {};
    virtual int getPszam() {};
    virtual void setBnev(Sztring s) {} ;
    virtual Sztring getBnev() {};
    virtual ~Adat() {};



};

class Szemely: public Adat
{
    Sztring becenev;
    int privatszam;

public:
    Szemely(Sztring s1 = "" ):Adat(s1) {};
    void setPszam(int i)
    {
        this->privatszam = i;
    }
    int getPszam()
    {
        return this->privatszam;
    }
    void setBnev(Sztring s)
    {
        this->becenev = s;
    }
    Sztring getBnev()
    {
        return this->becenev;
    }
    void kiir(std::ostream& os);
    ~Szemely() {};
};

class Ceg : public Adat
{
    int alapitasiev;
    int dolgozokszama;
public:
    Ceg(Sztring s1 = "" ):Adat(s1) {};
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
    Adat** eleje;
    size_t meret;
public:
    Lista();
    void beolvas (std::ifstream backupfile);
    bool torol(Sztring torolni);
    size_t getMeret()
    {
        return this->meret;
    }
    Adat** getEleje ()
    {
        return this->eleje;
    }
    // viszaadja az új rekord indexét
    void ujrekord (Adat* hozzad);
    Adat* operator[] (size_t i);
    //void kiir (std::ostream& os);

    ~Lista();


};


std::ostream& operator<< (std::ostream& os, Adat* kiirando);
std:: ostream& operator<< (std::ostream& os, Lista& lista);

void ujrekord(Lista& listam);

void torles(Lista& listam);





#endif // FGVHEADER_H_INCLUDED

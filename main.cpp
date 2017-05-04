#include <iostream>
#include <fstream>
#include "fgvheader.h"
#include "fgv.cpp"


using namespace std;

int main()
{
    try{
    Lista listam;
    ifstream backupfile;
  //  listam.beolvas(backupfile);
    std::cout<< "Mit szeretnel tenni?"<<std::endl
    << "1.Uj nevjegy felvetele"<<std::endl
    << "2.Nevjegyek listazasa"<<std::endl
    << "3.Nevjegy törlese"<<std::endl
    << "4.Kereses"<<std::endl
    << "5.Kilepes"<<std::endl;

    int x;
    switch(x):
    case 1:
        ujrekord(listam);
        break;
    case 2:
        listazas(listam);
        break;
    case 3:
        torles(listam);
        break;
    case 4:
        kereses(listam);
        break;
    case 5:
        break;

    std::cout<<"Viszontlatasra"<std::endl;
    ofstream bpfile;
    listam.mentes(bpfile);

    }
  /*  catch {
    }
*/
    return 0;
}

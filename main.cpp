#include <iostream>
#include <fstream>
#include "fgvheader.h"
//#include "fgv.cpp"


using namespace std;

int main()
{

    Lista listam;
    std::ifstream backupfile;
  //  listam.beolvas(backupfile);
  int x;
    std::cout<< "Mit szeretnel tenni?"<<std::endl
    << "1.Uj nevjegy felvetele"<<std::endl
    << "2.Nevjegyek listazasa"<<std::endl
    << "3.Nevjegy törlese"<<std::endl
    << "4.Kilepes"<<std::endl;
std::cin>>x;

    switch(x){
    case 1:
        ujrekord(listam);
        break;
    case 2:
        listam.listazas(std::cout);
        break;
    case 3:
        torles(listam);
        break;
    case 4:
        break;
    }

    std::cout<<"Viszontlatasra"<<std::endl;
    std::ofstream bpfile;
    bpfile.open("backup.txt");
	listam.listazas(bpfile);

  /*  catch {
    }
*/
    return 0;
}

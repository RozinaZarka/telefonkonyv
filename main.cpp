#include <iostream>
#include <fstream>
#include <exception>
#include "memtrace.h"
#include "gtest_lite.h"
#include "fgvheader.h"



int main(int argc, char* argv[])
{
   try {// setbuf(stdout, 0);
    Lista listam;
   /* std::ifstream backupfile;
    backupfile.open("backupfile.txt);
    listam.beolvas(backupfile);
    */
    char x = 'l';
    while (!(x == 'e' || x== 'E' || x == '\032') )
    {

        std::cout<< "Mit szeretnel tenni?"<<std::endl
                 << "(U) Uj nevjegy felvetele"<<std::endl
                 << "(L) Nevjegyek listazasa"<<std::endl
                 << "(K) Nevjegy keresese"<<std::endl
                 << "(T) Nevjegy torlese"<<std::endl
                 << "(E) Kilepes"<<std::endl;

        std::cin>>x;

        switch(x)
        {
        case 'U':
        case 'u':
            ujrekord(listam);
            break;
        case 'l':
        case 'L':
            std::cout<<listam;
            break;
        case 't':
        case 'T':
            torles(listam);
            break;
        case 'k':
        case 'K':
            kereses(listam);
            break;
        case 'e':
        case 'E':
            break;
        }

    }
    std::cout<<"Viszontlatasra"<<std::endl;

    std::ofstream bpfile;
    bpfile.open("backup.txt");
    std::cout<<"Viszontlatasra2"<<std::endl;
    bpfile<<listam;
    std::cout<<"Viszontlatasra3"<<std::endl;
    bpfile.close();
   std::cout<<"Viszontlatasra4"<<std::endl;
   } catch (std::exception& e){
       std::cerr<<e.what()<<"vegre megtudjuk mi a hiba";
   }
    return 0;
}

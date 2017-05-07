#include <iostream>
#include <fstream>
#include <exception>
#include "memtrace.h"
#include "gtest_lite.h"
#include "fgvheader.h"



int main()
{
   try {// setbuf(stdout, 0);
    Lista listam;
   /* std::ifstream backupfile;
    backupfile.open("backupfile.txt);
    listam.beolvas(backupfile);
    */
    char x = 'l';
    while (!(x == 'k' || x== 'K' || x == '\032') )
    {

        std::cout<< "Mit szeretnel tenni?"<<std::endl
                 << "(U) Uj nevjegy felvetele"<<std::endl
                 << "(L) Nevjegyek listazasa"<<std::endl
                 << "(T) Nevjegy torlese"<<std::endl
                 << "(K) Kilepes"<<std::endl;
                 std::cout.flush();
        std::cin>>x;

        switch(x)
        {
        case 'U':
        case 'u':
            ujrekord(listam);
            break;
        case 'l':
        case 'L':
            std::cout.flush();
            std::cout<<listam;
            break;
        case 't':
        case 'T':
            torles(listam);
            break;
        case 'k':
        case 'K':
            break;
        }

    }
    std::cout<<"Viszontlatasra"<<std::endl;
    std::cout.flush();
   /* std::ofstream bpfile;
    bpfile.open("backup.txt");
    bpfile<<listam;
    bpfile.close();
    */
   } catch (std::exception& e){
       std::cerr<<e.what()<<"vegre megtudjuk mi a hiba";
   }
    return 0;
}

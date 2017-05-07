#include <iostream>
#include <fstream>
#include "memtrace.h"
#include "gtest_lite.h"
#include "fgvheader.h"



int main()
{
    // setbuf(stdout, 0);
    Lista listam;
   /* std::ifstream backupfile;
    backupfile.open("backupfile.txt);
    listam.beolvas(backupfile);
    */
    char x = 'l';
    while (!(x == 'k' || x== 'K' || x == EOF) )
    {

        std::cout<< "Mit szeretnel tenni?"<<std::endl
                 << "Uj nevjegy felvetele (U)"<<std::endl
                 << "2.Nevjegyek listazasa (L)"<<std::endl
                 << "3.Nevjegy torlese"<<std::endl
                 << "4.Kilepes"<<std::endl;
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
    std::ofstream bpfile;
    bpfile.open("backup.txt");
    bpfile<<listam;
    bpfile.close();
    return 0;
}

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
    int x =1;
    while (x != -1 )
    {

        std::cout<< "Mit szeretnel tenni?"<<std::endl
                 << "1.Uj nevjegy felvetele"<<std::endl
                 << "2.Nevjegyek listazasa"<<std::endl
                 << "3.Nevjegy torlese"<<std::endl
                 << "4.Kilepes"<<std::endl;
                 std::cout.flush();
        std::cin>>x;

        switch(x)
        {
        case 1:
            ujrekord(listam);
            break;
        case 2:
            std::cout.flush();
            std::cout<<listam;
            break;
        case 3:
            torles(listam);
            break;
        case 4:
            x= -1;
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

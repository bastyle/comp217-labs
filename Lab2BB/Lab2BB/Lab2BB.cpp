// Lab2BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;
#include "RecursiveTOH.h"
#include "IterativeTOH.h"


/*void playHanoi(int numberDisksToMove, char originalPeg, char destinationPeg, char temporalPeg) {
    if(numberDisksToMove==1)
    {
        cout << originalPeg << "->" << destinationPeg << std::endl;
        return;
    }
    playHanoi(numberDisksToMove - 1, originalPeg, temporalPeg, destinationPeg);
    cout << originalPeg << "->" << destinationPeg << std::endl;
    playHanoi(numberDisksToMove - 1, temporalPeg, destinationPeg, originalPeg);
}*/

void basicRec(int n)
{
    std::cout << "n; " << n << std::endl;
	if(0==n)
	{
        std::cout << "return 0 " << n << std::endl;
        return;
	}
    std::cout << "calling; " << std::endl;
    basicRec(n - 1);
    std::cout << "finishing with; " << n << std::endl;
}

/*class toh {                  //To make a variable which can keep a track of source, auxiliary and destination pole.
public:
    char from;
    char to;
    char aux;
    int n;
};*/



int main()
{
    //basicRec(3);

    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    RecursiveTOH recToh{};
    recToh.playHanoi(n, '1', '3', '2');

    std::cout << "------------------------ "<<endl;

    IterativeTOH iteToh{};
    iteToh.towerOfHanoi(n, '1', '2', '3');
    return 0;
}



// Lab2BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void playHanoi(int numberDisksToMove, char originalPeg, char destinationPeg, char temporalPeg) {
    if(numberDisksToMove==1)
    {
        cout << originalPeg << "->" << destinationPeg << std::endl;
        return;
    }
    playHanoi(numberDisksToMove - 1, originalPeg, temporalPeg, destinationPeg);
    cout << originalPeg << "->" << destinationPeg << std::endl;
    playHanoi(numberDisksToMove - 1, temporalPeg, destinationPeg, originalPeg);
}

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

/*void hanoi2(int n, char source, char auxiliary, char target) {
    std::cout << "disk amount:" << n << std::endl;
    if (n > 0) {
        hanoi(n - 1, source, target, auxiliary);
        std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
        hanoi(n - 1, auxiliary, source, target);
    }
}*/

int main()
{
    //basicRec(3);

    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    playHanoi(n, '1', '3', '2');
    return 0;
}



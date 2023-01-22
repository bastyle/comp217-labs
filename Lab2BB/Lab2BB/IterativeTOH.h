#pragma once
#include <ostream>
#include <stack>
#include "Toh.h"
//using namespace std;

class IterativeTOH
{
public:
    void letsPlay(int numberOfDisks, char source, char auxiliary, char destination)const {
        stack<Toh> tohStack;      //Declaring a stack. 
        while (numberOfDisks >= 1 or !tohStack.empty()) {
            while (numberOfDisks >= 1) {//Save the current state and move to  the letsPlay(numberOfDisks-1,source,destination,auxiliary).
                Toh toh;
                toh.setOriginalPeg(source);
                toh.setTemporalPeg(auxiliary);
                toh.setDestinationPeg(destination);
                toh.setDiskNumber(numberOfDisks);
                tohStack.push(toh); // adding the current object at the top of the stack.
                //cout << "before swap dest " << destination << " aux" << auxiliary << std::endl;
                //cout << destination << " -> " << auxiliary << endl;
                swap(destination, auxiliary);// swapping the destination peg with the auxiliary one, so the next iteration will move from the original auxiliary peg on the
                //cout << "after swap dest " << destination << " aux" << auxiliary << std::endl;
                numberOfDisks--;//discount one of the total of disks to process the next one.
            }
            Toh cur = tohStack.top();
            tohStack.pop();
            //cout << "Move disk " << cur.getDiskNumber() << " from rod " << cur.getOriginalPeg() << " to rod " << cur.getDestinationPeg() << std::endl;
            cout << cur.getOriginalPeg() << "->" << cur.getDestinationPeg() << std::endl;
            
            if (cur.getDiskNumber() >= 1) {
                source = cur.getTemporalPeg();           // Simulates the letsPlay(numberOfDisks-1,auxiliary,source,destination) of Recursive Step.
                auxiliary = cur.getOriginalPeg();
                destination = cur.getDestinationPeg();
                numberOfDisks = cur.getDiskNumber() - 1;
                cout << "numberOfDisks: " << numberOfDisks << std::endl;
            }
        }
    }
};


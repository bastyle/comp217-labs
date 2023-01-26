#pragma once
#include <ostream>
#include <stack>
#include "Toh.h"
//using namespace std;

class IterativeTOH
{
public:
    int letsPlay(int numberOfDisks, char originalPeg, char temporalPeg, char destinationPeg)const {
        int totalMoves{0};
        stack<Toh> tohStack; 
        while (numberOfDisks >= 1 or !tohStack.empty()) {
            while (numberOfDisks >= 1) {//Save the current state and move to  the letsPlay(numberOfDisks-1,originalPeg,destinationPeg,temporalPeg).
                Toh toh;
                toh.setOriginalPeg(originalPeg);
                toh.setTemporalPeg(temporalPeg);
                toh.setDestinationPeg(destinationPeg);
                toh.setDiskNumber(numberOfDisks);
                tohStack.push(toh); // adding the current object at the top of the stack.
                swap(destinationPeg, temporalPeg);// swapping the destinationPeg peg with the temporalPeg one, so the next iteration will move from the original temporalPeg peg on the
                numberOfDisks--;//discount one of the total of disks to process the next one.
            }
            Toh cur = tohStack.top();
            tohStack.pop();
            cout << cur.getOriginalPeg() << "->" << cur.getDestinationPeg() << std::endl;
            totalMoves++;
            if (cur.getDiskNumber() >= 1) { //***s e
                originalPeg = cur.getTemporalPeg();           
                temporalPeg = cur.getOriginalPeg();
                destinationPeg = cur.getDestinationPeg();
                numberOfDisks = cur.getDiskNumber() - 1;
                //cout << "numberOfDisks: " << numberOfDisks << std::endl;                
            }
        }
        return totalMoves;
    }
};


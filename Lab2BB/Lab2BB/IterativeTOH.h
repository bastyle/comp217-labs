#pragma once
#include <ostream>
#include <stack>
#include "Toh.h"
//using namespace std;

class IterativeTOH
{
public:
    void letsPlay(int n, char source, char auxiliary, char destination)const {
        stack<Toh> st;      //Declaring a stack. 
        while (n >= 1 or !st.empty()) {
            while (n >= 1) {//Save the current state and move to  the letsPlay(n-1,source,destination,auxiliary).
                Toh cur;
                cur.setOriginalPeg(source);
                cur.setTemporalPeg(auxiliary);
                cur.setDestinationPeg(destination);
                cur.setDiskNumber(n);
                st.push(cur);
                //cout << "before swap dest " << destination << " aux" << auxiliary << std::endl;
                //cout << destination << " -> " << auxiliary << endl;
                swap(destination, auxiliary);
                //cout << "after swap dest " << destination << " aux" << auxiliary << std::endl;
                n--;                
            }
            Toh cur = st.top();
            st.pop();
            //cout << "Move disk " << cur.getDiskNumber() << " from rod " << cur.getOriginalPeg() << " to rod " << cur.getDestinationPeg() << std::endl;
            cout << cur.getOriginalPeg() << "->" << cur.getDestinationPeg() << std::endl;
            
            if (cur.getDiskNumber() >= 1) {
                source = cur.getTemporalPeg();           // Simulates the letsPlay(n-1,auxiliary,source,destination) of Recursive Step.
                auxiliary = cur.getOriginalPeg();
                destination = cur.getDestinationPeg();
                n = cur.getDiskNumber() - 1;
            }
        }
    }
};


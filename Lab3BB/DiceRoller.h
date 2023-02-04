#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class DiceRoller {
private:
    int *tally;
    const int ROLLS = 36000;  // number of times to roll the dice
    const int SIDES = 6;  // number of sides on each dice
public:
    DiceRoller() {
        tally = new int[13];
        for (int i = 0; i < 13; i++) {
            tally[i] = 0;
        }
    }
    ~DiceRoller() {
        delete[] tally;
    }
    void rollDices() {
        srand(time(0));
        int* ptr = tally;
        for (int i = 0; i < ROLLS; ++i) {
            int die1 = rand() % SIDES + 1;
            int die2 = rand() % SIDES + 1;
            int sum = die1 + die2;
            *(ptr + sum) = *(ptr + sum) + 1;
        }
        displayTally();
    }
    void displayTally() {
        cout << "Dices Sum\tTally" << endl;
        for (int i = 2; i <= 12; ++i) {
            cout << i << "\t\t" << tally[i] << endl;
        }
    }
};

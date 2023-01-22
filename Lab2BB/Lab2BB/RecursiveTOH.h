#pragma once
class RecursiveTOH
{
public:
    //RecursiveTOH();
    void playHanoi(int numberDisksToMove, char originalPeg, char destinationPeg, char temporalPeg) {
        if (numberDisksToMove == 1)
        {
            cout << originalPeg << "->" << destinationPeg << std::endl;
            return;
        }
        playHanoi(numberDisksToMove - 1, originalPeg, temporalPeg, destinationPeg);
        cout << originalPeg << "->" << destinationPeg << std::endl;
        playHanoi(numberDisksToMove - 1, temporalPeg, destinationPeg, originalPeg);
        return;
    }
};


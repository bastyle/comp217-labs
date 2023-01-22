#pragma once
class RecursiveTOH
{
public:
    //RecursiveTOH();
    void letsPlay(int numberDisksToMove, char originalPeg, char destinationPeg, char temporalPeg) {
        if (numberDisksToMove == 1)
        {
            cout << originalPeg << "->" << destinationPeg << std::endl;
            return;
        }
        letsPlay(numberDisksToMove - 1, originalPeg, temporalPeg, destinationPeg);
        cout << originalPeg << "->" << destinationPeg << std::endl;
        letsPlay(numberDisksToMove - 1, temporalPeg, destinationPeg, originalPeg);
        return;
    }
};


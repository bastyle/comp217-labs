#pragma once
class Toh
{
public:
    char getOriginalPeg()const
    {
	    return originalPeg;
    }
    char getDestinationPeg()const
    {
	    return destinationPeg;
    }
    char getTemporalPeg()const
    {
	    return temporalPeg;
    }
    int getDiskNumber()const
    {
	    return disksNumber;
    }

    void setOriginalPeg(char ori)
    {
	    originalPeg = ori;
    }
    void setDestinationPeg(char dest)
    {
        destinationPeg = dest;
    }
    void setTemporalPeg(char temp)
    {
        temporalPeg = temp;
    }
    void setDiskNumber(int diskNum)
    {
        disksNumber = diskNum;
    }
    

private:
    char originalPeg{};
    char destinationPeg{};
    char temporalPeg{};
    int disksNumber{};
};


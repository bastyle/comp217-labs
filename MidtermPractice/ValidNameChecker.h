#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>

class ValidNameChecker {
private:
    int validCount = 0;
    int invalidCount = 0;
    std::vector<std::string> validStrings;
    std::vector<std::string> invalidStrings;

    bool isUpperCase(char c) {
        return c >= 'A' && c <= 'Z';
    }

    bool isValidWord(const std::string& word) {
        if (word.empty() || !isUpperCase(word[0])) {
            return false;
        }
        for (size_t i = 1; i < word.length(); i++) {
            if (!isalpha(word[i]) || isUpperCase(word[i])) {
                return false;
            }
        }
        return true;
    }

public:
    bool operator()(const std::string& name) {
        auto spaceIndex = name.find(' ');
        if (spaceIndex == std::string::npos) {
            invalidCount++;
            invalidStrings.push_back(name);
            return false;
        }
        std::string firstName = name.substr(0, spaceIndex);
        std::string lastName = name.substr(spaceIndex + 1);
        if (!isValidWord(firstName) || !isValidWord(lastName)) {
            invalidCount++;
            invalidStrings.push_back(name);
            return false;
        }
        validCount++;
        validStrings.push_back(name);
        return true;
    }

    void printValidStrings() const {
        std::cout << "Valid Names:\n";
        std::for_each(validStrings.rbegin(), validStrings.rend(), [](const std::string& name) { std::cout << name << '\n'; });
    }

    void printInvalidStrings() const {
        std::cout << "Invalid Names:\n";
        std::for_each(invalidStrings.rbegin(), invalidStrings.rend(), [](const std::string& name) { std::cout << name << '\n'; });
    }

    int getValidCount() const {
        return validCount;
    }

    int getInvalidCount() const {
        return invalidCount;
    }
};

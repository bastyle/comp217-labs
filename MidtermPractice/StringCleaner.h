#include <string>

class StringCleaner {
public:
    StringCleaner() : num_cleared_(0), num_removed_(0) {}

    void operator()(std::string& str) {
        num_cleared_++;  // increment number of strings cleared
        // remove spaces from beginning
        size_t startpos = str.find_first_not_of(" ");
        if (startpos != std::string::npos) {
            str.erase(0, startpos);
        }
        else {
            str.clear();
            return;
        }
        // remove spaces from end
        size_t endpos = str.find_last_not_of(" ");
        if (endpos != std::string::npos) {
            str.erase(endpos + 1);
        }
        num_removed_ += startpos + (str.length() - endpos - 1);
    }

    int getNumCleared() const {
        return num_cleared_;
    }

    int getNumRemoved() const {
        return num_removed_;
    }

private:
    int num_cleared_;
    int num_removed_;
};


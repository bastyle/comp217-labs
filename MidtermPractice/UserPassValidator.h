#include <fstream>
#include <string>
#include <stdexcept>

class UserPassValidator {
public:
    explicit UserPassValidator(const std::string& filename) : filename_(filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }
    }

    bool operator()(const std::string& username, const std::string& password) const {
        std::ifstream file(filename_);
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find(':');
            if (pos == std::string::npos) {
                continue;
            }
            std::string user = line.substr(0, pos);
            std::string pass = line.substr(pos + 1);
            if (user == username && pass == password) {
                return true;
            }
        }
        return false;
    }

private:
    std::string filename_;
};


#include <string>
#include <unordered_set>

class PasswordValidator {
public:
    PasswordValidator(const std::unordered_set<char>& validChars, const std::unordered_set<char>& invalidChars)
        : validChars_(validChars), invalidChars_(invalidChars), requireLowercase_(true),
        requireUppercase_(true), requireNumber_(false), minLength_(0) {}

    bool operator()(const std::string& password) const {
        // Check if password contains all required characters
        bool hasValidChars = false;
        for (const char c : validChars_) {
            if (password.find(c) != std::string::npos) {
                hasValidChars = true;
                break;
            }
        }
        if (!hasValidChars) {
            return false;
        }

        // Check if password contains any invalid characters
        for (const char c : invalidChars_) {
            if (password.find(c) != std::string::npos) {
                return false;
            }
        }

        // Check for optional requirements
        if (requireLowercase_) {
            bool hasLowercase = false;
            for (const char c : password) {
                if (std::islower(c)) {
                    hasLowercase = true;
                    break;
                }
            }
            if (!hasLowercase) {
                return false;
            }
        }

        if (requireUppercase_) {
            bool hasUppercase = false;
            for (const char c : password) {
                if (std::isupper(c)) {
                    hasUppercase = true;
                    break;
                }
            }
            if (!hasUppercase) {
                return false;
            }
        }

        if (requireNumber_) {
            bool hasNumber = false;
            for (const char c : password) {
                if (std::isdigit(c)) {
                    hasNumber = true;
                    break;
                }
            }
            if (!hasNumber) {
                return false;
            }
        }

        if (minLength_ > 0 && password.length() < minLength_) {
            return false;
        }

        return true;
    }

    void setRequireLowercase(bool value) { requireLowercase_ = value; }
    void setRequireUppercase(bool value) { requireUppercase_ = value; }
    void setRequireNumber(bool value) { requireNumber_ = value; }
    void setMinLength(int value) { minLength_ = value; }

private:
    std::unordered_set<char> validChars_;
    std::unordered_set<char> invalidChars_;
    bool requireLowercase_;
    bool requireUppercase_;
    bool requireNumber_;
    int minLength_;
};

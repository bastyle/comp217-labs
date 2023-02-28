#include <string>
#include <list>

class PasswordValidator2 {
public:
    PasswordValidator2(const std::string& allowed_chars, const std::list<char>& forbidden_chars)
        : m_allowed_chars(allowed_chars), m_forbidden_chars(forbidden_chars), m_require_lowercase(true),
        m_require_uppercase(true), m_require_digit(false), m_min_length(0)
    {}

    void requireLowercase(bool value) { m_require_lowercase = value; }
    void requireUppercase(bool value) { m_require_uppercase = value; }
    void requireDigit(bool value) { m_require_digit = value; }
    void setMinLength(int value) { m_min_length = value; }

    bool operator()(const std::string& password) const {
        // Check for forbidden characters
        for (char c : password) {
            if (m_forbidden_chars.find(c) != m_forbidden_chars.end()) {
                return false;
            }
        }

        // Check for required characters
        bool has_lowercase = false;
        bool has_uppercase = false;
        bool has_digit = false;

        for (char c : password) {
            if (m_allowed_chars.find(c) == std::string::npos) {
                continue;
            }

            if (std::islower(c)) {
                has_lowercase = true;
            }
            else if (std::isupper(c)) {
                has_uppercase = true;
            }
            else if (std::isdigit(c)) {
                has_digit = true;
            }
        }

        if (m_require_lowercase && !has_lowercase) {
            return false;
        }

        if (m_require_uppercase && !has_uppercase) {
            return false;
        }

        if (m_require_digit && !has_digit) {
            return false;
        }

        if (m_min_length > 0 && password.length() < m_min_length) {
            return false;
        }

        return true;
    }

private:
    std::string m_allowed_chars;
    std::list<char> m_forbidden_chars;
    bool m_require_lowercase;
    bool m_require_uppercase;
    bool m_require_digit;
    int m_min_length;
};

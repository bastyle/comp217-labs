#include <iostream>
using namespace std;

class SalaryCalculator {
private:
    int salary[3];
    int *ptr;

public:
    SalaryCalculator() {
        ptr = salary;
    }
    void inputSalary() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter Salary: ";
            cin >> *(ptr + i);
        }
        displaySalaries();
    }
    void displaySalaries() {
        cout << endl;
        cout << "Entered salaries are: " << endl;
        for (int i = 0; i < 3; ++i) {
            cout << *(ptr + i) << " ";
        }
    }
    void updateSalaries() {
        cout << endl;
        cout << "Updated salaries are: " << endl;
        for (int i = 0; i < 3; ++i) {
            *(ptr + i) = *(ptr + i) + *(ptr + i) / (i + 1);
            cout << *(ptr + i) << " ";
        }
    }
};

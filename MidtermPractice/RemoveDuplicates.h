#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

class RemoveDuplicates {
public:
    RemoveDuplicates(double tolerance) : tolerance_(tolerance), num_removed_(0) {}

    void operator()(std::vector<double>& arr) {
        std::sort(arr.begin(), arr.end()); // sort array
        std::vector<double> unique_arr; // store unique values

        for (size_t i = 0; i < arr.size(); ++i) {
            bool is_duplicate = false;
            for (size_t j = 0; j < unique_arr.size(); ++j) {
                if (std::abs(arr[i] - unique_arr[j]) < tolerance_) {
                    is_duplicate = true;
                    break;
                }
            }
            if (!is_duplicate) {
                unique_arr.push_back(arr[i]);
            }
            else {
                log_duplicates_.push_back(arr[i]);
                ++num_removed_;
            }
        }

        arr = unique_arr; // set output array
        //log(arr); // write to log file
    }

    int num_removed() const {
        return num_removed_;
    }

    void print_log() const {
        std::cout << "Removed duplicates:" << std::endl;
        for (double num : log_duplicates_) {
            std::cout << num << std::endl;
        }
    }

private:
    double tolerance_;
    int num_removed_;
    std::vector<double> log_duplicates_;

    void log(const std::vector<double>& arr) {
        std::ofstream file("log.txt", std::ios_base::app);
        if (file.is_open()) {
            file << "Input array: ";
            for (double num : arr) {
                file << num << " ";
            }
            file << std::endl;

            file << "Removed duplicates: ";
            for (double num : log_duplicates_) {
                file << num << " ";
            }
            file << std::endl;

            file.close();
        }
    }
};

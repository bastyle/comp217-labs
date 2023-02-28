#pragma once
#include <algorithm>
//#include <exception>
//#include <iostream>
//#include <cstring>


template <typename T>
class TemplateUtils
{
public :

    int genericCount(const T* arr, int size, const T& item) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == item) {
                count++;
            }
        }
        return count;
    }

    int stringCount(const std::string* arr, const std::string& item) {
        int count = 0;
        for (int i = 0; i <= arr->length(); i++) {
            if (!arr[i].empty() && arr[i][0] == item[0]) {
                count++;
            }
        }
        return count;
    }


    int genericSmallerCount(const T* arr, int size, const T& value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] < value) {
                count++;
            }
        }
        return count;
    }

    int smallerStringCount(const std::string* arr, int size, const std::string& value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i].length() < value.length()) {
                count++;
            }
        }
        return count;
    }

    void genericReplaceValue(T* arr, size_t size, const T& old_value, const T& new_value) {
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == old_value) {
                arr[i] = new_value;
            }
        }
    }

    //size_t countIfBetween(char** arr, size_t size, char* min_value, char* max_value) {
    void replace(const char** arr, size_t size, const char* old_value, const char* new_value) {
        size_t old_len = strlen(old_value);
        size_t new_len = strlen(new_value);
        if (new_len > old_len) {
            throw std::length_error("New value is longer than old value");
        }
        for (size_t i = 0; i < size; i++) {
            if (strcmp(arr[i], old_value) == 0) {
                //strcpy(arr[i], new_value);
                arr[i] = new_value;
            }
        }
    }

    T genericSum(T* arr, size_t size) {
        T result = 0;
        for (size_t i = 0; i < size; i++) {
            result += arr[i];
        }
        return result;
    }

    std::string stringSum(std::string* arr, size_t size) {
        std::string result;
        for (size_t i = 0; i < size; i++) {
            result += arr[i];
            if (i != size - 1) {
                result += ",";
            }
        }
        return result;
    }


    bool exists(T* arr, size_t size, const T& value) {
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    bool exists(char** arr, size_t size, const char* value) {
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    template<typename Func>
    size_t countIf(T* arr, size_t size, Func pred) {
        size_t count = 0;
        for (size_t i = 0; i < size; i++) {
            if (pred(arr[i])) {
                count++;
            }
        }
        return count;
    }

    template <typename T, typename U>
    size_t countIfBetween(T* arr, size_t size, U min_value, U max_value) {
        size_t count = 0;
        for (size_t i = 0; i < size; i++) {
            if (arr[i] > min_value && arr[i] < max_value) {
                count++;
            }
        }
        return count;
    }

    
    size_t countIfBetween(const char** arr, size_t size, char* min_value, char* max_value) {
        size_t count = 0;
        for (size_t i = 0; i < size; i++) {
            if (strlen(arr[i]) > strlen(min_value) && strlen(arr[i]) < strlen(max_value)) {
                count++;
            }
        }
        return count;
    }

    template <typename T, typename Predicate>
    T* findIf(T* arr, size_t size, Predicate predicate) {
        for (size_t i = 0; i < size; i++) {
            if (predicate(arr[i])) {
                return &arr[i];
            }
        }
        return nullptr;
    }

    template <typename T, typename Predicate>
    bool allOf(T* arr, size_t size, Predicate predicate) {
        for (size_t i = 0; i < size; i++) {
            if (!predicate(arr[i])) {
                return false;
            }
        }
        return true;
    }

    T second_biggest(T* arr, size_t size) {
        if (size <= 1) {
            throw std::invalid_argument("Array must have at least 2 elements");
        }

        // Find the largest element in the array
        T largest = *std::max_element(arr, arr + size);

        // Find the second largest element in the array
        T second_largest = *std::max_element(arr, arr + size, [&](T a, T b) { return a < b&& b < largest; });

        if (second_largest == largest) {
            throw std::invalid_argument("No second biggest element in array");
        }

        return second_largest;
    }

    // Specialization for char*
    char* second_biggest(char** arr, size_t size) {
        if (size <= 1) {
            throw std::invalid_argument("Array must have at least 2 elements");
        }

        // Find the largest element in the array
        char* largest = *std::max_element(arr, arr + size, [](char* a, char* b) { return std::strcmp(a, b) < 0; });

        // Find the second largest element in the array
        char* second_largest = *std::max_element(arr, arr + size, [&](char* a, char* b) {
            return std::strcmp(a, b) < 0 && std::strcmp(b, largest) < 0;
            });

        if (std::strcmp(second_largest, largest) == 0) {
            throw std::invalid_argument("No second biggest element in array");
        }

        return second_largest;
    }

    
};


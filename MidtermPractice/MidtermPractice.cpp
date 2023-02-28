// MidtermPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LambdaUtils.h"
#include "PasswordValidator.h"
#include "RecursiveUtils.h"
#include "RemoveDuplicates.h"
#include "StringCleaner.h"
#include "TemplateUtils.h"
#include "UserPassValidator.h"
#include "ValidNameChecker.h"

void countConcurrences()
{
    int arr[] = { 1, 2, 3, 2, 1, 4, 5, 2 };
    std::string strArray[] = { "apple", "banana", "cherry", "pear", "peach" , "peach" };
    TemplateUtils<int> intCounter;
    int intOccurrences = intCounter.genericCount(arr, 8, 2);
    std::cout << "Number of occurrences of '2': " << intOccurrences<< std::endl;
    TemplateUtils<std::string> counter;
    int occurrences = counter.stringCount(strArray, std::string("p"));
	std::cout << "Number of occurrences of 'p' as the first letter in str_arr: " << occurrences << std::endl;
}

void smallerCount()
{
    int arr[] = { 1, 2, 3, 2, 1, 4, 5, 2 };
    std::string str_arr[] = { "apple", "banana", "cherry", "pear", "peach" };
    TemplateUtils<int> intCounter;
    int ints = intCounter.genericSmallerCount(arr, 8, 3);
    TemplateUtils<std::string> strCounter;
    int strings = strCounter.smallerStringCount(str_arr, 5, std::string("peach"));

    std::cout << "Number of integers smaller than 3: " << ints << std::endl;
    std::cout << "Number of strings with length smaller than \"peach\": " << strings << std::endl;
}

void replaceValue()
{
    int arr1[] = { 1, 2, 3, 2, 1 };
    TemplateUtils<int> intReplacer;
    intReplacer.genericReplaceValue(arr1, 5, 2, 0);
    for (size_t i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    TemplateUtils<char> charReplacer;
    const char* arr2[5] = { "hello", "world", "hello", "goodbye", "world" };
    //const char* arr2[2] = { "hello","world"};
    //const char* str_arr[4] = { "hello", "world", "c++", "templates" };
    charReplacer.replace(arr2, 5, "hello", "hi");
    
    for (size_t i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;    
    std::cout << std::endl;
}

void sum()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    TemplateUtils<int> intSum;
    std::cout << "sum of arr1: " << intSum.genericSum(arr1, size1) << std::endl;

    // Test the second function with a std::string array
    std::string arr2[] = { "hello", "world", "foo", "bar" };
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    TemplateUtils<std::string> strSum;
    std::cout << "sum of arr2: " << strSum.stringSum(arr2, size2) << std::endl;
}

void exists()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "size: " << size1 << std::endl;
    std::cout << "size: " << sizeof(arr1) << std::endl;
    std::cout << "size: " << sizeof(arr1[0]) << std::endl;
    TemplateUtils<int> intObj;
    std::cout << "5 exists in arr1: " << intObj.exists(arr1, size1, 5) << std::endl;
    std::cout << "6 exists in arr1: " << intObj.exists(arr1, size1, 6) << std::endl;

    // Test the second function with a char* array
    char arr2[] = {"hello"};
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    TemplateUtils<char> charObj;
    std::cout << "\"l\" exists in arr2: " << charObj.exists(arr2, size2, 'l') << std::endl;
    std::cout << "\"h\" exists in arr2: " << charObj.exists(arr2, size2, 'h') << std::endl;
}



void lambdaCounterTest()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    TemplateUtils<int> intObj;
    // Count the number of even numbers in the array
    size_t count = intObj.countIf(arr, size, [](int x) { return x % 2 == 0; });
    std::cout << "Number of even numbers in the array: " << count << std::endl;
}

void countIfBetween()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Count the number of elements between 2 and 4 in the array
    TemplateUtils<int> intObj;
    size_t count = intObj.countIfBetween(arr, size, 2, 4);

    std::cout << "Number of elements between 2 and 4 in the array: " << count << std::endl;

    const char* str_arr[4] = { "hello", "worlda2", "c++", "templates" };
    size_t str_size = sizeof(str_arr) / sizeof(str_arr[0]);

    // Count the number of strings between "hello" and "templates" in the array
    TemplateUtils<char> charObj;
    char hello[] = {"hello"};
    char templates[] = { "templates" };
    size_t str_count = charObj.countIfBetween(str_arr, str_size, hello, templates);

    std::cout << "Number of strings between 'hello' and 'templates' in the array: " << str_count << std::endl;
}

void findIf()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    TemplateUtils<int> intObj;
    // Find the first even number in the array
    auto even_ptr = intObj.findIf(arr, size, [](int x) { return x % 2 == 0; });

    if (even_ptr != nullptr) {
        std::cout << "Found even number in array: " << *even_ptr << std::endl;
    }
    else {
        std::cout << "No even number found in array" << std::endl;
    }

    std::string str_arr[] = { "hello", "world", "c++", "templates" };
    size_t str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    TemplateUtils<char> charObj;
    // Find the first string with length > 5 in the array
    auto long_str_ptr = charObj.findIf(str_arr, str_size, [](std::string s) { return s.length() > 5; });

    if (long_str_ptr != nullptr) {
        std::cout << "Found string with length > 5 in array: " << *long_str_ptr << std::endl;
    }
    else {
        std::cout << "No string with length > 5 found in array" << std::endl;
    }

}

void allOf()
{
    int arr[] = { 2, 4, 6, 8, 10 };
    size_t size = sizeof(arr) / sizeof(arr[0]);
    TemplateUtils<int> intObj;
    // Check if all elements in the array are even
    bool all_even = intObj.allOf(arr, size, [](int x) { return x % 2 == 0; });

    if (all_even) {
        std::cout << "All elements in array are even" << std::endl;
    }
    else {
        std::cout << "Not all elements in array are even" << std::endl;
    }

    std::string str_arr[] = { "hello", "world", "c++", "templates" };
    size_t str_size = sizeof(str_arr) / sizeof(str_arr[0]);

    // Check if all strings in the array have length > 3
    bool all_long = intObj.allOf(str_arr, str_size, [](std::string s) { return s.length() > 3; });

    if (all_long) {
        std::cout << "All strings in array have length > 3" << std::endl;
    }
    else {
        std::cout << "Not all strings in array have length > 3" << std::endl;
    }
}

void printPointsRecursive()
{
    RecursiveUtils recursive;
    //recursive.printPoints(5);
    recursive.printPoints2(5);

}

void recursiveFormula()
{
    RecursiveUtils recursive;
    int result = recursive.recursiveFormula(6);
    std::cout << "The result is " << result << std::endl;
}

void counterLetterARecursive()
{
    std::string str = "banana";
    RecursiveUtils recursive;
    int count = recursive.countLetterA(str);
    std::cout << "The string \"" << str << "\" contains " << count << " letter a's." << std::endl;
}

void sumArrayRecursive() {
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calculate the sum of all elements in the array
    RecursiveUtils recursive;
    double sum = recursive.sumArray(arr, n);

    // output the sum to the console
    std::cout << "The sum of all elements in the array is: " << sum << std::endl;
}
void countEvenRecursive()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calculate the sum of all elements in the array
    RecursiveUtils recursive;
    double sum = recursive.countEvenRecursive(arr, n);

    // output the sum to the console
    std::cout << "The sum of all elements in the array is: " << sum << std::endl;
}

void replaceSpacesWithDotRecursive()
{
    RecursiveUtils recursive;
    std::string aux = "aa jj kk,.l ll ";
    std::cout << aux << std::endl;
    recursive.replaceSpacesWithDotRecursive(aux);
    std::cout << aux << std::endl;
    std::cout << recursive.replaceSpacesWithDotRecursive2(aux);
    //std::cout << aux << std::endl;
}

void replaceNegativeRecursive()
{
    RecursiveUtils recursive;
    float arr[] = { 1.5, -2.7, 3.0, -4.2, 5.1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    recursive.replaceNegativeRecursive(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void countDivisionsByTwoRecursive()
{
    RecursiveUtils recursive;
    int aux = recursive.countDivisionsByTwoRecursive(8);
    std::cout << "8 is "<< aux << " times divisible by 2" << std::endl;
}

void printIntArrayRecursive()
{
    RecursiveUtils recursive;
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    recursive.printIntArrayRecursive(arr,n);
}

void arrayToStringRecursive2()
{
    RecursiveUtils recursive;
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::string aux = recursive.arrayToStringRecursive2(arr, n);
    std::cout << aux << std::endl;
}

void passwordValidator()
{
    std::unordered_set<char> validChars = { '!', '@', '#', '$', '%', '^', '&', '*' };
    std::unordered_set<char> invalidChars = { ' ', '\t', '\n' };

    PasswordValidator validator(validChars, invalidChars);
    validator.setRequireNumber(true);
    validator.setMinLength(8);

    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;

    if (validator(password)) {
        std::cout << "Password is valid." << std::endl;
    }
    else {
        std::cout << "Password is invalid." << std::endl;
    }
}

void stringCleaner()
{
    StringCleaner cleaner;
    std::vector<std::string> strings = { "   hello", "world  ", "  foo bar  ", "  ", "","bastian"};
    for (auto& str : strings) {
        cleaner(str);
        std::cout << "Cleaned string: " << str << std::endl;
    }
    std::cout << "Number of strings cleared: " << cleaner.getNumCleared() << std::endl;
    std::cout << "Number of spaces removed: " << cleaner.getNumRemoved() << std::endl;
}

void validNameChecker()
{
    ValidNameChecker checker;

    checker("John Doe");
    checker("Mary Jane");
    checker("Alice Smith");
    checker("Bob");
    checker("David Lee");

    std::cout << "Valid count: " << checker.getValidCount() << '\n';
    std::cout << "Invalid count: " << checker.getInvalidCount() << '\n';

    checker.printValidStrings();
    checker.printInvalidStrings();
}

void removeDuplicates()
{
    std::vector<double> arr = { 1.0, 2.0, 2.5, 3.0, 3.5, 4.0 };
    RemoveDuplicates remove_duplicates(0.5);
    remove_duplicates(arr);
    std::cout << "Removed " << remove_duplicates.num_removed() << " duplicates" << std::endl;
    remove_duplicates.print_log();
}

void userPassValidator()
{
    UserPassValidator validator("users.txt");

    std::string username;
    std::string password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (validator(username, password)) {
        std::cout << "Access granted!\n";
    }
    else {
        std::cout << "Access denied.\n";
    }
}

template<typename Func>
int lambdaSum(int arr[], Func func)
{
    return func(arr);
}

template<typename Func>
int add(int i, Func func)
{
    return func(i);
}

void lambdaArraySum()
{
    auto sum = [](const int arr[], int size) -> int {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    };

    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sum(arr, size);
    // print the result to the console
    std::cout << "The sum is: " << result << std::endl;

	std::cout << lambdaSum(arr, [&](int[])
    {
        int totalArr = 0;
		int sizeArr = sizeof(arr) / sizeof(arr[0]);
		for (int index = 0; index < sizeArr; index++) {
            totalArr += arr[index];
		}
		return totalArr;
    }) << std::endl;
    //int k = 4;
    //std::cout << add(10, [&](int i) { return i + k++; }) << std::endl;

}

void lambdaCheckInterval() {
    auto checkInterval = [](const std::vector<int>& nums, int min, int max) {
        for (auto num : nums) {
            if (num < min || num > max) {
                return false;
            }
        }
        return true;
    };
    std::vector<int> nums = { 1, 3, 5, 7, 9 };
    int min = 0, max = 10;

    bool result = checkInterval(nums, min, max);
    std::cout << "All numbers within interval? " << result << std::endl;
}


void lambdaIsLowerCase()
{
    auto isLowerCase = [](const std::string& s) {
        return std::all_of(s.begin(), s.end(), [](char c) { return std::islower(c); });        
    };

    bool result = isLowerCase("lalalala");
    std::cout << "is lower case? " << result << std::endl;
    result = isLowerCase("lalAlala");
    std::cout << "is lower case? " << result << std::endl;
}

void lambdaMultiply()
{
    auto multiplyByN = [](int n, const std::vector<int>& arr) {
        std::vector<int> result;
        for (auto x : arr) {
            result.push_back(n * x);
        }
        return result;
    };
    std::vector<int> arr = { 1, 2, 3, 4 };
    auto result = multiplyByN(5, arr); // multiplies each element of arr by 5
    //std::cout << "is lower case? " << result << std::endl;
}




int main() {
    //countConcurrences();
    //smallerCount();
    //replaceValue();
    //sum();
    //exists();
    //lambdaCounterTest();
    //countIfBetween();
    //findIf();
    //allOf();
    //printPointsRecursive();
    //recursiveFormula();
    //counterLetterARecursive();
    //sumArrayRecursive();
    //countEvenRecursive();
    //replaceSpacesWithDotRecursive();
    //replaceNegativeRecursive();
    //countDivisionsByTwoRecursive();
    //printIntArrayRecursive();
    //arrayToStringRecursive2();
    //passwordValidator();
    //stringCleaner();
    //validNameChecker();
    //removeDuplicates();
    //lambdaArraySum();
    //lambdaCheckInterval();
    //lambdaIsLowerCase();
    //std::cout << std::string(5, '.');
    int i = 3;

    // A pointer to variable i or "stores the address of i"
    int* ptr = &i;
    std::cout << ptr << std::endl;
    // A reference (or alias) for i.
    int& ref = i;
    std::cout << ref << std::endl;

    std::cout << i << std::endl;
    std::cout << &i << std::endl;

}


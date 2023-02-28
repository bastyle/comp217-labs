// MidtermPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "RecursiveUtils.h"
#include "TemplateUtils.h"
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

void printPoints()
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
    //printPoints();
    recursiveFormula();
}


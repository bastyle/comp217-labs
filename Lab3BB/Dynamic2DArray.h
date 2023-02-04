#include <iostream>

template <typename type>
class Dynamic2DArray {
    
private:
    int rows, columns;
    T** arr;

public:
    Dynamic2DArray(int r, int c) : rows(r), columns(c) {
        arr = new T * [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new T[columns];
        }
    }

    ~Dynamic2DArray() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cin >> arr[i][j];
            }
        }
    }
};

#include <iostream>
#include <ctime>
#include <cmath>

//////////////////////////////////////////////////////////////////////////////

size_t** Init2DArray(size_t** arr, const size_t row, const size_t col) {
    arr = new size_t * [row];
    for (size_t i = 0; i < row; i++) {
        arr[i] = new size_t[col];
    }
    return arr;
}

void Fill2DArray(size_t** arr, const size_t row, const size_t col, const size_t border) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            arr[i][j] = (rand() % border + 1);
        }
    }
}

void Print2DArray(size_t** arr, const size_t row, const size_t col, const size_t width) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            std::cout.width(width);
            std::cout << arr[i][j];
            //printf("%5d",arr[i][j]);
        }
        std::cout << std::endl;
    }
}

void Print2DArrayPointer(size_t** arr, const size_t row, const size_t col) {
    size_t** ptr = (size_t**)arr;
    size_t** end = (size_t**)arr + row;

    size_t* e;
    while (ptr != end) {
        e = (size_t*)*ptr + col;
        for (size_t* i = *ptr; i != e; ) {
            printf("%5d", *i++);
        }
        std::cout << std::endl;
        ++ptr;
    }
}

void DeInit2DArray(size_t** arr, const size_t row) {
    for (size_t i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

void Swap(size_t* a, size_t* b) {
    size_t temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(size_t** arr, const size_t row, const size_t col) {
    const size_t max = row * col;
    for (size_t k = 0; k < max; k++) {
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (!(i == row - 1 && j == col - 1)) {
                    if (j == col - 1) {
                        if (arr[i][j] > arr[i + 1][0]) {
                            Swap(&arr[i][j], &arr[i + 1][0]);
                            continue;
                        }
                    }
                    else if (arr[i][j] > arr[i][j + 1]) {
                        Swap(&arr[i][j], &arr[i][j + 1]);;
                    }
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

size_t* InitArray(size_t* arr, const size_t SIZE) {
    arr = new size_t[SIZE];
    return arr;
}

void FillArray(size_t* arr, const size_t SIZE) {
    std::cout << "Enter 11 numbers" << std::endl;
    for (size_t i = 1; i <= SIZE; i++) {
        std::cout << "Enter " << i << " number: ";
        std::cin >> arr[i - 1];
    }
}

void DeInitArray(size_t* arr) {
    delete[] arr;
    arr = nullptr;
}

void PrintArray(size_t* arr, const size_t SIZE, const size_t WIDTH) {
    for (size_t i = 0; i < SIZE; i++) {
        std::cout.width(WIDTH);
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void ReverseArray(size_t* arr, const size_t SIZE) {
    for (size_t i = 0; i < SIZE / 2; i++) {
        Swap(&arr[i], &arr[SIZE - i - 1]);
    }
}

void AlgorithmTPK(size_t* arr, const size_t SIZE) {
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
        if (arr[i] > 400) {
            std::cout << "The number under the number " << i + 1 << " gave a result of more than 400" << std::endl;
        }
    }
}


//////////////////////////////////////////////////////////////////////////////

int main() {

    //////////////////////////////////////////////////////////////////////////

    srand(time(0));

    const size_t ROW = 3;
    const size_t COL = 5;
    const size_t BORDER = 9;
    const size_t WIDTH = 5;

    size_t** arr = nullptr;
    arr = Init2DArray(arr, ROW, COL);
    Fill2DArray(arr, ROW, COL, BORDER);
    Print2DArray(arr, ROW, COL, WIDTH);
    BubbleSort(arr, ROW, COL);
    std::cout << std::endl;
    //Print2DArrayPointer(arr, ROW, COL);
    Print2DArray(arr, ROW, COL, WIDTH);
    DeInit2DArray(arr, ROW);

    //////////////////////////////////////////////////////////////////////////

    const size_t SIZE = 11;

    size_t* arrTPK = nullptr;
    arrTPK = InitArray(arrTPK, SIZE);
    FillArray(arrTPK, SIZE);
    PrintArray(arrTPK, SIZE, WIDTH);
    ReverseArray(arrTPK, SIZE);
    PrintArray(arrTPK, SIZE, WIDTH);
    AlgorithmTPK(arrTPK, SIZE);
    PrintArray(arrTPK, SIZE, WIDTH);
    DeInitArray(arrTPK);

    /// //////////////////////////////////////////////////////////////////////

    return 0;
}

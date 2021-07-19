#include <iostream>
#include <ctime>

void swap(size_t *a, size_t *b) {
    size_t temp = *a;
    *a = *b;
    *b = temp;
}

size_t** init2Darray(size_t** arr, size_t row, size_t col) {
    arr = new size_t* [row];
    for (size_t i = 0; i < row; i++) {
        arr[i] = new size_t [col];
    }
    return arr;
}

void fill2Darray(size_t** arr, size_t row, size_t col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            arr[i][j] = (rand() % 9 + 1);
        }
    }
}

void print2Darray(size_t** arr, size_t row, size_t col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            std::cout.width(5);
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}



void bubbleSort(size_t** arr, size_t row, size_t col) {
    const size_t max = row * col;
    for (size_t k = 0; k < max; k++) {
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (!(i == row - 1 && j == col - 1)) {
                    if (j == col - 1) {
                        if (arr[i][j] > arr[i + 1][0]) {
                            swap(&arr[i][j], &arr[i + 1][0]);
                            continue;
                        }
                    }
                    if (arr[i][j] > arr[i][j + 1]) {
                        swap(&arr[i][j], &arr[i][j + 1]);
                    }
                }
            }
        }
    }
}

int main()
{
    srand(time(0));

    const size_t row = 5;
    const size_t col = 5;
    
    size_t** arr;
    //init2Darray(arr, row, col);
    arr = new size_t * [row];
    for (size_t i = 0; i < row; i++) {
        arr[i] = new size_t[col];
    }

    fill2Darray(arr, row, col);
    print2Darray(arr, row, col);
    bubbleSort(arr, row, col);
    std::cout << std::endl;
    print2Darray(arr, row, col);

}


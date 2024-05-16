#include<iostream>
#include <fstream>
#include <chrono>

using namespace std;

void print(int*& arr, int size) {
    cout << "[ ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void push(int*& arr, int& size, int val) {
    int* new_arr = new int[size+1];
    for(int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[size] = val;
    arr = new_arr;
    size++;
    delete[] new_arr;
}

void push_reserve(int*& arr, int &cap, int& size, int val) {
    if(cap > size) {
        arr[size] = val;
    } else {
        cap+=10;
        int* new_arr = new int[cap] {0};
        for(int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = val;
        arr = new_arr;
    }
    size++;
}

void push_multiply(int*& arr, int &cap, int& size, int val) {
    if(cap > size) {
        arr[size] = val;
    } else {
        cap*=2;
        int* new_arr = new int[cap] {0};
        for(int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = val;
        arr = new_arr;
    }
    size++;
}

int main() {
    int MIN = 100, MAX = 1000000, STEP = 1000;
    int COUNT = (MAX - MIN) / STEP;
    int REPEAT = 10;

    int* RES1 = new int[COUNT];
    int* RES2 = new int[COUNT];
    int* RES3 = new int[COUNT];

    for(int j = 0; j < COUNT; j++) {
        int mean = 0;
        for(int m = 0; m < REPEAT; m++) {
            int N = 1;
            int* arr = new int[] {1};

            auto begin = std::chrono::steady_clock::now();
            for(int k = 0; k < MAX; k+=STEP) {
                push(arr,N,1);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            mean += time_span.count();
        }
        mean = mean / REPEAT;
        RES1[j] = mean;
    }

    for(int j = 0; j < COUNT; j++) {
        int mean = 0;
        for(int m = 0; m < REPEAT; m++) {
            int N = 1;
            int busyN = N;
            int* arr = new int[] {1};

            auto begin = std::chrono::steady_clock::now();
            for(int k = 0; k < MAX; k+=STEP) {
                push_reserve(arr,N,busyN,1);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            mean += time_span.count();
        }
        mean = mean / REPEAT;
        RES2[j] = mean;
    }

    for(int j = 0; j < COUNT; j++) {
        int mean = 0;
        for(int m = 0; m < REPEAT; m++) {
            int N = 1;
            int busyN = N;
            int* arr = new int[] {1};

            auto begin = std::chrono::steady_clock::now();
            for(int k = 0; k < MAX; k+=STEP) {
                push_multiply(arr,N,busyN,1);
            }
            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            mean += time_span.count();
        }
        mean = mean / REPEAT;
        RES3[j] = mean;

    }

    ofstream file;
    file.open("array.txt");

    file << "N,one-by-one,append,multiply\n";

    for(int j = 0; j < COUNT; ++j) {
        file << STEP*(j+1) << "," << RES1[j] << "," << RES2[j] << "," << RES3[j] << "\n";
    }
    file.close();

    delete[] RES1;
    delete[] RES2;
    delete[] RES3;

}
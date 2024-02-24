#include <iostream>

using namespace std;

int main() {
    short int *array; 
    array = new short int[10]; // выделил память на 10 элементов
    for(int i = 0; i<10; i++) {
        array[i] = i;
    }
    for(int i = 0; i<10; i++) {
        cout << &array[i] << " ";
    }
    cout << endl; 
    for(int i = 0; i<10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    // q: указательная арифметика? +
    for(int i = 1; i<10; i+=2) {
        *(array+i) = i*i; // сос мыслом
    }
    for(int i = 0; i<10; i++) {
        cout << array[i] << " ";
    }
}
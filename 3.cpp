#include <iostream>

using namespace std;

int main() {
    short int *array; 
    int value = 0;
    cin >> value;
    int array_size = 1;
    array = new short int[array_size];
    array[0] = value;
    while(value!=0) {
        array_size++;
        short int *new_array = new short int[array_size];
        for(int i = 0; i < array_size; i++) {
            new_array[i] = array[i];
        }
        delete array;
        array = nullptr;
        new_array[array_size-1]=value;
        cin >> value;
        array = new_array;
    }
    cout << "output:" << endl;
    for(int i = 1; i < array_size; i++) {
        cout << array[i]-array[i-1] << " ";
    }
    // других реализаций не придумал
}
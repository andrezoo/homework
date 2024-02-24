#include <iostream>

using namespace std;

int main() {
    double *ptr; // создал указатель
    ptr = nullptr; // присвоил нулевое значение
    cout << "Adress: " << &ptr << " Value:" << ptr << endl; // 16ое представление (адрес)
    ptr -= 3;
    cout << "Adress: " << &ptr << " Value:" << ptr << endl;
    ptr += 5;
    cout << "Adress: " << &ptr << " Value:" << ptr << endl;
    // q: хранимое значение это адрес?

    /** Вывод: 
    Adress: 0xb498fff798 Value:0
    Adress: 0xb498fff798 Value:0xffffffffffffffe8
    Adress: 0xb498fff798 Value:0x10
    **/
    
    return 0;
}
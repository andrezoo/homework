#include <iostream>

using namespace std;

void input_array(int** ptr, size_t N) {
        *ptr = new int[N];
        for(int i = 0; i < N; i++) {
            cin >> *(*ptr+i);  
        }
}
void reverse(int** ptr, size_t N) {
    int temp = 0;
    for(size_t i = 0; i < (int)N/2; i++) {
        temp = *(*ptr + i);
        *(*ptr + i) = *(*ptr + N - i - 1);
        *(*ptr + N - i - 1) = temp;
    }
}
void print(int** ptr, size_t N) {
    for(int i = 0; i < (int)N; i++) {
        cout << *(*ptr + i) << " ";
    }
}

int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;

    // хочу работать со своим указателем
    input_array(&ptr, N);
    reverse(&ptr, N);
    print(&ptr, N);

    return 0;
}
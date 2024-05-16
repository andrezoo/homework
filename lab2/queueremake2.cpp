#include <iostream>

using namespace std;

void print(int*& arr, int size, int read, int write) {
    cout << "[ ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    cout << "[ ";
    for(int i = 0; i < size; i++) {
        if(i == read) cout << "R ";
        else if(i == write) cout << "W ";
        else cout << "0 ";
    }
    cout << "]" << endl;
    cout << read << " " << write << endl << endl;
}

void queue_new(size_t &read, size_t &write, int *&data) {
    extern int len;

    int* new_data = new int[len*2]{0};

    if(write < len) {
        for(int i = 0; i < write+1; i++) {
            new_data[i] = data[i];
        }

        for(int i = write+1; i < len; i++) {
            new_data[i+len] = data[i];
        }
        
        delete[] data;
        data = new_data;

        if(read>write) read+=len;
        len*=2; 
    }
}

bool queue_poll(size_t &read, size_t &write, int *&data) {
    extern int len;
    if(read!=write+1) {
        cout << data[read] << endl;
        if(read+1==len) {
            read = 0;
        } else {
            read++;
        }
    } else return false; // не уверен, что именно в этом случае
    return true;
}

bool queue_push(size_t &read, size_t &write, int *&data, int element) {
    extern int len;

    if(write+1==len) {
        data[0] = element;
        write = 0;
    } else if(write==read) {
        queue_new(read, write, data);
        data[write+1] = element;
        write++;
    } else {
        data[write+1] = element;
        write++;
    }
    return true;
}

int len = 5;

int main() {

    size_t poll_idx = 3, push_idx = 3;

    int* arr = new int[len]{0};

    queue_push(poll_idx, push_idx, arr, 1);
    print(arr, len, poll_idx, push_idx);
    queue_push(poll_idx, push_idx, arr, 2);
    print(arr, len, poll_idx, push_idx);
    queue_push(poll_idx, push_idx, arr, 3);
    queue_push(poll_idx, push_idx, arr, 4);
    queue_push(poll_idx, push_idx, arr, 5);
    queue_push(poll_idx, push_idx, arr, 6);
    print(arr, len, poll_idx, push_idx);

    queue_poll(poll_idx, push_idx, arr);
    queue_poll(poll_idx, push_idx, arr);
    queue_poll(poll_idx, push_idx, arr);
    queue_poll(poll_idx, push_idx, arr);
    queue_poll(poll_idx, push_idx, arr);
    queue_poll(poll_idx, push_idx, arr);

}
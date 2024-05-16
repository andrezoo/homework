#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

#define int long long

void queue_new(size_t &push_idx, size_t &pull_idx, int *&data) {
    extern int len;
    int* new_data = new int[2*len]{0};
    for (int i = pull_idx; i < len; i++) {
        new_data[i + len] = data[i];
    }
    pull_idx += len;
    len*=2;
}

bool queue_push(size_t &push_idx, size_t &pull_idx, int *&data) {
    extern int len;
    if(push_idx < len-1) {
        if(push_idx != pull_idx) {
            push_idx++;
            return true;
        }
    } else {
        push_idx = 0;
        return true;
    }
    return false;
}

bool queue_pull(size_t &push_idx, size_t &pull_idx, int *&data) {
    extern int len;
    if(pull_idx < len-1) {
        pull_idx++;
        return true;
    }
    return false;
}

int len = 5;

int NARR[24] = {        1000, 2000, 4000, 6000, 8000, 10000, 15000,
                        20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 
                        65000, 70000, 75000, 80000, 85000, 90000, 95000, 100000};

int K[26] = {100000, 10000, 10000, 10000, 10000, 10000,
                        10000, 10000, 5000, 5000, 5000, 1000, 1000, 1000,
                        1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
                        1000, 1000, 1000, 1000};


signed main() {
    int result1_array[10] = {0};
    int result2_array[10] = {0};
    int exp_count = 10;
    for(int i = 0; i < exp_count ; i++) {
        int N = NARR[i];
        for(int j = 0; j < K[i]; ++j) {
            size_t push_idx = 1, pull_idx = 0;
            int *arr = new int[len] {1,2,3,4,5};

            auto begin = std::chrono::steady_clock::now();

            while(len < N) {
                if(queue_push(push_idx, pull_idx, arr) == false) {
                    queue_new(push_idx, pull_idx, arr);
                }
            }

            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            result1_array[i] += time_span.count();
        }
        for(int j = 0; j < K[i]; ++j) {
            size_t push_idx = 1, pull_idx = 0;
            int *arr = new int[len] {1,2,3,4,5};

            auto begin = std::chrono::steady_clock::now();

            while(len < N) {
                if(queue_pull(push_idx, pull_idx, arr) == false) {
                    queue_new(push_idx, pull_idx, arr);
                }
            }

            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

            result2_array[i] += time_span.count();
        }
    }
    
    ofstream file;
    file.open("queue1.txt");

    for(int j = 0; j < exp_count; ++j) {
        file << NARR[j] << " " << result1_array[j] / K[j] << "\n";
    }
    file.close();

    file.open("queue2.txt");
    for(int j = 0; j < exp_count; ++j) {
        file << NARR[j] << " " << result2_array[j] / K[j] << "\n";
    }
    file.close();
    return 0;
}



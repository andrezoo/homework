#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

#ifndef ARRAYSIZE
#define ARRAYSIZE 5000
#endif
#define SEED 1001
#define MAX 999

using namespace std;

int main() {

    unsigned seed = SEED;
    default_random_engine rng(seed);
    uniform_int_distribution<unsigned> dstr(0,MAX);

    //cout << "ARRAY SIZE: " << ARRAYSIZE << endl;
    const int repeat = 10;
    int k = 0;
    long long int temp_standart[repeat] = {0};
    long long int temp_binary[repeat] = {0};

    while(k < repeat){
        // создаем наш загадочный массив
        long long int arr[ARRAYSIZE] = {0};
        for (unsigned i = ARRAYSIZE; i != 0; --i) {
            arr[i] = dstr(rng);
        }
        
        // выбираем жертву 
        uniform_int_distribution<int> target_dstr(0,ARRAYSIZE-1);
        int target = target_dstr(rng);

        // обычный поиск 
        auto begin = chrono::steady_clock::now();
        for (unsigned i = 0; i < ARRAYSIZE; i++) {
            if(arr[i] == arr[target]) break; // мы ему верим
        }
        auto end = chrono::steady_clock::now();
        auto time_span = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        
        //cout << "Standart search:" << time_span.count() << endl;
        temp_standart[k] = time_span.count();

        sort(std::begin(arr),std::end(arr));

        // бинарный поиск
        begin = chrono::steady_clock::now();

        std::binary_search(std::begin(arr),std::end(arr),arr[target]);

        end = chrono::steady_clock::now();
        time_span = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        //cout << "Binary search:" <<  time_span.count() << endl;
        temp_binary[k] = time_span.count();
        //cout << "\n";

        k++;
    }
    int smm = 0;
    for(int m = 0; m < repeat; m++) {
        smm += temp_standart[m];
    }
    cout << smm / repeat << "@";
    smm = 0;
    for(int m = 0; m < repeat; m++) {
        smm += temp_binary[m];
    }
    cout << smm / repeat;
    return 0;
}
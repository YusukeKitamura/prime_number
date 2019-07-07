/***********************************************************
    primes.cpp -- 素数（C++）
    最適化なし
    g++ primes.cpp -o primes (またはclang++ primes.cpp -o primes)
    最適化あり
    g++ -O3 primes.c -o primes (またはclang++ -O3 primes.c -o primes)
    ./primes
***********************************************************/
#include <iostream>
#include <iomanip>
#include <time.h>

int* generate_primes(int total)
{
    int* primes = new int[total];
    primes[0] = 2;
    int x = 1;
    int k = 1;
    while (k < total) {
        int j = 0;
        x += 2;
        while (j < k && x % primes[j] != 0) {
            if (primes[j] * primes[j] >= x) {
                primes[k++] = x;
                break;
            }
            j++;
        }
    }
    return primes;
}

int main()
{
    int total = 10000;
    std::cout << "素数表 C++";
    clock_t start_time = clock();
    int* primes = generate_primes(total);
    clock_t end_time = clock();
    std::cout << "\n";
    std::cout << "計算時間：" << (double)(end_time-start_time)/CLOCKS_PER_SEC << "秒\n";
    start_time = clock();
    for (int i = 0; i < total; i++) {
        if (i % 10 == 0) std::cout << "\n";
        std::cout << std::setw(8) << std::setfill(' ') << primes[i];
    }
    end_time = clock();
    std::cout << "\n";
    std::cout << "出力時間：" << (double)(end_time-start_time)/CLOCKS_PER_SEC << "秒\n";
    delete[] primes;
    return 0;
}

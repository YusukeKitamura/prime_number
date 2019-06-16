/***********************************************************
    primes.cpp -- 素数（C++）
    g++ primes.cpp -o primes (またはclang++ primes.cpp -o primes)
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
    int j = 0;
    int k = 1;
    while (k < total) {
        x += 2;
        j = 0;
        while (j < k && x % primes[j] != 0) j++;
        if (j == k) primes[k++] = x;
    }
    return primes;
}

int main()
{
    int total = 10000;
    std::cout << "素数表 C++";
    clock_t start_time = clock();
    int* primes = generate_primes(total);
    for (int i = 0; i < total; i++) {
        if (i % 10 == 0) std::cout << "\n";
        std::cout << std::setw(8) << std::setfill(' ') << primes[i];
    }
    clock_t end_time = clock();
    std::cout << "\n";
    std::cout << "計：" << (double)(end_time-start_time)/CLOCKS_PER_SEC << "秒\n";
    delete[] primes;
    return 0;
}

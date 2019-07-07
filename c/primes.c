/***********************************************************
    primes.c -- 素数（C言語）
    最適化なし
    gcc primes.c -o primes (またはclang primes.c -o primes)
    最適化あり
    gcc -O3 primes.c -o primes (またはclang -O3 primes.c -o primes)
    ./primes
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_primes(int total)
{
    int* primes = malloc(sizeof(int) * total);
    primes[0] = 2;
    int x = 1;
    int j = 0;
    int k = 1;
    while (k < total) {
        x += 2;
        j = 0;
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
    int* primes;
    printf("素数表 C言語");
    clock_t start_time = clock();
    primes = generate_primes(total);
    clock_t end_time = clock();
    printf("\n");
    printf("計算時間：%f秒\n", (double)(end_time-start_time)/CLOCKS_PER_SEC);
    start_time = clock();
    for (int i = 0; i < total; i++) {
        if (i % 10 == 0) printf("\n");
        printf("%8d", primes[i]);
    }
    end_time = clock();
    printf("\n");
    printf("出力時間：%f秒\n", (double)(end_time-start_time)/CLOCKS_PER_SEC);
    free(primes);
    return 0;
}

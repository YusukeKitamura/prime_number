# coding=utf-8
# primes.py -- 素数（Python）
# python primes.py
import time

class Primes():
    def generate_primes(self, total) :
        primes = [0] * total
        primes[0] = 2
        x = 1
        k = 1
        while (k < total):
            x += 2
            j = 0;
            while (j < k and x % primes[j] != 0):
                if (primes[j] * primes[j] >= x):
                    primes[k] = x
                    k = k + 1
                    break
                j = j + 1

        return primes

print("素数表 Python")
p = Primes()
total = 10000

start_time = time.perf_counter()
primes = p.generate_primes(total)
end_time = time.perf_counter()
interval = (end_time - start_time)
print("")
print("計算時間：{0}秒".format(interval))

start_time = time.perf_counter()
for i in range(0, total):
    if (i % 10 == 0):
        print("")
    print("{:<8}".format(primes[i]), end="")

end_time = time.perf_counter()
interval = (end_time - start_time)
print("")
print("出力時間：{0}秒".format(interval))
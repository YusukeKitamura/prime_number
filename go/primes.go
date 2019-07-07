/***********************************************************
    primes.go -- 素数（Go言語）
    go run primes.go
***********************************************************/
package main
import (
    "fmt"
    "time"
)

func generate_primes(total int) []int {
    var primes [] int
    primes = append(primes, 2)
    var x, j, k int = 1, 0, 1
    for {
        if k >= total {
            break
        }
        x += 2
        j = 0
        for {
        	if j >= k || x % primes[j] == 0 {
                break
            }
            if primes[j] * primes[j] > x {
                k++
                primes = append(primes, x)
                break
            }
            j++
        }
    }
    return primes
}

func main() {
    fmt.Println("素数表 Go")
    var total int = 10000
    start_time := time.Now()
    var primes = generate_primes(total)
    end_time := time.Now()
    fmt.Println("")
    fmt.Printf("計算時間：%f秒\n", (end_time.Sub(start_time)).Seconds())

    start_time = time.Now()
    var i int = 0
    for i < total {
        if i % 10 == 0 {
            fmt.Println("")
        }
        fmt.Printf("%8d", primes[i])
        i++
    }
    end_time = time.Now()
    fmt.Println("")
    fmt.Printf("出力時間：%f秒\n", (end_time.Sub(start_time)).Seconds())
}
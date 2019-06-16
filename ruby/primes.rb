# primes.rb -- Ruby
# ruby primes.rb
class Primes
    def generate_primes(total)
        $primes = []
        $primes[0] = 2
        x = 1
        k = 1
        while (k < total)
            x += 2
            j = 0
            while (j < k && ((x % $primes[j]) != 0))
                j += 1
            end
            if (j == k)
                $primes[k] = x
                k += 1
            end
        end
        return $primes
    end
end

p = Primes.new
total = 10000
printf("素数表 Ruby")

start_time = Time.now
$primes = p.generate_primes(total)
for i in 0...total
    if (i % 10 == 0); printf("\n"); end
    printf("%8d", $primes[i])
end
end_time = Time.now

printf("\n")
interval = end_time - start_time
printf("計：%.8f秒\n", interval)
exit 0
<?php
/***********************************************************
    primes.php -- 素数（PHP）
    php primes.php
***********************************************************/


class Primes
{
    public function generate_primes($total) {
        $prime = array_fill(0, $total, 0);
        $prime[0] = 2;
        $x = 1;
        $k = 1;
        while ($k < $total) {
            $x += 2;
            $j = 0;
            while ($j < $k && $x % $prime[$j] != 0) {
                $j++;
            }
            if ($j == $k){
                $prime[$k] = $x;
                $k++;
            }
        }
        return $prime;
	}
}

echo "素数表 PHP\n";
$p = new Primes();
$total = 10000;

$start_time = microtime(true);
$primes = $p->generate_primes($total);
foreach ($primes as $i => $prime) {
    if ($i % 10 == 0) {
        echo "\n";
    }
    echo sprintf("%8d", $prime);
}
$end_time = microtime(true);

$interval = $end_time - $start_time;
echo "\n";
echo "計：". $interval ."秒\n";


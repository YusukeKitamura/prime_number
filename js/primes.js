/***********************************************************
    primes.js -- 素数（JavaScript）
    node primes.js
***********************************************************/
function generate_primes(n) {
    var primes = Array(n);
    primes[0] = 2;
    var x = 1;
    var j = 0;
    var k = 1;
    while (k < n) {
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

console.log("素数表 JavaScript");
const Total = 10000;

const {
  performance
} = require('perf_hooks');

var startTime = performance.now();
var primes = generate_primes(Total);
var endTime = performance.now();
console.log("計算時間：" + (endTime - startTime)/1000.0000 + "秒");

startTime = performance.now();
for (var i = 0; i < primes.length; i++) {
    if (i % 10 == 0) {
        console.log("");
    }
    process.stdout.write(("       " + primes[i]).slice(-8));
}
endTime = performance.now();

console.log("");
console.log("出力時間：" + (endTime - startTime)/1000.0000 + "秒");
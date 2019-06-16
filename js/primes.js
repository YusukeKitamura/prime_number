/***********************************************************
    primes.js -- 素数（JavaScript）
    node primes.js
***********************************************************/
function generate_primes(n) {
    var prime = Array(n);
    prime[0] = 2;
    var x = 1;
    var j = 0;
    var k = 1;
    while (k < n) {
        x += 2;
        j = 0;
        while (j < k && x % prime[j] != 0) j++;
        if (j == k) prime[k++] = x;
    }

    return prime;
}

console.log("素数表 JavaScript");
const Total = 10000;

var startTime = new Date();
var prime = generate_primes(Total);
for (var i = 0; i < prime.length; i++) {
    if (i % 10 == 0) {
        console.log("");
    }
    process.stdout.write(("       " + prime[i]).slice(-8));
}
var endTime = new Date();

console.log("計：" + (endTime - startTime)/1000.0 + "秒");
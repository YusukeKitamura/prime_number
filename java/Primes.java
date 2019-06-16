/***********************************************************
    primes.java -- 素数（Java）
    javac Primes.java
    java Primes
***********************************************************/
public class Primes {
    static int[] generatePrimes(int total) {  // n 個の素数を生成
        int primes[] = new int[total];
        primes[0] = 2;
        int k = 1;
        for (int x = 3; k < total; x += 2) {
            int i = 0;
            while (i < k && x % primes[i] != 0) i++;
            if (i == k) primes[k++] = x;
        }
        return primes;
    }

    public static void main(String[] args) {
        int total = 10000;
        System.out.println("素数表 Java");

        long start_time = System.currentTimeMillis();
        int[] primes = generatePrimes(total);
        for (int i = 0; i < total; i++) {
            if (i % 10 == 0) System.out.println();
            System.out.print(String.format("%8d",primes[i]));
        }
        long end_time = System.currentTimeMillis();

        System.out.println();
        System.out.println("計：" + (double)(end_time - start_time)/1000  + "秒");
    }

}
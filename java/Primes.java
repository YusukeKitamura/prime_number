/***********************************************************
    primes.java -- 素数（Java）
    javac Primes.java
    java Primes
***********************************************************/
public class Primes {
    static int[] generatePrimes(int total) {
        int primes[] = new int[total];
        primes[0] = 2;
        int k = 1;
        for (int x = 3; k < total; x += 2) {
            int i = 0;
            while (i < k && x % primes[i] != 0) {
                if (primes[i] * primes[i] >= x) {
                    primes[k++] = x;
                    break;
                }
                i++;
            }
        }
        return primes;
    }

    public static void main(String[] args) {
        int total = 10000;
        System.out.println("素数表 Java");

        long start_time = System.nanoTime();
        int[] primes = generatePrimes(total);
        long end_time = System.nanoTime();
        System.out.println();
        System.out.println("計算時間：" + (double)(end_time - start_time)/1000000000  + "秒");
        start_time = System.nanoTime();
        for (int i = 0; i < total; i++) {
            if (i % 10 == 0) System.out.println();
            System.out.print(String.format("%8d",primes[i]));
        }
        end_time = System.nanoTime();

        System.out.println();
        System.out.println("出力時間：" + (double)(end_time - start_time)/1000000000  + "秒");
    }

}
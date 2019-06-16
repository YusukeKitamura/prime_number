/***********************************************************
    primes.cs -- 素数（C#）
    mcs primes.cs
    mono primes.exe
***********************************************************/
using System;

public class Primes
{
    int[] generate_primes(int total)
    {
        int[] primes = new int[1];
        Array.Resize(ref primes, total);
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

    static public void Main()
    {
        int total = 10000;
        Primes p = new Primes();
        Console.WriteLine("素数表 C#");
        var time = new System.Diagnostics.Stopwatch();
        time.Start();
        int[] primes = p.generate_primes(total);
        for (int i = 0; i < total; i++) {
            if (i % 10 == 0) Console.WriteLine("");
            Console.Write(primes[i].ToString().PadLeft(8, ' '));
        }
        time.Stop();
        Console.WriteLine("");
        Console.WriteLine("計：{0}秒", (double)time.ElapsedMilliseconds/1000);
    }
}
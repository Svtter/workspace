/*=============================================================================
#
# Author: svtter - svtter@qq.com
#
# QQ : 57180160
#
# Last modified: 2014-11-02 13:38
#
# Filename: enum_sort.java
#
# Description: 
#
=============================================================================*/
import java.lang.Math.*;

public class enum_sort extends Thread {
    public int n;
    public int a[];
    public int b[];
    public static int NUM_THREADS = 4;
    public static int MAXN = 10000;
    public static int MAXV = 10000;
    public enum_sort(int n, int a[], int b[]) {
        this.a = a;
        this.b = b;
        this.n = n;
    }
    public void run() {
        try {
            int k;
            for(int i = n; i <= MAXN; i += NUM_THREADS) {
                k = 1;
                for(int j = 1; j <= MAXN; j++)
                    if(a[i] > a[j] || (a[i] == a[j] && i > j))
                        k++;
                b[k] = a[i];
            }
        } catch(Exception e) {}
    }

    //  build random num;
    public static void build(int a[], int a1[]) {
        for(int i = 1; i <= MAXN; i++) {
            a[i] = a1[i] = (int)(Math.random() * MAXV);
        }
    }

    public static void debug(int a[] ,int len) {
        for(int i = 1; i <= len; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("");
    }

    public static void serial(int a1[], int b1[]) {
        int k;
        for(int i = 1; i <= MAXN; i++) {
            k = 1;
            for(int j = 1; j <= MAXN; j++) {
                if(a1[i] > a1[j] || (a1[i] == a1[j] && i > j)) {
                    k++;
                }
            }
            b1[k] = a1[i];
        }
    }

    public static void main(String args[]) throws Exception { 
        int a[], b[];
        a = new int[MAXN+1];
        b = new int[MAXN+1];

        int a1[], b1[];
        a1 = new int[MAXN+1];
        b1 = new int[MAXN+1];

        enum_sort.build(a, a1);
        enum_sort.debug(a, 100);

        long start = System.currentTimeMillis(); 
        enum_sort.serial(a1, b1);
        long end= System.currentTimeMillis(); 
        long c1 = end - start;
        System.out.println("Serial time is: "+c1);
        System.out.println("Serial array is: \n");
        enum_sort.debug(b1, 100);


        start = System.currentTimeMillis(); 
        enum_sort threads[] = new enum_sort[NUM_THREADS+1];
        for(int i = 1; i < threads.length; i++) {
            threads[i] = new enum_sort(i, a, b);
        }

        for(int i = 1; i < threads.length; i++) {
            threads[i].start();
        }

        for(int i = 1; i < threads.length; i++) {
            threads[i].join();
        }
        end= System.currentTimeMillis(); 
        long c2 = end - start;
        System.out.println("Parallel time is: "+c2);
        System.out.println("parallel array is: \n");
        enum_sort.debug(b, 100);

        System.out.println("加速比："+c1/(double)c2);
    }
}


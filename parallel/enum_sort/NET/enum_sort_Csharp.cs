using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Diagnostics;

namespace parallel_csharp
{
    class Program
    {
        static int NUM_THREADS = 4;
        static int MAXN = 20000;
        static int MAXV = 10000;
        static void Main(string[] args)
        {
            int[] a, b, at, bt;
            a = new int[MAXN+10];
            b = new int[MAXN+10];
            bt = new int[MAXN+10];
            at = new int[MAXN+10];
            Stopwatch stopwatch = new Stopwatch();
            build(a, b);
            
            //enum_sort[] es = new enum_sort[NUM_THREADS + 1];
            enum_sort es = new enum_sort(a, at, b, bt, MAXN, NUM_THREADS);
            //es[0] = new enum_sort(a, at, b, bt, MAXN, NUM_THREADS);
            //int i;
            //for (i = 0; i <= NUM_THREADS; i++)
            //{
            //    es[i] = new enum_sort(a, at, b, bt, MAXN, NUM_THREADS);
            //}
           
            //serial
            //double cost1 = es[0].serial();
            double cost1 = es.serial();
            Console.WriteLine("serial time is: {0}", cost1);
            //debug(a, 100); 
            //debug(at, 100);

            //parallel
            
            ThreadStart[] thread= new ThreadStart[NUM_THREADS + 1];
            Thread[] newThread = new Thread[NUM_THREADS+1];
            int i;
            stopwatch.Start();
            for (i = 1; i <= NUM_THREADS; i++)
            {
                //thread[i] = new ThreadStart(es[i].parallel);
                thread[i] = new ThreadStart(es.parallel);
                //es.plus();
            }

            for (i = 1; i <= NUM_THREADS; i++)
            {
                newThread[i] = new Thread(thread[i]);
                //es.plus();
            }
            for (i = 1; i <= NUM_THREADS; i++)
            {
                newThread[i].Start();
                //es.plus();
            }
            for (i = 1; i <= NUM_THREADS; i++)
            {
                newThread[i].Join();
                //es.plus();
            }

            stopwatch.Stop();
            TimeSpan tsp = stopwatch.Elapsed;
            double cost2 = tsp.TotalMilliseconds;
            //debug(b, 100); 
            //debug(bt, 100);

            Console.WriteLine("parallel time is: {0}", cost2);
            Console.WriteLine("加速比为:  {0}", cost1 / cost2);
            
            //for pause
            Console.ReadLine();
        }
        public static void build(int[] a, int[] b)
        {
            Random rand = new Random();
            for (int i = 1; i <= MAXN; i++)
            {
                a[i] = b[i] = rand.Next(MAXV);
            }
        }

        // debug array
        public static void debug(int[] a, int len)
        {
            for (int i = 1; i <= len; i++)
            {
                Console.Write("{0}    ", a[i]);
            }
            Console.WriteLine();
        }
    }
    class enum_sort
    {
        //public fixed int a[MAXN+10], at[MAXN+10], b[MAXN+10], bt[MAXN+10];
        Stopwatch stopwatch;
        int[] b, bt, a, at;
        int s;
        int MAXN, NUM_THREADS;
        public enum_sort(int[] a, int [] at, int[] b, int[] bt, int MAXN, int NUM_THREADS)
        {
            this.a = a;
            this.b = b;
            this.at = at;
            this.bt = bt;
            this.MAXN = MAXN;
            this.NUM_THREADS = NUM_THREADS;
            stopwatch = new Stopwatch();
            s = 0;
        }
 
        // generate array
        public double serial() 
        {
            stopwatch.Start();
            int k, i, j;
            for (i = 1; i <= MAXN; i++)
            {
                k = 1;
                for (j = 1; j <= MAXN; j++)
                {
                    if (a[i] > a[j] || (a[i] == a[j] && i > j))
                        k++;
                }
                at[k] = a[i];
            }
            stopwatch.Stop();
            TimeSpan ts = stopwatch.Elapsed;
            double millssecond = ts.TotalMilliseconds;
            return millssecond;
        }
        public int setS(int s)
        {
            this.s = s;
            return s;
        }
        public int plus()
        {
            s++;
            return s;
        }
        private static Mutex mut = new Mutex();
        public void parallel()
        {
            mut.WaitOne();
            s++;
            mut.ReleaseMutex();
            //Console.WriteLine("Thread {0} is running...", s);
            int k, i, j;
            //for (i = 1; i <= 100; i++)
            //    Console.WriteLine("out b[{0}]: {1}", i, b[i]);
            for (i = s; i <= MAXN; i += NUM_THREADS)
            {
                k = 1;
                for (j = 1; j <= MAXN; j++)
                {
                    if (b[i] > b[j] || (b[i] == b[j] && (i > j)))
                    {
                        //Console.WriteLine("Waring!");
                        k++;
                    }
                }
                //if (k != 1)
                //    Console.WriteLine("有不等于1的情况");
                bt[k] = b[i];
            }
        }

    }
    // for test
    class Work
    {
        public static void DoWork()
        {
            Console.WriteLine("static Thread Procedure");
        }
        public int Data;
        public void DoMoreWork()
        {
            Console.WriteLine("instance thread procedure Data={0}", Data);
        }
    }
}

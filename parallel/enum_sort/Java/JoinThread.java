public class JoinThread extends Thread {
    public static int n = 0;
    static synchronized void inc() {
        n++;
    }
    public void run() {
        for(int i = 0; i < 10; i++) {
            try{
                inc();
                sleep(3);
            } catch (Exception e) {}
        }
    }

    public static void main(String args[]) throws Exception {
        Thread threads[] = new Thread[100];
        for(int i = 0; i < threads.length; i++)
            threads[i] = new JoinThread();
        for(int i = 0; i < threads.length; i++)
            threads[i].start();
        for(int i = 0; i < threads.length; i++)
            threads[i].join();
        System.out.println("n=" + JoinThread.n);
    }
}

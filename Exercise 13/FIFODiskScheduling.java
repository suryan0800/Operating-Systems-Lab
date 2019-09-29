import java.util.Scanner;
import java.util.ArrayList;

class FIFODiskScheduling
{

    ArrayList<Integer> alist1;
    Scanner scan;
    int start,n;
    float avgseek;

    FIFODiskScheduling()
    {
        scan = new Scanner(System.in);

        alist1 = new ArrayList<>();
        
        System.out.println("Enter Starting Track ");
        start = scan.nextInt();

        alist1.add(start);

        System.out.println("Enter Sequence Length ");
        n = scan.nextInt();

        System.out.println("Enter Sequence ");
        for(int i =0; i< n;i++)
        {
            alist1.add(scan.nextInt());
        }
    }

    void scheduling()
    {
        System.out.println("The Track Sequence Being Traversed ");
        System.out.println(alist1);

        avgseek = 0;

        for(int i =0; i< alist1.size()-1;i++)
        {
            int traverse = Math.abs(alist1.get(i)-alist1.get(i+1));
            avgseek += traverse;
        }

        avgseek /= n;
        System.out.println("The Average Seek Time " + avgseek);
        
    }

    public static void main(String args[])
    {
        FIFODiskScheduling fifo = new FIFODiskScheduling();
        fifo.scheduling();
    }
}

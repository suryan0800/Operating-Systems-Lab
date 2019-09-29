import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class SCANDiskScheduling
{

    ArrayList<Integer> alist1,alist2,alist3,alist4;
    Scanner scan;
    int start,n;
    float avgseek;

    SCANDiskScheduling()
    {
        scan = new Scanner(System.in);

        alist1 = new ArrayList<>();
        
        alist2 = new ArrayList<>();

        alist3 = new ArrayList<>();

        alist4 = new ArrayList<>();
        
        System.out.println("Enter Starting Track ");
        start = scan.nextInt();

        alist4.add(start);

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

        for(int i = 0; i < alist1.size(); i++)
        {
            if(alist1.get(i) < start)
            {
                alist2.add(alist1.get(i));
            } 
            else
            {
                alist3.add(alist1.get(i));
            }      
        }

        Collections.sort(alist2,Collections.reverseOrder());
        Collections.sort(alist3);

        alist4.addAll(alist3);
        alist4.addAll(alist2);

        System.out.println("The Track Sequence Being Traversed ");
        System.out.println(alist4);

        avgseek = 0;

        for(int i =0; i< alist4.size()-1;i++)
        {
            int traverse = Math.abs(alist4.get(i)-alist4.get(i+1));
            avgseek += traverse;
        }

        avgseek /= n;
        System.out.println("The Average Seek Time " + avgseek);
        
    }

    public static void main(String args[])
    {
        SCANDiskScheduling scan = new SCANDiskScheduling();
        scan.scheduling();
    }
}

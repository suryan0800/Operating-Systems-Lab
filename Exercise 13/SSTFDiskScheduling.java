import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

class SSTFDiskScheduling
{

    ArrayList<Integer> alist1,alist2;
    Scanner scan;
    int start,n;
    float avgseek;

    SSTFDiskScheduling()
    {
        scan = new Scanner(System.in);

        alist1 = new ArrayList<>();

        alist2 = new ArrayList<>();
        
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

        Collections.sort(alist1);
        int t = start;
        alist2.add(t);
        while(!alist1.isEmpty())
        {
            int ind = alist1.indexOf(t);
            if(ind - 1 >= 0 && ind + 1 < alist1.size())
            {
                if(Math.abs(t - alist1.get(ind-1)) < Math.abs(t - alist1.get(ind+1)))
                {
                    t = alist1.get(ind-1);
                    alist2.add(t);
                    alist1.remove(ind);
                } 
                else
                {
                    t = alist1.get(ind+1);
                    alist2.add(t);
                    alist1.remove(ind);
                }
            }
            else if(ind - 1 >= 0)
            {
                t = alist1.get(ind-1);
                alist2.add(t);
                alist1.remove(ind);
            }
            else if(ind + 1 < alist1.size())
            {
                t = alist1.get(ind+1);
                alist2.add(t);
                alist1.remove(ind);
            }
            else
            {
                alist1.remove(ind);
            }
        }        

        System.out.println("The Track Sequence Being Traversed ");
        System.out.println(alist2);

        avgseek = 0;

        for(int i =0; i< alist2.size()-1;i++)
        {
            int traverse = Math.abs(alist2.get(i)-alist2.get(i+1));
            avgseek += traverse;
        }

        avgseek /= n;
        System.out.println("The Average Seek Time " + avgseek);
        
    }

    public static void main(String args[])
    {
        SSTFDiskScheduling sstf = new SSTFDiskScheduling();
        sstf.scheduling();
    }
}

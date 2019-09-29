import java.util.Scanner;
import java.util.*;


class LeastRecentlyUsedPageReplacement
{
    Scanner scan;
    int f,page[],n,arr[],k;
    ArrayList<Integer> alist;
    
    LeastRecentlyUsedPageReplacement()
    {
        scan = new Scanner(System.in);
        
        System.out.println("Enter No of Frames ");
        f = scan.nextInt();

        page = new int[f];

        System.out.println("Enter Sequence Length ");
        n = scan.nextInt();
    
        arr = new int[n];
        System.out.println("Enter Sequence ");
        for(int i = 0; i < n; i++)
        {
            arr[i] = scan.nextInt();
        }

        alist = new ArrayList<>();
        
    }
    
   
    void pageReplacement()
    {
        
        for(k=0 ;k<n;k++)
        {
            if(findPage(arr[k]) != -1)
            {
                System.out.println("Page Hit ");
            }
            else
            {
               int l = leastRecentPage();
               page[l] = arr[k];
               printPage(); 
            }
        
            alist.add(arr[k]);
          
        }

    }

    int leastRecentPage()
    {
       // System.out.println(alist);
        int ind = -1;
        int min = 99;
        for(int i = 0; i < f;i++)
        {
            if(page[i] == 0){   return i; }
            if(alist.lastIndexOf(page[i]) < min)
            {
                min = alist.lastIndexOf(page[i]);
                ind = i;
            }
        }

        return ind;
    }

    

    int findPage(int p)
    {
        
        for(int i = 0; i < page.length; i++)
        {
            
            if(p == page[i])
            {
                return i;
            }
        }

        return -1;
    }

    void printPage()
    {
        for(int i = 0; i < page.length;i++)
        {
            System.out.print(page[i]);
        }
        System.out.println();
    }

    public static void main(String args[])
    {
       
        LeastRecentlyUsedPageReplacement lrupr = new LeastRecentlyUsedPageReplacement();

        lrupr.pageReplacement();
    }

    
}

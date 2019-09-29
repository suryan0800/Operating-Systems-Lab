import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class LeastFrequentlyUsedPageReplacement
{
    Scanner scan;
    int f,page[],n,arr[],k;
    HashMap<Integer,Integer> hmap;
    
    LeastFrequentlyUsedPageReplacement()
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

        hmap = new HashMap<>();
        
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
               int l = leastUsedPage();
               page[l] = arr[k];
               printPage(); 
            }
        
            addToHmap(arr[k]);
        }

    }

    int leastUsedPage()
    {
        int ind = -1;
        int min = 99;
        for(int i = 0; i < f;i++)
        {
            if(page[i] == 0){   return i; }
            if(hmap.get(page[i]) < min)
            {
                min = hmap.get(page[i]);
                ind = i;
            }
        }

        return ind;
    }

    void addToHmap(int p)
    {
        if(hmap.containsKey(p))
        {
            hmap.put(p,hmap.get(p)+1);
        }
        else{   hmap.put(p,1); }
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
       
        LeastFrequentlyUsedPageReplacement lfupr = new LeastFrequentlyUsedPageReplacement();

        lfupr.pageReplacement();
    }

    
}

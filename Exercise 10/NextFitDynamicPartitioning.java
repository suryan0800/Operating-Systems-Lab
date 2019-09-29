
import java.util.Scanner;
import java.util.LinkedList;
import java.util.ListIterator;

class Space
{
	 int process;
     int flag;
     int start;
     int finish;

    Space()
    {
        flag = start = finish = 0;
        process = -1;
    }
    
    Space(int f,int s, int fh)
    {
    	process = -1;
        flag = f;
        start = s;
        finish = fh;
    }
    
    void allocate(int p,int f,int s, int fh)
    {
    	process = p;
        flag = f;
        start = s;
        finish = fh;
    }
}

class NextFitDynamicPartitioning
{

    int size;
    Scanner scan;
    LinkedList<Space> llist;
    Space s1;
    ListIterator<Space> iter, iter1;
    int index;

    NextFitDynamicPartitioning()
    {
        scan = new Scanner(System.in);
        
        System.out.println("Enter Size of RAM ");
        size = scan.nextInt();

        llist = new LinkedList<>();
       
        s1 = new Space(0,0,size-1);
        llist.add(s1);
        index = 0;
    }

    int addToList(int p,int sp)
    {
        iter1 = llist.listIterator(index);
        
        while(true)
        {
        	if(iter1.nextIndex() == index - 1) {	break; }
        	s1 = iter1.next();
        	if(s1.flag == 0 && s1.finish - s1.start + 1 >= sp )
        	{
        		index = iter1.previousIndex();
        		s1.process = p;
        		s1.flag = 1;
        		if(s1.finish - s1.start + 1 != sp)
        		{
	        		int fin = s1.finish;
	        		s1.finish = s1.start + sp -1;
	        		Space s2 = new Space(0,s1.finish+1,fin);
	        		
	        		llist.add(iter1.nextIndex(),s2);
        		}
        		return 0;
        		
        	}
        	if(!iter1.hasNext()) {	iter1 = llist.listIterator(0);}
        	
        }
        
        return -1;
    }
    
    void removeFromList(int p)
    {
    	iter = llist.listIterator();
    	
    	while(iter.hasNext())
    	{
    		s1 = iter.next();
    		if(s1.flag == 1 && s1.process == p)
    		{
    			s1.flag = 0;
    			s1.process = -1;
    			if(iter.previousIndex() - 1 >= 0)
    			{
	    			Space s2 = llist.get(iter.previousIndex()-1);
	    			
	    			
	    			if(s2.flag == 0)
					{
	    				
						s1.start = s2.start;
						llist.remove(s2);
					}
    			}
    			if(iter.nextIndex() < llist.size())
    			{
    				Space s3 = llist.get(iter.nextIndex());
    				if(s3.flag == 0)
	    			{
	    				
	    				s1.finish = s3.finish;
	    				llist.remove(s3);
	    			}
    			}
    			break;
    		}
    	}
    	
    }

    void display()
    {
    	iter = llist.listIterator();
    	System.out.println("Process \t Flag \t Start \t Finish ");
    	while(iter.hasNext())
    	{
    		s1 = iter.next();
    		System.out.println(s1.process + "  \t\t" + s1.flag + "\t" + s1.start + "\t" + s1.finish);
    	}
    }
    public static void main(String args[])
    {
        NextFitDynamicPartitioning dp = new NextFitDynamicPartitioning();
        dp.addToList(1,8);
        dp.addToList(2,30);
        dp.addToList(3,12);
        dp.addToList(4,10);
        dp.addToList(5,22);
        dp.addToList(6,25);
        dp.addToList(7,18);
        dp.addToList(8,10);
        dp.addToList(9,10);
        dp.addToList(10,8);
        dp.addToList(11,10);
        dp.addToList(12,6);
        dp.addToList(13,25);
        dp.addToList(14,14);
        dp.addToList(15,25);
        dp.display();
        
        dp.removeFromList(1);
        dp.display();
        dp.removeFromList(3);
        dp.display();
        dp.removeFromList(5);
        dp.display();
        dp.removeFromList(7);
        dp.display();
        dp.removeFromList(10);
        dp.display();
        dp.removeFromList(12);
        dp.display();
        dp.removeFromList(14);
        dp.display();
        
        dp.addToList(16,16);
        dp.display();
    }
}

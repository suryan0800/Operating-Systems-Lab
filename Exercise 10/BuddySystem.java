
import java.util.Scanner;
import java.util.LinkedList;
import java.util.ListIterator;

class Space
{
	 int process;
     int flag;
     int u;
     int size;

    Space()
    {
        flag = u  = 0;
        size = 1;
        process = -1;
    }
    
    Space(int f,int s, int fh)
    {
    	process = -1;
        flag = f;
        u = s;
        size = fh;
    }
    
    
}

class BuddySystem
{

    int size;
    Scanner scan;
    LinkedList<Space> llist;
    Space s1;
    ListIterator<Space> iter ;

    BuddySystem()
    {
        scan = new Scanner(System.in);
        
        System.out.println("Enter Size of RAM in terms of 2 power");
        size = scan.nextInt();

        llist = new LinkedList<>();
       
        s1 = new Space(0,size,(int)Math.pow(2,size));
        llist.add(s1);
        
    }

    int addToList(int p,int sp)
    {
        iter = llist.listIterator(0);
        
        while(iter.hasNext())
        {
        	s1 = iter.next();
        	if(s1.flag == 0 && s1.size >= sp)
        	{
                while(Math.pow(2,s1.u-1) >= sp)
                {
                    s1.u = s1.u-1;
                    s1.size = (int)Math.pow(2,s1.u);

                    Space s2 = new Space(0,s1.u,s1.size);
                    llist.add(iter.nextIndex(),s2);
                    
                }
                s1.flag = 1;
                s1.process = p;
                return 0;
              	
        	} 
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
                while(true)
                {
                    int ind = llist.indexOf(s1);
                    Space s2=null,s3=null;
                    if(ind - 1 >=0 )
                     s2 = llist.get(ind - 1);
                    if(ind+1 < llist.size())
                     s3 = llist.get(ind + 1);
        			if(s2!= null && s2.flag == 0 && s2.size == s1.size)
        			{
   				
						    s1.u +=1;
                            s1.size *= 2;
						    llist.remove(s2);
					    
        			}
        			else if(s3!=null && s3.flag == 0 && s3.size == s1.size)
        			{
        						
	        			    s1.u +=1;
                            s1.size *= 2;
	        				llist.remove(s3);
                        
        			}
                    else{   break;   }
                    
                }
    			break;
             
    		}
    	}
    	
    }

  

    void display()
    {
    	iter = llist.listIterator();
    	System.out.println("Process \t Flag \t Size ");
    	while(iter.hasNext())
    	{
    		s1 = iter.next();
    		System.out.println(s1.process + "  \t\t" + s1.flag  + "\t" + s1.size);
    	}
    }
    public static void main(String args[])
    {
        BuddySystem bs = new BuddySystem();

        bs.display();
       
        bs.addToList(1,2);
        bs.addToList(2,4);
        bs.addToList(3,1);
        bs.addToList(4,4);
        bs.display();

        bs.removeFromList(2);
        bs.display();
        bs.removeFromList(1);
        bs.display();
        
        bs.addToList(5,2);
        bs.display();

        bs.removeFromList(3);
        bs.display();
        bs.removeFromList(5);
        bs.display();
        bs.removeFromList(4);
        bs.display();
        /*
        bs.addToList(2,30);
        bs.addToList(3,12);
        bs.addToList(4,10);
        bs.addToList(5,22);
        bs.addToList(6,25);
        bs.addToList(7,18);
        bs.addToList(8,10);
        bs.addToList(9,10);
        bs.addToList(10,8);
        bs.addToList(11,10);
        bs.addToList(12,6);
        bs.addToList(13,25);
        bs.addToList(14,14);
        bs.addToList(15,25);
        bs.display();
        
        bs.removeFromList(1);
        bs.display();
        bs.removeFromList(3);
        bs.display();
        bs.removeFromList(5);
        bs.display();
        bs.removeFromList(7);
        bs.display();
        bs.removeFromList(10);
        bs.display();
        bs.removeFromList(12);
        bs.display();
        bs.removeFromList(14);
        bs.display();
        
        bs.addToList(16,16);
        bs.display();

        */
    }
}

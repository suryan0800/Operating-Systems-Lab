import java.util.Scanner;


class Space
{
	 int process;
     int flag;
     int u;
     int size;
     Space left;
     Space right;
     

    Space()
    {
        flag = u  = 0;
        size = 1;
        process = -1;
        left = right = null;
    }
    
    Space(int f,int s, int fh)
    {
    	process = -1;
        flag = f;
        u = s;
        size = fh;
        left = right = null;
    }
    
    
}

class BuddySystem1
{

    int size;
    Scanner scan;
   
    Space s1;
    int flag1;
   

    BuddySystem1()
    {
        scan = new Scanner(System.in);
        
        System.out.println("Enter Size of RAM in terms of 2 power");
        size = scan.nextInt();

    
       
        s1 = new Space(0,size,(int)Math.pow(2,size));
      
        
    }

    void addToList(Space root, int p, int sp)
    {
    	if(root == s1) {	flag1 = 0;	}
    	if (root == null || flag1 == 1)
    		return;

    		if (root.left == null && root.right == null && root.flag == 0 && root.size >= sp)
    		{
    			Space s2 = root;
    			
				while(s2.size/2 >= sp)
                {
					Space s3 = new Space(0,s2.u-1,(s2.size/2));
					Space s4 = new Space(0,s2.u-1,(s2.size/2));
					
					s2.left = s3;
					s2.right = s4;
					
                    s2 = s3;
                                
                }
                s2.flag = 1;
                s2.process = p;
    			flag1 = 1;
    			return;
    			//System.out.println(s1.process + "  \t\t" + s1.flag  + "\t" + s1.size);
    			
    		}

    		addToList(root.left,p,sp);
    		addToList(root.right,p,sp);
    }
    
    void removeFromList(Space root, int p)
    {
    	
    	
    	if(root == s1) {	flag1 = 0;	}
    	if (root == null || flag1 == 1)
    		return;

    		if (root.left == null && root.right == null && root.flag == 1 && root.process == p )
    		{
    			root.flag = 0;
    			root.process = -1;
    			return;
    			//System.out.println(s1.process + "  \t\t" + s1.flag  + "\t" + s1.size);
    			
    		}

    		removeFromList(root.left,p);
    		removeFromList(root.right,p);
    		
    		if(root != null &&
        			root.left != null && root.left.left == null && root.left.right == null &&
        			root.right != null && root.right.left == null && root.right.right == null && 
        			root.left.flag == 0 && root.right.flag == 0)
        	{
        		root.flag = 0;
        		root.process = -1;
        		root.left = root.right = null;
        		return;
        	}
    }

  

    void display(Space root)
    {
    	if (root == null)
    		return;

		if (root.left == null && root.right == null)
		{
			System.out.println(root.process + "  \t\t" + root.flag  + "\t" + root.size);
		}

		display(root.left);
		display(root.right);
    }
    public static void main(String args[])
    {
        BuddySystem1 bs = new BuddySystem1();

        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
       
        bs.addToList(bs.s1,1,2);
        bs.addToList(bs.s1,2,4);
        bs.addToList(bs.s1,3,1);
        bs.addToList(bs.s1,4,4);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);

        bs.removeFromList(bs.s1,2);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
        bs.removeFromList(bs.s1,1);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
        
        bs.addToList(bs.s1,5,2);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);

        bs.removeFromList(bs.s1,3);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
        bs.removeFromList(bs.s1,5);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
        bs.removeFromList(bs.s1,4);
        System.out.println("Process \t Flag \t Size ");
        bs.display(bs.s1);
        
        
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

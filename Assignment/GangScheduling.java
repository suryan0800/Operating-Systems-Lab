package os;

import java.util.Comparator;
import java.util.Collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
class Process implements Comparable<Process>
{
	int id;
	int iscomp;
	int service;
	int arrival;
	int threads;
	int start;
	int finish;
	
	public int compareTo(Process p)
	{
		return (int)(this.arrival - p.arrival);
	}
	
	public String toString()
	{
		return (id + " ");
	}
}

class SortByThreads implements Comparator<Process>
{
	public int compare(Process p1,Process p2)
	{
		return (int)( p2.threads - p1.threads);
	}
}
public class GangScheduling {
	
	int p;
	int size;
	Process pss[];
	ArrayList<Process> queue;
	
	int front,rear;
	Random r;
	int processor[];
	int cnt;
	GangScheduling()
	{
		
		r = new Random();
		p = 10; // No of Processors
		processor = new int[p];
		size = 10; // No of Processes
		pss = new Process[size];
		int cnt = 0;
		queue = new ArrayList<Process>();
		
		for(int i = 0; i < size; i++)
		{
			pss[i] = new Process();
			pss[i].id = i;
			pss[i].iscomp = 0;
			pss[i].service = r.nextInt(10)+1;
			pss[i].arrival = r.nextInt(20);
			pss[i].threads = r.nextInt(10)+1;
		}
		
	}
	
	void printProcess1()
	{
		
		System.out.println("Id \t Arrival \t Service \t Threads \t Start \t\t Finish \t TAT ");
		
		for(int i = 0; i < size; i++)
		{
			System.out.println(pss[i].id + "\t" 
							 + pss[i].arrival + "\t\t" 
							 + pss[i].service + "\t\t" 
							 + pss[i].threads + "\t\t" 
							 + pss[i].start + "\t\t" 
							 + pss[i].finish + "\t\t"
							 + (pss[i].finish - pss[i].arrival));
		}
	}
	
	void printProcess()
	{
		
		System.out.println("Id \t Arrival \t Service \t Threads ");
		
		for(int i = 0; i < size; i++)
		{
			System.out.println(pss[i].id + "\t" 
							 + pss[i].arrival + "\t\t" 
							 + pss[i].service + "\t\t" 
							 + pss[i].threads);
		}
	}
	
	void scheduling()
	{
		printProcess();
		
		Arrays.sort(pss);
		
		//printProcess();
		
		int h = 0;
		int sum = pss[0].arrival;
		for(int time = 0; (queue.size() > 0) || (h < pss.length); time++)
		{
			
			
			while(h < pss.length && pss[h].arrival == time)
			{
				queue.add(pss[h]);
			//	System.out.print(pss[h]);
				h++;
				
				Collections.sort(queue,new SortByThreads());
				
			}
			
			//System.out.println(queue);
			cnt = 0;
			for(int i =0 ; i < p; i++)
			{
				if(processor[i] > 0)
				{
					processor[i]--;
				}
				
			    if(processor[i] == 0)
				{
					cnt++;
				}
			}
			
			System.out.println("Time : " + time);
			while(cnt > 0 && queue.size() > 0)
			{
			
			//sum += queue.first().service;
				
				if(queue.get(0).threads <= cnt)
				{
					for(int i = 0; i < queue.get(0).threads ; i++)
					{
						int j = 0;
						while(j < p && processor[j] != 0 ) {j++;}
						processor[j] = queue.get(0).service;
					}
					System.out.print(queue.get(0));
					cnt -= queue.get(0).threads;
					queue.get(0).start = time;
					queue.get(0).finish= time + queue.get(0).service;
					
					queue.remove(0);
					Collections.sort(queue,new SortByThreads());
				}
				else if(queue.get(queue.size()-1).threads <= cnt)
				{
					for(int i = 0; i < queue.get(queue.size()-1).threads;i++)
					{
						int j =0;
						while(j < p && processor[j] != 0) {j++;}
						processor[j] = queue.get(queue.size()-1).service;
					}
					System.out.print(queue.get(queue.size()-1));
					cnt -= queue.get(queue.size()-1).threads;
					queue.get(queue.size()-1).start = time;
					queue.get(queue.size()-1).finish = time + queue.get(queue.size()-1).service;
					
					queue.remove(queue.size()-1);
					Collections.sort(queue,new SortByThreads());
				}
				else { break; }
			}
			System.out.println();
		}
		
		printProcess1();
	}
	
	
	public static void main(String args[])
	{
		GangScheduling gs = new GangScheduling();
		gs.scheduling();
		
	}

}

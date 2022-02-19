import java.util.ArrayList; 
import java.util.Scanner;
import java.util.Collections;


public class SRTF implements Comparable<SRTF>{
	
	int complete, burst_time, wait_time, id, arrival_time ;
	int remain_burst_time, turnAround_time ; 
	
	public SRTF(int burst_time,int id, int arrival_time) {
		this.id = id ; 
		this.arrival_time = arrival_time ; 
		this.burst_time = burst_time ; 
		this.wait_time = 0 ; 
		this.complete = arrival_time ; 
		this.remain_burst_time = burst_time ; 
	}
	
	public int compareTo(SRTF process) {
		return this.arrival_time - process.arrival_time ; 
	}

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in) ;
		System.out.print("Enter number of processes : ");
		int n = input.nextInt() ; 
		
		ArrayList<SRTF> arr = new ArrayList<SRTF>() ;
		
		for(int i=0 ; i<n ; i++) {
			System.out.print("Enter id, burst time, arrival time : ");
			int id=input.nextInt(), burst=input.nextInt(), arrival=input.nextInt() ; 
			arr.add(new SRTF(burst, id, arrival)) ; 
		}
		// Before sorting according to arrival time of each process
		for(SRTF process : arr) {
			System.out.println("id: " + process.id + ",  burst: "+process.burst_time + ",  arrival time: " + process.arrival_time);
		}
		
//		Collections.sort(arr); 
//		To detect the sorting according to arrival time of each process
//		for(SRTF process : arr) {
//			System.out.println("id: " + process.id + ",  burst: "+process.burst_time + ",  arrival time: " + process.arrival_time);
//		}
		
		int current_time=0, numOf_process=0 ;
		
		Collections.sort(arr);

		while(numOf_process!=n) {
			ArrayList<Integer> indices = new ArrayList<Integer>() ; 
			
			for( int i=0 ; i<n ; i++) {
				
				if( arr.get(i).arrival_time<=current_time && arr.get(i).remain_burst_time>0 ) {
					indices.add(i) ; 
					arr.get(i).complete++ ;
				}
				
			}
			if(indices.size() != 0) {
				int minBurst=arr.get(indices.get(0)).burst_time, idxMinBurst=indices.get(0) ; 
				for(int i=0 ; i<indices.size() ; i++) {
					
					if(arr.get(indices.get(i)).burst_time < minBurst ) {
						idxMinBurst = indices.get(i) ;
						minBurst = arr.get(indices.get(i)).burst_time ; 
					}
				}
				arr.get(idxMinBurst).remain_burst_time-- ; 
			}
			
			current_time++ ;
			
			for(int i=0 ; i<indices.size() ; i++) {
				if( arr.get(indices.get(i)).remain_burst_time == 0 ) {
					numOf_process++ ; 
				}
			}
		}
		
		
		// To handle turn-around time of each process
		// As known that turn-around time = complete-arrival & wait=turn around - burst time
		float wait_avg=0, turnAround_avg=0 ; 
		for(int i=0 ; i<n ; i++) {
			arr.get(i).turnAround_time = arr.get(i).complete - arr.get(i).arrival_time ;
			arr.get(i).wait_time = arr.get(i).turnAround_time - arr.get(i).burst_time ;
			wait_avg += arr.get(i).wait_time ; 
			turnAround_avg += arr.get(i).turnAround_time ; 
			//arr.get(i).complete -= arr.get(i).arrival_time ; 
		}
		
		wait_avg /= n ; 
		turnAround_avg /= n ; 
		
		for(SRTF process : arr) {
			System.out.println();
			System.out.println("*********************");
			System.out.println("id: "+process.id+",  burst: "+process.burst_time+",  arrival time: "+process.arrival_time);
			System.out.println(",  complete time: "+process.complete+",  waiting time: "+process.wait_time+ ",  turn-around time: "+process.turnAround_time) ; 
		}
		
		System.out.println("*********************");
		System.out.println("The average wait is : " + wait_avg) ; 
		System.out.println("The average turn-around is : " + turnAround_avg);
	}

}

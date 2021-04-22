/**
 * @author Tawfik Yasser
 * @since 4-2021
 * */
// Program imports below
import java.util.ArrayList;
import java.util.Scanner;
// The following class to represent the process
// ** In future i will fix the name "process" to "Process"
class process {
    String name;
    int burset_time;
    int arrive_time;
    int waiting_time;
    int turn_round_time;
    int temp_time;
    int queueNumber;
    
    //Priority Algorithm
    private int processID;
    private int priority;

    public process() {
        this.processID = 0;
        this.priority = 0;
        this.arrive_time = 0;
        this.burset_time = 0;
    }

    public process(String name, int burset_time, int arrive_time) {
        this.arrive_time = arrive_time;
        this.burset_time = burset_time;
        this.name = name;
        this.temp_time = burset_time;
    }

    public process(String name, int burset_time, int arrive_time, int queueNumber) {
        this.name = name;
        this.burset_time = burset_time;
        this.arrive_time = arrive_time;
        this.queueNumber = queueNumber;
    }

    public process(int processID, int priority, int arrivingTime, int burstTime) {
        this.processID = processID;
        this.priority = priority;
        this.arrive_time = arrivingTime;
        this.burset_time = burstTime;
    }

    public int getProcessID() {
        return processID;
    }

    public void setProcessID(int processID) {
        this.processID = processID;
    }

    public int getPriority() {
        return priority;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public void setWaiting_time(int waiting_time) {
        this.waiting_time = waiting_time;
    }

    public void setTurn_round_time(int turn_round_time) {
        this.turn_round_time = turn_round_time;
    }

    public void setTemp_burset_time(int temp_burset_time) {
        this.temp_time = temp_burset_time;
    }

    public int getWaiting_time() {
        return waiting_time;
    }

    public int getTurn_round_time() {
        return turn_round_time;
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setBurset_time(int burset_time) {
        this.burset_time = burset_time;
    }

    public void setArrive_time(int arrive_time) {
        this.arrive_time = arrive_time;
    }

    public int getBurset_time() {
        return burset_time;
    }

    public int getTemp_burset_time() {
        return temp_time;
    }

    public int getArrive_time() {
        return arrive_time;
    }

    public int getQueueNumber() {
        return queueNumber;
    }

    public void setQueueNumber(int queueNumber) {
        this.queueNumber = queueNumber;
    }

    public void reduceTime(int time) {
        if(burset_time >= time)
            burset_time = burset_time - time;
    }
}

// ****************** The following class to start the MLQ Algorithm, Called from the main
class MultiLevelQueueScheduling {
    public MultiLevelQueueScheduling() {

    }

    public void MLQ(int number,process[] processes,int quantum){
        float totalwt = 0, totaltat = 0;
        int[] completionTime = new int[number], waitingTime = new int[number], turnaroundTime = new int[number];
        ArrayList<Integer> RRQueue = new ArrayList<Integer>(); // Queue to store Round Robin Processes Indexes
        ArrayList<Integer> FCFSQueue = new ArrayList<Integer>(); // Queue to store FCFS Processes Indexes

        for (int i = 0; i < number; i++) {
            if (processes[i].getQueueNumber() == 1) {
                RRQueue.add(i);
            }else{
                FCFSQueue.add(processes[i].getQueueNumber());
            }
        }

        int[] highPriorityProcessArray = new int[number]; // Array to work on it instead of the RRQueue
        for (int i = 0; i < RRQueue.size(); i++) {
            highPriorityProcessArray[i] = RRQueue.get(i);
        }

        int rem_bt[] = new int[RRQueue.size()]; // Array to store the burst time of each process from RRQueue and work on it.
        for (int i = 0; i < RRQueue.size(); i++) {
            rem_bt[i] = processes[highPriorityProcessArray[i]].getBurset_time();
        }
        int rem_bt_2[] = new int[FCFSQueue.size()]; // Array to store the burst time of each process from FCFSQueue and work on it.
        for (int i =0;i<FCFSQueue.size();i++){
            rem_bt_2[i] = processes[FCFSQueue.get(i)].getBurset_time();
        }

        int t = completionTime[0]; // t is the starting time of executing processes (t=0)
        int flag  =0;

        //Starting to execute the processes
        while (true) {
            boolean done = true;

            // Starting of executing the Round Robin Queue Processes
            for (int i = 0; i < RRQueue.size(); i++)
            {
                //Checking if the process arrived and still has burst time
                if (processes[RRQueue.get(i)].getArrive_time() <= t && rem_bt[i] > 0) {
                    //System.out.println("Process "+processes[RRQueue.get(i)].getName()+" Arrived Now - Time: "+t);
                    // Check again for burst time if still greater than 0
                    if (rem_bt[i] > 0) {
                        done = false; // Processes still working

                        //Checking if the process still has burst time
                        if (rem_bt[i] > quantum) {
                            System.out.println("Process "+processes[RRQueue.get(i)].getName()+" Running Now.");
                            // Increase the value of t of the program and shows how much time a process has been processed.
                            t += quantum;
                            // Decrease the burst_time of current process by quantum
                            rem_bt[i] -= quantum;
                        }
                        // If burst time is smaller than or equal to quantum. So this is the last loop this process
                        else {
                            System.out.println("Process "+processes[RRQueue.get(i)].getName()+" Running Now.");
                            // Increase the value of t
                            t = t + rem_bt[i];
                            completionTime[highPriorityProcessArray[i]] = t; //Calculate that process completion time.
                            //--> [Turnaround Time = Completion Time - Arrival Time]
                            turnaroundTime[highPriorityProcessArray[i]] = completionTime[highPriorityProcessArray[i]]
                                    - processes[highPriorityProcessArray[i]].getArrive_time();//Calculate the process turnaround time
                            //--> [Waiting Time = Turnaround Time - Burst Time]
                            waitingTime[highPriorityProcessArray[i]] = turnaroundTime[highPriorityProcessArray[i]]
                                    - processes[highPriorityProcessArray[i]].getBurset_time();//Calculating the process waiting time
                            // And finally that process finished it’s work so the burst time will be ZERO now.
                            rem_bt[i] = 0;
                            System.out.println("Process "+processes[RRQueue.get(i)].getName()+" Finished Work - Time: "+t);
                        }
                    }

                }

                //Here we are check if there are another processes need to work in the second queue.
                flag=0;
                for(int k = 0 ; k <RRQueue.size();k++){
                    if(rem_bt[k] == 0 || processes[RRQueue.get(k)].getArrive_time() > t){
                        flag++;
                    }
                }
            }
            //Position a variable to store the position of the processes from the second queue.
            int position =0;
            if(flag==RRQueue.size()){
                //Looping on the second queue and execute the processes until the first queue filled again.
                for (int j = 0; j < FCFSQueue.size(); j++) {
                    String fl = " ";//Flag
                    do{
                        //System.out.println("Process "+processes[FCFSQueue.get(j)].getName()+" Arrived Now - Time: "+t);
                        //The following loop to get the process position.
                        for(int y =0;y<number;y++){
                            if(processes[FCFSQueue.get(j)].getName().equals(processes[y].getName())){
                                position = y;
                                break;
                            }
                        }
                        //Calculating the Completion time and turnaround time and waiting time for each process in FCFSQueue.
                        completionTime[position] = t;
                        turnaroundTime[position] = completionTime[position] - processes[position].getArrive_time();
                        waitingTime[position] = turnaroundTime[position] - processes[position].getBurset_time();
                        if(rem_bt_2[j]==0){
                            System.out.println("Process "+processes[FCFSQueue.get(j)].getName()+" Finished Work - Time: "+t);
                        }else {
                            System.out.println("Process "+processes[FCFSQueue.get(j)].getName()+" Running Now.");
                        }
                        t++;//Increase the time.
                        rem_bt_2[j] -= 1;//Decrease the process burst time.
                        //Every unit of time checking if there are new process in the first queue.
                        //So we should stop the FCFS queue execution and go back to the first queue because the first queue has higher priority.
                        for(int h = 0 ; h<RRQueue.size();h++){
                            if(t == processes[RRQueue.get(h)].getArrive_time()){
                                System.out.println("Process "+processes[FCFSQueue.get(j)].getName()+" Blocked Temporary (X) at Time: "+t);
                                fl = "out";
                                break;
                            }
                        }

                    }while(fl.equals(" ") && rem_bt_2[j] >0);
                    if(!fl.equals(" ")){
                        break;
                    }
                }
            }

            // If all processes are done their execution.
            if (done == true)
                break;
        }


        //Printing the final results of execution.
        System.out.println("\nProcess Name\t\t Queue Number \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time");
        for (int i = 0; i < number; i++) {
            System.out.println("\n\t" + processes[i].getName() + "\t\t\t\t\t" + processes[i].getQueueNumber() + "\t\t\t\t" + processes[i].getBurset_time() + "\t\t\t\t" + completionTime[i] + "\t\t\t\t" + waitingTime[i] + "\t\t\t\t" + turnaroundTime[i]);
        }

        //Calculating the AVG Waiting Time and Turnaround Time
        for (int i = 0; i < number; i++) {
            totalwt += waitingTime[i];
            totaltat += turnaroundTime[i];
        }
        System.out.println("\n" + "Average Waiting Time is: " + totalwt / number);
        System.out.println("Average Turnaround Time is : " + totaltat / number);
    }
}

// The following is the Main function to run the program

public class Main {
    public static void main(String[] args) {
        System.out.print("\n");
        System.out.println("Welcome to the CPU Scheduler Simulator >>>>> (OS)");
        System.out.println("-------------------------------------------------");
        System.out.println("Running the Multi-Level Queue Scheduling Algorithm");
        multiLevelScheduling();
    }
    
        public static void multiLevelScheduling() {
        int quantum = 0;
        int number;
        System.out.println("Enter number of processes: ");
        Scanner scanner = new Scanner(System.in);
        number = scanner.nextInt();
        process[] processes = new process[number];

        for (int i = 0; i < number; i++) {

            System.out.println("Enter the name of process " + (i + 1) + " : ");
            String name = scanner.next();
            System.out.println("Enter the arrival time of process " + (i + 1) + " : ");
            int arrival = scanner.nextInt();
            System.out.println("Enter the burst time of process " + (i + 1) + " : ");
            int burst = scanner.nextInt();
            System.out.println("Enter the queue number of process " + (i + 1) + " : ");
            int qNumber = scanner.nextInt();

            process process = new process(name, burst, arrival, qNumber);
            processes[i] = process;
        }
        System.out.println("Enter the quantum time: ");
        quantum = scanner.nextInt();
        MultiLevelQueueScheduling multiLevelQueueScheduling = new MultiLevelQueueScheduling();
        multiLevelQueueScheduling.MLQ(number,processes,quantum);

    }
}
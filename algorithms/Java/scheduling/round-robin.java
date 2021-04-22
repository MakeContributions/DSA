/**
 * @author Tawfik Yasser
 * @since 4-2021
 * */
// Program imports below
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

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

// ****************** The following class to start the Round Robin Algorithm, Called from the main

class RoundRobin {
    public ArrayList<process> round_processes=new ArrayList<>();
    private int Quantum_time;
    private int total_time;

    public void setContext_switching(int context_switching) {
        this.context_switching = context_switching;
    }

    public int getContext_switching() {
        return context_switching;
    }

    private int context_switching;
    void setQuantum_time(int q)
    {
        this.Quantum_time=q;
    }
    private void sort_process ()
    {
        Collections.sort(round_processes, Comparator.comparing(process :: getArrive_time));
    }
    void round_robien ()
    {
        sort_process();
        int flag=0,i=0,temp;
        while (flag!=round_processes.size())
        {
            if (round_processes.get(i).getBurset_time()!=0)
            {

                if (round_processes.get(i).getBurset_time()>=Quantum_time)
                {
                    System.out.println("process :"+round_processes.get(i).getName()+"is running");
                    total_time+=Quantum_time;
                    temp=round_processes.get(i).getBurset_time();
                    temp-=Quantum_time;
                    round_processes.get(i).setBurset_time(temp);
                    if (temp==0)
                    {
                        flag++;
                        round_processes.get(i).setTurn_round_time(total_time);
                        System.out.println("process :"+round_processes.get(i).getName()+"is terminated");
                        i++;
                    }
                    else {
                        System.out.println("process :"+round_processes.get(i).getName()+"is waiting");
                        i++;}
                    total_time+=context_switching;

                }
                else if (round_processes.get(i).getBurset_time()<Quantum_time)
                {
                    System.out.println("process :"+round_processes.get(i).getName()+"is running");
                    total_time+=round_processes.get(i).getBurset_time();
                    round_processes.get(i).setBurset_time(0);
                    round_processes.get(i).setTurn_round_time(total_time);
                    flag++;
                    System.out.println("process :"+round_processes.get(i).getName()+"is terminated");
                    i++;
                    total_time+=context_switching;
                }
            }
            else
                i++;
            if (i==round_processes.size())
                i=0;
        }
    }
    public double calculate_average_waiting() {
        double av=0;

        for (int i = 0; i < round_processes.size(); i++) {
            av+=round_processes.get(i).getTurn_round_time()-round_processes.get(i).getTemp_burset_time();
        }
        return (av/round_processes.size());
    }
    public double calculate_average_turnround() {
        double av=0;

        for (int i = 0; i < round_processes.size(); i++) {
            av+=round_processes.get(i).getTurn_round_time();
        }
        return (av/round_processes.size());
    }
    public void print ()
    {
        for (int i=0;i<round_processes.size();i++)
        {
            System.out.print("Name: "+round_processes.get(i).getName()+" ");
            System.out.println("turn round time: "+round_processes.get(i).getTurn_round_time());
            System.out.print("waiting time: "+(round_processes.get(i).getTurn_round_time()-round_processes.get(i).getTemp_burset_time())+"\n");
        }
        System.out.println("average waiting time : "+calculate_average_waiting());
        System.out.println("average turn_round_time : "+calculate_average_turnround());
    }
}

// The following is the Main function to run the program

class Main {
    public static void main(String[] args) {
        System.out.print("\n");
        System.out.println("Welcome to the CPU Scheduler Simulator >>>>> (OS)");
        System.out.println("-------------------------------------------------");
        System.out.println("Running the Round Robin Scheduling Algorithm");
        RRAlgorithm();
    }
    
    public static void RRAlgorithm() {
        RoundRobin r1=new RoundRobin();
        int number,quantam,burset_time,arrive_time,con;
        Scanner input=new Scanner(System.in);
        System.out.println("enter number of process");
        number=input.nextInt();
        process p2;
        String name;
        for (int i=0;i<number;i++)
        {
            System.out.println("enter burset_time of process");
            burset_time=input.nextInt();

            System.out.println("enter arrive_time of process");
            arrive_time=input.nextInt();

            System.out.println("enter name of process");
            name=input.nextLine();
            name=input.nextLine();

            p2=new process(name,burset_time,arrive_time);

            r1.round_processes.add(p2);
        }
        System.out.println("enter quantam time");
        quantam=input.nextInt();
        System.out.println("enter context switching");
        con=input.nextInt();
        r1.setContext_switching(con);

        r1.setQuantum_time(quantam);
        r1.round_robien();
        r1.print();

    }
}

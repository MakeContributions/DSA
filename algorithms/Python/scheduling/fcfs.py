def getwaitingtime(n,bt,at,wt):
    st = [0]*n
    for i in range(1,n):
        st[i] = st[i-1] + bt[i-1]
        wt[i] = st[i] - at[i]

def gettat(n,bt,wt,tat):
    for i in range(n):
        tat[i] = wt[i] + bt[i] 

def getaverage(n,p,bt,at):
    wt = [0]*n
    tat = [0]*n
    getwaitingtime(n,bt,at,wt)
    gettat(n,bt,wt,tat)
    totwt = 0
    tottat = 0
    print("Processes \tBT\tAT\tWT\tTAT")
    for i in range (n):
        totwt+= wt[i]
        tottat += tat[i]
        print(f"\tP{p[i]}\t{bt[i]}\t{at[i]}\t{wt[i]}\t{tat[i]}")
    avgwt = totwt/n
    avgtat = tottat/n
    print(f"Average Waiting time is {round(avgwt,2)}")
    print(f"Average Turnaround time is {round(avgtat,2)}")

n = int(input("Enter the no. of processes"))
processes = list(map(int,input(f"Enter {n} process seperated by space").split()))
burtsttime = list(map(int,input("Enter burst time of each process seperated by ").split()))
arriavaltime = list(map(int,input("Enter arrival time of each process seperated by").split()))
getaverage(n,processes,burtsttime,arriavaltime)

"""  Output
Processes 	BT	AT	WT	TAT
	P1	10	0	0	10
	P2	5	2	8	13
	P3	6	5	10	16
	P4	8	7	14	22
Average Waiting time is 8.0
Average Turnaround time is 15.25 """
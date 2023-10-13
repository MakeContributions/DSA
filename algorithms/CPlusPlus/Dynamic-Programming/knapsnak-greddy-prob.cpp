// You are using GCC
#include<iostream>

using namespace std;

int main()
{
    int capacity,items,cur_weight,item;
    int used[10];
    float profit;
    int i;
    int weight[10];
    int value[10];
    
    cout<<"Enter the capacity of knapsack:"<<endl;
    cin>>capacity;
    
    
    cout<<"Enter the number of items:"<<endl;
    cin>>items;
    
    cout<<"Enter the weight and value of "<<items<<" item:"<<endl;
    for(i=0;i<items;i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }
    for(i=0;i<items;++i)
    {
        used[i]=0;
    }
    
    cur_weight = capacity;
    
    while(cur_weight>0)
    {
        item = -1;
        for(i=0;i<items;++i)
            if((used[i]==0) && ((item==-1) || ((float) value[i] / weight[i] > (float) value[item] / weight[item])))
                item = i;
                
        used[item] = 1;
        cur_weight -= weight[item];
        profit += value[item];
        
        if(cur_weight >= 0)
            cout<<item+1<<" "<<value[item]<<" "<<weight[item]<<" "<<cur_weight<<"."<<endl;
        
        else
        {
            int percent;
            percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            cout<<percent<<"%"<<" "<<value[item]<<" "<<weight[item]<<" "<<item+1<<" "<<endl;
            profit -= value[item];
            profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }
    printf("Filled the bag with objects worth %.2f Rs.\n",profit);
}

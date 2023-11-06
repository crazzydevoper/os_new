#include<stdio.h>
#include<conio.h>

void main(){
    int i, nop, sum=0, count=0, quant,y, wt=0, tat=0;
    int at[10],bt[10], temp[10];
    float avg_wt,avg_tat;
    printf("Enter Total Number of Processes in the system");
    scanf("%d",&nop);
    y=nop;

    for(i=0;i<nop;i++){
        printf("\nEnter the Arrival and Burst Time of the process[%d]\n",i+1);
        printf("Arrival Time is :\t");
        scanf("%d", &at[i]);
        printf("Burst Time is :\t");
        scanf("%d", &bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter the time quantam of the process: \t");
    scanf("%d", &quant);

    printf("\nProcess No \t\tBurst Time \t\t TAT \t\t Waiting Time ");
    
    sum=0,i=0;
    while(y!=0){
        if(temp[i]<=quant && temp[i]>0)
        {
            sum=sum+temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-quant;
            sum=sum+quant;
        }
        if(temp[i]==0 && count==1){
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==nop-1){
            i=0;
        }
        else if(at[i+1]<=sum){
            i++;
        }
        else{
            i=0;
        }
    }
    avg_wt = wt * 1.0 / nop;
    avg_tat = tat * 1.0 / nop;

    printf("\nAverage Turn Around Time: \t%f",avg_tat);
    printf("\nAverage Waiting Time: \t%f",avg_wt);
    getch();
}
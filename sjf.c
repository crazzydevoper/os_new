#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Schedule
{
    int at, bt, ct, ta, wt, btt;
    char pro_id[10];
};

int compare(const void *a, const void *b)
{
    return ((struct Schedule *)a)->at - ((struct Schedule *)b)->at;
}

int compare2(const void *a, const void *b)
{
    return ((struct Schedule *)a)->bt - ((struct Schedule *)b)->bt;
}

int main()
{
    struct Schedule pro[10];
    int n, i, j, pcom;
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the Process name : ");
        scanf("%s", pro[i].pro_id);
        printf("Enter the Arrival time : ");
        scanf("%d", &pro[i].at);
        printf("Enter the Burst time : ");
        scanf("%d", &pro[i].bt);
        pro[i].btt = pro[i].bt;
    }

    qsort(pro, n, sizeof(struct Schedule), compare);

    i = 0;
    pcom = 0;
    while (pcom < n)
    {
        for (j = 0; j < n; j++)
        {
            if (pro[j].at > i)
                break;
        }

        qsort(pro, j, sizeof(struct Schedule), compare2);

        if (j > 0)
        {
            for (j = 0; j < n; j++)
            {
                if (pro[j].bt != 0)
                    break;
            }
            if (pro[j].at > i)
            {
                i = pro[j].at;
            }
            pro[j].ct = i + 1;
            pro[j].bt--;
        }
        i++;
        pcom = 0;
        for (j = 0; j < n; j++)
        {
            if (pro[j].bt == 0)
                pcom++;
        }
    }

    printf("ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n");

    for (i = 0; i < n; i++)
    {
        pro[i].ta = pro[i].ct - pro[i].at;
        pro[i].wt = pro[i].ta - pro[i].btt;

        total_waiting_time += pro[i].wt;
        total_turnaround_time += pro[i].ta;

        printf("%s\t%d\t%d\t%d\t%d\t%d\n", pro[i].pro_id, pro[i].at, pro[i].btt, pro[i].ct, pro[i].ta, pro[i].wt);
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}



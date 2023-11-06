#include <stdio.h>
int main()
{
    // int incomingStream[] = {4 , 1 , 2 , 4 , 5};
    int num;
    printf("Enter the size of an incoming stream : ");
    scanf("%d", &num);
    int incomingStream[num];
    printf("Enter the incoming stream : ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &incomingStream[i]);
    }
    int pageFaults = 0;
    int frames;
    printf("Enter the number of frames : ");
    scanf("%d", &frames);

    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 ");
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];     //catch
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" -\t\t\t");
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    float miss = pageFaults;
    float hit = pages - miss;
    printf("Total hit is : %f\n", hit);
    float hitRatio = hit / pages;
    printf("The hit ratio is : %f\n", hitRatio);
    float missRatio = miss / pages;
    printf("The miss ratio is : %f\n", missRatio);
    return 0;
}



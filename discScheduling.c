#include <stdio.h>
#include <stdlib.h>

int SSTF(); 
int SCAN(); 
int CLOOK(); 

int main(){
    int ch, YN = 1;
    do{

        printf("\n\n\t*********** MENU ***********"); 
        printf("\n\n\t1:SSTF\n\n\t2:SCAN\n\n\t3:CLOOK\n\n\t4:EXIT"); 
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch){

            case 1:
            SSTF();
            break;

            case 2:
            SCAN();
            break;

            case 3:
            CLOOK();
            break;

            case 4:
            exit(0);
        } 
        printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0: ");


        scanf("%d", &YN); 
    } 
    while (YN == 1);
    return (0);
}

//SSTF Algorithm 


int SSTF(){
    int RQ[100], i, n, THM = 0, head, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++){
        scanf("%d", &RQ[i]);
    }
    printf("Enter head head position\n");
    scanf("%d", &head);

    while (count != n){
        int min = 1000, d, index;
        for (i = 0; i < n; i++){
            d = abs(RQ[i] - head);
            if (d<min){
                min = d;
                index = i;
            }
        }
        THM = THM + min;
        head = RQ[index];

        RQ[index] = 1000;
        count++;
    }
    printf("Total head movement is %d", THM);
    return 0;
}


//SCAN Algorithm

int SCAN(){
        int RQ[100], i, j, n, THM = 0, head, size, move;
        printf("Enter the number of Requests\n");
        scanf("%d", &n);
        printf("Enter the Requests sequence\n"); 
        for (i = 0; i < n; i++) {
            scanf("%d", &RQ[i]);
        }
        printf("Enter head head position\n");
        scanf("%d", &head); 
        printf("Enter total disk size\n"); 
        scanf("%d", &size);
        printf("Enter the head movement direction for high 1 and for low 0\n");
        scanf("%d", &move);
        for (i = 0; i < n; i++){
            for (j = 0; j < n - i - 1; j++){
                if (RQ[j] > RQ[j + 1]){
                    int temp;
                    temp = RQ[j];
                    RQ[j] = RQ[j + 1]; 
                    RQ[j + 1] = temp;
                }
            }
        }
        int index;
        for (i = 0; i < n; i++){
            if (head < RQ[i]){
                index = i;
                break;
            }
        }
        if (move == 1){
           for (i = index; i < n; i++){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];                   
            }

            THM = THM + abs(size - RQ[i - 1] - 1);
            head = size - 1;

            for (i = index - 1; i >= 0; i--){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
        }
        else{
            for (i = index - 1; i >= 0; i--) {
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
            THM = THM + abs(RQ[i + 1] - 0);
            head = 0;
            for (i = index; i < n; i++){
                THM = THM + abs(RQ[i] - head);
                head = RQ[i];
            }
        }
        printf("Total head movement is %d", THM);
        return 0;
    }


//C-LOOK Algorithm 

int CLOOK(){
    int RQ[100], i, j, n, THM = 0, head, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++){
        scanf("%d", &RQ[i]);
    }
    printf("Enter head head position\n");
    scanf("%d", &head); 
    printf("Enter total disk size\n"); 
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);

    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (RQ[j] > RQ[j + 1]){
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++){
        if (head < RQ[i]){
            index = i;
            break;
        }
    }
    if (move == 1){
        for (i = index; i < n; i++){
        THM = THM + abs(RQ[i] - head);
        head = RQ[i];
        }
        for (i = 0; i < index; i++){
            THM = THM + abs(RQ[i] - head);
            head = RQ[i];
        }
    }
    else{
        for (i = index - 1; i >= 0; i--){
            THM = THM + abs(RQ[i] - head);
            head = RQ[i];
        }
        for (i = n - 1; i >= index; i--){
            THM = THM + abs(RQ[i] - head);
            head = RQ[i];
        }
    }
    printf("Total head movement is %d", THM);
    return 0;
}


 

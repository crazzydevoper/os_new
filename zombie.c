#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void bubbleSort(int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Sorted array in child process in ascending");
    for(int i=0;i<n;i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void bubbleSort2(int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array in parent process in descending");
    for(int i=0;i<n;i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main(){

    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }

    pid_t child_pid = fork();

    if(child_pid==0)
	{
		printf("\n-----Inside child-----\n");
		printf("\nChild id %d",getpid());
		printf("\nparent id %d",getppid());
		bubbleSort(arr,n);
	}
    else{
        sleep(3);        //to demonstrate zmbie state
        //wait(&status);   // to avoid zombie state  
        system("ps aux");
        printf("\n-----Inside Parent Process-----\n");
        printf("\nparent id %d",getpid());
        
        bubbleSort2(arr,n);
        	
    }
}

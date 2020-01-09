#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLargest(int arr[], int size){

    int largeNum;
    largeNum = arr[0];
    int i;

    for(i = 0; i < size; i++){
        if(arr[i] > largeNum){
            largeNum = arr[i];
        }
    }
    return largeNum;
}

int main(){

int size;
int array[100];
int i;
int largestNum;

FILE * ptr;
ptr = fopen("C:\\Users\\Ruben\\Desktop\\SEM.2\\CPS125\\numData.txt","r");

fscanf(ptr, "%d", &size);

for(i = 0; i < size; i++){
    fscanf(ptr, "%d", &array[i]);
}

fclose(ptr);

largestNum = findLargest(array, size);

printf("The largest number: %d\n\n", largestNum);


return 0;
}


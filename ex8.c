#include <stdio.h>
#include <stdlib.h>
#include "qsort.c"

int main () {
    int N ;
    int count = 0;
    char c;

    FILE *fp;
    fp = fopen ("data.txt", "r");

     for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n'){
            count = count + 1;
            }
    }
    fclose(fp);
    printf("%d",count);
    int arr[count];
    int i;
    char* row;
    ssize_t read;
    ssize_t len =0;
    int round=0;
    fp = fopen ("data.txt", "r");
        while (((read = getline(&row, &len, fp)) != -1)&& (round<count)) {
            arr[round]=atoi(row);
            round++;
        }
    fclose(fp);

quickSort(arr,0,count-1);
    for (i = 0; i < count; i++)
    {
        printf("Number is %d : %d\n\n", i, arr[i]);
    }
    fp = fopen ("data_sorted.txt", "w");
    for(int i = 0; i<count; i++){
        fprintf(fp, " %d \n", arr[i] );
    }
    fclose(fp);

}
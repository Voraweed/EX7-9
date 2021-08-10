#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int N ;

    FILE *fp;
    fp = fopen ("data.txt", "w");

    printf("Enter Number for random: ");
    scanf("%d",&N);
    srand (time(NULL));

    for(int i = 0; i<N; i++){
        fprintf(fp, " %d \n", rand() %1000 );
    }
    fclose(fp);
    return(0); 
}
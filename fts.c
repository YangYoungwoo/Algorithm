/* ID: 2016115487
 * Name: Yang Youngwoo
 * School of Electronics Engineering, Kyungpook National University
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
    char infile[2048];
    int i, numElements, j, k;
    int a[100][100];
    int arr[100][100];
    FILE *fp;


    printf("Input file name: ");
    scanf("%s", infile);
    fp = fopen(infile, "r");
    fscanf(fp, "%d", &numElements);
    for(i=0;i<200;i++){
        fscanf(fp, "%d", &j);
        if(i%2==0){
            a[i/2][0] = j;
        }
        else{
            a[i/2][1] = j;
        }
    }
    k = 300;
    k = 700;
    k = 1100;
    k = 1500;

    return 0;
}

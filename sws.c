/* ID: 2016115487
 * Name: Yang Youngwoo
 * School of Electronics Engineering, Kyungpook National University
 */
//Not using any internet codes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX 256

typedef struct node{
    int differ;
    int number;
} NODE;

NODE Node[MAX];
int a[100][100];
int e[100];

int main(){
    int i, j, n, k, p, plate, input, limit, start;
    int x = 0;
    int y = 0;
    int l = 0;
    int b = 0;
    int c = 0;
    int left, right;
    int arr[100];

    fscanf(stdin, "%d", &plate);
    fscanf(stdin, "%d", &limit);
    fscanf(stdin, "%d", &k);
    start = limit/2;
    while(k == (-1)){
        fscanf(stdin, "%d", &n);
        e[x] = n;
        while(n != (-3)){
            fscanf(stdin, "%d", &input);
            if(input>0){
                if(x<=j){
                    a[x][y] = input;
                    y++;
                }
                else{
                    printf("over width\n");
                    break;
                }
            }
            else if(input == (-2)){
                if(x<=plate){
                    x++;
                    y = 0;
                    break;
                }
                else{
                    printf("over plate\n");
                    break;
                }
            }
        }
        if(n == (-3))
            break;
    }

    Node[0].differ = 0;
    Node[0].number = start;

    for(i=0;i<pow(2, plate)-1;i++){

        p = e[l];
        left = a[l][0];
        right = a[l][p-1];
        for(j=0;j<p;j++){
            if(a[l][j]<=Node[i].number){
                left = a[l][j];
            }
        }
        for(j=2;j<p;j++){
            if(a[l][p-j]>=Node[i].number){
                right = a[l][p-j];
            }
        }
        Node[2*(i+1)-1].number = left;
        Node[2*(i+1)].number = right;
        Node[2*(i+1)-1].differ = abs(left-Node[i].number)+Node[i].differ;
        Node[2*(i+1)].differ = abs(right-Node[i].number)+Node[i].differ;
        b++;
        if(b==pow(2, c)){
            l++;
            c++;
            b = 0;
        }
    }

    i = pow(2,plate)-1;
    k = Node[i].differ;
    j = pow(2,plate)-1;

    for(i=pow(2,plate)-1;i<pow(2,plate+1)-1;i++){
        if(k>Node[i].differ){
            k = Node[i].differ;
            j = i;
        }
    }
    for(i=0;i<plate+1;i++){
        arr[plate-i]=Node[j].number;
        if(j%2==0){
            j = j/2-1;
        }
        else{
            j = (j-1)/2;
        }
    }
    printf("%d  ", k);
    for(i=1;i<plate+1;i++){
        printf("%d  ", arr[i]);
    }
}

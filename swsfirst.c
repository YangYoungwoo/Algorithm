/* ID: 2016115487
 * Name: Yang Youngwoo
 * School of Electronics Engineering, Kyungpook National University
 */
//Using https://mattlee.tistory.com/50 for making codes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[100][100];
int e[100];
int right_arr[100];
int left_arr[100];
int stortest_path(int start, int n);
/*
typedef struct count{
    int x;
    int data;
    struct count *left;
    struct count *right;
}count;

count *root;

void initTree(int data, int number){
    count *New;
    New = (count*)(malloc(sizeof(count));
    root = New;
    root ->data = data;
    root->x = number;
    root->left = NULL;
    root->right = NULL;
}

void *addchi(count *parrent, int data, int number){
    count *New;
    New = (count*)(malloc(sizeof(count)));
    New->left = NULL;
    New->right = NULL;
    New->data = data;
    New->x = number;

    if(parrent->left == NULL){
        parrent->left = New;
    }
    else if(parrent->right == NULL){
        parrent->right = New;
    }
    return New;
}
*/
int main(){
    int i, j, k, x;
    int b = 0;
    int c = 0;
    int start, n, o, d=0;
    int left, right, p, q, s, t, r = 0;

    fscanf(stdin, "%d", &i);
    fscanf(stdin, "%d", &j);
    fscanf(stdin, "%d", &k);
    start = j/2;
    t = i;
    while(k == (-1)){
        fscanf(stdin, "%d", &n);
        e[b] = n;
        while(n != (-3)){
            fscanf(stdin, "%d", &x);
            if(x>0){
                if(x<=j){
                    a[b][c] = x;
                    c++;
                }
                else{
                    printf("over width\n");
                    break;
                }
            }
            else if(x == (-2)){
                if(b<=i){
                    b++;
                    c = 0;
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
    q = start;
    s = start;
    for(i=0;i<b;i++){
        p = e[i];
        left = a[i][0];
        right = a[i][p-1];
        for(j=2;j<e[i];j++){
            if(a[i][j]<=q){
                left = a[i][j];

            }
        }
        for(j=2;j<e[i];j++){
            if(a[i][p-j]>=s){
                right = a[i][p-j];
            }
        }
        printf("%d %d\n", left, right);
        right_arr[r]=right;
        left_arr[r]=left;
        q = left;
        s = right;
        r++;
    }

    printf("\n right");
    for(i=0;i<r;i++){
        printf("%d ", right_arr[i]);
    }

    printf("\n left");
    for(i=0;i<r;i++){
        printf("%d ", left_arr[i]);
    }
    printf("\n");
    //initTree(0, l);
    //for(i = 0;i<b)
    //shortest_path(0, j);
    return 0;
}

int shortest_path(int start, int n){
    int i, j, u, w, x;
    i = n/2;




}

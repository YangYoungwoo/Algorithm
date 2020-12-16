#include <stdio.h>
#include <stdlib.h>

int a[100][100];
int e[100];

int main(){
    int i, j, k, x;
    int b = 0;
    int c = 0;
    int l, n, o, d = 0;

    fscanf(stdin, "%d", &i);
    fscanf(stdin, "%d", &j);
    fscanf(stdin, "%d", &k);
    l = j/2;

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

    for(i=0;i<b;i++){
            n = abs(l-a[i][0]);
            o = a[i][0];
        for(j=1;j<e[i];j++){
            if(n>abs(l-a[i][j])){
                n = abs(l-a[i][j]);
                o = a[i][j];
            }
        }
        d = d + n;
        l = o;
        e[i] = o;
    }
    printf("%d  ", d);
    for(i = 0; i<b;i++){
        printf("%d  ", e[i]);
    }
    printf("\n");
}

/* ID: 2016115487
 * Name: Yang Youngwoo
 * School of Electronics Engineering, Kyungpook National University
 */
//Using alg20-lec11-dp.pdf for making codes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, j, m, n;
    char x[100], y[100], z[100], k[100];
    char a[100];
    int e, f, d;
    int b = 0;

    fscanf(stdin, "%s", &z);
    fscanf(stdin, "%s", &k);

    m = strlen(z);
    n = strlen(k);
    int c[m+1][n+1];
    x[0]= 'X';
    y[0]= 'Y';
    for(i=0;i<m;i++){
        x[i+1]=z[i];
    }
    for(j=0;j<n;j++){
        y[j+1]=k[j];
    }
    for(i=0;i<=m;i++){
        c[i][0] = 0;
    }

    for(j=0;j<=n;j++){
        c[0][j] = 0;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){

            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1]+1;
            }
            else{
                if(c[i-1][j]>=c[i][j-1])
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
        }

    }
    e = n;
    f = m;
    d = c[f][e];
    while(1){
        if(d!=c[f-1][e]&&d!=c[f][e-1]){
            a[b] = x[f];
            e = e-1;
            f = f-1;
            d = c[f][e];
            b++;

        }
        else if(d==c[f-1][e]){
            f = f-1;
            d = c[f][e];
        }
        else if(d==c[f][e-1]){
            e = e-1;
            d = c[f][e];
        }
        else{
            e = e-1;
            d = c[f][e];
        }
        if(e==0||f==0){
            break;
        }

    }
/*
    while(1){
        for(i=1;i<m;i++){
            for(j=2;j<e;j++){
                if(d != c[f][e-j]){
                    a[b]=x[f];
                    e = e-j;
                    f = f-1;
                    break;
                }
            }
            b++;
        }
        break;
    }*/
    printf("LCS ");
    for(i=0; i<b;i++){
        printf("%c", a[b-i-1]);
    }
    printf("\n");
    printf("  ");

    for(i=0;i<=n;i++){
    printf("%c  ", y[i]);
    }
    printf("\n");
    for(i=0;i<=m;i++){
        printf("%c ", x[i]);
        for(j=0;j<=n;j++){
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

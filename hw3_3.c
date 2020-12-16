/* ID 2016115487        - REPLACE WITH YOUR ID
 * NAME Yang Youngwoo       - REPLACE WITH YOUR NAME */

//////////////////////////////////////////////////////////////////
// If you have referred any code, leave the comments like this
// to avoid "COPY"
// SOURCE for heapify: https://www.geeksforgeeks.org/heap-sort/
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEASURE_TIME	// to measure execution time
// from GJANG: not sure if the time measurement code works with Windows
// If it works, execution time will be printed.
// Otherwise, comment out the line "#define MEASURE_TIME" and compile again.

/////////////////////////////////////////////////////////////////////
// to compute execution time in seconds
/////////////////////////////////////////////////////////////////////
#ifdef MEASURE_TIME
#include<time.h>
#endif

/////////////////////////////////////////////////////////////////////
// homework programming assignment 3-3
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// function to find median using min heap and max heap
// to find median value from an array, use the following heap architecture
// 1) store all the data to heap L and heap R
// 2) all values in L < any value in R
// 3) if the number of total items is N,
//   odd  N: number of items in L = N/2+1, number of items in R = N/2
//   even N: number of items in L = number of items in R = N/2
//     i.e. n_L = n_R or n_L = n_R+1
// 4) keep L as max heap, keep R as min heap, then the median is root(L)
//   *in many definitions of median, when N is even, the median is
//    defined as an average of item N/2 and item N/2+1, but we assume
//    it is root(L) (item ceiling(N/2)) to make the problem simple
//   *all values in L <= root(L), so it also satisfies definition of median
//   *Reference:
// https://www.quora.com/How-do-you-find-the-median-from-a-set-of-even-numbers
// https://www.dkfindout.com/us/math/averages/more-about-medians/
//
// What to do:
// 1) Implement
//    Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
//    to add a value to L and R
//    heaps L and R should satisfy the above conditions
// 2) Implement
//    Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
//    For an unsorted array, it builds heaps L and R from empty heaps
//    A: size N array
//    L: size ceil(N/2) array,  R: size floor(N/2) array
//    the array memory should be allocated in advance
// 3) Implement
//    Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int p_N)
//    For Heap4Median given by L and R (with their number of elements by n_L and n_R)
//    fill the array A in an ascending order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// ***FILL*** if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int arr[], int n, int i, int L[], int *p_n_L)
{
    int k;
    for(k =1; k<i/2;k++){
        int left = n + 2*k-1;
        int right = n + 2*k;
        int max = n;
        if(right<=i&&arr[right]>arr[max])
            max = right;
        if(left<=i&&arr[left]>arr[max])
            max = left;
        if(max!=n) {
            swap(&arr[n], &arr[max]);
            MaxHeapify(arr, max, i, L, &p_n_L);
        }
    }

}

void MinHeapify(int arr[], int n, int i)
{
    int k;
    for(k =1; k<i/2;k++){
        int left = n + 2*k-1;
        int right = n + 2*k;
        int min = n;

        if(right<=i&&arr[right]<arr[min])
            min = right;
        if(left<=i&&arr[left]<arr[min])
            min = left;
        if(min!=n) {
            swap(&arr[n], &arr[min]);
        MinHeapify(arr, min, i);
        }

    }
}



void Heap4Median_AddItem(int L[], int *p_n_L, int R[], int *p_n_R, int value)
{
    int i;
    if(value%2 == 0){
        *p_n_L = value/2;
        *p_n_R = value/2;
    }
    else{
        *p_n_L = value/2+1;
        *p_n_R = value/2;
    }

}

void Heap4Median_Build(int A[], int N, int L[], int *p_n_L, int R[], int *p_n_R)
{
    int i, j;
    int k = 1;
    Heap4Median_AddItem(L, &p_n_L, R, &p_n_R, N);
    for(i=1; i<=p_n_L; i++){
        MaxHeapify(A, i, N, L, &p_n_L);
        L[i] = A[i];
    }
    for(j=p_n_L; j>=k; j--){
        swap(&L[k], &L[j]);
        k = k+1;
    }
    for(i=1; i<=p_n_R; i++){
        MinHeapify(A, i, N);
        R[i] = A[i];
    }
    if(R[1]>R[2])
        swap(&R[1], &R[2]);
}

void Heap4Median_Sort(int L[], int n_L, int R[], int n_R, int A[], int *p_N)
{
    int i;
    int k;
    k = (int)*p_N;
    if(k%2 == 0){
        n_L = k/2;
        n_R = k/2;
    }
    else{
        n_L = k/2+1;
        n_R = k/2;
    }
    for(i=1; i<=n_R; i++){
        A[i]= R[i];
    }
    for(i=i; i<=n_L; i++){
        A[n_R+i]= L[i];
    }
}

/////////////////////////////////////////////////////////////////////
// test your implementation
/////////////////////////////////////////////////////////////////////
int main()
{
  int i, N;
  int *A, *L, *R;
  int n_L, n_R;

  // 0. read input
  fscanf(stdin, "%d", &N);

  // allocate interger arrays and read input values
  // In the textbook, the array indexing is 1-based (i.e. starts with 1)
  // so this template code is written for 1-based indexing
  // (starts with 1, leaving A[0] untouched.
  // If you prefer 0-based indexing, you may modify the example code below
  // ex.) "for (i=1; i<=N; i++) " --> "for (i=0; i<N; i++) "
  // "median = L[1]; " --> "median = L[0]; "
  A = (int*)malloc(sizeof(int)*(N+1));
  for (i=1; i<=N; i++) {
    if ( fscanf(stdin, "%d", A+i) != 1 ) {
      fprintf(stderr, "cannot read integer from standard input.\n");
      free(A);
      exit(0);
    }
  }

  L = (int*)malloc(sizeof(int)*(N/2+1+1));
  R = (int*)malloc(sizeof(int)*(N/2+1+1));

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif
  /////////////////////////////////////////////////////////////////////
  // ***FILL*** :  invoke Heap4Median_Build(...) to obtain sub-heaps L and R
  /////////////////////////////////////////////////////////////////////
  Heap4Median_Build(A, N, L, &n_L, R, &n_R);

  // output for evaluation: print median only
  fprintf(stdout,"%d\n",L[1]);

  Heap4Median_Sort(L, n_L, R, n_R, A, &N);

#ifdef MEASURE_TIME
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
#endif

  // output for evaluation: sorted list
  for (i=1; i<=N; i++) fprintf(stdout, "%d ", A[i]);
  fprintf(stdout, "\n");

  // free memory
  free(A);
  free(L);
  free(R);

  return 0;
}


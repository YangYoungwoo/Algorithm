/* ID 2016115487       - REPLACE WITH YOUR ID
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
// homework programming assignment 3-2
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// What to do:
// 1) Implement
//    MinHeapify(int arr[], int n, int i)
//    reorders the array elements to satisfy min heap property
// 2) Implement
//    MinHeapSort(int arr[], int n)
//    sort the array in an ascending (increasing) order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// ***FILL*** if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////

//Using hw3_1.c for making codes
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

void MinHeapSort(int arr[], int n)
{
    int i;
    for(i=n; i>=1; i--){
        MinHeapify(arr, i, n);
    }
}

/////////////////////////////////////////////////////////////////////
// test your implementation
/////////////////////////////////////////////////////////////////////
int main()
{
  int i, N;
  int *A;

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

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;

  start = clock();
#endif
  /////////////////////////////////////////////////////////////////////
  // ***FILL*** :  invoke Heap4Median_Build(...) to obtain sub-heaps L and R
  /////////////////////////////////////////////////////////////////////
  MinHeapSort(A, N);

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

  return 0;
}


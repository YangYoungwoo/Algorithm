/* ID 2016115487     - REPLACE WITH YOUR ID
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
// homework programming assignment 3-1
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// What to do:
// 1) Implement
//    MaxHeapify(int arr[], int n, int i)
//    reorders the array elements to satisfy min heap property
// 2) Implement
//    MaxHeapSort(int arr[], int n)
//    sort the array in an ascending (increasing) order
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// ***FILL*** if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////




//SOURCE for heapify: https://reakwon.tistory.com/43  for making swap, MaxHeapify, MaxHeapsort codes
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int arr[], int n, int i)
{
    int left = n*2;
    int right = n*2 +1;
    int max = n;
    if(right<=i&&arr[right]>arr[max])
        max = right;
    if(left<=i&&arr[left]>arr[max])
        max = left;
    if(max!=n) {
        swap(&arr[n], &arr[max]);
        MaxHeapify(arr, max, i);
    }
}
void MaxHeapSort(int arr[], int n)
{
    int i, j;
    for(i=n/2-1; i>=1; i--){
        MaxHeapify(arr, i, n);
    }
    for(j=n; j>=1; j--){
        swap(&arr[1], &arr[j]);
        MaxHeapify(arr, 1, j-1);
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
  MaxHeapSort(A, N);

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


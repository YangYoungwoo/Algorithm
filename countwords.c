/* ID: 2016115487
 * Name: Yang Youngwoo
 * School of Electronics Engineering, Kyungpook National University
 */
//using hw2 for making codes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN	256

struct Count{
	char *str;
	int number;
} *members;

char **read_chararr_textfile(FILE *fp, int *pN);
void insertion_sort_chararr(char* arr[], int n);
void sorts(char *arr[], int *n);
void count_sort(int n);

int main(){
  int i, numElements, loop;
  char infile[100], outfile[100];
  char **A;
  FILE *fp_in, *fp_out;

  for (loop = 0; loop < 3; loop++)
  {
	  switch (loop)
	  {
	  case 0:{
				 strcpy(infile, "input4a.txt");
				 strcpy(outfile, "out4a.txt");
				 break;
			}
	  case 1:{
				 strcpy(infile, "input4b.txt");
				 strcpy(outfile, "out4b.txt");
				 break;
			}
	  case 2:{
				 strcpy(infile, "input4c.txt");
				 strcpy(outfile, "out4c.txt");
				 break;
			}
	  }

	  fp_in = fopen(infile, "r");

	  printf("- Input Data%d Reading....\n", loop+1);
	  A = read_chararr_textfile(fp_in, &numElements);

	  if (A != NULL && numElements > 0) {

		  printf("    - Input Data%d Sorting....\n", loop+1);
		  sorts(A, &numElements);

		  printf("- Input Data%d Counting....\n", loop + 1);
		  count_sort(numElements);

		  fp_out = fopen(outfile, "w");
		  if (!fp_out) {
			  fprintf(stderr, "cannot open file for write \n");
		  }
		  else{
			  printf("    - Output Data%d Writing....\n", loop+1);
			  for (int i = 0; i<numElements; i = i + 1){
				  fprintf(fp_out, "%s %d\n", members[i].str, members[i].number);
			  }
			  fclose(fp_out);
		  }
		  printf("- Write Complete\n\n\n");

		  for (int i = 0; i < numElements; i++) free(A[i]);
		  free(A);
	  }
	  fclose(fp_in);
  }
  return 0;
}

char **read_chararr_textfile(FILE *fp, int *pN){
	char **A;
	char tmp[MAX_STR_LEN];
	int i = 0;

	while (!feof(fp)){
		fscanf(fp, "%s", tmp);
		i++;
	}

	A = (char**)malloc(sizeof(char*)*(i));
	i = 0;
	rewind(fp);
	while (!feof(fp)){
		A[i] = (char*)malloc(sizeof(char*)*(MAX_STR_LEN));
		fscanf(fp, "%s", A[i]);
		i++;
	}
	*pN = i-1;
	fclose(fp);
	return A;
}

void sorts(char* arr[], int *n){
    int i;
    int j;
    int k = 1;

	members = (struct Count*)malloc(sizeof(struct Count)*(*n));
	members[0].str = (char *)malloc(sizeof(char*)*(MAX_STR_LEN));
    members[0].str= arr[0];
	members[0].number = 1;

    for(i = 1; i < *n; i++){
		for(j = 0; j < k; j++){
			if ( strcmp(arr[i], members[j].str) == 0){
				members[j].number = members[j].number + 1;
                break;
            }
		}
		if ( k == j ){
			members[j].str = (char *)malloc(sizeof(char*)*(MAX_STR_LEN));
			members[j].str = arr[i];
			members[j].number = 1;
			k++;
		}
    }
	*n = k;
}

void count_sort(int n){
    int i, j;
    struct Count temp;

    for(i=0; i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(members[j].number<members[j+1].number){
                temp = members[j];
                members[j] = members[j+1];
                members[j+1] = temp;
            }
        }
    }
}

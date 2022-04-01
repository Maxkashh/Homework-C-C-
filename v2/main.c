#include "lib2.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h> /* for wait */
#include <sys/mman.h> /* for mmap */

 

int main() {
  int size = 1000000;
  int size_components = 100;
   Vector **ptr = mmap(NULL,sizeof(Vector *) * size,PROT_READ | PROT_WRITE,
MAP_SHARED | MAP_ANONYMOUS,
     0,0);    

  if (!ptr) {
    return 1;
  }
  for (int i = 0; i < size; ++i) {
    ptr[i] = Vec_init(size_components);
  }

  Vector *val = Vec_init(size_components);
  if (!val) {
    return 1;
  }

  clock_t start = clock();
  
  double res = Norma_Difference(val, size_components);

  double *arr = (double *)malloc(sizeof(double) * size);
  

    if(ptr == MAP_FAILED){
     printf("Mapping Failed\n");
     return 1;
    }
for (int i = 0; i < size/2; ++i) {
    arr[i] = Norma_Difference(ptr[i], size_components);
  }

  for (int i = 0; i < size/2; ++i) {
    arr[i] = minDiff(arr[i], res);
  }
  pid_t child_pid=fork();
   
    if ( child_pid == 0 ){
   
     for (int i = size/2; i < size; ++i) {
    arr[i] = Norma_Difference(ptr[i], size_components);
  }

  for (int i = size/2; i < size; ++i) {
    arr[i] = minDiff(arr[i], res);
  }
  
    }
    else{
     //parent
waitpid ( child_pid, NULL, 0);
 
      int ind = min_vector(arr, size); //получили индекс вектора
clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;

  printf("Time elapsed in ms: %f", elapsed);

  Create_Result_FILE(res, arr[ind] + res, ind, val,
                     ptr[ind]); //запись результатов в файл
                     int err = munmap(ptr, sizeof(Vector *) * size);
                     FILE *res2 = fopen("time2.txt", "w+");
                     fprintf(res2, "%f",elapsed);
                     fclose(res2);
    
    if(err != 0){
     printf("UnMapping Failed\n");
     return 1;
    }
  free(val);
  free(arr);

  //DelMem(objects, size);
   
}

     
     
   

  
   
  return 0;

 }

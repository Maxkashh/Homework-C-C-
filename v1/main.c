#include "lib1.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() {
  int size = 1000000;
  int size_components = 100;
  Vector **objects = malloc(sizeof(Vector *) * size);

  if (!objects) {
    return 1;
  }
  for (int i = 0; i < size; ++i) {
    objects[i] = Vec_init(size_components);
  }

  Vector *val = Vec_init(size_components);
  if (!val) {
    return 1;
  }

  clock_t start = clock();
  double res = Norma_Difference(val, size_components);

  double *arr = (double *)malloc(sizeof(double) * size);
  for (int i = 0; i < size; ++i) {
    arr[i] = Norma_Difference(objects[i], size_components);
  }

  for (int i = 0; i < size; ++i) {
    arr[i] = minDiff(arr[i], res);
  }

  int ind = min_vector(arr, size); //получили индекс вектора
  clock_t stop = clock();
  double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Time elapsed in ms: %f", elapsed);

  Create_Result_FILE(res, arr[ind] + res, ind, val,
                     objects[ind]); //запись результатов в файл
                     FILE *res1 = fopen("time1.txt", "w+");
                     fprintf(res1, "%f",elapsed);
                     fclose(res1);
  free(val);
  free(arr);

  DelMem(objects, size);
  return 0;
}

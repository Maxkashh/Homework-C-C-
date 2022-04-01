
#include "lib2.h"
#include <locale.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int status = 0;
int check_status() { return status; }
double Norma_Difference(const Vector *vec, int size) {
  if (!vec) {
    return 1;
  }
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += ((vec->vec[i]) * (vec->vec[i]));
  }
  double res = sqrt(sum);
  return res;
}

Vector *Vec_init(int size_vec) {

  // int size_vec=100;
  Vector *vector = (Vector *)malloc(sizeof(Vector));
  if (!vector) {
    status = 1;
  }

  for (int i = 0; i < size_vec; ++i) {
    vector->vec[i] = rand() % 1000;
  }
  return vector;
}

double minDiff(double vector, double val) { return fabs(vector - val); }

int min_vector(const double *arr, int size) {
  if (!arr) {
    return 1;
  }
  double min = arr[0];
  int ind = 0;
  for (size_t i = 0; i < size; i++) {
    if (min > arr[i]) {
      min = arr[i];
      ind = i;
    }
  }
  return ind;
}

int DelMem(Vector **objects, const int count) {
  if (!objects) {
    return 1;
  }
  for (int i = 0; i < count; ++i) {
    free(objects[i]);
  }
  free(objects);
  return 0;
}

int Create_Result_FILE(double norma_vvedennogo, double norma_naidennogo,
                       int index, const Vector *vec, const Vector *foundvec) {
  FILE *f = fopen("result.txt", "w+");
  if (!f) {
    return 1;
  }
  fclose(f);
  f = fopen("result.txt", "a+");
  if (!f) {
    return 1;
  }
  char *str = "Компоненты введенного вектора: ";
  fputs(str, f);
  fprintf(f, "\n");
  for (int i = 0; i < 100; ++i) {
    fprintf(f, "%d ", vec->vec[i]);
  }
  fprintf(f, "\n");
  char *str2 = "Норма введенного вектора";
  fputs(str2, f);
  fprintf(f, "\n");
  fprintf(f, "%f ", norma_vvedennogo);
  fprintf(f, "\n");
  char *st = "Норма найденного вектора";
  fputs(st, f);
  fprintf(f, "\n");
  fprintf(f, "%f ", norma_naidennogo);
  fprintf(f, "\n");
  char *str3 = "Норма разности с введенным минимальна с вектором под индексом:";
  fputs(str3, f);
  fprintf(f, "\n");
  fprintf(f, "%d ", index);
  fprintf(f, "\n");
  char *str4 = "Компоненты найденного  вектора: ";
  fputs(str4, f);
  fprintf(f, "\n");
  for (int i = 0; i < 100; ++i) {
    fprintf(f, "%d ", foundvec->vec[i]);
  }

  fclose(f);
  return 0;
}
#include "./fib_lib/fib.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("chcp 65001");
  setlocale(LC_ALL, "ru_RU.UTF-8");

  printf("%s\n", "Введите количество кораблей:");
  char c = 0;
  scanf("%c", &c);
  while (!isdigit(c)) {
    printf("Error! Its not a digit! Enter your value again:%s\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%c", &c);
  }
  int a = 0;
  a = c - '0';

  Warship **objects = malloc(sizeof(Warship *) * a);

  if (!objects) {
    return 1;
  } else {
    for (int i = 0; i < a; ++i) {
      objects[i] = initShip(objects[i]);
    }
    SearchInfo(objects, a);
    DeleteMemory(objects, a);
  }

  return 0;
}
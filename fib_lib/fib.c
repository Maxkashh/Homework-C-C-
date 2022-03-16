#include "fib.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <ctype.h>
#include <stdint.h>

// char** get_atributes_for_test(Warship* obj)
// {
//     printf("%s\n", "В каком количестве кампаний участвовал?");

//     char buf[50];

//     fseek(stdin, 0, SEEK_END);

//     int count = 3 ;
//     obj->countOfHistoryShip = count;
//     printf("%s\n", "Перечислите эти кампании:");

//     obj->HistoryOfShip =  malloc(sizeof(char*) * count);
//     if (obj->HistoryOfShip != NULL) {
//         for (int i = 0; i < count; i++)
//         {
//             buf[i]="a";
//             size_t len = strlen(buf);
//             for (int j = 0; j < len; ++j)
//             {
//                 if (isdigit(buf[j]))
//                 {
//                     fseek(stdin, 0, SEEK_END);
//                     printf("Строка не может содержать другие символы!Поворите
//                     ввод:%s\n"); fgets(buf, 50, stdin); len = strlen(buf); j
//                     = 0;

//                 }
//             }

//             obj->HistoryOfShip[i] =  malloc(50);
//             if (!obj->HistoryOfShip) { printf("%s", "Sorry!Dont have memory
//             for object!"); return 1; } else
//                 strcpy(obj->HistoryOfShip[i],  buf);

//         }
//         return obj->HistoryOfShip;
//     }
//     else { printf("%s", "Sorry!Dont have memory for object!"); return 1; }
// }

int GetIntFromString(char *name) {

  size_t len = strlen(name);
  for (int i = 0; i < len - 1; ++i) {
    if (!isdigit(name[i])) {
      fseek(stdin, 0, SEEK_END);
      printf("Строка не может содержать другие символы!Поворите ввод:%s\n");
      fgets(name, 50, stdin);
      len = strlen(name);
      i = 0;
    }
  }

  int arr[50];
  int count = 0;
  for (int i = 0; i < strlen(name) - 1; ++i) {
    arr[i] = name[i] - '0';
    ++count;
  }

  int n = 0;
  for (int i = 0; i < count; i++) {
    n *= 10;
    n += arr[i];
  }
  return n;
}
char **get_atributes(Warship *obj) {
  printf("%s\n", "В каком количестве кампаний участвовал?");

  char buf[50];
  char name[50];
  fseek(stdin, 0, SEEK_END);
  fgets(name, 50, stdin);
  int count = GetIntFromString(name);
  obj->countOfHistoryShip = count;
  printf("%s\n", "Перечислите эти кампании:");

  obj->HistoryOfShip = malloc(sizeof(char *) * count);
  if (obj->HistoryOfShip != NULL) {
    for (int i = 0; i < count; i++) {
      fseek(stdin, 0, SEEK_END);
      fgets(buf, 50, stdin);
      size_t len = strlen(buf);
      for (int j = 0; j < len; ++j) {
        if (isdigit(buf[j])) {
          fseek(stdin, 0, SEEK_END);
          printf("Строка не может содержать другие символы!Поворите ввод:%s\n");
          fgets(buf, 50, stdin);
          len = strlen(buf);
          j = 0;
        }
      }

      obj->HistoryOfShip[i] = malloc(50);
      if (!obj->HistoryOfShip) {
        printf("%s", "Sorry!Dont have memory for object!");
        return 1;
      } else
        strcpy(obj->HistoryOfShip[i], buf);
    }
    return obj->HistoryOfShip;
  } else {
    printf("%s", "Sorry!Dont have memory for object!");
    return 1;
  }
}

const char *GetString(const char *name) {

  size_t len = strlen(name);
  for (int i = 0; i < len; ++i) {
    if (isdigit(name[i])) {
      fseek(stdin, 0, SEEK_END);
      printf("Строка не может содержать другие символы!Поворите ввод:%s\n");
      fgets(name, 50, stdin);
      len = strlen(name);
      i = 0;
    }
  }

  char *str = malloc(sizeof(char) * len);

  if (!str) {
    return "Dont have memory!";
  } else
    strcpy(str, name);
  return str;
}

Warship *initShip(Warship *obj) {

  obj = malloc(sizeof(Warship));
  if (!obj) {
    return 1;
  } else {

    printf("%s\n", "Введите имя корабля:");

    char name[50];
    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    obj->NameOfShip = GetString(name);

    printf("%s\n", "Введите название верфи-производителя:");

    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    obj->ManufacturerName = GetString(name);
    printf("%s\n", "Введите год  спуска на воду корабля:");

    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    int age = GetIntFromString(name);

    obj->Age = age;
    obj->HistoryOfShip = get_atributes(obj);
    printf("%s\n", "Какая численность экипажа?");
    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    int crew = GetIntFromString(name);

    obj->CountOFCrew = crew;
    printf("%s\n", "Какое состояние эксплуатации корабля?(списан,в "
                   "эксплуатации,на ремонте)");

    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    obj->Status = GetString(name);

    return obj;
  }
}

void SearchInfo(Warship **objects, const int countOfObjects) {
  char name[50];
  fseek(stdin, 0, SEEK_END);
  fgets(name, 50, stdin);
  int choice = GetIntFromString(name);
  while (choice != 7) {
    printf("%s\n", "Выберите критреии поиска: и введите цифру");
    printf("%s\n", "1 Вывод информации по названию корабля  ");
    printf("%s\n", "2 Вывод информации по названию верфи-производителя  ");

    printf("%s\n", "3 Вывод информации по году спуска на воду  ");
    printf("%s\n",
           "4 Вывод информации по названию военных кампаний в истории  ");
    printf("%s\n", "5 Вывод информации по численности экипажа  ");
    printf("%s\n", "6 Вывод информации по состоянию корабля  ");
    printf("%s\n", "7 Выход ");

    fseek(stdin, 0, SEEK_END);
    fgets(name, 50, stdin);
    choice = GetIntFromString(name);
    switch (choice) {
    case 1:

    {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите название корабля:");
      char name[50];
      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      char *name2 = GetString(name);
      bool flag = false;

      for (int i = 0; i < countOfObjects; ++i) {
        if (!strcmp(name2, objects[i]->NameOfShip)) {
          PrintObj(objects[i]);
          flag = true;
        }
      }
      free(name2);
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }
      break;
    }
    case 2: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите верфи-производителя:");
      char name[50];
      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      char *name2 = GetString(name);
      bool flag = false;

      for (int i = 0; i < countOfObjects; ++i) {
        if (!strcmp(name2, objects[i]->ManufacturerName)) {
          PrintObj(objects[i]);
          flag = true;
        }
      }
      free(name2);
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }
      break;
    }
    case 3: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите год спуска на воду корабля:");
      char name[50];
      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      int age = GetIntFromString(name);
      bool flag = false;
      for (int i = 0; i < countOfObjects; ++i) {
        if (age == objects[i]->Age) {
          PrintObj(objects[i]);
          flag = true;
        }
      }
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }
      break;
    }
    case 4: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите кампанию в истории корабля:");
      char name[50];

      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      char *name2 = GetString(name);
      bool flag = false;
      for (int i = 0; i < countOfObjects; ++i) {
        for (int j = 0; j < objects[i]->countOfHistoryShip; ++j) {

          if (!strcmp(name2, objects[i]->HistoryOfShip[j])) {
            PrintObj(objects[i]);
            flag = true;
          }
        }
      }
      free(name2);
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }

      break;
    }

    case 5: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите численность экипажа:");
      char name[50];
      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      int age = GetIntFromString(name);
      bool flag = false;
      for (int i = 0; i < countOfObjects; ++i) {
        if (age == objects[i]->CountOFCrew) {
          PrintObj(objects[i]);
          flag = true;
        }
      }
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }
      break;
    }
    case 6: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      printf("%s\n", "Введите состояние корабля:");
      char name[50];
      fseek(stdin, 0, SEEK_END);
      fgets(name, 50, stdin);
      char *name2 = GetString(name);
      bool flag = false;

      for (int i = 0; i < countOfObjects; ++i) {
        if (!strcmp(name2, objects[i]->Status)) {
          PrintObj(objects[i]);
          flag = true;
        }
      }
      free(name2);
      if (!flag) {
        printf("%s\n", "Нет совпадений!");
      }
      break;
    }
    case 7: {
      if (!objects) {
        printf("Error! Noone user!");
        return;
      }
      return;
    }

    default:
      printf("%s", "Error, try again");
    }
  }
}

int DeleteMemory(Warship **objects, const int count) {
  if (!objects) {
    return -1;
  } else {
    for (int i = 0; i < count; ++i) {
      free(objects[i]->NameOfShip);
      free(objects[i]->ManufacturerName);
      free(objects[i]->Status);
      for (int j = 0; j < objects[i]->countOfHistoryShip; ++j) {

        free(objects[i]->HistoryOfShip[j]);
      }
      free(objects[i]->HistoryOfShip);
      free(objects[i]);
    }
    free(objects);
    return 1;
  }
}
int PrintObj(const Warship *obj) {
  if (!obj) {
    return -1;
  } else {
    printf("Название корабля:%s\n", obj->NameOfShip);
    printf("Название верфи-производителя:%s\n", obj->ManufacturerName);
    printf("Год  спуска на воду:%d\n", obj->Age);

    int i = 0;
    while (i < obj->countOfHistoryShip) {
      printf("Кампания № %d:\n%s\n", i + 1, obj->HistoryOfShip[i]);
      ++i;
    }
    printf("Состав команды:%d\n", obj->CountOFCrew);
    printf("Состояние корабля:%s\n", obj->Status);
    return 1;
  }
}
#pragma once

typedef struct {
  const char *NameOfShip;
  const char *ManufacturerName;
  int Age;
  char **HistoryOfShip;
  int countOfHistoryShip;
  int CountOFCrew;
  const char *Status;

} Warship;

Warship *initShip(Warship *obj);
const char *GetString(const char *name);
int PrintObj(const Warship *);
int DeleteMemory(Warship **, const int);
void SearchInfo(Warship **, const int);
char **get_atributes(Warship *);
int GetIntFromString(char *name);
// char** get_atributes_for_test(Warship* obj)
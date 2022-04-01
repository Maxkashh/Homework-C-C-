#pragma once
typedef struct
{
    int vec[100];
}Vector;
int check_status();//для возврата статуса успешно ли создан  объект
unsigned int root1(unsigned int a);
double Norma_Difference(const Vector* vec,int size);//Нахождение нормы вектора
Vector* Vec_init(int size_vec);//Инициализация компонент вектора рандомными значениями
double minDiff(double  vector, double val);//разность норм векторов
int min_vector(const double * arr,int size);//поиск минимальной разности
int DelMem(Vector **objects, const int count);//Освобождение памяти выделенной под объекты
int Create_Result_FILE(double norma_vvedennogo, double norma_naidennogo,int index,const Vector* vec,const Vector* foundvec  );//Создания файла с результатами поиска
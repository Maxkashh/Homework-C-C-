#include <gtest/gtest.h>

extern "C" {
    #include "fib.h"
}

TEST(GetIntFromString, ProverkaNaInt) {

    int a=1970;
    char dig[]="1970\n";
    EXPECT_EQ(1970,  GetIntFromString(dig));
    
}
 
 
 TEST(GetString, Overflow) {
    const char str[55]="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    EXPECT_STRNE("Dont have memory!",  GetString(str));
    
 }
TEST(InitStructure, WarshipInit) {
    Warship * a=NULL;
     
    EXPECT_FALSE(a==initShip(a) );
    
}


TEST(GetString, Overfloww) {
     
    EXPECT_STREQ("Boat\0",  GetString("Boat"));
    
 }

//  TEST(getatr, Testforgetatr) {
//      Warship b;
//     b.NameOfShip="Boat";
//     b.ManufacturerName="Comp";
//     b.Age=1922;
//     b.CountOFCrew=100;
//     b.Status="Bad";
//      Warship* a=&b;
//      char** ptr=get_atributes_for_test(a);
//      char *buf[3];
//      for(int i=0;i<3;++i)
//      {
//          buf[i]=ptr[i];
//     EXPECT_TRUE(*buf[i]==*ptr[i]);
//      }

    
    
//  }
// TEST(voidfunctions, check) {
// printf("%s\n", "Введите количество кораблей:");
//     char c = 0;
//     scanf("%c", &c);
//     while (!isdigit(c))
//     {
//         printf("Error! Its not a digit! Enter your value again:%s\n");
//         fseek(stdin, 0, SEEK_END);
//         scanf("%c", &c);

//     }
//     int a = 0;
//     a = c - '0';


//     Warship** objects = (Warship**)malloc(sizeof(Warship*) * a);
//     //EXPECT_EQ(NULL,objects);
//     if (!objects) { return ; }
     
//     else
//     {
//         for (int i = 0; i < a; ++i)
//         {
//             objects[i] = initShip(objects[i]);
//         }
//         SearchInfo(objects, a);
         
//        int check= DeleteMemory(objects, a);
//        EXPECT_EQ(1,check);
//     }
// }

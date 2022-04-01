#include <gtest/gtest.h>
#include<malloc.h>
#include<stdio.h>
extern "C" {
    #include "lib1.h"
     
}
 TEST(lib1,Check_NormaDifference)
 {
 Vector check;
 int size=2;
 int a=3;
 for (int i = 0; i < size; i++)
 {
      check.vec[i]=a++;
 }
 double res=Norma_Difference(&check,size);
 EXPECT_EQ(res,5.0);
 
 }
TEST(lib1,Check_NormaDifference2)
 {
 Vector check;
 int size=2;
 int a=-3;
 for (int i = 0; i < size; i++)
 {
      check.vec[i]=a--;
 }
 double res=Norma_Difference(&check,size);
 EXPECT_EQ(res,5.0);
 
 }


 TEST(lib1,Check_NormaDifference3)
 {
 Vector *check=NULL;
 
 double res=Norma_Difference(check,0);
 EXPECT_EQ(res,1);
 
 }

 TEST(lib1, Check_mindif)
 {
int a=5; 
int b=6;
int res=minDiff(a,b);
EXPECT_EQ(res,1);
 }


TEST(lib1,check_init)
{
    Vector *vec=Vec_init(1);
    EXPECT_EQ(check_status(),0);
}
  
TEST(lib1,check_init2)
{
    Vector *vec=Vec_init(1);
    EXPECT_TRUE(vec!=NULL);
}
TEST(lib1,check_min_vector)
{
    double arr[3]={1,2,3};
    int res=min_vector(arr,3);
    EXPECT_EQ(res,0);

}

TEST(lib1,check_min_vector2)
{
    double arr[4]={-1,2,-3,-5};
    int res=min_vector(arr,4);
    EXPECT_EQ(res,3);

}

TEST(lib1,check_DelMem)
{
    int size=3;
    Vector **objects = (Vector**)malloc(sizeof(Vector *) * size);
    for (size_t i = 0; i < size; i++)
    {
        objects[i]=Vec_init(1);
    }
    int res=DelMem(objects,3);
    EXPECT_EQ(res,0);
    

}


TEST(lib1,check_CreateFILE)
{
    Vector *a=Vec_init(1);
    Vector *b=Vec_init(2);

    int res=Create_Result_FILE(5,7,0,a,b);
    EXPECT_EQ(res,0);
    free(a);
    free(b);
    

}

 int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//
//  main.c
//  test.1
//
//  Created by 曾爷666 on 2022/4/18.
//
#include <stdio.h>
#include <string.h>
#include <assert.h>
//暴力求解法
//三步求解法
void reverse(char* left, char* right)
{
    while (left<right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
void left_move(char* arr , int k)
{
    assert(arr);
    int len = strlen(arr);
    reverse(arr,arr+k-1);//逆序左边
    reverse(arr+k+1,arr+len-1);//逆序右边
    reverse(arr,arr+len-1);//逆序整体
   // int i ;
  //  for (i=0; i<k; i++)
    //{
        //1
      //  char tmp = *arr;
        //2
        //int j;
        //for (j=0; j<len-1; j++)
        //{
        //    *(arr+j)=*(arr+1+j);
       // }
        //3
       // *(arr+len-1)=tmp;
    //}
}
int main()
{
    //设计一个左旋字符串的函数
    char arr[] = "abcdef";
    int k ;
    printf("请输入左旋次数\n");
    scanf("%d",&k);
    left_move(arr,k);
    
    printf("%s\n",arr);
    return 0 ;
}

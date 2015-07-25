// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
    int N;
    int s, i, j;
    int squa;
    scanf_s("%d", &N);
    int **a = (int **)malloc(N * sizeof(int));
    if(NULL == a)
    {
        return 0;
    }
    //空间分配
    for(i = 0; i < N; i++)
    {
        if(NULL == (a[i] = (int*)malloc(N * sizeof(int))))
        {
            while(--i >= 0)
            {
                free(a[i]);
            }
            free(a);
            return 1;
        }
    }
    squa = N * N;
    //求对应位置上应填写的值
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        { 
            s = i + j;
             
            if(s < N)//上三角
            {
                s = i + j;//为了看的更清楚，这里加了这条与下面对称的语句    
                a[i][j] = s * (s + 1) / 2 + ((0 == (i + j) % 2) ? i : j);
            }
            else//下三角
            {
                s = (N - 1 - i) + (N - 1 - j);
                a[i][j] = squa - s * (s + 1) / 2 - (N - ((0 == (i + j) % 2) ? i : j));
            }
        }
    }
    //打印输出
    for(i = 0; i < N; i ++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    system("Pause"); 
    return 0;
}
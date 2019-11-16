#ifndef MAXGAP_H_INCLUDED
#define MAXGAP_H_INCLUDED
class MaxGap{
    public:
        int count;//数据的个数
        double maxGap;
        double *num;//存放数据的数组
        MaxGap(const char *filename);
        ~Maxgap();
        double getMaxGap(int n, double *ary);
};
int minIndex(int n, double *ary);
int maxIndex(int n, double *ary);
void menu();
#endif

#include <fstream>
#include "MaxGap.h"

MaxGap::MaxGap(const char *filename){
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("can't open the file!");
        exit(0);
    }
    fscanf(fp, "%d", &count);//读取第一行数据
    num = new double[count];
    for (int i = 0; i < count; i++)
        fscanf(fp, "%lf", &num[i]);//读取第二行数据
    maxGap = 0;
    fclose(fp);
}

double MaxGap::getMaxGap(int n, double *ary)
{
    int  min = getmin(n, ary);
    double minnum = ary[min];
    int max = getmax(n, ary);
    double maxnum = ary[max];

    double avg_gap = (maxnum - minnum) / (n - 1);
    int *block = new int[n];
    double *low = new double[n];
    double *high = new double[n];
    for (int i = 1; i < n; i++){
        block[i] = 0;
        low[i] = maxnum;
        high[i] = minnum;
    }
    int index;//间隔区间编号
    for (int i = 0; i < n; i++){
        index = int((ary[i] - minnum) / avg_gap) + 1;
        if(index == n){
            index--;
        }
        block[index]++;
        if(ary[i] < low[index])
            low[index] = ary[i];
        if(ary[i] > high[index])
            high[index] = ary[i];
    }
    double temhigh = high[1], tempmaxgap = 0, tempgap;
    for (int i = 2; i < n; i++){
        if(block[i]){
            temgap = low[i] - temphigh;
            if(tempgap > maxgap){
                tempmaxgap = tempgap;
            }
            temphigh = high[i];
        }
    }
    delete[] block; block = NULL;
    delete[] low; low = NULL;
    delete[] high; high = NULL;
    maxGap = tempmaxgap;
    return maxGap;
}

int minIndex(int n, double *ary){
    int index;
    double min = ary[0];
    for (int i = 1; i < n; i++){
        if(ary[i] < min){
            min = ary[i];
            index = i;
        }
    }
    return index;
}

int maxindex(int n, double *ary){
    int index;
    double max = ary[0];
    for (int i = 1; i < n; i++){
        if(ary[i] > max){
            max = ary[i];
            index = i;
        }
    }
    return index;
}

void menu(){
    printf("-----------------------------------\n");
    printf("input command to test the program\n");
    printf(" i or I : input filename to test\n");
    printf(" q or Q : quit\n");
    printf("------------------------------------\n");
    printf("$ input command >");
}

#include <iostream>
#include <string.h>
#include "MaxGap.h"
#define FILE_NAME_LENGTH 50
using namespace std;
int main(){
    char input[10];
    char filename[FILE_NAME_LENGTH];
    char *f = fopen("output.text", "w");
    menu();
    scanf("%s", input);
    while(stricmp(input, "p") != 0){
        if(stricmp(input, "i") == 0){
            printf("Please input the filename:");
            scanf("%s", filename);
            MaxGap gap(filename);
            double answer = gap.getMaxGap(gap.count, gap.num);
            printf("Max gap is :%.2f", answer);
            fprintf(f, "%.2f", answer);
            printf("$input command >");
            scanf("%s", input);
        }
    }
    fclose(f);
    return 0;
}
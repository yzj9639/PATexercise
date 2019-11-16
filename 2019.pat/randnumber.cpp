#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 int main(){
     srand((unsigned)time(NULL));
     for(int i = 0; i < 10; i++){
         printf("%d ",rand()%2);       //[0,1]
     }
     printf("\n");
     for(int i = 0; i < 10; i++){
         printf("%d ",rand()%5 + 3);   //[3,7]
     }
     printf("\n");
     for(int i = 0; i < 10; i++){ //任意区间[a,b](int)round((1.0*rand()/RAND_MAX*(b-a)+a))
         printf("%d ",(int)round((1.0*rand()/RAND_MAX * 50000 + 10000))); //[10000,60000]
     }                                                  //round要加一个<math.h>
     return 0;
 }
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
bool flag;
int num[4];
struct node
{
    int a,b,sum;//sum存放a,b经过oper运算之后的值 
    char oper;
};
void dfs(int cur,int a,int b,queue <node> route)
{
    if(flag) return ;
    if(cur==3)//计算收尾 
    {
        if(((a+b)==24)||((a-b)==24)||((a*b)==24)||(b!=0&&a%b==0&&a/b==24)){//如果经过上面的计算得到解 
           while(!route.empty()){
              node now=route.front();
              printf("%d%c%d=%d\n",now.a,now.oper,now.b,now.sum);//依次输出前面的计算过程 
              route.pop();
           }
           if((a+b)==24){
              if(b>a) swap(a,b);
              printf("%d+%d=%d\n",a,b,a+b);
           }
           if((a-b)==24) printf("%d-%d=%d\n",a,b,a-b);
           
           
           if((a*b)==24) {
              if(b>a) swap(a,b);
              printf("%d*%d=%d\n",a,b,a*b);
           }
           if(a%b==0&&b!=0&&(a/b)==24) printf("%d/%d=%d\n",a,b,a/b);//a/b比较特殊，要求结果必须是整数 
           flag=true;//表示找到解，一旦找到任何一个解就退出                                                               
        }
        return ;
    }
    queue <node> temp=route;
    node x;
    x.a=a,x.b=b,x.sum=a+b,x.oper='+';
    if(b>a) swap(x.a,x.b);
    temp.push(x);
    dfs(cur+1,a+b,num[cur+1],temp);//(((a*b)*c)*d) 模型 
 
    temp=route;
    x.a=a,x.b=b,x.sum=a*b,x.oper='*';
    if(b>a) swap(x.a,x.b);
    temp.push(x);
    dfs(cur+1,a*b,num[cur+1],temp);
 
    temp=route;
    x.a=a,x.b=b,x.sum=a-b,x.oper='-';
    temp.push(x);
    dfs(cur+1,a-b,num[cur+1],temp);
 
 
    if(b!=0&&a%b==0){//a/b需要验证合法性 
       temp=route;
       x.a=a,x.b=b,x.sum=a/b,x.oper='/';
       temp.push(x);
       dfs(cur+1,a/b,num[cur+1],temp);
    }
 
    temp=route;
    x.a=b,x.b=num[cur+1],x.sum=b+num[cur+1],x.oper='+';
    if(x.b>x.a) swap(x.a,x.b);
    temp.push(x);
    dfs(cur+1,a,b+num[cur+1],temp);//a*((b*c)*d) 模型 
    
    temp=route;
    x.a=b,x.b=num[cur+1],x.sum=b*num[cur+1],x.oper='*';
    if(x.b>x.a) swap(x.a,x.b);
    temp.push(x);
    dfs(cur+1,a,b*num[cur+1],temp);
 
    temp=route;
    x.a=b,x.b=num[cur+1],x.sum=b-num[cur+1],x.oper='-';
    temp.push(x);
    dfs(cur+1,a,b-num[cur+1],temp);
 
    if(num[cur+1]!=0&&b%num[cur+1]==0) {
      temp=route;
      x.a=b,x.b=num[cur+1],x.sum=b/num[cur+1],x.oper='/';
      temp.push(x);
      dfs(cur+1,a,b/num[cur+1],temp);
    }
}
int main()
{
    queue <node> t;
    scanf("%d %d %d %d",&num[0],&num[1],&num[2],&num[3]);
    while(!flag){
         dfs(1,num[0],num[1],t);
         if(!next_permutation(num,num+4))  break;
    }
    if(!flag) printf("No answer!\n");
    return 0;
}
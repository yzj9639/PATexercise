#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node{
    double num;
    char op;
    bool flag;//true表示操作数，false表示操作符
};
string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char,int> op;//优先级映射

void change(){//将中缀表达式转换为后缀表达式
    double num;
    node temp;
    for(int i = 0; i < str.length(); ){
        if(str[i] >= '0' && str[i] <= '9'){//如果是数字
            temp.flag = true;//标记这个数字
            temp.num = str[i++] - '0';//记录这个操作数的第一个数位
            while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num * 10 + (str[i] - '0');//更新这个操作数
                i++;
            }
            q.push(temp);
        }else{      //如果是操作符
            temp.flag = false;
            //只要操作符栈的栈顶元素比该操作符的优先级高
            //就把操作符栈顶元素弹出到后缀表达式的队列中
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
        //如果操作符栈中还有操作符，就把它弹出到后缀表达式队列中
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
}
double cal(){     //计算后缀表达式
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()){//只要后缀表达式队列非空
        cur = q.front();
        q.pop();
        if(cur.flag == true) s.push(cur); //如果是操作数，直接压入栈
        else{
            temp2 = s.top().num; //弹出的是第二操作数
            s.pop();
            temp1 = s.top().num; //弹出的是第一操作数
            s.pop();
            temp.flag = true;
            if(cur.op == '+') temp.num = temp1 + temp2;
            else if(cur.op == '-') temp.num = temp1 - temp2;
            else if(cur.op == '*') temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp); 
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;//设定操作符优先级
    op['*'] = op['/'] = 2;
    while(getline(cin,str), str != "0"){
        for(string::iterator it = str.end(); it != str.begin(); it--){
            if(*it == ' ') str.erase(it);
        }
        while(!s.empty()) s.pop();//初始化栈
        change();//将中缀表达式转化为后缀表达式
        printf("%.2f\n",cal());//计算后缀表达式
    }
    return 0;
}
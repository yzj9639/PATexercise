#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    vector <int> vi;
    for(int i = 1; i <= 5; i++){//循环后vi中元素为1 2 3 4 5
        vi.push_back(i);//push_back(i)在vi的末尾添加元素i，即依次添加1 2 3 4 5
    }
    vector<int>::iterator it = vi.begin();//vi.begin()取为vi的首元素地址，而it指向这个地址
    for(int i = 0; i < 5; i++){
        printf("%d ",*(it + i));//输出vi[i],从这可以看出v[i]和*(vi.begin()+i) 是等价的
    }
    return 0;
}

//另一种写法 因为迭代器还实现了两种自加操作 ++it和it++
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    vector<int> vi;
    for(int i = 1; i <= 5; i++){
        vi.push_back(i);
    }
    //vector不支持i<vi.end()的写法，因此循环采用it != vi.end()的写法
    for(vector<int> it = vi.begin(); it != vi.end(); it++){
        printf("%d ",*it);
    }
    return 0;
}
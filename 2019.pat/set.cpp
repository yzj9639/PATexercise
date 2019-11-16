#include <stdio.h>
#include <set>
using namespace std;
//内部自动有序且不含重复元素
int main(){//set只能通过迭代器iterator访问，除了vector和string，STL容器都不支持*(it+i)的访问方式
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    //注意不支持i<st.end()的写法
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        printf("%d ",*it);
    }
    return 0;
}
//insert(x) 时间复杂度O(logN)
//find(value) 返回set中对应值为value的迭代器(地址)，时间复杂度为O(logN),其中N为set内的元素个数
#include <stdio.h>
#include <set>
using namespace std;
int main(){
    set<int> st;
    for(int i = 1; i <= 3; i++){
        st.insert(i);
    }
    set<int>::iterator it = st.find(2);
    printf("%d",*it);
    return 0;
}
//erase(it) 删除元素的迭代器  时间复杂度为O(1)
//erase(value) value为需要删除元素的值 时间复杂度为O(logN)
//erase(first,last) 删除区间[first,last)内的所有元素 时间复杂度为O(last-first)
#include <stdio.h>
#include <set>
using namespace std;

int main(){
    set<int> st;
    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(30);
    set<int>::iterator it = st.find(30);
    st.erase(it,st.end());
    for(it = st.begin(); i != st.end(); i++){
        printf("%d ", *it);
    }
    return 0;
}   
//size()时间复杂度O(1) clear()时间复杂度O(N)
//set的主要作用是自动去重并升序排序
//延伸：set中元素是唯一的，如果需要处理不唯一的情况，则需要使用multiset

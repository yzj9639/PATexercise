//使用string,需要添加#include <string>  这与#include <string.h>是不一样的
//同时也要加using namespace std;
// 定义并赋值 sting str = "abcd";
//通过下标访问
// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str = "abcd";
//     for(int i = 0; i < 4; i++){
//         printf("%c",str[i]);
//     }
//     return 0;
// }
//如果要读入和输出整个字符串，则只能用cin和cout
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string str;
//     cin >> str;
//     cout << str;
//     return 0;
// }
//(2)通过迭代器访问 string::iterator it;可以用*(it+i) 只有vector和string可以
//operator:+= 这是string的加法 把两个string直接拼接起来
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string str1 = "abc", str2 = "xyz", str3;
//     str3 = str1 + str2;
//     str1 += str2;//将str2直接拼接到str1上
//     cout << str1 << endl;
//     cout << str3 << endl;
//     return 0;
// }
//operator compare 两个string类型可以直接使用==,!=,<,<=,>,>=比较大小，比较规则是字典序
//example：
// #include <stdio.h>
// #include <string>
// using namespace std;
// int main(){
//     string str1 = "aa", str2 = "aaa", str3 = "abc", str4 = "xyz";
//     if(str1 < str2) printf("ok1\n");
//     if(str2 != str3) printf("ok2\n");
//     if(str4 >= str3) printf("ok3\n");
//     return 0;
// }
//length()/size() 时间复杂度为O(1)
//insert() 时间复杂度为O(N) 有以下几种写法
//string str = "abcxyz", str2 = "opq";
//str.insert(3,str2);//往str[3]处插入opq，这里str2的位置直接写opq也是可以的
//or insert(it,it2,it3) it为原字符串欲插入位置，it2和it3为待插入字符串的首位迭代器 
//用于表示[it2,it3)将被插在it的位置上 实质上与第一种方法相同
//erase():有两种  删除单个元素和删除一个区间内所有元素  时间复杂度均为O(N)
//erase(it)  erase(first, last)  erase(pos, length)
//substr(pos,len) 返回从pos号位开始，长度为len的子串，时间复杂度为O(len)
//string::npos 是一个常数 它等于-1或者4294967295
//find(str2)：当str2是str的子串时，返回其在str中第一次出现的位置；如果不是，则返回string::npos
//str.find(str2,pos)从str的pos号位开始匹配str2，返回值与上相同。时间复杂度为O(nm),n,m分别是str1，str2长度
#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "Thank you for your smile";
    string str1 = "you";
    if(str.find(str1,7) != string::npos){
        cout << str.find(str1,7) <<endl;
    }
    return 0;
}
//str.replace(pos,len,str2)把str从pos号位开始，长度为len的子串替换成str2
//str.replace(it,it2,str2)把str的迭代器[it,it2)范围的子串替换成str2 时间复杂度为O(str.length())
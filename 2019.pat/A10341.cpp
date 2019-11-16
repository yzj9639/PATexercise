#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 1010;
map<int, string> inttoString;//编号转换为姓名
map<string, int> stringtoInt;//姓名转换为编号
map<string, int> Gang;
int weight[maxn] = {0}, G[maxn][maxn] = {{0}};
int n, k, numPerson = 0;
bool vis[maxn] = {false};
void DFS(int nowVisit, int &head, int &numMember, int &totalValue){
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]){
        head = nowVisit;
    }
    for(int i = 0; i < numPerson; i++){
        if(G[nowVisit][i] > 0){
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false){
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}
void DFSTrave(){
    for(int i = 0; i < numPerson; i++){
        if(vis[i] == false){
            int head = 0, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k){
                //head人数为numMember
                Gang[inttoString[head]] = numMember;
            }
        }
    }
}

int change(string str){
    if(stringtoInt.find(str) != stringtoInt.end()){
        //如果str已经出现
        return stringtoInt[str];
    }else{
        stringtoInt[str] = numPerson;
        inttoString[numPerson] = str;
        return numPerson++;
    }
}
int main(){
    string str1, str2;
    int w;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for(it = Gang.begin(); it != Gang.end(); it++){
        cout << it -> first << " " << it -> second << endl;
    }
    return 0;
}

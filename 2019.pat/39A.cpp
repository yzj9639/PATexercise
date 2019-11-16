#include <iostream>
#include <cstring>
using namespace std;
string state[4];
void changestate(int i){
    state[i] = (state[i] == "IN")? "OUT":"IN";
}
void pressButton(int i){
    changestate((i - 1 + 4)%4);
    changestate(i);
    changestate((i + 1) % 4);
}
bool isAllIn(){
    bool res = true;
    for(int i = 0; i < 4; i++){
        res = res && (state[i] == "IN");
    }
    return res;
}
int main(){
    for(int i = 0; i < 4; i++){
        cin >> state[i];
    }
    int k;
    cin >> k;
    bool isYes = isAllIn();
    for(int i = 0; i < k; i++){
        string op;
        cin >> op;
        if(!isYes){
            if(op == "UP"){
                pressButton(0);
            }else if(op == "RIGHT"){
                pressButton(1);
            }else if(op == "DOWN"){
                pressButton(2);
            }else if(op == "LEFT"){
                pressButton(3);
            }
            cout << state[0] << " " << state[1] << " " << state[2] << " " << state[3] <<endl;
            isYes = isAllIn();
        }
    }
    if(isYes){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
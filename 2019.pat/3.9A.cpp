#include <iostream>
#include <string>
using namespace std;
string state[4];    // 上右下左的内外状态
void changeState(int i) {   // 改变state[i]的内外状态
    state[i] = (state[i] == "IN") ? "OUT" : "IN";
}
void pressButton(int i) {   // 按上右下左中的一个按钮
    changeState((i - 1 + 4) % 4);   // 切换i-1位置的状态
    changeState(i);                 // 切换i位置的状态
    changeState((i + 1) % 4);       // 切换i+1位置的状态
}
bool isAllIn() {        // 判断是否上右下左都在内部
    bool res = true;
    for(int i = 0; i < 4; i++) {
        res = res && (state[i] == "IN");
    }
    return res;
}
int main() {
    for(int i = 0; i < 4; i++) {
        cin >> state[i];        // 输入上右下左的内外状态
    }
    int k;
    cin >> k;   // 操作次数
    bool isYes = isAllIn();     // 是否成功,初始值是初始状态下是否都在内部
    for(int i = 0; i < k; i++) {
        string op;
        cin >> op;  // 输入操作
        if(!isYes) {    // 如果已经都在内部,那么不需要处理按键
            if(op == "UP") {
                pressButton(0);         // 上的state数组下标为0
            } else if(op == "RIGHT") {
                pressButton(1);         // 右的state数组下标为1
            } else if(op == "DOWN") {
                pressButton(2);         // 下的state数组下标为2
            } else if(op == "LEFT") {
                pressButton(3);         // 左的state数组下标为3
            }
            cout << state[0] << " " << state[1] << " " << state[2] << " " << state[3] << endl;  // 输入上右下左的内外状态
            isYes = isAllIn();  // 判断是否已经成功
        }
    }
    if(isYes) {     // 输出封印解除是否成功
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
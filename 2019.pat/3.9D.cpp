#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXPlayerCards = 10;  // 每个玩家的手牌数上限
const int MAXPublicCards = 10;  // 公共牌池牌数上限
const int MAXCombines = 15;     // 组合数上限
string card[MAXPlayerCards * 4 + MAXPublicCards];   // 总牌堆
map<string, char> cardType;     // 牌名 -> 花色
// 组合
struct Combine {
    vector<string> cards;   // 组成组合的牌名们
    int score;      // 组合分
} combine[MAXCombines];

// 每个玩家的手牌数, 公共牌池牌数, 每张牌的基础分, 组合的数目, 总牌堆的牌数, 总牌堆当前下标
int numCardForPlayer, numCardForPublic, score, numCombine, numCardTotal, idxPublic;
// 我方最高总得分, 对应的对方总得分
int maxMyScore = 0, resultFriendScore = 0;

// 公共牌池, 我方手牌, 对方手牌, 我方牌组, 对方牌组
vector<string> publicCards, myHandCards, friendHandCards, myDeck, friendDeck;

// 根据牌堆计算总分
int calculateScore(vector<string> deckCards) {
    sort(deckCards.begin(), deckCards.end());   // includes函数的包含逻辑是顺序相关的,所以先排下序(组合里面的牌已经在输入时排过序了)
    int resultScore = score * (int)deckCards.size();    // 基础分
    for(int i = 0; i < numCombine; i++) {
        if(includes(deckCards.begin(), deckCards.end(), combine[i].cards.begin(), combine[i].cards.end())) {
            resultScore += combine[i].score;    // 如果牌组里的牌包含了组合,就加上组合分
        }
    }
    return resultScore;
}

// 因为friendRound函数里调用了DFS,所以这里提前声明一下
void DFS(int numRound);

// 对方回合
void friendRound(int numRound) {
    int idxFriendHandCardThisRound = -1, idxPublicCardThisRound = -1;   // 对方本回合最终选择的手牌, 对方本回合最终选择的公共牌
    for(int k = 0; k < friendHandCards.size(); k++) {   // 遍历对方手牌
        for(int l = 0; l < publicCards.size(); l++) {   // 遍历公共牌池
            if(cardType[publicCards[l]] == cardType[friendHandCards[k]]) {      // 如果花色相同
                idxFriendHandCardThisRound = k;     // 对方本回合最终选择的手牌的下标一定为k
                if(idxPublicCardThisRound == -1 || publicCards[l] < publicCards[idxPublicCardThisRound]) {
                    idxPublicCardThisRound = l;     // 如果公共牌的字典序比已选择的更小,那么更新选择的牌为下标为l的公共牌
                }
            }
        }
        if(idxFriendHandCardThisRound == -1) {      // 如果已经确定了选择,那么不需要继续遍历了
            break;
        }
    }
    if(idxFriendHandCardThisRound == -1) {  // 如果没有花色相同的牌
        idxFriendHandCardThisRound = 0; // 那么选择字典序最小的手牌(手牌已经在发牌后排过序了)
    }
    string tempFriendHandCard = friendHandCards[idxFriendHandCardThisRound];        // 备份需要删掉的手牌
    friendHandCards.erase(friendHandCards.begin() + idxFriendHandCardThisRound);    // 删掉对方本回合选择的手牌
    friendDeck.push_back(tempFriendHandCard);   // 把这张手牌加入对方牌组
    if(idxPublicCardThisRound != -1) {      // 如果对方有选择公共牌
        string tempPublicCard2 = publicCards[idxPublicCardThisRound];       // 备份需要删掉的公共牌
        publicCards.erase(publicCards.begin() + idxPublicCardThisRound);    // 删掉对方本回合选择的公共牌
        friendDeck.push_back(tempPublicCard2);          // 把这张公共牌加入对方牌组
        publicCards.push_back(card[idxPublic]);         // 往公共牌池里加一张新牌
        idxPublic++;                // 总牌堆当前牌的位置加1
        DFS(numRound - 1);          // 递归处理下一个回合
        idxPublic--;                // 总牌堆当前牌的位置减1
        publicCards.pop_back();     // 去掉上面"往公共牌池里加一张新牌"操作加入的新牌
        friendDeck.pop_back();      // 去掉上面"把这张公共牌加入对方牌组"操作加入对方牌组的牌
        publicCards.insert(publicCards.begin() + idxPublicCardThisRound, tempPublicCard2);  // 将上面"删掉对方本回合选择的公共牌"删掉的牌插回去
    } else {    // 如果对方没有选择公共牌
        DFS(numRound - 1);  //那么直接递归处理下一个回合
    }
    friendDeck.pop_back();      // 从对方牌组里去掉上面"把这张手牌加入对方牌组"的手牌
    friendHandCards.insert(friendHandCards.begin() + idxFriendHandCardThisRound, tempFriendHandCard);   // 将上面"删掉对方本回合选择的手牌"删掉的牌插回去
}

// DFS的一层处理我方的一个回合+对方的一个回合
void DFS(int numRound) {
    if(!numRound) {     // 如果手牌已经全部出完
        int myScore = calculateScore(myDeck);           // 结算我方总得分
        int friendScore = calculateScore(friendDeck);   // 结算对方总得分
        if(myScore > maxMyScore) {      // 如果我方获得了更高的总得分
            maxMyScore = myScore;       // 更新最高总得分
            resultFriendScore = friendScore;    // 更新对方总得分
        } else if(myScore == maxMyScore && friendScore < resultFriendScore) {   // 如果我方获得了与最高总得分相同的总得分,并且对方总得分更低
            resultFriendScore = friendScore;    // 更新对方总得分
        }
        return;
    }
    bool haveSameTypeCard = false;      // 记录我方手牌与公共牌池是否有相同花色的牌
    for(int i = 0; i < myHandCards.size(); i++) {       // 遍历我方手牌
        string tempMyHandCard = myHandCards[i];         // 备份需要删掉的手牌
        myHandCards.erase(myHandCards.begin() + i);     // 删掉我方本回合选择的手牌
        myDeck.push_back(tempMyHandCard);               // 把这张手牌加入我方牌组
        for(int j = 0; j < publicCards.size(); j++) {   // 遍历公共牌池的牌
            if(cardType[publicCards[j]] == cardType[tempMyHandCard]) {  // 如果花色相同
                haveSameTypeCard = true;    // 说明存在相同花色的牌
                string tempPublicCard = publicCards[j];     // 备份需要删掉的公共牌
                publicCards.erase(publicCards.begin() + j); // 删掉我方本回合选择的公共牌
                myDeck.push_back(tempPublicCard);           // 把这张公共牌加入我方牌组
                publicCards.push_back(card[idxPublic]);     // 往公共牌池里加一张新牌
                idxPublic++;                                // 总牌堆当前牌的位置加1
                friendRound(numRound);      // 处理对方回合,注意numRound不需要减1
                idxPublic--;                                // 总牌堆当前牌的位置减1
                publicCards.pop_back();                     // 去掉上面"往公共牌池里加一张新牌"操作加入的新牌
                myDeck.pop_back();                          // 去掉上面"把这张公共牌加入我方牌组"操作加入我方牌组的牌
                publicCards.insert(publicCards.begin() + j, tempPublicCard);    // 将上面"删掉我方本回合选择的公共牌"删掉的牌插回去
            }
        }
        myDeck.pop_back();      // 从我方牌组里去掉上面"把这张手牌加入对方牌组"的手牌
        myHandCards.insert(myHandCards.begin() + i, tempMyHandCard);    // 将上面"删掉我方本回合选择的手牌"删掉的牌插回去
    }
    if(!haveSameTypeCard) {     // 如果不存在花色相同的牌
        for(int i = 0; i < myHandCards.size(); i++) {                       // 遍历我方手牌
            string tempMyHandCard = myHandCards[i];                         // 备份需要删掉的手牌
            myHandCards.erase(myHandCards.begin() + i);                     // 删掉我方本回合选择的手牌
            myDeck.push_back(tempMyHandCard);                               // 把这张手牌加入我方牌组
            friendRound(numRound);      // 处理对方回合,注意numRound不需要减1
            myDeck.pop_back();                                              // 从我方牌组里去掉上面"把这张手牌加入对方牌组"的手牌
            myHandCards.insert(myHandCards.begin() + i, tempMyHandCard);    // 将上面"删掉我方本回合选择的手牌"删掉的牌插回去
        }
    }
}

int main() {
    cin >> numCardForPlayer >> numCardForPublic >> score;       // 每个玩家的手牌数, 公共牌池牌数
    numCardTotal = numCardForPlayer * 4 + numCardForPublic;     // 总牌数
    for(int i = 0; i < numCardTotal; i++) {
        char type;
        cin >> card[i] >> type;     // 输入牌名与花色
        cardType[card[i]] = type;   // 建立牌名->花色的映射
    }
    cin >> numCombine;  // 组合数
    for(int i = 0; i < numCombine; i++) {
        int num;
        cin >> num >> combine[i].score;     // 组合需要的牌数, 组合分
        for(int j = 0; j < num; j++) {
            string tempCard;
            cin >> tempCard;
            combine[i].cards.push_back(tempCard);   // 组合需要的牌
        }
        sort(combine[i].cards.begin(), combine[i].cards.end());     // 按牌名字典序从小到大排序,方便处理算分相关的逻辑
    }
    idxPublic = 0;      // 总牌堆的当前发到的牌的下标
    while(myHandCards.size() < numCardForPlayer or publicCards.size() < numCardForPublic) {     // 发牌
        if(myHandCards.size() < numCardForPlayer) {         // 手牌还没发够数量
            myHandCards.push_back(card[idxPublic++]);       // 发给我方手牌
            friendHandCards.push_back(card[idxPublic++]);   // 发给对方手牌
        }
        if(publicCards.size() < numCardForPublic) {         // 公共牌池还没发够数量
            publicCards.push_back(card[idxPublic++]);       // 发给公共牌池
        }
    }
    sort(friendHandCards.begin(), friendHandCards.end());   // 将手牌按字典序从小到大排序,方便处理对方相关的逻辑
    DFS(numCardForPlayer);      // 递归遍历所有情况
    cout << maxMyScore << " " << resultFriendScore << endl; // 输出我方最高总得分与相应的对方总得分
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> MinDenomination(vector<int> coins, int amount){
    vector<int> outcome;
    for(int i=coins.size() - 1;i>=0;i--){
        while(amount >= coins[i]){
            amount -= coins[i];
            outcome.push_back(coins[i]);
        }
    }
    return outcome;
}

int main(){
 vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
 int amount = 49;
 vector<int> ans = MinDenomination(coins,amount);
 for(auto it: ans) cout<<it<<" ";
}
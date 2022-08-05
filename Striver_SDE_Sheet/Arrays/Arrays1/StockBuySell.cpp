#include "bits/stdc++.h"
using namespace std;

//! Brute Force
// O(n2)

//  int maxProfit(vector<int>& prices){
//     int diff = 0;
//     int maxprofit = INT_MIN;
//     vector<int> profits;

    // i is my day to buy
    // j is my day to sell
//     for (int i = 0; i <= prices.size()-1; i++){
//         for (int j = i+1; j <= prices.size()-1; j++){
            
//             diff = prices[j] - prices[i];
//             if(diff>maxprofit){
//                 maxprofit = diff;
//             }
//         }    
//     }
//     if(maxprofit>=0)
//         return maxprofit;
//     else
//         return 0;
// }

//! Optimal
// O(n)

 int maxProfit(vector<int>& prices){
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++){
        if(prices[i]<minPrice)
            minPrice = prices[i];
        maxProfit = max(maxProfit,prices[i]-minPrice);
    }
    return maxProfit;
    
}

 int main(){

    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
 }
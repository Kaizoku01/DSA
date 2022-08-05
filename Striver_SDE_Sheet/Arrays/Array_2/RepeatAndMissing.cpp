#include "bits/stdc++.h"
using namespace std;

//!Brute
// void repeatAndMissing(vector<int>& num){

//     int n = num.size()+1;
//     vector<int> substitute(n,0);
//     vector<int> ans;
//     for (int i = 0; i < num.size(); i++){
//         substitute[num[i]]++;
//     }
//     for (int i = 1; i <= num.size(); i++){
//         if(substitute[i]==0 || substitute[i]>1){
//             ans.push_back(i);
//         }
//     }
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout<<ans[i];
//     }   
// }

//! Using maths eqns
vector<int> repeatAndMissing(vector<int>& num){
    long long int size = num.size();

    long long int S = (size*(size+1))/2;
    long long int P = (size*(size+1)*(2*size+1))/6;
    long long int missing = 0 , repeat = 0;

    for (int i = 0; i < num.size(); i++){
        S -= (long long int)num[i];
        P -= (long long int)num[i]*(long long int)num[i];
    }
    missing = (S + P/S)/2;
    repeat = missing - S;

    vector<int> ans;

    ans.push_back(repeat);
    ans.push_back(missing);
    
    return ans;

} 

int main(){
    vector<int> num{3,1,2,5,3,};
    
    vector<int> outcome = repeatAndMissing(num);
    for(auto it: outcome){
        cout<<it;
    }
    
    
}
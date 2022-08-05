#include <bits/stdc++.h>
using namespace std;


//! Brute 
//? TC = O(n! * n) + O(2n)    ..... Recursive approach we are using next permutation fn
    // string getPermutation(int n, int k) {
    //     //generating input sequence
    //     vector<int> seq;
    //     for(int i=0; i<n;i++){
    //         seq.push_back(i + 1);
    //     }
    //     //generating all possible permutations
    //     vector<vector<int>> permu;
   
    //     do{
    //         permu.push_back(seq);
    //     }
    //     while(next_permutation(seq.begin(), seq.end()));
    //     //searching for kth row
    //     string s;
    //     for(int i = 0; i< permu[0].size(); i++){
    //         int temp = permu[k-1][i];
    //         s += to_string(temp);
    //     }
    //     return s;
            
    // }


//! Optimized
//? TC = O(N^2)  SC = O(N) ......Non recursive method.....mathematical approach
string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> seq;
    //making sequence from n
    for(int i=1;i<n;i++){
        fact *= i;
        seq.push_back(i);
    }
    seq.push_back(n);
    string s = "";
    k = k - 1;
    while(true){
        s += to_string(seq[k / fact]);
        seq.erase(seq.begin() + k / fact);

        if(seq.size() == 0){
            break;
        }
        k %= fact;
        fact /= seq.size();
    }
    return s;

}
int main(){
    int n = 3,k = 3;

    string s = getPermutation(n,k);
    cout<<s;
    return 0;
}
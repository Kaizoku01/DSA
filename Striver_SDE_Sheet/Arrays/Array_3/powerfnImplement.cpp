#include "bits/stdc++.h"
using namespace std;

//! Brute 

// double myPow(double x , int n){
//     double ans=1;
//     long long int newN = n;

//     if(newN<0) newN = -1* newN;

//     for (int i = 1; i <= newN; i++){
//         ans = ans*x;
//     }
//     if(n<0){
//         ans = 1/ans;
//         return ans;
//     }
//     else if (n>0){
//         return ans;
//     }
//     else{
//         return 1;
//     }
// }

//! Binary exponentation method

double myPow(double x ,int n){
    double ans = 1.0;
    long long int newN = n;
    if(newN<0) newN = -1* newN;

    while (newN){
        if(newN % 2==0){
            x = x * x;
            newN = newN/2;
        }
        if(newN % 2==1){
            ans = ans * x;
            newN = newN - 1;
        }
    }
    if(n<0) ans = (double)(1.0) / (double)ans;
    return ans;
}
    
int main(){

    cout<<myPow(5,2);
}
#include <bits/stdc++.h>
using namespace std;


//! TC = O(N) * O(log(m*10^d))    SC = O(1)


double multiply(double number, int n){
    double ans = 1.0;
    for (int i = 1; i <= n; i++){
        ans = ans * number;
    }
    return ans;
}

void nthRoot(int n, int m){
    double low = 1;
    double high = m;
    double esp = 1e-6;

    while (high-low > esp){
        double mid = (low+high) / 2.0;
        if(multiply(mid,n) < m){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    cout<<"Root of "<<m<<" is "<<low;
    
}
int main(){
    int n = 5;
    int m = 27;
    nthRoot(n,m);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int numRollsToTarget(int d, int f, int target) {
        
        int** dp = new int*[d];
        for(int i=0;i<d;i++){
            dp[i] = new int[1000+1];
        }
        
        for(int i=0;i<d;i++){
            for(int j=0;j<=1000;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=f;i++){
            dp[0][i]=1;
        }
        
        int MOD = 1000000007;
        
        for(int i=1;i<d;i++){
            
            for(int s=1;s<=target;s++){
                int ans = 0;
                for(int k=s-1;k>=s-f && k>=0;k--){
                    ans = (ans + dp[i-1][k])%MOD;
                }
                dp[i][s]=ans;
            }
        }
        
        return dp[d-1][target];
}

int main(){
    int n,m,X;
    cin>>n>>m>>X;
    cout<<"No. of ways = "<<numRollsToTarget(n,m,X)<<endl;
    return 0;
}

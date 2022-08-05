#include "bits/stdc++.h"
using namespace std;

//! Brute
int MinimumPlatform(vector<int> start, vector<int> end,int n){
    // int n = start.size();
    pair<int,int> timeStamp[n];
    int platform = 0;

    //storing
    for(int i = 0; i<n;i++){
        timeStamp[i].first = start[i];
        timeStamp[i].second = end[i];
    }
    int upLimit = timeStamp[0].first;
    int downLimit = timeStamp[0].second;

    for(int i = 1;i<=n;i++){
        if(timeStamp[i].first > downLimit){
            upLimit = timeStamp[i].first;
            downLimit = timeStamp[i].second;
        }
        else {   //timeStamp[i].first < downLimit
            if(timeStamp[i].first >= upLimit){
                upLimit = timeStamp[i].first;
                downLimit = timeStamp[i].second;
                platform++;
            }
        }
    }
    if(platform == 0) return 1;
    else{
        return platform;
    }
        
}
//! Optimized

// int countPlatforms(int n,int arr[],int dep[])
//  {
//     sort(arr,arr+n);
//     sort(dep,dep+n);
 
//     int ans=1;
//     int count=1;
//     int i=1,j=0;
//     while(i<n && j<n)
//     {
//         if(arr[i]<=dep[j]) //one more platform needed
//         {
//             count++;
//             i++;
//         }
//         else //one platform can be reduced
//         {
//             count--;
//             j++;
//         }
//         ans=max(ans,count); //updating the value with the current maximum
//     }
//     return ans;
//  }

int main(){

    // vector<int> start = {1020, 1200};
    // vector<int> end = {1050, 1230};
    vector<int> start = {900, 945, 955, 1100, 1500, 1800};
    vector<int> end = {920, 1200, 1130, 1150, 1900, 2000};

    int n = start.size();



    int ans = MinimumPlatform(start, end,n);
    cout<<ans;
}
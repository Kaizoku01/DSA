#include "bits/stdc++.h"
using namespace std;


//! Brute force 
// O(n2)

//*  --->>> can also be done by first sorting the array and then traversing linearly .. comparing i th and i+1 th element...
//* then complexity  = O(nlogn)+ O(n) 

// int duplicate(vector<int> & num){

//     int N = num.size();
//     int duplicate;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = i+1; j < N; j++)
//         {
//             if(num[i]==num[j]){
//                 duplicate = num[i];  
//             }
//         }  
//     }
//     return duplicate;
// }

//! Frequency Array approach
// TC = O(N)  SC = O(N)

// int duplicate(vector<int> & num){

//     int n = num.size();
//     vector<int> freq(n+1,0);

//     for (int i = 0; i < n; i++)
//     {
//         if(freq[num[i]]==0){
//             freq[num[i]]=1;
//         }else{
//             return num[i];
//         }
//     }
//     return 0;
    
// }

//! Linked List Cycle method      
// TC O(n)  SC O(1)

int duplicate(vector<int> & num){
    int slow = num[0];
    int fast = num[0];
    
    do{
        slow = num[slow];
        fast = num[num[fast]];
    }while(slow != fast);

    fast = num[0];

    while(slow != fast){
        slow = num[slow];
        fast = num[fast];
    }
    return slow;
}

int main(){
    vector<int> num{3,1,3,4,2};

    cout<<duplicate(num);

    return 0;
}

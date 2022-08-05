#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> merge(vector<vector<int>> & intervals){
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> answer;

    for (int i = 0; i < intervals.size(); i++){
        if(answer.empty() || answer.back()[1] < intervals[i][0]){
            vector<int> v = {
                intervals[i][0],
                intervals[i][1],
            };
            answer.push_back(v);
        }
        else{
            answer.back()[1]= max(answer.back()[1],intervals[i][1]);
        }
    }
    return answer;
}

int main(){

    vector<vector<int>> intervals = {{1,3},{1,3},{8,10},{15,18},{2,6}};
    // {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> answer = merge(intervals);


    for(auto it: answer){
        cout<< it[0]<<" "<<it[1]<<endl;
    }
    
}
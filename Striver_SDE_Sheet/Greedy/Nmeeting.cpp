#include <bits/stdc++.h>
using namespace std;

struct Meeting{
    int start;
    int end;
    int number;
};

bool comparator(struct Meeting m1, Meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.number < m2.number) return true;
    return false;
}

void Nmeeting(vector<int> &s, vector<int> & e){
    int n = s.size();
    struct Meeting meet[n];
    
    for(int i=0;i<n;i++){
        meet[i].start = s[i] , meet[i].end = e[i], meet[i].number = i+1;
    }

    sort(meet, meet + n, comparator);

    vector<int> answer;

    int limit = meet[0].end;
    answer.push_back(meet[0].number);

    for(int i = 1;i<n;i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            answer.push_back(meet[i].number);
        }
    }
    cout<<"Meeting Order "<<endl;
    for(int it: answer) cout<<it<<" ";
}

int main(){
    vector<int> s = {1,3,0,5,8,5};
    vector<int> e = {2,4,5,7,9,9};
    Nmeeting(s,e);
}
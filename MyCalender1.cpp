
//? Day 3

#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: v){
            if(!(it.second <start || end-1 < it.first)) return false;
        }
        v.push_back({start,end-1});
        return true;
    }
};

int main(){
    return 0;
}
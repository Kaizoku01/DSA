#include <bits/stdc++.h>
using namespace std;


bool isSafe(int node, vector<vector<bool>> graph, vector<int> color, int n, int col){
    for(int k = 0; k<n; k++){
        if(k!= node && graph[k][node] == 1 && color[k] == col){
            return false;
        }
    }
    return true;
}

bool Solve(int node, int m, int N, vector<vector<bool>> graph, vector<int> color){
    if(node == N) return true;

    for(int i = 1; i <= m; i++){
        if(isSafe(node, graph, color, N, i)){
            color[node] = i;
            if(Solve(node + 1, m, N, graph, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool mColor(vector<vector<bool>> graph, int m, int N){
    vector<int> color(N,0);
    if(Solve(0, m, N, graph, color)) return true;

    return false;
}

int main(){
    return 0;
}
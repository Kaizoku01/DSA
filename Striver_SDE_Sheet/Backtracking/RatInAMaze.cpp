#include <bits/stdc++.h>
using namespace std;
//! Naive
void Solve(int i, int j, int n, vector<vector<int>> &maze, vector<string> &ans, string move, vector<vector<int>> &vis){
    //exit condition
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    //downward
    if(i + 1 < n && !vis[i+1][j] && maze[i+1][j]==1){   // first: inBound condn  second: if not visited  
        vis[i][j] = 1;                                // third: should be accessible to move in maze
        Solve(i+1,j,n,maze,ans,move + 'D', vis);
        vis[i][j] = 0;                                                   
    }

    //left
    if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1]==1){
        vis[i][j] = 1;
        Solve(i, j-1, n, maze, ans, move + 'L', vis);
        vis[i][j] = 0;
    }
    //right
       if(j+1 < n && !vis[i][j+1] && maze[i][j+1]==1){
        vis[i][j] = 1;
        Solve(i, j+1, n, maze, ans, move + 'R', vis);
        vis[i][j] = 0;
    }
    //upward
       if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j]==1){
        vis[i][j] = 1;
        Solve(i-1, j, n, maze, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}
//! Optimized
void CleanSolve(int i, int j, int n, vector<vector<int>> &maze, vector<string> &ans, string move, vector<vector<int>> &vis,
vector<int>di,vector<int>dj){
    //exit condition
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for(int ind = 0; ind<4;ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj]==1){
            vis[i][j] = 1;
            CleanSolve(nexti, nextj, n, maze,ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}
vector<string> RatInAMaze(vector<vector<int>> &maze, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<int> di = {1,0,0,-1};
    vector<int> dj = {0,-1,1,0};
    if(maze[0][0]==1) CleanSolve(0,0,n,maze,ans,"",vis,di,dj);
    return ans;
}

int main() {
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};


  vector < string > result = RatInAMaze(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}
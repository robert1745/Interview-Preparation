#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>>&adj, vector<bool>&visited){

    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<"";
        for(auto it: adj[curr]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
}
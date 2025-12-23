#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// Intuition

/*
“We’re given a reference to one node of a graph.
Since the graph can have cycles, I can’t just recursively copy nodes without tracking 
what I’ve already cloned.

So my idea is to traverse the graph and, for each original node, 
create exactly one cloned node and store the mapping.
Whenever I see the same node again, I reuse its clone instead of recreating it.
*/    


// Algorithm
/*

- If the input node is null, return null

- If the node already exists in the map, return its clone

- Create a new node with the same value
- Store the original → clone mapping

- For each neighbor of the original node:
   - clone the neighbor
   - add it to the cloned node’s neighbors list

Return the cloned node

*/
class Solution {
    unordered_map<Node*,Node*>mp;
public:
    Node* cloneGraph(Node* node) {

        if(!node) return nullptr;

        if(mp.find(node)!=mp.end()){
            return mp[node];
        }   

        Node* clone = new  Node(node->val);
        mp[node] = clone;

        // clone for neighbours
        for(auto neigh : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neigh));
        }

        return clone;
    }
};
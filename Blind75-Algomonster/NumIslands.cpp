#include <bits/stdc++.h>
using namespace std;

/* ==============================
   1. DFS APPROACH
   ==============================
   Idea: 
   - Traverse grid, whenever we find a '1' (land),
     we explore the whole island recursively using DFS.
   - Mark visited cells as '0' to avoid revisiting.

   Time Complexity: O(m * n)
   - Each cell is visited once.
   Space Complexity: O(m * n) (in worst case recursion stack)
   ============================== */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        function<void(int,int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0') return;
            grid[x][y] = '0'; // mark visited
            for (int k = 0; k < 4; k++) {
                dfs(x + dx[k], y + dy[k]);
            }
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j);
                }
            }
        }
        return islands;
    }
};

/* ==============================
   2. BFS APPROACH
   ==============================
   Idea: 
   - Similar to DFS, but use a queue for BFS.
   - Expand level by level until all connected land is marked visited.

   Time Complexity: O(m * n)
   - Each cell is visited once.
   Space Complexity: O(min(m, n)) 
   - Queue can hold boundary cells in worst case.
   ============================== */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

/* ==============================
   3. UNION-FIND (Disjoint Set Union - DSU)
   ==============================
   Idea: 
   - Treat each land cell as a node.
   - Connect adjacent lands with union operation.
   - Finally, count number of unique parents (roots).

   Time Complexity: O(m * n * α(m*n))
   - α is the Inverse Ackermann function (almost constant).
   Space Complexity: O(m * n) 
   - Parent & rank arrays.
   ============================== */
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[rx] > rank[ry]) parent[ry] = rx;
        else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n);

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Unite neighbors
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id1 = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == '1') {
                            int id2 = ni * n + nj;
                            dsu.unite(id1, id2);
                        }
                    }
                }
            }
        }

        // Count unique roots of land
        unordered_set<int> roots;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    roots.insert(dsu.find(i * n + j));
                }
            }
        }
        return roots.size();
    }
};


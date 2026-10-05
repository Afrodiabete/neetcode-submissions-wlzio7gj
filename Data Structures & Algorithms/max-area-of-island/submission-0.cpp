class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // 1. 統一在開頭擋掉越界與水域 (0)
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        // 2. 沉島：標記為 0，代表此格已被算入面積，防止走回頭路引發死循環
        grid[i][j] = 0;

        // 3. 當前格子算 1，加上四個方向算出的總面積
        return 1 + dfs(grid, i + 1, j)
                + dfs(grid, i - 1, j)
                + dfs(grid, i, j + 1)
                + dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans= 0;
        for(int i=0; i< grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]!= 0){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};

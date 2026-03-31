class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // 1. 排序是 O(n^2) 演算法的前提
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // 如果當前最小的數大於 0，後面的和必大於 0
            if (nums[i] > 0) break;

            // 2. 固定第一個數，並去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 3. 雙指標搜尋
            int L = i + 1;
            int R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    
                    // 找到解後，左右指標都要跳過重複值
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R] == nums[R - 1]) R--;
                    
                    L++;
                    R--;
                } 
                else if (sum < 0) {
                    L++; // 太小了，增加左邊
                } 
                else {
                    R--; // 太大了，減小右邊
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // 使用陣列紀錄 A-Z 的出現次數
        int head = 0, maxCount = 0, ans = 0;
        
        for (int tail = 0; tail < s.size(); tail++) {
            // 1. 更新當前字元的頻率，並記錄視窗內「曾經出現過」的最大頻率
            maxCount = max(maxCount, ++count[s[tail] - 'A']);
            
            // 2. 核心判斷：如果 (視窗寬度 - 視窗內最高頻率) > k，代表替換次數不夠
            // 注意：這裡可以用 if 而不是 while，因為視窗大小只需要「不縮小」即可維持最大值
            if ((tail - head + 1) - maxCount > k) {
                count[s[head] - 'A']--;
                head++;
            }
            
            // 3. 更新結果
            ans = max(ans, tail - head + 1);
        }
        
        return ans;
    }
};
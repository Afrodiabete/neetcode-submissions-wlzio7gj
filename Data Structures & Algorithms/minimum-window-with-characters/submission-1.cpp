class Solution {
public:
    string minWindow(string s, string t) {
        // 1. 建立目標頻率表（ASCII 128 陣列比 map 快很多）
        vector<int> target(128, 0);
        for (char c : t) target[c]++;

        int left = 0, min_left = 0, min_len = INT_MAX;
        int required = t.size(); // 總共需要的字元數量

        for (int right = 0; right < s.size(); right++) {
            // 2. 移入右側字元
            // 如果該字元在 target 中仍大於 0，代表這是一個「有效匹配」
            if (target[s[right]] > 0) required--;
            target[s[right]]--; // 即使不是目標字元，也減少頻率（變成負數代表多餘）

            // 3. 當所有字元都湊齊了（required == 0），開始收縮左側
            while (required == 0) {
                // 更新最小長度
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }

                // 準備移出左側字元
                target[s[left]]++;
                // 如果移出的字元變回正數，代表視窗現在缺少一個必要字元了
                if (target[s[left]] > 0) required++;
                
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};
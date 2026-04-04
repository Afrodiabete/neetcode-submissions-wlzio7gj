class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; // 使用 unordered_set 查找速度為 O(1)
        int head = 0, maxLength = 0;

        for (int tail = 0; tail < s.size(); tail++) {
            // 如果發現重複字元，收縮左邊邊界 (head)
            while (charSet.find(s[tail]) != charSet.end()) {
                charSet.erase(s[head]);
                head++;
            }
            
            // 放入新字元並更新最大長度
            charSet.insert(s[tail]);
            maxLength = max(maxLength, tail - head + 1);
        }
        
        return maxLength;
    }
};
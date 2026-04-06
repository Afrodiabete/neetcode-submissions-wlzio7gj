class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        // 使用陣列代替 map，效能更快 (O(1) 空間)
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n1; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        // 統計一開始有多少個字母頻率是相同的
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] == cnt2[i]) matches++;
        }

        // 開始滑動視窗
        for (int i = 0; i < n2 - n1; i++) {
            if (matches == 26) return true;

            int left = s2[i] - 'a';          // 即將移出的字元
            int right = s2[i + n1] - 'a';    // 即將移入的字元

            // 更新右側 (移入)
            cnt2[right]++;
            if (cnt2[right] == cnt1[right]) {
                matches++;
            } else if (cnt2[right] == cnt1[right] + 1) {
                matches--;
            }

            // 更新左側 (移出)
            cnt2[left]--;
            if (cnt2[left] == cnt1[left]) {
                matches++;
            } else if (cnt2[left] == cnt1[left] - 1) {
                matches--;
            }
        }

        return matches == 26;
    }
};
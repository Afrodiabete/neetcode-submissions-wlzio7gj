class Solution {
public:
    // 編碼：將每個字串轉為 "長度#字串"
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    // 解碼：先讀長度，再抓字串
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            // 1. 找到分隔符號 # 的位置
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // 2. 提取長度資訊並轉換為整數
            int length = stoi(s.substr(i, j - i));
            
            // 3. 根據長度，從 # 後面切出原始字串
            string temp = s.substr(j + 1, length);
            decoded.push_back(temp);
            
            // 4. 移動指標到下一個長度前綴的起點
            i = j + 1 + length;
        }
        return decoded;
    }
};
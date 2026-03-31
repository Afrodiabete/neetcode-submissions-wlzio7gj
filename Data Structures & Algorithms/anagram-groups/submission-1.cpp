class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. 使用 unordered_map 提高查找速度
        unordered_map<string, vector<string>> m;
        
        for (string& s : strs) {
            string t = s; // 每次只拷貝單個字串
            sort(t.begin(), t.end()); // 排序作為 Key
            
            // 2. 簡潔的語法：直接 push_back，若 key 不存在會自動建立
            m[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        // 預先分配空間可以稍微提升效能
        ans.reserve(m.size()); 
        
        for (auto& entry : m) {
            // 使用 move 轉移所有權，避免大規模 vector 拷貝
            ans.push_back(std::move(entry.second));
        }
        
        return ans;
    }
};
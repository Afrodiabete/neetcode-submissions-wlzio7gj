class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> t_strs = strs;
        map<string, vector<string>>m;
        for(int i=0; i<strs.size(); i++){
            sort(t_strs[i].begin(), t_strs[i].end());
            if(m.find(t_strs[i])== m.end()){
                pair<string, vector<string>> p= {t_strs[i], vector<string>{strs[i]}};
                m.insert(p);
            }
            else{
                m[t_strs[i]].push_back(strs[i]);
            }
        }
        vector<vector<string>>ans;
        for(auto i= m.begin(); i!= m.end(); i++){
            ans.push_back(i->second);
        }
        return ans;
    }
};

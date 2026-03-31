using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> m;
        for(auto n: nums){
            if(m.find(n) != m.end()){
                return true;
            }
            m.insert(pair<char, bool>(n, true));
        }
        return false;
    }
};
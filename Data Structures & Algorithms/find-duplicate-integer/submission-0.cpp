class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto n: nums){
            if(m[n]== true) return n;
            m[n]= true;
        }
        return 0;
    }
};

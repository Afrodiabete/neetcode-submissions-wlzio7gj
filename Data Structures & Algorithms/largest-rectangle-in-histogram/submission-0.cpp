class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<int> ans(heights.size());
        stk.push(0);
        int i;
        for(i=1; i< heights.size(); i++){
            while(heights[i]< heights[stk.top()]){
                ans[stk.top()]= heights[stk.top()]* (i- stk.top());
                stk.pop();
                if(stk.empty()) break;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()]= heights[stk.top()]* (i- stk.top());
            stk.pop();
        }
        for(int i=0; i< ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        stk.push(i-1);
        for(i=heights.size()- 2; i>= 0; i--){
            while(heights[i]< heights[stk.top()]){
                ans[stk.top()]+= heights[stk.top()]* (stk.top()- i- 1);
                stk.pop();
                if(stk.empty()) break;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()]+= heights[stk.top()]* (stk.top()- i- 1);
            stk.pop();
        }
        for(int i=0; i< ans.size(); i++){
            cout << ans[i] << " ";
        }
        return *max_element(ans.begin(), ans.end());
    }
};

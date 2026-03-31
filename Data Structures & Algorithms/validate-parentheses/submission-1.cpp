class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(auto c: s){
            if(c== ')' || c== ']' || c== '}'){
                if(stk.empty()){
                    return false;
                }
                if(c== ')'){
                    if(stk.top()!= '('){
                        return false;
                    }
                    stk.pop();
                }
                if(c== ']'){
                    if(stk.top()!= '['){
                        return false;
                    }
                    stk.pop();
                }
                if(c== '}'){
                    if(stk.top()!= '{'){
                        return false;
                    }
                    stk.pop();
                }
            }
            else{
                stk.push(c);
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};

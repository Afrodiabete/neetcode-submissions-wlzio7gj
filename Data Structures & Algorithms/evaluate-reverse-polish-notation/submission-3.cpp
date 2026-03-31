class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int num1= 0, num2= 0, temp;
        if(tokens.size()== 1){
            return stoi(tokens[0]);
        }
        for(auto t: tokens){
            if(t != "+" && t != "-" && t != "*" && t != "/"){
                nums.push(stoi(t));
            }
            else{
                num1= nums.top();
                nums.pop();
                num2= nums.top();
                nums.pop();
                if(t== "+"){
                    temp= num2+ num1;
                    nums.push(temp);
                }
                if(t== "-"){
                    temp= num2- num1;
                    nums.push(temp);
                }
                if(t== "*"){
                    temp= num2* num1;
                    nums.push(temp);
                }
                if(t== "/"){
                    temp= num2/ num1;
                    nums.push(temp);
                }
            }
        }
        return temp;
    }
};

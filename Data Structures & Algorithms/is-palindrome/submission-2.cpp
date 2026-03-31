class Solution {
public:
    bool isPalindrome(string s) {
        string s_process;
        for(auto v:s){
            if((v>=65 && v<=90) || (v>=97 && v<=122) || (v>=48 && v<=57)){
                if((v>=97 && v<=122)){
                    v-=32;
                }
                s_process+=v;
            }
        }
        string s_process_reverse= s_process;
        reverse(s_process_reverse.begin(), s_process_reverse.end());
        cout << s_process << endl;
        cout << s_process_reverse << endl;
        if(s_process_reverse== s_process) return true;
        return false;
    }
};

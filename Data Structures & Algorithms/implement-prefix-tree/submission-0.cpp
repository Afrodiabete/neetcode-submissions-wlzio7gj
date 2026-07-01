class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        uset.insert(word);
        return;
    }
    
    bool search(string word) {
        if(uset.find(word)!= uset.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto iter: uset){
            if((iter).starts_with(prefix)){
                return true;
            }
        }
        return false;
    }
private:
    unordered_set<string> uset;
};

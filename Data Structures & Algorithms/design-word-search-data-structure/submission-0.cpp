#include <string>

using namespace std;

// 定義 Trie 節點結構
struct TrieNode {
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // 和標準 Trie 一模一樣的插入邏輯
    void addWord(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isWord = true;
    }
    
    // 呼叫帶有 DFS 的輔助函式
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

private:
    TrieNode* root;

    // 專門處理 '.' 分岔的 DFS 函式
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // 終止條件：字串已經檢查完畢，看看當下節點是不是一個單字的結尾
        if (index == word.length()) {
            return node->isWord;
        }

        char c = word[index];

        if (c == '.') {
            // 遇到萬用字元，嘗試所有可能的路徑 (a~z)
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] != nullptr) {
                    // 只要有一條路徑回傳 true，就代表匹配成功
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
            // 26 條路都試過了，都不通
            return false;
        } else {
            // 遇到一般字元，單純往下走
            int childIndex = c - 'a';
            if (node->children[childIndex] == nullptr) {
                return false; // 根本沒這條路
            }
            // 路徑存在，繼續檢查下一個字母
            return searchHelper(word, index + 1, node->children[childIndex]);
        }
    }
};
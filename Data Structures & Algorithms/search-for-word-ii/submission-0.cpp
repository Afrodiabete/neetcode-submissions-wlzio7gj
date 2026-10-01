#include <vector>
#include <string>

using namespace std;

// 1. 定義前綴樹 (Trie) 節點
class TrieNode {
public:
    TrieNode* children[26];
    string word; // 走到結尾時，直接把完整的單字存在這裡
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;

    // 將單字加入 Trie 中
    void insertWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word; // 在最後一個節點存入完整單字
    }

    // 結合 Backtracking 的 DFS
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        // 邊界檢查與是否走過的檢查 (走過會被標記為 '#')
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') {
            return;
        }

        char c = board[i][j];
        int idx = c - 'a';

        // 如果 Trie 裡面沒有這條路徑，直接剪枝退回
        if (node->children[idx] == nullptr) {
            return;
        }

        // 往下走到下一個節點
        node = node->children[idx];

        // 勝利條件：如果節點裡面有存單字，代表找到了！
        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // ★ 關鍵：找到後立刻清空，防止同一個單字被重複加入
        }

        // 標記這個格子為已走過，防止無限迴圈
        board[i][j] = '#';

        // 往四個方向繼續 DFS
        dfs(board, i - 1, j, node); // 上
        dfs(board, i + 1, j, node); // 下
        dfs(board, i, j - 1, node); // 左
        dfs(board, i, j + 1, node); // 右

        // 復原這個格子 (Backtracking 退回時要把路讓出來)
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 初始化 Trie 樹
        root = new TrieNode();
        for (const string& word : words) {
            insertWord(word);
        }

        // 遍歷整個矩陣，把每一個格子都當作起點找找看
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
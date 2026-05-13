#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int cap;
    // list 儲存 {key, value}，靠近 begin() 是最新，靠近 end() 是最舊
    list<pair<int, int>> cache;
    // map 儲存 key 到 list 節點位置（iterator）的對映
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // 1. 如果找不到，回傳 -1
        if (m.find(key) == m.end()) {
            return -1;
        }
        
        // 2. 如果找到了，將該節點移到 list 的最前面 (代表最新使用)
        // splice 可以 $O(1)$ 移動節點而不需要刪除再重新建立
        cache.splice(cache.begin(), cache, m[key]);
        
        return m[key]->second;
    }
    
    void put(int key, int value) {
        // 1. 如果 key 已經存在
        if (m.find(key) != m.end()) {
            // 更新值
            m[key]->second = value;
            // 移到最前面
            cache.splice(cache.begin(), cache, m[key]);
            return;
        }
        
        // 2. 如果 key 不存在且容量滿了
        if (cache.size() == cap) {
            // 取得最舊的 key (在 list 的最後面)
            int key_to_del = cache.back().first;
            // 從 map 中移除
            m.erase(key_to_del);
            // 從 list 中移除
            cache.pop_back();
        }
        
        // 3. 插入新節點到最前面
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};
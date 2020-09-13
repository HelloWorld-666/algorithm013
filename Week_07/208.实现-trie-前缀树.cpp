/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // 存在->匹配   不存在->开辟新节点  另外结束时，加结束标志位
        Trie* node = this;
        for (char ch : word) 
        {
            if (node->next[ch - 'a'] == NULL)   // 不存在：新开辟
            {
                node->next[ch - 'a'] = new Trie();
            }
            node = node->next[ch - 'a'];        // 存在，复用
        }
        node->isEnd =true;                      // 加结束标志位
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) 
        {
            node = node->next[ch - 'a'];
            if (node == NULL)                   // 如果没找到返回false 
            {
                return false;
            }
        }
        return node->isEnd;                     // 找到，返回word的结束标志位true
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix)
        {
            node = node->next[ch - 'a'];
            if (node == NULL)
            {
                return false;
            }
        }
        return true;  // 由于仅匹配word前缀prefix，所以遍历不完整个word的结束标志位isEnd=true，故遍历完prefix直接返回true
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


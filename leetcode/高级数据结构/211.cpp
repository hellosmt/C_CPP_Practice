/*
 * @Author: Cement
 * @Date: 2020-02-12 18:20:43
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-12 23:53:45
 * @Description: leetcode211-添加与搜索单词 - 数据结构设计 使用前缀树（没想出来）
 */
#include<string>
#include<vector>

using std::vector;
using std::string;

#define TRIE_MAX_CHAR_NUM 26 //因为只包含小写字母，所以每个TrieNode最多分26个叉

// Trie树节点表示
struct TrieNode
{
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool is_end;  // 记录这个TrieNode是不是一个单词的结尾

    TrieNode() : is_end(false)
    {
        for (int  i = 0; i < TRIE_MAX_CHAR_NUM; i++)
        {
            child[i] = 0;
        }
    }
};

class TrieTree
{
public:
    /** Initialize your data structure here. */
    TrieTree() 
    {
        
    }

    // 析构时直接遍历node_vec_，不需要遍历整个树
    ~TrieTree()
    {
        for (int i = 0; i < node_vec_.size(); i++)
        {
            delete node_vec_[i];
        }
    }
    
    TrieNode* get_root()
    {
        return &this->root_;
    }
    
    /** Inserts a word into the trie. */
    // 插入代码不变
    void insert(const char* word) 
    {
        TrieNode* ptr = &root_;
        
        while (*word)
        {
            int pos = *word - 'a';
            // ptr没有word对应的分叉
            if(!ptr->child[pos])
            {
                // 在ptr下添加这个分叉
                ptr->child[pos] = new_node();
            }      
            ptr = ptr->child[pos];
            word++;
        }

        // 单词全部遍历完了，ptr指向的是最后一个节点，标记is_end为true
        ptr->is_end = true;   
    }
    
    /** Returns if the word is in the trie. */
    // 搜索时可以带.，匹配任意一个小写字母
    bool search(TrieNode *node, const char* word) 
    {
        // 如果word已经到了结尾，就看这个node是不是结尾
        if(*word == '\0')
        {
            return node->is_end;
        }
        
        // word是.，遍历看该node下有哪些字符叉
        if (*word == '.')
        {
            for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++)
            {
                if (node->child[i] && search(node->child[i], word+1))
                {
                    return true;
                }
            }
            return false;
        }

        else
        {
            int pos = *word - 'a';
            if (node->child[pos])
            {
                return search(node->child[pos], word+1);
            }
        }
        
        return false;
    }
    
private:
    TrieNode* new_node()
    {
        TrieNode* node = new TrieNode();
        node_vec_.push_back(node);
        return node;
    }

    TrieNode root_;
    vector<TrieNode*> node_vec_;  // 存放所有的TrieNode，方便析构
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        this->_trie_tree.insert(word.c_str());
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return this->_trie_tree.search(this->_trie_tree.get_root(), word.c_str());
    }

private:
    TrieTree _trie_tree;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
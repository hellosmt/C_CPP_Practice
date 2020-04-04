/*
 * @Author: Cement
 * @Date: 2020-02-12 16:52:39
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-12 23:53:56
 * @Description: leetcode208-实现Trie树   （没想出来）
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
    
    /** Inserts a word into the trie. */
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
    bool search(const char* word) 
    {
        TrieNode* ptr = &root_;
        
        while (*word)
        {
            int pos = *word - 'a';

            // 没有该字母对应的分叉，返回false
            if (ptr->child[pos] == 0)
            {
                return false;
            }

            ptr = ptr->child[pos];
            word++;
        }
        
        return ptr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const char* prefix) 
    {
        TrieNode* ptr = &root_;
        
        while (*prefix)
        {
            int pos = *prefix - 'a';

            // 没有该字母对应的分叉，返回false
            if (ptr->child[pos] == 0)
            {
                return false;
            }

            ptr = ptr->child[pos];
            prefix++;
        }
        
        return true;
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


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        // c_str()返回字符串的不可修改的 C 字符数组版本
        trie_tree_.insert(word.c_str());
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        return trie_tree_.search(word.c_str());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        return trie_tree_.startsWith(prefix.c_str());
    }

private:
    TrieTree trie_tree_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
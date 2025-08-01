#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector
struct tri_node{
    vi<tri_node*> children =  vi<tri_node*>(200);
    bool endOfWord = false;
};
class tri_tree{
    private:
    tri_node *root = new tri_node;
    void insert(string &s){
        tri_node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if(node->children[s[i] - 'a'] == nullptr){
                node->children[s[i] - 'a'] = new tri_node;
            }
            node = node->children[s[i] - 'a'];
        }
        node->endOfWord = true;
        
    }
    bool search(string &s){
        tri_node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if(node->children[s[i] - 'a'] == nullptr)
                return false;
            node = node->children[s[i] - 'a'];
        }
        return node->endOfWord;
        
    }
    bool find_pref(string &s){
        tri_node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if(node->children[s[i] - 'a'] == nullptr)
                return false;
            node = node->children[s[i] - 'a'];
        }
        return true;
    }
    public:
    void insert_string(string &s){
        insert(s);
    }
    bool search_string(string &s){
        return search(s);
    }
    bool search_pref(string &s){
        return find_pref(s);
    }
};
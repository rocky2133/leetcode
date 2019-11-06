class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        char val;
        vector<Node*> next;
        Node(){next = vector<Node*>();};
        Node(char c){val = c; next = vector<Node*>();};
    };
    Node *root;
    Trie() {
        root = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word == "")  return;
        if(root==NULL)  root = new Node();
        Node* p = root;
        for(auto c:word){
            bool fg = false;
            for(auto it:p->next){
                if(it){
                    if(it->val==c){
                        p=it;
                        fg = true;
                        break;
                    }
                }
            }
            if(fg)  continue;
            Node *temp = new Node(c);
            p->next.push_back(temp);
            p=temp;
        }
        p->next.push_back(NULL);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(root==NULL)  return false;
        Node *p = root;
        for(auto c:word){
            bool fg = false;
            for(auto it:p->next){
                if(it){
                    if(c==it->val){
                        p=it;
                        fg=true;
                        break;
                    }
                }
            }
            if(!fg) return false;
        }
        for(auto it:p->next){
            if(it==NULL)
                return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(root==NULL)  return false;
        Node *p = root;
        for(auto c:prefix){
            bool fg = false;
            for(auto it:p->next){
                if(it){
                    if(c==it->val){
                        p=it;
                        fg=true;
                        break;
                    }
                }
            }
            if(!fg) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
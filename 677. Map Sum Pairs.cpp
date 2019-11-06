class MapSum {
public:
    /** Initialize your data structure here. */
    struct Node{
        char cc;
        int value;
        vector<Node*> next;
        Node(){next = vector<Node*>();};
        Node(char c){cc = c; next = vector<Node*>();};
    };
    Node *root;
    MapSum() {
        root = NULL;
    }
    void insert(string key, int val) {
        if(key == "")  return;
        if(root==NULL)  root = new Node();
        Node* p = root;
        bool fg = false;
        for(auto c:key){
            fg = false;
            for(auto it:p->next){
                if(it){
                    if(it->cc==c){
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
        fg = false;
        for(auto it:p->next){
            if(it==NULL)    fg = true;
        }
        p->value=val;
        if(!fg)
            p->next.push_back(NULL);
    }
    
    int doSum(Node* p){
        int sum = 0;
        for(auto it:p->next){
            if(it){
                sum+=doSum(it);
            }
            else{
                sum+=p->value;
            }
        }
        return sum;
    }
    
    int sum(string prefix) {
        if(root==NULL)  return false;
        int sum = 0;
        Node *p = root;
        for(auto c:prefix){
            bool fg = false;
            for(auto it:p->next){
                if(it){
                    if(c==it->cc){
                        p=it;
                        fg=true;
                        break;
                    }
                }
            }
            if(!fg) return 0;
        }
        sum = doSum(p);
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
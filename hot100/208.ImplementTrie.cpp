class Trie {
public:
    struct Node {
        int isWord;
        vector<Node*> next;
        Node(): isWord(false), next(26, nullptr) {}
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* ptr = root;
        for(auto c : word){
            int index = c - 'a';
            if(ptr->next[index] == nullptr){
                ptr->next[index] = new Node();
            }
            ptr = ptr->next[index];
        }
        ptr->isWord = true;
    }
    
    bool search(string word) {
        Node* ptr = root;
        for(auto c : word){
            int index = c - 'a';
            if(ptr->next[index] == nullptr){
                return false;
            }
            ptr = ptr->next[index];
        }
        return ptr->isWord == true;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;
        for(auto c : prefix){
            int index = c - 'a';
            if(ptr->next[index] == nullptr){
                return false;
            }
            ptr = ptr->next[index];
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

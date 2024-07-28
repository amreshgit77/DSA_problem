
class TrieNode {
public:
    int data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
            isTerminal = false;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }
    /** Inserts a word into the trie. */
    void insertUtils(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        // alphabet is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtils(child, word.substr(1));
    }

    void insert(string word) { insertUtils(root, word); }
    /** Returns if the word is in the trie. */
    bool searchUtils(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            return false;
        }
        return searchUtils(child, word.substr(1));
    }

    bool search(string word) { return searchUtils(root, word); }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool prefixUtils(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // absent
            return false;
        }
        return prefixUtils(child, word.substr(1));
    }
    bool startsWith(string prefix) { return prefixUtils(root, prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
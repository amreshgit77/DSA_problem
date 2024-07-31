class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() { 
        root = new TrieNode('\0'); 
    }
    
    void insertUtils(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtils(child, word.substr(1));
    }

    void insert(string word) {
        insertUtils(root, word);
    }

    void printSuggestion(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        for (char i = 'a'; i <= 'z'; i++) {
            TrieNode* next = curr->children[i - 'a'];
            if (next != NULL) {
                printSuggestion(next, temp, prefix + i);
            }
        }
    }

    vector<vector<string>> displaySuggestion(string& str) {
        vector<vector<string>> ans;
        TrieNode* prev = root;
        string prefix = "";

        for (int i = 0; i < str.size(); i++) {
            char lastCh = str[i];
            prefix.push_back(lastCh);
            TrieNode* curr = prev->children[lastCh - 'a'];
            
            if (curr == NULL) {
                break;
            }

            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            ans.push_back(temp);
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie t;
    for (int i = 0; i < contactList.size(); i++) {
        t.insert(contactList[i]);
    }
    return t.displaySuggestion(queryStr);
}
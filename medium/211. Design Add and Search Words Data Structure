struct TrieNode{   
        TrieNode* next[26];
        bool Is_End_of_Key = false;
        TrieNode():Is_End_of_Key(false){
            memset(next, NULL, sizeof(next));
        }
        
};

class WordDictionary {
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* tmp = root;
        for(int i=0; i<word.size(); i++){

            char ch = word[i];
            if(!tmp->next[ch-'a']){
                tmp->next[ch-'a'] = new TrieNode();
            }
            tmp = tmp->next[ch-'a'];
            
        }
        tmp->Is_End_of_Key=true;
    }
    
    bool search(string word) {
        return helper(word, root);
            
    }
private:
    TrieNode* root;
    bool helper(string word, TrieNode* node){
        for(int i=0; i<word.size(); i++){
            if(word[i]!='.'){
                if(!node->next[word[i]-'a']){ 
                    return false;
                }
                node = node->next[word[i]-'a'];
            }else{
                int j = 0;
                bool found = false;
                for(;j<26; j++){
                    if(node->next[j]){
                        found = helper(word.substr(i+1),node->next[j]);
                        if(found) return true;
                    }
                }
                return false;
            }
        }
        return node->Is_End_of_Key;
    }
};

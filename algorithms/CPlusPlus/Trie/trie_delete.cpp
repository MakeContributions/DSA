#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9;
#define inf2 2e18;



struct custom_hash {
   static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
   size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};



struct TrieNode{ TrieNode* child[26]; bool isEnd;
    TrieNode(){ isEnd = false; for(int i = 0; i<26; i++){ child[i] = NULL; } }
};
struct TrieNode* rootTrie;
void addTrie(string& s){ TrieNode* curr = rootTrie; for(int i = 0; i<s.length(); i++){ int n = s[i] - 'a';if(curr->child[n] == NULL){curr->child[n] = new TrieNode();} curr = curr->child[n]; } curr->isEnd = true; }
bool searchTrie(string& s){TrieNode* curr = rootTrie;for(int i = 0; i<s.length(); i++){int n = s[i] - 'a';if(!curr->child[n]) return false;curr = curr->child[n];}return curr->isEnd;}
bool startsWithTrie(string s) {int n = s.length();TrieNode* curr = rootTrie;for(int i  =0 ; i<n; i++){int k = s[i] - 'a';if(curr->child[k] == NULL) return false;curr = curr->child[k];}return true;}
bool isEmpty(TrieNode* rootTrie){ for (int i = 0; i < ALPHABET_SIZE; i++){if(rootTrie->child[i])return false;}return true;}
void remove(TrieNode* rootTrie, string key, int depth = 0){if (!rootTrie)return NULL;if (depth == key.size()) {if (rootTrie->isEnd)rootTrie->isEnd = false;if (isEmpty(rootTrie)) {delete (rootTrie);rootTrie = NULL;}return rootTrie;}int index = key[depth] - 'a';rootTrie->child[index] = remove(rootTrie->child[index], key, depth + 1);if (isEmpty(rootTrie) && rootTrie->isEnd == false) {delete (rootTrie);rootTrie = NULL;}return rootTrie;}


int main(){
//Jai Shree Ram
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    for (int i = 0; i < n; i++)
        insert(rootTrie, keys[i]);
 
    search(rootTrie, "the") ? cout << "Yes\n" : cout << "No\n";
    search(rootTrie, "these") ? cout << "Yes\n" : cout << "No\n";
 
    remove(rootTrie, "heroplane");
    search(rootTrie, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
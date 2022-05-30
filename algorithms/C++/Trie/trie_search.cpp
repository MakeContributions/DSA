

/*
Trie is ds implementation of tree with one root and further 26 children at each layer and specifying if 
it is end of tree. Better then hashmap in cases where we need to find words with same prefix,collisions 
etc and used for word search spell check.

*/

#include <bits/stdc++.h>

using namespace std;

struct TrieNode *root;
struct TrieNode
{

    struct TrieNode *children[26];

    bool isEnd;
};

struct TrieNode *getNode()
{

    struct TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;
    for (int i = 0; i < 26; i++)
    {

        pNode->children[i] = NULL;
    }

    return pNode;
}
class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {

        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {

        struct TrieNode *pcrawl = root;
        for (int i = 0; i < word.length(); i++)
        {

            if (!pcrawl->children[word[i] - 'a'])
                pcrawl->children[word[i] - 'a'] = getNode();

            pcrawl = pcrawl->children[word[i] - 'a'];
        }

        pcrawl->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        struct TrieNode *pcrawl = root;
        for (int i = 0; i < word.length(); i++)
        {

            if (!pcrawl->children[word[i] - 'a'])
                return false;

            pcrawl = pcrawl->children[word[i] - 'a'];
        }

        return pcrawl->isEnd;
    }
};

int main()
{

    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their", "where", "when"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Trie t;
    t.root = getNode();
    // Construct trie
    for (int i = 0; i < n; i++)
    {
        t.insert(keys[i]);
    }

    // Search for different keys
    cout << "'them' present in keys:";
    t.search("them") ? cout << "Yes\n" : cout << "No\n";
    cout << "'when' present in keys:";
    t.search("when") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}

/*

Time Complexity-
O(key_length)
Space Complexity-
O(ALPHABET_SIZE * key_length * N), N is no. of keys in trie

SAMPLE INPUT-OUTPUT

'them' present in keys:No
'when' present in keys:Yes


*/
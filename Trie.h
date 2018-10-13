#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#define AlphaSize 26

struct Trie{
    int EOW;
    Trie *next[AlphaSize];
};

Trie* createTrieNode();
int InsertInTrie(Trie* root,char* person);
int searchPerson(Trie* root,char* person);
bool deleteInTrie(Trie* root,char* person);
void destroyTrie(Trie* root);
char* traverseTrie(Trie* root,int data);
#endif // TRIE_H_INCLUDED

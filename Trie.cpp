#include <stdlib.h>
#include <stdbool.h>
#include "Trie.h"

Trie* createTrieNode(){
    Trie* t=(Trie*)malloc(sizeof(Trie));
    t->EOW=-1;
    for(int i=0;i<AlphaSize;i++){
        t->next[i]=NULL;
    }
    return t;
}
int InsertInTrie(Trie* root,char* person){
    static int num=0;
    for(int i=0;person[i]!='\0';i++){
        int index=person[i]-'a';
        if(root->next[index]==NULL){
            root->next[index]=createTrieNode();
        }
        root=root->next[index];
    }
    if(root->EOW!=-1)
        return root->EOW;
    root->EOW=num++;
    return root->EOW;
}

int searchPerson(Trie* root,char* person){
    for(int i=0;person[i]!='\0';i++){
        int index=person[i]-'a';
        if(root->next[index]==NULL){
            return -1;
        }
        root=root->next[index];
    }
    return root->EOW;
}

void destroyTrie(Trie* root){
    for(int i=0;i<AlphaSize;i++){
        if(root->next[i]!=NULL)
            destroyTrie(root->next[i]);
    }
    free(root);
}

bool isLeaf(Trie *root){
    for(int i=0;i<AlphaSize;i++){
        if(root->next[i]!=NULL)
            return false;
    }
    return true;
}

bool deleteInTrie(Trie* root,char* person){
    if(root==NULL)
        return false;
    int idx = person[0]-'a';
    if(person[0]=='\0'){
        if(isLeaf(root)){
            free(root);
            return true;
        }
        else{
            root->EOW=false;
            return false;
        }
    }
    if(deleteInTrie(root->next[idx],person+1)){
        root->next[idx]=NULL;
        if(isLeaf(root)&&!root->EOW){
            free(root);
            return true;
        }
    }

    return false;
 }

char str[30];
int idx=0;
char* traverseTrie(Trie* root,int data){
    Trie* temp=root;
    if(temp->EOW==data)
        return str;
    for(int i=0;i<AlphaSize;i++){
        if(temp->next[i]!=NULL)
        {
            str[idx++]='a'+i;
            str[idx]='\0';
            traverseTrie(temp->next[i],data);
        }
    }
    str[--idx]='\0';
}







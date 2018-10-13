#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph.h"
#include "LinkedList.h"
using namespace std;

Graph* creatGraph(int v){
    Graph* g=(Graph*)malloc(sizeof(Graph));
    g->nv=v;
    g->ne=0;
    g->adjlst=(Node**)malloc(v*sizeof(Node));
    for(int i=0;i<v;i++)
       g->adjlst[i]=NULL;
    return g;
}

Graph* AddFriendship(Graph* g, int u, int v){

    g->adjlst[u]=InsertInLinkedList(g->adjlst[u],v);
    g->adjlst[v]=InsertInLinkedList(g->adjlst[v],u);
    g->ne++;
    return g;
}

Graph* deleteInGraph(Graph* g, int u, int v){

    g->adjlst[u]=DeleteInLinkedList(g->adjlst[u],v);
    g->adjlst[v]=DeleteInLinkedList(g->adjlst[v],u);
    g->ne--;
    return g;
}

void listFriends(Graph* g, int u, Trie* root){
    printLinkedList(g->adjlst[u],root);
}

bool checkFriendship(Graph* g, int u, int v){
    return(searchInLinkedList(g->adjlst[u],v));
}

void findMutualFriends(Graph* g, int u, int v, Trie* root){
    PrintCommonNodes(g->adjlst[u],g->adjlst[v],root);
}

int TotalFriends(Graph* g, int u){
    return(CountTotalNodes(g->adjlst[u]));
}

void destroyGraph(Graph* g){
    for(int i=0;i<g->nv;i++)
        g->adjlst[i]=destroyLinedList(g->adjlst[i]);
    free(g->adjlst);
    free(g);
}

void findPathBetween(Graph* g, int u, int v){

}















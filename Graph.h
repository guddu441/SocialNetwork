#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "LinkedList.h"
#include "Trie.h"
struct Graph{
    int nv;
    int ne;
    Node **adjlst;
};

Graph* creatGraph(int v);
Graph* AddFriendship(Graph* g, int u, int v);
Graph* deleteInGraph(Graph* g, int u, int v);
void listFriends(Graph* g, int u, Trie* root);
bool checkFriendship(Graph* g, int u, int v);
void findMutualFriends(Graph* g, int u, int v, Trie* root);
int TotalFriends(Graph* g, int u);
void destroyGraph(Graph* g);
void findPathBetween(Graph* g, int u, int v);
#endif // GRAPH_H_INCLUDED

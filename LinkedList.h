#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Trie.h"


struct Node{
    int data;
    Node *next;
};

Node* InsertInLinkedList(Node* head, int data);
Node* DeleteInLinkedList(Node* head, int data);
void printLinkedList(Node *head, Trie* root);
bool searchInLinkedList(Node* head, int data);
void PrintCommonNodes(Node* head1, Node* head2, Trie* root);
int CountTotalNodes(Node* head);
Node* destroyLinedList(Node* head);
#endif // LINKEDLIST_H_INCLUDED

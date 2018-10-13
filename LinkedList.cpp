#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"
using namespace std;

Node* createNewNode(){
    Node* a=(Node*) malloc(sizeof(Node));
    a->data=0;
    a->next=NULL;
    return a;
}

Node* InsertInLinkedList(Node* head, int data){
    Node* t=createNewNode();
    t->data=data;
    t->next=head;
    return t;
}

Node* DeleteInLinkedList(Node* head, int data) {
    if(head==NULL)
        return NULL;
    Node* cur=head;
    Node* pre=NULL;
    while(cur!=NULL){
        if(pre==NULL && cur->data==data){
            pre=cur->next;
            free(cur);
            return pre;
        }
        else if(cur->data==data){
            pre->next=cur->next;
            free(cur);
            return head;
        }
        pre=cur;
        cur=cur->next;
    }
    return head;
}

void printLinkedList(Node *head, Trie* root){
    Node *cur=head;
    while(cur!=NULL){
        cout<<traverseTrie(root,cur->data)<<" ";
        cur=cur->next;
    }
}

bool searchInLinkedList(Node* head, int data){
    if(head==NULL)
        return false;
    Node* cur=head;
    while(cur!=NULL){
        if(cur->data==data)
            return true;
        cur=cur->next;
    }
    return false;
}

void PrintCommonNodes(Node* head1, Node* head2, Trie* root){
    while(head1!=NULL){
        while(head2!=NULL){
            if(head1->data==head2->data){
                cout<<traverseTrie(root,cur->data)<<" ";
                break;;
            }
            head2=head2->next;
        }
        head1=head1->next;
    }
}

int CountTotalNodes(Node* head){
    int cnt=0;
    Node* cur=head;
    while(cur!=NULL){
        cnt++;
        cur=cur->next;
    }
    return cnt;
}

Node* destroyLinedList(Node* head){
    Node* next;
    while(head!=NULL){
        next=head->next;
        free(head);
        head=next;
    }
    return head;
}

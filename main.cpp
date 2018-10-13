#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include "Trie.h"
#include "Graph.h"
using namespace std;


int Menu(){
    cout<<"\nMENU\n";
    cout<<"1. Add Friendship\n";
    cout<<"2. List Friends\n";
    cout<<"3. Mutual Friends\n";
    cout<<"4. Path Between Two\n";
    cout<<"5. Unfriend\n";
    cout<<"6. Delete A person\n";
    cout<<"7. Statistics\n";
    cout<<"8. RelationShip Status\n";
    cout<<"9. Exit\n\n";

    cout<<"Enter your Choice: ";
    int option;
    cin>>option;
    return option;
}

int main(){
    char person1[30],person2[30];
    Trie* root=createTrieNode();
    Graph* g=creatGraph(1000);
    FILE *fin=fopen("friendship.txt","r");
    if(fin==NULL){
        cerr<<"No Such File Found!!";
        return -1;
    }
    while(!feof(fin)){
        fscanf(fin,"%s %s\n",person1,person2);
        int i=InsertInTrie(root,person1);
        int j=InsertInTrie(root,person2);
        g=AddFriendship(g,i,j);
    }
    fclose(fin);
    while(true)
    {
        int choice = Menu();
        switch(choice)
        {
            case 1:{
                    char person1[30],person2[30];
                    cin>>person1;
                    cin>>person2;
                    int i=InsertInTrie(root,person1);
                    int j=InsertInTrie(root,person2);
                    if(checkFriendship(g,i,j)){
                        cout<<"\nAlready Friends!\n";
                    }
                    else{
                        g=AddFriendship(g,i,j);
                        cout<<"\nFriendship-Added-Sucessfully!\n";
                    }
                    break;
                }

            case 2:{
                    char person[30];
                    cin>>person;
                    int u=searchPerson(root,person);
                    if(u==-1){
                        cout<<"No such Person!!";
                    }
                    else{
                        cout<<person<<" : ";
                        listFriends(g,u,root);
                    }
                    break;
            }

            case 3:{
                    char person1[30],person2[30];
                    cin>>person1;
                    int u=searchPerson(root,person1);
                    cin>>person2;
                    int v=searchPerson(root,person2);
                    if(u==-1 || v==-1){
                        cout<<"No such Person!!";
                    }
                    else{
                        cout<<"Mutual Friends of "<<person1<<" & "<<person2<<" are : ";
                        findMutualFriends(g,u,v,root);
                    }
                    break;
            }

            case 4:{
                    char person1[30],person2[30];
                    cin>>person1;
                    int u=searchPerson(root,person1);
                    cin>>person2;
                    int v=searchPerson(root,person2);
                    if(u==-1 || v==-1){
                        cout<<"No such Person!!";
                    }
                    else{

                        findPathBetween(g,u,v);
                    }
                    break;
            }

            case 5:{
                    char person1[30],person2[30];
                    cin>>person1;
                    int u=searchPerson(root,person1);
                    cin>>person2;
                    int v=searchPerson(root,person2);
                    if(u==-1 || v==-1){
                        cout<<"No such Person!!";
                    }
                    else{
                        g=deleteInGraph(g,u,v);
                        cout<<"Successfully Delete!!";
                    }
                    break;
            }

            case 6:{
                    char person[30];
                    cin>>person;
                    if(deleteInTrie(root,person)){
                        cout<<"Delete successful";
                    }
                    else{
                        cout<<"No such Person!!";
                    }
                    break;
            }

            case 7:{
                    char person[30];
                    cin>>person;
                    int u=searchPerson(root,person);
                    if(u==-1){
                        cout<<"No such Person!!";
                    }
                    else{
                        cout<<"Total friends of "<<person<<" are : "<<TotalFriends(g,u);
                    }
                    break;
            }

            case 8:{
                    char person1[30],person2[30];
                    cin>>person1;
                    int u=searchPerson(root,person1);
                    cin>>person2;
                    int v=searchPerson(root,person2);
                    if(u==-1 || v==-1){
                        cout<<"No such Person!!";
                    }
                    else{
                        if(checkFriendship(g,u,v))
                            cout<<"Friends!!";
                        else
                            cout<<"Not Friends!!";
                    }
            }

            case 9:{
                    destroyGraph(g);
                    destroyTrie(root);
                    return 0; // exit(0);
            }

            default:
                cout<<"Wrong Choice!!!";
        }
    }
    return -1;
}

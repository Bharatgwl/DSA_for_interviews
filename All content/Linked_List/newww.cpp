#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertatfirst(Node* &head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        return ;
    }
    newnode->next=head;
    head=newnode;
}

void insertatend(Node* &head,int data){
    Node*newnode=new Node(data);
    Node*ptr=head;
    while(ptr->next!=NULL){   //why we dont use here only ptr!=NULL;
        ptr=ptr->next;
    }
    ptr->next=newnode;
}


void insertatposition(Node* &head,int position,int data){
    if(position==1){
        insertatfirst(head,data);
        return ;
    }
    Node *ptr=head;
    int count=1;
    while(count<position-1){
        ptr=ptr->next;
        count++;
    }
    if(ptr->next==NULL){
        insertatend(head,data);
        return ;
    }
     Node* newnode=new Node(data);
    newnode->next=ptr->next;
    ptr->next=newnode; 
}

void print(Node* &head){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
         ptr=ptr->next;
    }

}

int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    
    insertatfirst(head,5);
    insertatfirst(head,6);
    insertatend(head,11);
    insertatend(head,12);
    insertatposition(head,3,500);
    
    print(head);
    
    return 0;
}
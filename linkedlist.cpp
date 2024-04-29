#include <iostream>

using namespace std;

  struct node{
   int data;
   node*next;

  node*head=NULL;
  void insertatend(int val){
  node*newnode=new node;
  newnode->next=NULL;
  newnode->data=val;
  if (head==NULL){
    head=newnode;
  }
  else{
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
  }
  }
 void remove(int val){
 if (head==NULL)
    return;
 node*temp=head;
 node*prev=head;
 if (temp->data==val){
    head=temp->next;
    delete temp;
    return;
 }
 while(temp!=NULL&&temp->data!=val){
   prev=temp;
   temp=temp->next;
 }
 if (temp==NULL)
    return;
 else {
    prev->next=temp->next;
    delete temp;
 }
 }
 void display(){
 node*temp=head;
 while(temp!=NULL){
    cout<<"the data is :"<<temp->data<<endl;
    temp=temp->next;
 }

 }
void insertatpos(int val,int pos){
 node*newnode=new node;
 newnode->data=val;
 newnode->next=NULL;
 if (pos==0){
    newnode->next=head;
    head=newnode;
 }
 node*temp=head;
 for (int i=0;i<pos-1;i++){
    if (temp->next==NULL)
        break;
   temp=temp->next;

 }
newnode->next=temp->next;
temp->next=newnode;

}
void deleteatpos(int pos ){
 node*newnode=new node;
 newnode->next=NULL;
 node*temp=head;
  if (head==NULL)
     return;
 if (pos==0){
    temp=head;
    head=head->next;
    }
else {
    for (int i=0;i<pos-1;i++){
        temp=temp->next;
      }
    if (temp==NULL){
        return;
    }
    node*temp2=temp->next;
    temp->next=temp->next->next;
    delete temp2;
}

}
void reverselist(){
 if (head==NULL)
     return;
  node*current=head;
  node*nextlist=NULL;
  node*prev=NULL;
  while(current!=NULL){
    nextlist=current->next;
    current->next=prev;
    prev=current;
    current=nextlist;
  }
  head=prev;

}
  };




int main()
{
  node n;
  n.insertatend(5);
  n.insertatend(7);
  n.insertatend(5);
  n.insertatend(3);
  n.insertatend(1);
   n.insertatend(5);
   n.display();
   cout<<"============insertion at the end is completed==============="<<endl;
   n.remove(3);
   n.display();
   cout<<"============remove is completed==============="<<endl;

   n.insertatpos(5,2);
   n.display();
    cout<<"===========insertion at position is completed================"<<endl;

   n.deleteatpos(2);
   n.display();
   cout<<"===========deletion at position is completed================"<<endl;

   n.reverselist();
   n.display();
   cout<<"=========== reverstion at position is completed================"<<endl;
    return 0;
}

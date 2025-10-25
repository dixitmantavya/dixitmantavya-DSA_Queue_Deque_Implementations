#include <iostream>
using namespace std;


class Node {

public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class Queue{

    Node* head;
    Node* tail;
    int size;

     public:
     Queue(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
     }
    
     void enqueue(int data){
        Node* newNode = new  Node(data);
        if(this->head==NULL){
            //LL empty
            this->head=this->tail=newNode;
        }
        else{
            this->tail->next=newNode;
            this->tail=newNode; 
        }
        this->size++;
     }
     void dequeue(){
        if(this->head==NULL){
            //LL empty
            return;
        }
        else{
            Node* temp1=this->head;
            Node* temp2=this->head->next;
            this->head=temp2;
            if(head==NULL) this->tail=NULL;
            temp1->next=NULL;
            delete temp1;
        }
        this->size--;
     }
     int getSize(){
        return this->size;
     }
     bool isempty(){
        return this->head==NULL;
     }
    
    int front(){
        if(this->head==NULL) return -1;
        return this->head->data;
    }
    
};

int main(){
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    while(!q.isempty()){
        cout<<q.front()<< " ";
        q.dequeue();
    }
    return 0;
}
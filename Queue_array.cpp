#include <iostream>
#include <vector>
using namespace std;


class Queue{
    int f;
    int b;
    vector<int> v;
public:
    Queue(){
        this->b=-1;
        this->f=-1;
    }

    void enqueue(int val){
        v.push_back(val);
        if(f == -1) f = 0;
        b++;
        
    }

    void dequeue(){
        if(f == -1) return;
        if(f == b){
            f = -1;
            b = -1;
        }   
        else{
            f++;
        }
    }

    int front(){
        if(f == -1){
            return -1;
        }
        else{
            return v[f];
        }
    }

    bool isempty(){
        return f == -1;
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
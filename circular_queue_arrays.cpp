#include <iostream>
#include <vector>
using namespace std;

class Queue{
    int f;      // front index
    int b;      // back index
    vector<int> v; // storage vector
    int cs;     // current size
    int ts;     // total size
public:
    Queue(int n){       // constructor
        v.resize(n);
        ts = n;
        b = n-1;
        f = 0;
        cs = 0;
    }

    void enqueue(int val){      // add element to queue
        if(isfull()) return;
        b = (b + 1) % ts;
        v[b] = val;
        cs++;
    }

    void dequeue(){             // remove element from queue
        if(isempty()) return;
        f = (f + 1) % ts;
        cs--;
    }

    int front(){                // get front element
        if(isempty()) return -1;
        return v[f];
    }

    bool isempty(){             // check if queue is empty
        return cs == 0;
    }

    bool isfull(){              // check if queue is full
        return cs == ts;
    }
};

int main(){
    Queue q(3);
    q.enqueue(20); q.enqueue(30); q.enqueue(40);

    while(!q.isempty()){        // print and dequeue all elements
        cout << q.front() << " ";
        q.dequeue();
    }
    
    return 0;
}

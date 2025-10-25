#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> st;   // single stack used for queue operations
public:
    Queue(){}

    void push(int x){ // enqueue: push directly onto stack
        st.push(x);
    }

    void pop(){       // dequeue: remove bottom element
        stack<int> temp;
        if(st.empty()) return;

        // move all but last element to temp
        while(st.size() > 1){
            temp.push(st.top());
            st.pop(); 
        }

        st.pop(); // remove the front element

        // move elements back to original stack
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }

    bool empty(){     // check if queue is empty
        return st.empty();
    }

    int front(){      // get front element without removing
        stack<int> temp;
        if(st.empty()) return -1;

        while(st.size() > 1){   // move all but last to temp
            temp.push(st.top());
            st.pop(); 
        }

        int result = st.top();  // front element

        while(!temp.empty()){   // restore stack
            st.push(temp.top());
            temp.pop();
        }

        return result;
    }
};

int main(){
    Queue q;
    q.push(20); q.push(30); q.push(40);

    while(!q.empty()){   // print and dequeue all elements
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

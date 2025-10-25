#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30); q.push(40); // initialize queue

    stack<int> s;

    while(!q.empty()) {    // move queue elements to stack
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {    // move elements back to queue (reversed)
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()) {    // print reversed queue
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

/* Sliding Window Maximum*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> max_window(vector<int> x, int k) {
    deque<int> dq;
    vector<int> r;
    int n = x.size();

    // process first k elements
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && x[dq.back()] < x[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // first window maximum
    r.push_back(x[dq.front()]);

    // process rest of the elements
    for(int i = k; i < n; i++) {
        // remove indices outside the current window
        if(dq.front() == i - k) dq.pop_front();

        // remove smaller elements from back
        while(!dq.empty() && x[dq.back()] < x[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // current window maximum
        r.push_back(x[dq.front()]);
    }

    return r;
}

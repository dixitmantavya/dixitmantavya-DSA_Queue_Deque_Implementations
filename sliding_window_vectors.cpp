#include <iostream>
#include <vector>
using namespace std;

// Brute-force sliding window maximum
vector<int> maxsliding(vector<int> x, int k){
    vector<int> r;
    int n = x.size();

    for (int i = 0; i <= n - k; i++){   // iterate over all windows
        int maxval = x[i];
        for(int j = i; j < i + k; j++){ // find max in current window
            if(x[j] > maxval){
                maxval = x[j];
            }
        }
        r.push_back(maxval);            // store max of this window
    }
    return r;
}

int main(){
    vector<int> arr = {2, 1, 3, 4, 6, 3, 8, 9, 10, 12, 56};
    int k = 4;

    vector<int> result = maxsliding(arr, k);

    cout << "Sliding window maximums: ";
    for (int val : result) {            // print results
        cout << val << " ";
    }       
    cout << endl;

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &input){
    stack<int> temp,result;
    while(! input.empty()){
        int curr= input.top();
        input.pop();
        temp.push(curr);
    }
    while(! temp.empty()){
        int curr= temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;

}

void InsertatAnyIndex(int x, int val, stack<int> &input) {
    int size = input.size();

    if (x < 0 || x > size) {
        cout << "Invalid index\n";
        return;
    }

    stack<int> temp;

    while (size != x) {
        temp.push(input.top());
        input.pop();
        size--;
    }

    input.push(val);

    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}
void insertatBottom(stack<int> &st , int x){
    stack<int> temp;
    while(! st.empty()){
        int curr= st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);
    while(! temp.empty()){
        int curr= temp.top();
        temp.pop();
        st.push(curr);
    }


}

void reverse(stack<int> &st){
    stack<int> temp;
    while(! st.empty()){
        int curr= st.top();
        st.pop();
        temp.push(curr);
    }
    while(! temp.empty() ){
        int curr=temp.top();
        temp.pop();
        insertatBottom(st,curr);
    }
}

int main(){


    return 0;
}
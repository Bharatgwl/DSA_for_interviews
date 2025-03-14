#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s="palindrome";
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        st.push(ch);

    }
    for(int i=0; i<s.length(); i++){
        cout<<st.top();
        st.pop();
    }
}
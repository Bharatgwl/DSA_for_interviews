#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;
int minWindow(string s, string t) {
    unordered_map<char,int>mp;
    for(int i=0;i<t.length();i++){
        mp[t[i]]++;
    }
    int count=mp.size();
    int i=0,j=0;
    int ans=INT_MAX;
    while(j<s.length()){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
        }
        if(count==0){
            ans=min(ans,j-i+1);
            while(count==0){
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    if(ans==INT_MAX){
        return 0;
    }
    return ans;
}
int main(){
    // string s="TOTMTAPTAT";
    // string t="TTA";
    string s="timetopractice";
    string t="toc";
    cout<<minWindow(s,t);
}
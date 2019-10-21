#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool *store;

bool isPali(string &s){
	int n = s.length();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-1-i])
			return false;
	}
	return true;
}

void part(vector<vector<string> > &ans, vector<string> &curr, string &s, int &index){
	if(index==s.length()-1){
		ans.push_back(curr);
		return;
	}
	int n = s.length();
	for(int i=index+1;i<n;i++){
		string str = s.substr(index+1,i-index);
		// cout<<str<<endl;
		if(!store[(index+1)*n+i]){
			store[(index+1)*n+i] = true;
			if(isPali(str)){
				store[i*n+index+1] = true;
				curr.push_back(str);
				part(ans, curr, s, i);
				curr.pop_back();
			}
			else{
				store[i*n+index+1] = false;
			}
		}
		else{
			if(store[i*n+index+1]){
				curr.push_back(str);
				part(ans, curr, s, i);
				curr.pop_back();
			}
		}
	}
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > ans;
    int n = s.length();
    if(n==0)
    	return ans;
    store = new bool[n*n];
    for(int i=0;i<n*n;i++)
    	store[i]=false;
    for(int i=0;i<n;i++)
    	store[i*n+i]=true;
    vector<string> temp;
    int index = -1;
    part(ans, temp, s, index);
    return ans;
}

int main(){
	string s = "abba";
	vector<vector<string> > ans = partition(s);
	for(auto i:ans){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
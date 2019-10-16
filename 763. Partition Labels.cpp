#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static bool mysort(const vector<int> &t1, const vector<int> &t2){
	return t1[0]<t2[0];
}

vector<int> partitionLabels(string S) {
    vector<vector<int> > mp;
    int a[2] = {INT_MAX, -1};
    vector<int> temp(a, a+2);
    for(int i=0;i<26;i++){
    	mp.push_back(temp);
    }
    for(int i=0;i<S.length();i++){
    	if(i<mp[S[i]-'a'][0]){
    		mp[S[i]-'a'][0]=i;
    	}
    	if(i>mp[S[i]-'a'][1]){
    		mp[S[i]-'a'][1]=i;
    	}
    }
    sort(mp.begin(),mp.end(),mysort);
    while(mp[mp.size()-1][1]==-1)
    	mp.pop_back();
    int right=mp[0][1];
    int loc = mp[0][0];
    vector<int> ans;
    for(int i=1;i<mp.size();i++){
    	if(mp[i][0]>right){
    		ans.push_back(right-loc+1);
    		loc = mp[i][0];
    	}
    	if(mp[i][1]>right)
    		right = mp[i][1];
    }
    if(S.size()-1>loc);
    ans.push_back(S.size()-loc);
    return ans;
}

int main(){
	string s = "ababcbacadefegdehijhklij";
	vector<int> tp = partitionLabels(s);
	for(int i=0;i<tp.size();i++)
		cout<<tp[i]<<" ";
	return 0;
}
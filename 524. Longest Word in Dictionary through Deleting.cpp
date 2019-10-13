#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool mysort(const string a, const string b){
	if(a.length()!=b.length())
		return a.length()>b.length();
	else{
		for(int i=0;i<a.length();i++){
			if(a[i]<b[i])
				return true;
			if(a[i]>b[i])
				return false;
		}
	}
	return true;
}

bool ifSubStr(string sub, string ori){
	int pori = 0;
	for(int i=0;i<sub.length();i++){
		while(sub[i] != ori[pori++]){
			if(pori >= ori.length())
				return false;
		}
	}
	return true;
}

string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), mysort);
    for(int i=0; i<d.size(); i++){
    	if(ifSubStr(d[i], s))
    		return d[i];
    }
    return "";
}

int main(){
	string s = "bab";
	string dd[4] = {"ba","ab","a","b"};
	vector<string> d(dd, dd+2);
	cout<<findLongestWord(s, d);
	return 0;
}
#include <iostream>
#include <string>
#include <map>

using namespace std;

string frequencySort(string s) {
    map<char, int> charmap;
    map<char, int>::iterator iter;
    string* dic = new string[s.length()+1];
    for(int i=0;i<s.length();i++){
    	dic[i] = "";
    	iter = charmap.find(s[i]);
    	if(iter == charmap.end())
    		charmap[s[i]]=1;
    	else
    		iter->second++;
    }

    for(iter=charmap.begin();iter!=charmap.end();iter++){
    	dic[iter->second] += iter->first;
    }
    int loc = 0;
    for(int i=s.length();i>=0;i--){
    	if(dic[i]!=""){
    		for(int j=0;j<dic[i].length();j++){
    			for(int k=0;k<i;k++){
    				s[loc++] = dic[i][j];
    			}
    		}
    	}
    }
    return s;
}

int main(){
	string s = "Ad";
	cout<<frequencySort(s)<<endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool ifTrans(string s1, string s2){
	int cnt = 0;
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i])
			cnt++;
	}
	return cnt==1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> qe;
    qe.push(beginWord);
    int len = 0;
    while(!qe.empty()){
    	int size = qe.size();
    	len++;
    	while(size-->0){
	    	string tp = qe.front();
	    	qe.pop();
	    	for(int i=wordList.size()-1;i>=0;i--){
	    		if(ifTrans(wordList[i], tp)){
	    			if(wordList[i]==endWord)
	    				return len+1;
	    			qe.push(wordList[i]);
	    			wordList.erase(wordList.begin()+i);
	    		}
	    	}
	    }
    }
    return 0;
}

int main(){
	string ss[20] = {"hot","dot","dog","lot","log","cog"};
	vector<string> wl(ss,ss+6);
	string bw = "hit";
	string ew = "cag";
	cout<<ladderLength(bw,ew,wl)<<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string str;

void countIP(vector<string> &ans, string curr, int num){
	if(num>4)
		return;
	if(curr.length()==str.length()+4){
		ans.push_back(curr.substr(0,curr.length()-1));
		return;
	}
	for(int i=0;i<str.length()+num-curr.length();i++){
		string temp = str.substr(curr.length()-num, i+1);
		if(temp.length()>1 && temp[0]!='0' || temp.length()==1){
			if(temp.length()<4){
				if(stoi(temp)<=255){
					countIP(ans, curr+temp+'.', num+1);
				}
			}
		}

	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	if(s.length()<4)
		return ans;
    str = s;
    countIP(ans, "", 0);
    return ans;
}

int main(){
	vector<string> ans;
	ans = restoreIpAddresses("0000");
	for(auto i:ans)
		cout<<i<<endl;
	return 0;
}
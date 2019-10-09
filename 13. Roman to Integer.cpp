#include<iostream>
#include<string>
#include<map>
#include<stdlib.h>

using namespace std;

map<char, int> data;

// int data[7] = {1, 5, 10, 50, 100, 500, 1000};
// char chardata[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int romanToInt(string s) {
	int loc = 0;
	int num = s.length()-1;
	int ans = 0;
	while(loc <= num){
		char c = s[loc];
		int count = 1;
		loc++;
		while(loc<=num && s[loc]==c){
			loc++;
			count++;
		}
		if(loc<=num){
			if(data[s[loc]]==5*data[c]){
				ans += 4*data[c];
				loc++;
				continue;
			}
			else if(data[s[loc]]==10*data[c]){
				ans += 9*data[c];
				loc++;
				continue;
			}
		}
		ans += data[c]*count;
	}
	return ans;
}

int main(){
	data.insert(pair<char, int>('I', 1));
	data.insert(pair<char, int>('V', 5));
	data.insert(pair<char, int>('X', 10));
	data.insert(pair<char, int>('L', 50));
	data.insert(pair<char, int>('C', 100));
	data.insert(pair<char, int>('D', 500));
	data.insert(pair<char, int>('M', 1000));
	// map<char,int>::iterator iter = data.begin();
 //    for(;iter != data.end();iter++){
 //        cout<<iter->first<<' '<<iter->second<<endl;
 //    }
	string s = "";
	cout<<romanToInt(s)<<endl;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

bool isPal(string s, int left, int right){
	for(int i=left,j=right;i<j;i++,j--){
		if(s[i]!=s[j])
			return false;
	}
	return true;
}

bool validPalindrome(string s) {
    for(int i=0,j=s.length()-1;i<j;i++,j--){
    	if(s[i]!=s[j]){
    		if(isPal(s,i+1,j) || isPal(s,i,j-1))
    			return true;
    		else
    			return false;
    	}
    }
    return true;
}

int main(){
	string s = "abca";
	cout<<validPalindrome(s)<<endl;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

string decodeAtIndex(string S, int K) {
	long long count = 0;
    for(int i=0;i<S.length();i++){
    	if(S[i] >= 'a' && S[i] <= 'z'){
    		count++;
    	}
    	else{
    		count *= S[i]-'0';
    	}
    }
    for(int i=S.length()-1;i>=0;i--){
    	// K %= count;
    	if(S[i] >= 'a' && S[i] <= 'z'){
    		if(K%count == 0)
    			return (string)""+S[i];
    		else
    			count--;
    	}
    	else
    		count/=S[i]-'0';
    }
    return "";
}

int main(){
	string s = "ha22";
	cout<<decodeAtIndex(s, 5)<<endl;
	return 0;
}
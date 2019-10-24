#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string removeKdigits(string num, int k) {
    for(int i=0;i<k;i++){
    	int j=0;
    	int n=num.length();
    	while(j<n-1 && num[j]<=num[j+1]) j++;
    	num.erase(j,1);
    	if(num[0]=='0')
    		num.erase(0,1);
    	if(num.length()==0)
    		return "0";
    }
    return num;
}

int main(){
	cout<<removeKdigits("10", 2)<<endl;
	return 0;
}
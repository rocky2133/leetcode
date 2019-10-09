#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str) {
    int loc = 0;
    double ans = 0;
    bool mut = true;
	while(str[loc]==' ' && str[loc]!='\0'){
		loc++;
	}
	if(str[loc] == '-'){
		loc++;
		mut = false;
	}
	else if(str[loc] == '+'){
		loc++;
	}
	while(str[loc]>='0'&&str[loc]<='9'){
		ans *= 10;
		ans += (str[loc]-'0');
		loc++;
	}
	if(mut)
		return ans<INT_MAX?ans:INT_MAX;
	else
		return -ans>INT_MIN?-ans:INT_MIN;
}

int main(){
	string s = "-91283472332";
	cout<<myAtoi(s)<<endl;
	return 0;
}
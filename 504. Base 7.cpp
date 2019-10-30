#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

string convertToBase7(int num) {
    string s="";
    bool flag = 0;
    if(num<0){
    	num*=-1;
    	flag = 1;
    }
    if(num==0)
    	return "0";
    while(num>0){
    	s.insert(0,1,'0'+num%7);
    	num/=7;
    }
    if(flag)
    	s.insert(0,1,'-');
    return s;
}

int main(){
	cout<<convertToBase7(-14)<<endl;
	return 0;
}
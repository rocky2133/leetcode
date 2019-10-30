#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

string toHex(int num) {
	char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    string s = "";
    if(num==0)
    	return "0";
    unsigned int num1 = num;
    while(num1!=0){
    	s.insert(0,1,map[num1 & 0b1111]);
    	num1 >>= 4;
    }
    return s;
}

int main(){
	cout<<toHex(-10)<<endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

bool isPerfectSquare(int num) {
	int sub = 1;
	while(num>0){
		num-=sub;
		sub+=2;
	}
    return num==0;
}

int main(){
	cout<<isPerfectSquare(1)<<endl;
	return 0;
}
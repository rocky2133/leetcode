#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	if(x<0)
		return false;
	int ans = 0;
	int xs = x;
	while(xs>0){
		ans*=10;
		ans+=(xs%10);
		xs/=10;
	}
	if(ans == x)
		return true;
	else
		return false;
}

int main(){
	cout<<isPalindrome(1212121212);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size()-1;
    while(left<right){
    	int mid = left+(right-left)/2;
    	if(letters[mid]<=target)
    		left = mid+1;
    	else
    		right = mid;
    }
    if(letters[right]<=target)
    	right=0;
    return letters[right];
}

int main(){
	char c[20] = {'c','f','j'};
	vector<char> lt(c,c+3);
	cout<<nextGreatestLetter(lt,'k')<<endl;
	return 0;
}
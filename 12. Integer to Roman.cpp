#include<iostream>
#include<string>

using namespace std;

int data[7] = {1, 5, 10, 50, 100, 500, 1000};
char datachar[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

string intToRoman(int num) {
	string res = "";
	int nums = num;
	while(nums > 0){
		int max = 0;
		for(int i=6;i>=0;i--){
			if(nums>=data[i]){
				max = i;
				break;
			}
		}
		int count = nums/data[max];
		if(count == 4){
			int loc = res.length()-1;
			if(loc>=0 && (res[loc] == datachar[max+1])){
				res[loc] = datachar[max];
				res += datachar[max+2];
			}
			else{
				res += datachar[max];
				res += datachar[max+1];
			}
		}
		else{
			for(int i=0;i<count;i++){
				res += datachar[max];
			}
		}
		nums %= data[max];
	}
	return res;
}

int main(){
	cout<<intToRoman(1994)<<endl;
	return 0;
}
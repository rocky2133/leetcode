#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1;
    int p2 = n-1;
    int loc = m+n-1;
    while(p1>=0 && p2>=0){
    	nums1[loc--] = nums1[p1]>nums2[p2]?nums1[p1--]:nums2[p2--];
    }
    for(int i=p2;i>=0;i--)
		nums1[i] = nums2[i];
}

int main(){
	int a[20] = {0};
	int b[20] = {1};
	vector<int> n1(a,a+1);
	vector<int> n2(b,b+1);
	merge(n1,0,n2,1);
	for(int i=0;i<n1.size();i++)
		cout<<n1[i]<<endl;
	return 0;
}

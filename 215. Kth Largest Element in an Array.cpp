#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//heap
// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int, vector<int>, greater<int> > qe;
//     for(int i=0;i<nums.size();i++){
//     	qe.push(nums[i]);
//     	if(qe.size()>k)
//     		qe.pop();
//     }
//     return qe.top();
// }


//quick select
int quicksort(vector<int>& nums, int left, int right){
	int st = nums[left];
	while(left<right){
		while(left<right && nums[right]>=st) right--;
		nums[left] = nums[right];
		while(left<right && nums[left]<=st) left++;
		nums[right] = nums[left];
	}
	nums[left] = st;
	return left;
}

int findKthLargest(vector<int>& nums, int k) {
	k = nums.size() - k;
    int l = 0, h = nums.size() - 1;
    while (l < h) {
        int j = quicksort(nums, l, h);
        if (j == k) {
            break;
        } 
        else if (j < k) {
            l = j + 1;
        } 
        else {
            h = j - 1;
        }
    }
    return nums[k];
}

int main(){
	int a[20] = {3,2,3,1,2,4,5,5,6};
	vector<int> nums(a,a+9);
	cout<<findKthLargest(nums, 4)<<endl;
	return 0;
}
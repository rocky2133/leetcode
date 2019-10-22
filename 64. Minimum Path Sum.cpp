#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	if(grid.size()<1||grid[0].size()<1)
		return 0;
    int i=0;
    int j=0;
    for(i=1;i<grid.size();i++)
    	grid[i][0]+=grid[i-1][0];
    for(j=1;j<grid[0].size();j++)
    	grid[0][j]+=grid[0][j-1];
    for(i=1;i<grid.size();i++){
    	for(j=1;j<grid[0].size();j++){
    		grid[i][j]+=min(grid[i-1][j], grid[i][j-1]);
    	}
    }
    return grid[--i][--j];
}

int main(){
	vector<vector<int> > temp = {};
	cout<<minPathSum(temp);
	return 0;
}
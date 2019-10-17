#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int f1[4] = {1,0,-1,0};
int f2[4] = {0,1,0,-1};

int countArea(vector<vector<int> >& grid, int x, int y){
	if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y] == 0)
		return 0;
	int area = 1;
	grid[x][y] = 0;
	for(int i=0;i<4;i++)
		area+=countArea(grid, x+f1[i], y+f2[i]);
	return area;
}

int maxAreaOfIsland(vector<vector<int> >& grid) {
	int ans=0;
    for(int i=0;i<grid.size();i++){
    	for(int j=0;j<grid[0].size();j++){
    		if(grid[i][j]){
    			ans = max(ans,countArea(grid, i, j));
    		}
    	}
    }
    return ans;
}

int main(){

	return 0;
}
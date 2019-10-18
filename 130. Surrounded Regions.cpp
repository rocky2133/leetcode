#include <iostream>
#include <vector>

using namespace std;

int x;
int y;
int f1[4] = {1,-1,0,0};
int f2[4] = {0,0,1,-1};

void ctFlag(vector<vector<char> >& board, int *flag, int i, int j, bool flip){
	if(i>=0 && i<x && j>=0 && j<y && board[i][j] == 'O' && flag[i*y+j]){
		flag[i*y+j] = 0;
		if(flip)
			board[i][j] = 'X';
		for(int k=0;k<4;k++){
			ctFlag(board, flag, i+f1[k], j+f2[k], flip);
		}
	}
}

void solve(vector<vector<char> >& board) {
    x = board.size();
    if(x<=2)
    	return;
    y = board[0].size();
    if(y<=2)
    	return;
    int *flag = new int[x*y];
    for(int i=0;i<x*y;i++)
    	flag[i]=1;
    for(int i=0;i<x;i++){
		ctFlag(board, flag, i, 0, 0);
		ctFlag(board, flag, i, y-1, 0);
    }
    for(int i=0;i<y;i++){
		ctFlag(board, flag, 0, i, 0);
		ctFlag(board, flag, x-1, i, 0);
    }
    for(int i=1;i<x-1;i++){
    	for(int j=1;j<y-1;j++){
    		ctFlag(board, flag, i, j, 1);
    	}
    }
}

int main(){

	return 0;
}
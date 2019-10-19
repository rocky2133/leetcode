#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string wd;

int f1[4] = {1,-1,0,0};
int f2[4] = {0,0,1,-1};
int x;
int y;

bool search(vector<vector<char>>& board, bool *flag, string curr, int i, int j){
	if(i<0||i>=x||j<0||j>=y||flag[i*y+j]||board[i][j]!=wd[curr.length()])
		return false;
	if(curr.length()==wd.length()-1)
		return true;
	flag[i*y+j]=true;
	for(int k=0;k<4;k++){
		if(search(board, flag, curr+board[i][j], i+f1[k], j+f2[k]))
			return true;
	}
	flag[i*y+j]=false;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word.length()<1 || board.size()<1 || board[0].size()<1)
    	return false;
    wd=word;
    x = board.size();
    y = board[0].size();
    bool *flag = new bool[x*y];
    for(int i=0;i<x*y;i++)
    	flag[i]=false;
    for(int i=0;i<x;i++){
    	for(int j=0;j<y;j++){
    		if(search(board, flag, "", i, j))
    			return true;
    	}
    }
    return false;
}

int main(){
	vector<vector<char> >board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	cout<<exist(board, "ABCB")<<endl;
	return 0;
}
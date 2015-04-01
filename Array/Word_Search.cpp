/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or
vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


------------------------------

1-先扫描一遍board ，统计各个字符的长度保存在数组中；
2-在扫描word 看其中的字符是否存在 上面的数组中，
	若是，true；
	若否，false；

-----理解错了任何的词，而是垂直相连的或者水平相连的
63 / 83 test cases passed.
Status: Wrong Answer
Submitted: 9 hours, 25 minutes ago
Input:	["ab","cd"], "abcd"
Output:	true
Expected:	false

------------------------

*/

/* 自己理解错误的，写法   */
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) 
    {
        if (board.empty())
        	return false;
        int Sum_Arry[128] = {0};
        const size_t n = board.size(); //行数
        const size_t m = board.front().size(); //列数

        for(int first = 0 , end = n*m ,i = 0; first < end ; first++)
        {
        	int index = board[first/m][first%m] - '0';
        	Sum_Arry[index]++; //统计词出现的频率
        }
    
        for(int i = 0 ; word[i] != '\0' ; i++)
        {
        	int Tmp = word[i] - '0';
        	if (Sum_Arry[Tmp] == 0)
        		return false;
        	else
        		Sum_Arry[Tmp]--;
        }
     return true;
    }
};

/*  修正后的写法  */

class Solution {
    public:
         bool exist(vector<vector<char> > &board, string word) 
         {
            m = board.size(); //行数
            n = board.front().size(); //列数
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
                    if(isFound(board,word.c_str(),x,y))
                        return true;
                }
            return false;
        }
    private:
    	size_t m ;
    	size_t n ;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
            if(x<0 || y<0 || x>=m || y>=n || board[x][y] == '\0' || *w != board[x][y])
                return false;
            if(*(w+1) == '\0')
                return true;
            char t = board[x][y];
            board[x][y] = '\0'; //标记不可以访问
            if(isFound(board,w+1,x-1,y) || isFound(board,w+1,x+1,y) || isFound(board,w+1,x,y-1) || isFound(board,w+1,x,y+1)) 
                return true; //递归调用 上左右下 探索
            board[x][y] = t; //复原值
            return false;
        }
    };
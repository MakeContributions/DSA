/*
Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.
Example 1:
Input: N = 1, dictionary = {"CAT"}, R = 3, C = 3, board = {{C,A,P},{A,N,D},{T,I,E}}
Output: CAT
Explanation: 
    C A P
    A N D
    T I E
*/
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool isSafe(int i, int j, int N, int M, vector<vector<bool>> &vis)
    {
        return i >= 0 && j >= 0 && i < N && j < M && !vis[i][j];
    }
    bool wordInDict(vector<string> &dictionary, string &s)
    {
        for(int i = 0 ; i < dictionary.size() ; i++)
        {
            if(s.compare(dictionary[i]) == 0)
                return true;
        }
        return false;
    }
    void wordBoggleRec(vector<vector<char>> &board, vector<string> &dictionary, vector<vector<bool>> &vis, int i, int j, vector<string> &res, string s)
    {
        vis[i][j] = true;
        s += board[i][j];
        if(wordInDict(dictionary, s))
            res.push_back(s);
        static int rows[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int cols[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int k = 0 ; k < 8 ; k++)
        {
            if(isSafe(i + rows[k], j + cols[k], board.size(), board[0].size(), vis))
                wordBoggleRec(board, dictionary, vis, i + rows[k], j + cols[k], res, s);
        }
        s.pop_back();
        vis[i][j] = false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary)
	{
	    // Code here
	    vector<string> res;
	    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
	    string s = "";
	    for(int i = 0 ; i < board.size() ; i++)
	    {
	        for(int j = 0 ; j < board[0].size() ; j++)
	            wordBoggleRec(board, dictionary, vis, i, j, res, s);
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends

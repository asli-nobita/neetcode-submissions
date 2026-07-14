class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int mask; 
        // check duplicates row-wise 
        for(int r=0;r<9;r++) {  
            mask=0;
            for(int c=0;c<9;c++) { 
                if(board[r][c]!='.') { 
                    int y=(board[r][c]-'1'); 
                    int bit=1<<y;  
                    if(mask&bit) return false; 
                    mask|=bit;  
                }
            }
        } 
        // check duplicates column wise 
        for(int c=0;c<9;c++) { 
            mask=0;
            for(int r=0;r<9;r++) { 
                if(board[r][c]!='.') { 
                    int y=(board[r][c]-'1'); 
                    int bit=1<<y;  
                    if(mask&bit) return false; 
                    mask|=bit;  
                }
            }
        } 
        // check duplicates square wise 
        for(int i=0;i<3;i++) { 
            for(int j=0;j<9;j+=3) { 
                mask=0;
                for(int r=3*i;r<3*i+3;r++) { 
                    for(int c=j;c<j+3;c++) { 
                       if(board[r][c]!='.') { 
                            int y=(board[r][c]-'1'); 
                            int bit=1<<y;  
                            if(mask&bit) return false; 
                            mask|=bit;  
                        } 
                    }
                }
            }
        } 
        return true; 
    }
};

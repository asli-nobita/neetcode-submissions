class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int rows=picture.size(); 
        int cols=picture[0].size(); 
        vector<int> rowB(rows), colB(cols); 
        for(int r=0;r<rows;r++) { 
            for(int c=0;c<cols;c++) { 
                if(picture[r][c]=='B') { 
                    rowB[r]++; 
                    colB[c]++; 
                }
            }
        }  
        int count=0; 
        for(int r=0;r<rows;r++) { 
            for(int c=0;c<cols;c++) { 
                if(picture[r][c]=='B' && rowB[r]==1 && colB[c]==1) { 
                    count++; 
                } 
            }
        }
        return count; 
    }
};

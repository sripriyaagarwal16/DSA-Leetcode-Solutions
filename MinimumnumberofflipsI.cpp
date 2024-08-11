class Solution {
public:
//m/2==m
//n/2==n
//time complexity: O(m*n)
//spaCe complexity: O(1)
    int minFlips(vector<vector<int>>& grid) {
        //edge cases 
        if(grid.size()==1 && grid[0].size()==1){
            return 0;
        }
        int rowpalindromic=0;
        int colpalindromic=0;
        int row=0;
        while(row<grid.size()){
            int i=0;
            int j =grid[0].size()-1;
            while(i<j){
                if(grid[row][i]!=grid[row][j]){
                    rowpalindromic++;
                }
                i++;
                j--;
            } 
            row++;
        }
        
        int col=0;
        while(col<grid[0].size()){
            int i=0;
            int j =grid.size()-1;
            while(i<j){
                if(grid[i][col]!=grid[j][col]){
                    colpalindromic++;
                }
                i++;
                j--;
            } 
            col++;
        }
        int minswaps=0;
        minswaps=min(rowpalindromic,colpalindromic);
        return minswaps;
    }

};

lass Solution 
{
    public:

  // here i am using the
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
                if(grid[i][j]==0){
                    for(int p=1;p<=9;p++){
                        if(isvalid(i,j,p,grid)){
                            grid[i][j]=p;
                            if(SolveSudoku(grid))return true;
                            else grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }


  // checking the validity of each vacant element which can be assigned or not 
    bool isvalid(int row,int col,int val,int grid[N][N]){
        for(int i=0;i<9;i++){
            if(grid[row][i]==val)return false;
            if(grid[i][col]==val)return false;
            if(grid[3*(row/3) + i/3][3*(col/3)+i%3]==val)return false;
        }
        return true;
    }
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)cout<<grid[i][j]<<" ";
        }
        
    }
};

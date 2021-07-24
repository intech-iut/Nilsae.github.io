def matrixScore(self, grid: List[List[int]]) -> int:
 for i in range(len(grid)):
        if grid[i][0]==0:
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    grid[i][j]=0
                else:
                    grid[i][j]=1

    # Counting number of 0 for each Column
    m=len(grid)
    n=len(grid[0])
    col=[0]*n
    for i in range(m):
        for j in range(n):
            if grid[i][j]==0:
                col[j]+=1

    # if number of zeroes are greater then one in column then toggle that column
    for j in range(n):
        if col[j]>(m-col[j]):
            for i in range(m):
                if grid[i][j]==1:
                    grid[i][j]=0
                else:
                    grid[i][j]=1

    # Calculating the sum
    num=0
    for row in grid:
        p=0
        for j in range(n-1,-1,-1):
            num+=row[j]*(2**p)
            p+=1
    return num



n= int(input())
m= int(input())
mat[n][m]=[]
for(int i=0;i<n;i++){
for(int j=0;j<m ;j++){
  cin>>mat[i][j];
}
}
print(num)

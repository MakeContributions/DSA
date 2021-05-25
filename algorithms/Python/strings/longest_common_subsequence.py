class Solution:
    def longest_common_subsequence(self, text1: str, text2: str) -> int:
        n,m = len(text1),len(text2)
        
        grid=[[0] * (m+1) for z in range(n+1)]
        
        for i in range(n):
            for j in range(m):
                
                if text1[i]==text2[j]:
                    grid[i+1][j+1]=grid[i][j] +1
                    
                else:
                    grid[i+1][j+1]=max(grid[i][j+1], grid[i+1][j])
                    
        return grid[-1][-1]
    
if __name__=='__main__':
    instance = Solution()
    print(instance.longest_common_subsequence("abcdefg","aceg"))

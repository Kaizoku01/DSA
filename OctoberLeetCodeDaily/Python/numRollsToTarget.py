class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[-1 for i in range(target+2)]for j in range(n+2)]
        def f(i, target):
            if(i<0):
                if(target==0):
                    return 1
                else:
                    return 0
            if(target<0):
                return 0
            if(dp[i][target]!=-1):
                return dp[i][target]
            take = 0
            for j in range(1, k+1):
                if(j<=target):
                    take += f(i-1, target-j)
            dp[i][target] = take
            return dp[i][target]
        return f(n-1, target)%((10**9)+7)

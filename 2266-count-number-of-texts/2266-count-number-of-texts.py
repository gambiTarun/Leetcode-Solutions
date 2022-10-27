class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        
        dp = [0]*(len(pressedKeys)+1)
        dp[0] = 1
        
        for i in range(1,len(pressedKeys)+1):
            dp[i] = dp[i-1]
            if i-2>=0 and pressedKeys[i-1]==pressedKeys[i-2]:
                dp[i] += dp[i-2]
            if i-3>=0 and pressedKeys[i-1]==pressedKeys[i-2] and pressedKeys[i-1]==pressedKeys[i-3]:
                dp[i] += dp[i-3]
            
            if pressedKeys[i-1] in "79":
                if i-4>=0 and pressedKeys[i-1]==pressedKeys[i-2] and pressedKeys[i-1]==pressedKeys[i-3] and pressedKeys[i-1]==pressedKeys[i-4]:
                    dp[i] += dp[i-4]
                
            dp[i] %= (1e9+7)
                
        return int(dp[-1]%(1e9+7))
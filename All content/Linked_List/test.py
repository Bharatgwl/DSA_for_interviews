import itertools.groupby 
def poss(self , word : str , k :int )-> int:
    MOD = 10**9 + 7
    n = len(word)
    g_length = [len(list(group)) for _, group in groupby(word)]
    
    total = 1
    
    for g_size in g_length:
        total = (total * g_size) % MOD
    
    if len(g_length)>=k:
        return total
    
    prefix_sum = [1] *k
    
    for g_size in g_length:
        dp = [0] * k
        
        for length in range(1,k):
            dp[length] = prefix_sum[length-1]
            if length - g_size-1 >=0:
                dp[length] = (dp[length] - prefix_sum[length - g_size - 1] + MOD) % MOD
        
        prefix_sum = [0]*k
        prefix_sum[0]= dp[0]
        
        for i in range(1,k):
            prefix_sum[i] = (prefix_sum[i-1] + dp[i]) % MOD
            
    return (total - prefix_sum[k-1])%MOD
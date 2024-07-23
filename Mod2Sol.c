#include <stdio.h>
#include <string.h>

#define MAX 20

int n;
int preferences[MAX][MAX];
long long dp[1 << MAX];

int main() 
{

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &preferences[i][j]);
        }
    }

    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; 

    
    for (int mask = 0; mask < (1 << n); mask++) 
    {
        
        int k = __builtin_popcount(mask);

        
        if (k >= n) continue;

       
        for (int topic = 0; topic < n; topic++) 
        {
           
            if (!(mask & (1 << topic)) && preferences[k][topic]) 
            {
                dp[mask | (1 << topic)] += dp[mask];
            }
        }
    }

  
    printf("%lld\n", dp[(1 << n) - 1]);

    return 0;
}

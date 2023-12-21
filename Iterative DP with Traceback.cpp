#include<stdio.h>
#include<string.h>

int dp[101][101];
int trace[101][101];

int LCS(char x[], char y[], int n, int m)
{
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                trace[i][j] = 1;
            }
            else
            {
                if (dp[i][j - 1] >= dp[i - 1][j])
                {
                    dp[i][j] = dp[i][j - 1];
                    trace[i][j] = 2;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    trace[i][j] = 3;
                }
            }
        }
    }
    return dp[n][m];
}

void traceback(char x[], char y[], int n, int m)
{
    char L3[101];
    int i = 0;

    while (n > 0 && m > 0)
    {
        if (trace[n][m] == 1)
        {
            L3[i++] = x[n - 1];
            --n;
            --m;
        }
        else if (trace[n][m] == 2)
        {
            --m;
        }
        else
        {
            --n;
        }
    }

    for (i = i - 1; i >= 0; --i)
    {
        printf("%c", L3[i]);
    }
}

int main()
{
    char x[100],y[100];
    int n,m;
    printf("X: ");

    gets(x);
    printf("Y: ");

    gets(y);
    n=strlen(x);
    m=strlen(y);
    memset(dp,-1,sizeof(dp));
    int len = LCS(x,y,n,m);
    printf("LCS length: %d\n",len);
    printf("LCS: ");

    traceback(x,y,n,m);
    printf("\n");
    return 0;
}

#include <stdio.h>

int max(int a, int b);
int knapsack(int W, int wt[], int profit[], int n);


// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int profit[], int n)
{
    int dp[W + 1];
    int i, w;

    // Initialize all dp values as 0
    for (i = 0; i <= W; i++)
        dp[i] = 0;

    // Fill dp[] using above recursive formula
    for (i = 0; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wt[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - wt[j]] + profit[j]);
            }
        }
    }

    return dp[W];
}

// Utility function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}


// Driver program to test above function
int main()
{
    // 4-a)
    // int profit[] = {7, 6, 9};
    // int wt[] = {4, 6, 8};

    // 4-b)
    int profit[] = {7, 6, 9};
    int wt[] = {5, 6, 8};

    int W = 14;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("Maximum value in a knapsack of capacity %d is %d\n", W, knapsack(W, wt, profit, n));
    return 0;
}

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int weight[n], profit[n], w;
    int i, j;
    printf("Enter the corresponding weight and profit:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &profit[i]);
    }
    printf("Enter the capacity: ");
    scanf("%d", &w);
    printf("MAximum Profit: %d", knapSack(w, weight, profit, n));
    return 0;
}

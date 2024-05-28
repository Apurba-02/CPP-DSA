#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobsByProfit(int jobIDs[], int deadlines[], int profits[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (profits[j] < profits[j + 1])
            {
                swap(&profits[j], &profits[j + 1]);
                swap(&deadlines[j], &deadlines[j + 1]);
                swap(&jobIDs[j], &jobIDs[j + 1]);
            }
        }
    }
}

int findMaxDeadline(int deadlines[], int n)
{
    int maxDeadline = deadlines[0];
    for (int i = 1; i < n; i++)
    {
        if (deadlines[i] > maxDeadline)
        {
            maxDeadline = deadlines[i];
        }
    }
    return maxDeadline;
}

void jobSequencing(int jobIDs[], int deadlines[], int profits[], int n)
{
    sortJobsByProfit(jobIDs, deadlines, profits, n);
    int maxDeadline = findMaxDeadline(deadlines, n);
    int slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
    {
        slot[i] = -1;
    }

    int totalProfit = 0;
    int jobSequence[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
    {
        jobSequence[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = deadlines[i]; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += profits[i];
                jobSequence[j] = jobIDs[i];
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (jobSequence[i] != -1)
        {
            printf("%d ", jobSequence[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main()
{
    int n, i;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int jobIDs[n], deadlines[n], profits[n];
    printf("Enter jobID, deadline, and profits:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &jobIDs[i], &deadlines[i], &profits[i]);
    }

    jobSequencing(jobIDs, deadlines, profits, n);

    return 0;
}


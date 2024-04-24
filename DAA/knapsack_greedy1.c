#include<stdio.h>

void swap(float *a , float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void fractional_knapsack(int n , float weight[] , float profit[] , float capacity)
{
    float M = capacity, total_profit=0.0 , x[n];
    int i;
    for(i=0 ; i<n ; i++)
    {
        x[i]=0.0;
    }

    for(i=0;i<n;i++)
    {
        if(weight[i]>M)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            M= M-weight[i];
            total_profit += profit[i];
        }
    }
    if(i<n)
    {
        x[i]=M/weight[i];
        total_profit+= x[i]*profit[i];
    }
    printf("Fraction of elements used : ");
    for(i=0;i<n;i++)
    {
        printf("%f ",x[i] );
    }
    printf("\nMaximum profit : %f\n",total_profit);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    float w[n], p[n],ratio[n],m;
    int i,j;
    printf("Enter the corresponding weight and profit:\n");
    for(i=0;i<n ; i++)
    {
        scanf("%f%f", &w[i],&p[i]);
    }
    printf("Enter the capacity: ");
    scanf("%f", &m);
    for(i=0;i<n;i++)
    {
        ratio[i]=p[i]/w[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                swap(&ratio[i], &ratio[j]);
                swap(&w[i],&w[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
    fractional_knapsack(n,w,p,m);
    return 0;
}

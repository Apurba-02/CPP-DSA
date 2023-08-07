
// Selection-Sort :

#include <iostream>
#include <string.h>
using namespace std;

void lexicographical_order(char array[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(array[min_index], array[j]) > 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(array[i], array[min_index]);
        }
    }
}

int main()
{
    char fruits[][100] = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};
    int n = sizeof(fruits) / sizeof(fruits[0]);
    lexicographical_order(fruits , n);
    for (int i = 0; i < n; i++)
    {
        cout << fruits[i] << endl;
    }
    return 0;
}
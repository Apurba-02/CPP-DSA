
// Binary search for sqr.root

#include <iostream>
using namespace std;
int search(int terget)
{
    int start = 1, end = terget, mid = end + (start - end) / 2, ans = -1;
    while (start < end)
    {
        if (mid * mid <= terget)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (mid * mid > terget)
        {
            end = mid - 1;
        }
        mid = end + (start - end) / 2;
    }
    return ans;
}

int main()
{
    int terget;
    cout << "Enter the number for sqr.root : \n";
    cin >> terget;
    cout << search(terget);
    return 0;
}
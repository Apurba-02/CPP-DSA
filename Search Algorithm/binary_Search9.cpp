#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cout << "Enter no. of rows and column : \n";
    cin >> row >> col;
    int arry[row][col], i, j, terget, start = 0, end = row * col - 1, ans = false;
    cout << "enter the elements :\n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> arry[i][j];
        }
    }
    cout << "Enter the number to search : \n";
    cin >> terget;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int x = mid / col, y = mid % col;
        if (arry[x][y] == terget)
        {
            ans = true;
            break;
        }
        else if (terget > arry[x][y])
        {
            start = mid + 1;
        }
        else if (terget < arry[x][y])
        {
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
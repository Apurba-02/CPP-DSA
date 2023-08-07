#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_Sort(float array[], int size)
{
    vector<vector<float>> bucket(size, vector<float>());

    for (int i = 0; i < size; i++)
    {
        int index = array[i] * size;
        bucket[index].push_back(array[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (!bucket[i].empty())
        {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            array[k++] = bucket[i][j];
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the arry : \n";
    cin >> n;
    float input[n];
    cout << "Enter the elements of the array : \n";
    for (int i = 0; i < n; i++)
    {
        float x;
        cin >> x;
        input[i] = x;
    }
    bucket_Sort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}
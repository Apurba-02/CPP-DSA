
// for array having elements value more then 1.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_Sort(float array[], int size)
{
    vector<vector<float>> bucket(size, vector<float>());
    float min_ele = array[0], max_ele = array[0];
    for (int i = 1; i < size; i++)
    {
        max_ele = max(max_ele, array[i]);
        min_ele = min(min_ele, array[i]);
    }

    float range = (max_ele - min_ele) / size;
    
    if (range == 0)
    {
        return;
    }

    for (int i = 1; i < size; i++)
    {
        int index = (array[i] - min_ele) / range;
        float diff = (array[i] - min_ele) / range - index;
        if (diff == 0 && array[i] != min_ele)
        {
            bucket[index - 1].push_back(array[i]);
        }
        else
        {
            bucket[index].push_back(array[i]);
        }
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
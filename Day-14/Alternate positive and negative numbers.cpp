void rearrange(int arr[], int n)
{
    // code here
    vector<int> neg;
    vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    int k = 0;
    int j = 0;
    int p = pos.size();
    int q = neg.size();
    int i = 0;
    while (k < p && j < q)
    {
        if (i % 2 == 0)
        {
            arr[i++] = pos[k++];
        }
        else
        {
            arr[i++] = neg[j++];
        }
    }

    while (k < p)
    {
        arr[i++] = pos[k++];
    }
    while (j < q)
    {
        arr[i++] = neg[j++];
    }
    // return arr;
}
/* we are given an array of integers/
we have to find the maximum subarray sum.
ie maximum sum of contiguous digits.


*/

//brute force approach.
//o(n2) time complexity.
//O(1) space complexity.
int maxSubArray(vector<int> &arr)
{
    //brute force approach
    int ans = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int max = arr[i];
        int curr = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            curr += arr[j];
            if (curr > max)
            {
                max = curr;
            }
        }
        if (max > ans)
            ans = max;
    }
    return ans;
}

// kadane's algorithm
int maxSubArray(vector<int> &arr)
{
    int maximum = arr[0];
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maximum = max(maximum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maximum;
}

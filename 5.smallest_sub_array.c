#include <stdio.h>
#include <limits.h>
 
// Utility function to find a minimum of two numbers
int min(int x, int y) {
    return (x < y) ? x : y;
}
 
// Function to find the length of the smallest subarray whose sum
// of elements is greater than the given number
int findSmallestSubarrayLen(int arr[], int n, int k)
{
    // stores the current window sum
    int windowSum = 0;
 
    // stores the result
    int len = INT_MAX;
 
    // stores the window's starting index
    int left = 0;
 
    // maintain a sliding window `[left…right]`
    for(int right = 0; right < n; right++)
    {
        // include the current element in the window
        windowSum += arr[right];
 
        // the window becomes unstable if its sum becomes more than `k`
        while (windowSum > k && left <= right)
        {
            // update the result if the current window's length is less than the
            // minimum found so far
            len = min(len, right - left + 1);
 
            // remove elements from the window's left side till the window
            // becomes stable again
            windowSum -= arr[left];
            left++;
        }
    }
 
    // invalid input
    if (len == INT_MAX) {
        return 0;
    }
 
    // return result
    return len;
}
 
int main()
{
    // an array of positive numbers
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int k = 21;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // find the length of the smallest subarray
    int len = findSmallestSubarrayLen(arr, n, k);
 
    if (len != INT_MAX) {
        printf("The smallest subarray length is %d", len);
    }
    else {
        printf("No subarray exists");
    }
 
    return 0;
}




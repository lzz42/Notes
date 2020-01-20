#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//O(log(m+n))
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int l = nums1Size + nums2Size;
    if (l % 2 == 1)
    {
        if (nums1[nums1Size - 1] <= nums2[0])
        {
            if (nums1Size >= (l / 2 + 1))
            {
                return nums1[l / 2];
            }
            else
            {
                return nums2[l / 2 - nums1Size - 1];
            }
        }
        else if (nums1[0] > nums2[nums2Size - 1])
        {
            if (nums2Size >= (l / 2 + 1))
            {
                return nums2[l / 2];
            }
            else
            {
                return nums1[l / 2 - nums2Size - 1];
            }
        }
        else
        {
            goto Mix;
        }
    }
    else
    {
        if (nums1[nums1Size - 1] <= nums2[0])
        {
            if (nums1Size >= (l / 2 + 1))
            {
                return (nums1[l / 2] + nums1[l / 2 - 1]) / 2.0;
            }
            else
            {
                return (nums2[l / 2 - nums1Size - 1] + nums2[l / 2 - nums1Size]) / 2.0;
            }
        }
        else if (nums1[0] > nums2[nums2Size - 1])
        {
            if (nums2Size >= (l / 2 + 1))
            {
                return (nums2[l / 2] + nums2[l / 2 - 1]) / 2.0;
            }
            else
            {
                return (nums1[l / 2 - nums2Size - 1] + nums1[l / 2 - nums2Size]) / 2.0;
            }
        }
        else
        {
            goto Mix;
        }
    }
Mix:
{
    int d = nums1Size - 1, u = 0;
    int t = 0;
    int dd = nums1[d] - nums2[u];
    while (nums1[d] > nums2[u])
    {
        if (t % 2 == 0)
        {
            d--;
        }
        else
        {
            u++;
        }
        t++;
    }
    return (nums1[d] + nums2[u]) / 2.0;
}
}

double findMedianSortedArraysEx(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int l1 = nums1[0];
    int h1 = nums1[nums1Size - 1];
    int l2 = nums2[0];
    int h2 = nums2[nums2Size - 1];
    int l = nums1Size + nums2Size;
    if (h1 <= l2 || h2 <= l1)
    {
        int *n1 = nums1;
        int *n2 = nums2;
        int s1 = nums1Size;
        int s2 = nums2Size;
        if (h2 <= l1)
        {
            int *temp = n1;
            n1 = n2;
            n2 = temp;
            int ts = s1;
            s1 = s2;
            s2 = ts;
            h1 = h2;
            l2 = l1;
        }
        if (s1 > s2)
        {
            if (l % 2 == 1)
            {
                return n1[l / 2];
            }
            else
            {
                return (n1[l / 2 - 1] + n1[l / 2]) / 2.0;
            }
        }
        else if (s1 == s2)
        {
            return (h1 + l2) / 2;
        }
        else
        {
            if (l % 2 == 1)
            {
                return n2[l / 2 - s1];
            }
            else
            {
                return (n2[l / 2 - s1 - 1] + n2[l / 2 - s1]) / 2.0;
            }
        }
    }
    return -3.14;
}

int main(char arg[])
{
    int a[7] = {2, 7, 8, 9, 12, 13, 14};
    int b[7] = {15, 17, 18, 19, 112, 113, 114};
    int c[3] = {15, 17, 18};
    int d[4] = {15, 17, 18, 19};
    int a1[3] = {2, 7, 8};
    int c1[7] = {9, 12, 13, 14,15, 17, 18};

    // printf("the Mid is %2f \n", findMedianSortedArrays(a, 7, b, 7));
    // printf("the Mid is %2f \n", findMedianSortedArrays(b, 7, a, 7));

    printf("the Mid is %2f \n", findMedianSortedArraysEx(a, 7, c, 3));
    printf("the Mid is %2f \n", findMedianSortedArraysEx(c, 3, a, 7));
    printf("the Mid is %2f \n", findMedianSortedArraysEx(a1, 3, c1, 7));
    printf("the Mid is %2f \n", findMedianSortedArraysEx(c1, 7, a1, 3));

    printf("the Mid is %2f \n", findMedianSortedArraysEx(a, 7, d, 4));
    printf("the Mid is %2f \n", findMedianSortedArraysEx(d, 4, a, 7));
}
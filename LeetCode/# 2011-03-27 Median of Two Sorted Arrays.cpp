/*	Question:
 *	There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
 *	The overall run time complexity should be O(log (m+n)).
 */

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)		/* O(m + n) Sort A and B into C */
	{
	    if(m == 0)
			return n % 2? B[n/2]:(B[n/2] + B[n/2 - 1])*1.0 /2;
		if(n == 0)
			return m % 2? A[m/2]:(A[m/2] + A[m/2 - 1])*1.0 /2;
		int * C = new int[m + n];
		int i = 0, j = 0, k = 0;
		while(i < m && j < n)
		{
			if(A[i] < B[j])
			{
				C[k] = A[i];
				++i;
			}
			else
			{
				C[k] = B[j];
				++j;
			}
			++k;
		}
		while(i < m)
		{
			C[k] = A[i];
			++k;
			++i;
		}
		while(j < n)
		{
			C[k] = B[j];
			++k;
			++j;
		}
		int index = (n + m)/2;

		return (m%2 + n%2)%2 ? C[index] : (C[index] + C[index - 1]) * 1.0 /2;
    }
};


/* test func */
int main()
{
	int a[2] = {2,3};
	int b[1] = {1};
	Solution s;
	s.findMedianSortedArrays(a,2,b,1);

	return 0;
}
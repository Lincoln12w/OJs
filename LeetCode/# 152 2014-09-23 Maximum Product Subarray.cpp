/*	Question:
 *	Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *	
 *	For example, given the array [2,3,-2,4],
 *	the contiguous subarray [2,3] has the largest product = 6.
 */


class Solution {
public:
    int maxProduct(int A[], int n)		/* Notice it is a int type number, so just need to consider negtive and zero. */
    {
		int maxPositiveProduct = -1;
		int currentPositiveProduct = -1;
		int currentNegativeProduct = 1;
		int currentProduct = 0;
		bool zeroFlag = false;

		if(n == 1)
			return A[0];
		
        for(int i = 0; i < n; i++)
		{
			if(A[i] == 0)
			{
				currentPositiveProduct = -1;
				currentNegativeProduct = 1;
				currentProduct = 0;
				zeroFlag = true;
			}
			else
			{
				if(!currentProduct)
					currentProduct = A[i];
				else
					currentProduct *= A[i];

				if(currentProduct > 0)
				{
					if(currentPositiveProduct < 0 || currentNegativeProduct > 0)
						currentNegativeProduct = A[i];
					else
						if(A[i] < 0)
							currentNegativeProduct = currentPositiveProduct * A[i];
						else
							currentNegativeProduct *= A[i];
					
					currentPositiveProduct = currentProduct;
				}
				else
				{
					if(currentNegativeProduct > 0 || currentPositiveProduct < 0)
						currentPositiveProduct = A[i];
					else
						if(A[i] < 0)
							currentPositiveProduct = currentNegativeProduct * A[i];
						else
							currentPositiveProduct *= A[i];

					currentNegativeProduct = currentProduct;
				}
				if(currentPositiveProduct > maxPositiveProduct)
					maxPositiveProduct = currentPositiveProduct;
			}
		}

		if(maxPositiveProduct < 0 && zeroFlag)
			return 0;
		
		return maxPositiveProduct;
    }
};

int main()
{
	//int A[10] = { -1, 1, 0, -2, 2, 3, 4, 5, 6, 1};
	int A[1] = {-2};

	Solution s;

	s.maxProduct(A, 1);

	return 0;
}
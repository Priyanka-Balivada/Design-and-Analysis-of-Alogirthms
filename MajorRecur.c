#include<stdio.h>
int majorityElement(int arr[], int l, int r)
{
    if (l == r)
        return arr[l];
        
    int m = (l + r) / 2;
    int left = majorityElement(arr, l, m);
    int right = majorityElement(arr, m + 1, r);
    
    if (left == right)
        return left;
        
    int leftCount = 0, rightCount = 0;
    int i;
    for (i = l; i <= r; i++)
    {
        if (arr[i] == left)
            leftCount++;
        else if (arr[i] == right)
            rightCount++;
    }
    
    if(leftCount>(r-l+1)/2||rightCount>(r-l+1)/2)
    {
    	if (leftCount > rightCount)
        	return left;
    	else
        	return right;
	}
	else
		return -1;
}

int main()
{
//    int array[] = {2,4,2,4,2,2,3,2};
    int array[] = {2,4,2,4,3,3,2,2};
    int n = sizeof(array) / sizeof(array[0]);
    int i=0;
    for(i=0;i<n;i++)
    	printf("%d ",array[i]);

    int majority = majorityElement(array,0,n-1);
    if(majority==-1)
    	printf("\n\nNo Majority Element");
    else
    	printf("\n\nMajority Element : %d" ,majority);
}

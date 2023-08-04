class Solution {
public:
	void main()
	{
		int n=0;
		cout<<"Enter n : ";
		cin>>n;
		cout<<"Count : "<<countPrimes(n);	
	}
	
    int countPrimes(int n) {
        int count=0;

        for(int i=2;i<n;i++)
        {
            int j=2;
            while(j<=int(sqrt(i)))
            {
                if(i%j==0)
                    break;
                
                j++;
            }

            if((j-1)==int(sqrt(i)))
            {
            	cout<<i;
            	count++;
			}
                
        }

        return count;
    }
};

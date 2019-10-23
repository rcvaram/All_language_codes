class canBalance
{
	public static void main(String args[])
	{
		boolean check=false;
		int[] nums={2, 3, 4, 1, 2};
		int sum=0,s1=0,s2=0,j=0;
		for(int i=0;i<nums.length;i++)
		{
			sum+=nums[i];
		}
		System.out.println(sum);
		if((sum%2)!=0)
		{
			check=false;
			return;
		}
		else
		{
			for(int i=0;i<nums.length-1;i++)
			{
				s1+=nums[i];
				j=i+1;
				s2=0;
				while(j<nums.length)
				{
					s2+=nums[j];
					j++;
				}
				if(s1==s2)
				{
					check=true;
					break;
				}
				System.out.println("S1:"+s1);
				System.out.println("S2:"+s2);
			}
		}
		System.out.println(check);
	}
}
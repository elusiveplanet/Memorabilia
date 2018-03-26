
public class NuclearArrayTesting {

	public static void main(String[] args) {
		/*
		String str = "";
		int[]nums = {5,3,2,8,9,1,-3};
		for (int x = 0; x <= nums.length - 1; x++)
			if (nums[x] % 3 == 0)
			str += nums[x] + " ";
		System.out.println(str);
		*/
		int[]nums = {2,3,5,6,7,8,9,10,11,12,13,14,15,16};
		int y = 1;
		for(int x: nums)
		{
			y = 1;
	         for (int i = 2 ; i <= Math.sqrt(x) ; i++)
	         {
	            if (x % i == 0)
	            y = 0;
	         }
		if (y == 1)
		System.out.println(x);
		
		}
	}

}

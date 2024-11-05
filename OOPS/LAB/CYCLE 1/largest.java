import java.util.*;
class largest
{
	public static void main (String args[])
	{
		Scanner s1 = new Scanner(System.in);
		System.out.println("Enter the number of elements");
		int n=s1.nextInt();
		int largest = 0;
		System.out.println("Enter the numbers:");
		for (int i=0;i<n;i++)		
		{
			int no=s1.nextInt();
			if(no>largest)
			{
				largest = no;
			}
		}
		System.out.println("The largest element is" + largest);
		s1.close();
	 }
}

import java.util.*;
class Avg
{
	public static void main(String args[])
	{
		int a,b;
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter 2 numbers:");
		a=s1.nextInt();
		b=s1.nextInt();
		float avg=(a+b)/2;
		System.out.println("The avg of 2 numbers is ="+avg);
		s1.close();
	}
}

import java.util.*;
class sum3
{
	public static void main(String args[])
	{
		int a,b,c;
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter 1st number:");
		a=s1.nextInt();
		System.out.println("Enter 2nd number:");
		b=s1.nextInt();
		System.out.println("Enter 3rd number:");
		c=s1.nextInt();
		int sum=a+b+c;
		System.out.println("Total="+sum);
		s1.close();
	}
}

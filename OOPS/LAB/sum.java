import java.util.*;
class sum
{
	public static void main(String args[])
	{
		int a,b;
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter 2 numbers:");
		a=s1.nextInt();
		b=s1.nextInt();
		int sum=a+b;
		System.out.println("The sum="+sum);
		s1.close();
	}
}

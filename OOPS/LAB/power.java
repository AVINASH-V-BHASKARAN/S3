import java.lang.*;
import java.util.*;
class sqrtandpower
{
	public static void main(String args[])
	{
		int a,b,c;
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter 2 numbers to find the power:");
		a=s1.nextInt();
		b=s1.nextInt();
		double pwr=Math.pow(a,b);
		System.out.println("The Power of the number="+pwr);
		System.out.println("Enter the number to find root:");
		c=s1.nextInt();
		double rt=Math.sqrt(c);
		System.out.println("The Square root of the number="+rt);
		s1.close();
	}
}

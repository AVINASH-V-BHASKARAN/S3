import java.lang.*;
import java.util.*;
class sqrt
{
	public static void main(String args[])
	{
		int a;
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter the number:");
		a=s1.nextInt();
		double rt=Math.sqrt(a);
		System.out.println("The Square root of the number="+rt);
		s1.close();
	}
}

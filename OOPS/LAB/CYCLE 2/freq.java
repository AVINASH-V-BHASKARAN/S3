import java.util.*;
class freq
{
	public static void main(String args[])
	{
		Scanner s1=new Scanner(System.in);
		System.out.println("Enter the string:");
		String str=s1.nextLine();
		System.out.println("Enter the character:");
		String f=s1.next();
		char l=f.charAt(0);
		int n= str.length();
		int c=0;
		for(int i=0;i<n;i++)
		{
			char m=str.charAt(i);
			if (m==l)
				c++;	
		}
		System.out.println("the number of "+ f+" in "+str+ " is " +c);
		s1.close();
	}
}
			
			

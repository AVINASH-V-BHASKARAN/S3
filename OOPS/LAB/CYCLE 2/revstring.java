import java.util.*;
class revstring
{
	public static void main(String args[])
	{
	
		Scanner s1=new Scanner(System.in);
		String word,rev="";
		System.out.println("Enter the string: ");
		word=s1.nextLine();
		int n=word.length();
		for(int i=n-1;i>-1;i--)
		{
			rev=rev+word.charAt(i);
		}
		System.out.println("The Reverse of the "+word+" is "+rev);
		s1.close();
	}
}
		
			

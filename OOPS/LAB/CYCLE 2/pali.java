import java.util.*;
class pali
{
	public static void main(String args[])
	{
		Scanner s1=new Scanner(System.in);
		String word,rev="";
		System.out.println("Enter the string: ");
		word=s1.nextLine();
		int n=word.length();
		word=word.toLowerCase();
		for(int i=n-1;i>-1;i--)
		{
			rev=rev+word.charAt(i);
		}
		if(word.equals(rev))
			System.out.println("The string is a Palindrome!");
		else
			System.out.println("The string is not a palindrome!");
		s1.close();
	}
}
		
			

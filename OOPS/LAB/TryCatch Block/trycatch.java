public class trycatch
{
	public static void main(String args[])
	{
		try
		{
			int[]num = {1,2,3};
			System.out.println(num[10]);
		}
		catch(Exception e)
		{
			System.out.println("Error occured in program");
		}
	}
}

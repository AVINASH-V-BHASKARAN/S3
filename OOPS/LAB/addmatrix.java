//Sum of 2 Matrics
import java.util.*;
class addmatrix
{
	public static void main (String args[])
	{
		Scanner s1= new Scanner(System.in);
		int a[][]= new int[100][100];
		int b[][]= new int[100][100];
		int s[][]= new int[100][100];
		int x,y,r,c;
		System.out.println("Enter the no of Rows and Columns:");
		r=s1.nextInt();
		c=s1.nextInt();
		System.out.println("Enter the 1st matrix elements:");
		for(x=0;x<r;x++)
		{
			for(y=0;y<c;y++)
			{
				a[x][y]=s1.nextInt();
			}
		}
		System.out.println("Enter the 2nd matrix elements:");
		for(x=0;x<r;x++)
		{
			for(y=0;y<c;y++)
			{
				b[x][y]=s1.nextInt();
			}
		}
		System.out.println("The sum of matrix");
		for(x=0;x<r;x++)
		{
			for(y=0;y<c;y++)
			{
				s[x][y]=a[x][y]+b[x][y];
			}
		}
		for(x=0;x<r;x++)
		{	
			System.out.println();
			for(y=0;y<c;y++)
			{
				System.out.print(s[x][y]+"\t");
			}
		}
		s1.close();
	}
}
		

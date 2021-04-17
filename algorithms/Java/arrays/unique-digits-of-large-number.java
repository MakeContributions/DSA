import java.util.*;
public class UniqueDigitsOfLargeNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int l,i,j,l1=0;
		String s,p="";
		char c,d;
		System.out.println("Enter a large number");
		s=sc.nextLine();
		l=s.length();
		for(i=0;i<l;i++)
		{
			c=s.charAt(i);
			for(j=0;j<l1;j++)
			{
				if(p.charAt(j)==c)
					break;
			}
			if(j==l1)
			{
				p=p+c;
				l1=p.length();
			}
		}
			System.out.print("The unique digits present in "+Long.parseLong(s)+" are ");
			if(l1>1)
			{
				for(i=0;i<l1-1;i++)
				{
					System.out.print(p.charAt(i)+", ");
				}
				System.out.println("and "+p.charAt(l1-1)+".");
				c=p.charAt(0);
				for(i=0;i<l1;i++)
				{
					if(p.charAt(i)>c)
						c=p.charAt(i);
				}
				s="";
				s=s+c;
				c--;
				for(d=c;d>='0';d--)
				{
					for(i=0;i<l1;i++)
					{
						if(p.charAt(i)==d)
							s=s+d;
					}
				}
				System.out.println("The largest number possible out of these unique digits is "+Long.parseLong(s));
			}
			else
			{
				System.out.println(p.charAt(0)+".");
				System.out.println("The largest number possible out of these unique digits is "+Integer.parseInt(p));
			}
		
	}

}

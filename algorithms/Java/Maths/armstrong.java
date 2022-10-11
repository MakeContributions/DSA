import java.io.*;  
class armstrong{    
public static void main(String args[])throws Exception
{             
    int t,i,s=0;
    String st;
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));   
    System.out.println("ENTER A NUMBER");
    t=Integer.parseInt(br.readLine());
    st=Integer.toString(t);
    for(i=0;i<st.length();i++)
    {
        s+=(st.charAt(i)-48)*Math.pow(10,st.length());
    }
    if(s!=t)
    {
         System.out.println("NOT ARMSTRONG");
    }
    else
    {
         System.out.println("ARMSTONG");
    }
}
}
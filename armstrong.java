public static void main(String[]args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter first number : ");
        int a = input.nextInt();
        System.out.println("Enter second number : ");
        int b = input.nextInt();

        for (int i = a; i<b; i++){
            
            int check,rem,sum=0;
            check=i;
        
        while (check!=0){
        rem=check%10;
        sum=sum+(rem*rem*rem);
        check=check/10;
        }
        if (sum==i)
        System.out.println(""+sum+" is an armstrong number");
        }

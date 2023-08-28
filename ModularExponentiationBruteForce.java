import java.util.Scanner;

public class ModularExponentiationBruteForce {

    static int result(int a , int b , int c)
    {

        int ans = 1;
        if (a == 0)
        {
            return  0;
        }
        if (b == 0)
        {
            return  1;
        }
        while (b>0)
        {
            if ((b % 2 != 0))
            {
                ans = ans * a;
            }

            b = b >> 1;
            a = a * a;
        }

        return (ans%c);


//        double ans;
//
//        double x = Math.pow(a,b);
//        ans = x%c;
//
//        return ans ;

    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        System.out.println("Enter a : ");
//        int a = sc.nextInt();
//        System.out.println("Enter b : ");
//        int b = sc.nextInt();
//        System.out.println("Enter c : ");
//        int c = sc.nextInt();
        int a = 2;
        int b = 5;
        int c = 13;

        int d = result(a,b,c);
        System.out.println("Result : " +d);


    }
}
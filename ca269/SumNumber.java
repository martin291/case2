import java.util.Scanner;

public class SumNumber
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        
        int num = in.nextInt();
        
        int sum = 0;
        for(int i = 0; i < num + 1; i++)
        {
            sum = sum + i;
        }
        System.out.println("The sum of the numbers from 1 to " + num + " is " + sum);
    }
}

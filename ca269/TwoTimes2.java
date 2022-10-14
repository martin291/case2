import java.util.Scanner;

public class TwoTimes
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        // Ask the user to enter a number
        System.out.print("Enter a number: ");
        
        int num = in.nextInt();
        
        // Call the Helper.twoTimes() method to calculate the result
        int result = Helper.twoTimes(num);
        
        // prepare the user for the result
        System.out.println("Times two is: " + result);
    }
}

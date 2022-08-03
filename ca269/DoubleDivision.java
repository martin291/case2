import java.util.Scanner;

public class DoubleDivision
{
    // Fill in the main method
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Please enter two floating point numbers: ");
        float a = in.nextFloat();
        float b = in.nextFloat();
        
        System.out.println(a + " / " + b + " is " + (a / b));
    }
}

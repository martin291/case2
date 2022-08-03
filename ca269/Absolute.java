import java.util.Scanner;

public class Absolute
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a number: ");

        int input = in.nextInt();
        
        if(input < 0) {
            System.out.println("The absolute value is " + (input * -1) + ".");
        }
        else
        {
            System.out.println("The absolute value is " + (input) + ".");
        }
    }
}

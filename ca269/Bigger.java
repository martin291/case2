// You may assume that the input will be two integers and that they will not be equal.
import java.util.Scanner;

public class Bigger
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter two numbers: ");

        int input1 = in.nextInt();
        int input2 = in.nextInt();
        
        if(input1 > input2) {
            System.out.println(input1 + " is the biggest.");
        }
        else
        {
            System.out.println(input2 + " is the biggest.");
        }
    }
}

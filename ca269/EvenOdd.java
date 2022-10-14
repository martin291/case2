import java.util.Scanner;

public class EvenOdd
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a number: ");

        int input = in.nextInt();
        
        if(input % 2 == 0) {
            System.out.println(input + " is even.");
        }
        else
        {
            System.out.println(input + " is odd.");
        }
    }
}

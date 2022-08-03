import java.util.Scanner;

public class NumToTwenty
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter a number: ");

        for(int num = in.nextInt() ;num < 21; num++)
        {
            System.out.print(num + " ");
        }

        System.out.println();
    }
}

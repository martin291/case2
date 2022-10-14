import java.util.Scanner;

public class NoMinusOne
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter numbers: ");
        
        int num = in.nextInt();
        int penultimate = 0;

        for(int i = 0; num != -1; i++)
        {
            penultimate = num;
            num = in.nextInt();
        }

        System.out.println("The penultimate number was: " + penultimate);
    }
}

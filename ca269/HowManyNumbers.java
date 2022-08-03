import java.util.Scanner;

public class HowManyNumbers
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter numbers: ");
        
        int num = in.nextInt();
        int count = 0;

        for(int i = 0; num != -1; i++)
        {
            count++;
            num = in.nextInt();
        }

        System.out.println(count + " numbers were entered.");
    }
}

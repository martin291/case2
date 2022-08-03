import java.util.Scanner;

public class OneToNum
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter a number: ");

        int num = in.nextInt();

        for(int i = 1; i < (num + 1); i++)
        {
            System.out.print(i + " ");
        }

        System.out.println();
    }
}

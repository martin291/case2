import java.util.Scanner;

public class NumToTwenty
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        
        int num = in.nextInt();
        
        while(num != 21)
        {
            System.out.print(num + " ");
            num++;
        }
        
        System.out.println();
    }
}

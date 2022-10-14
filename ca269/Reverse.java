import java.util.Scanner;

public class Reverse
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        // Read in the numbers
        System.out.print("How many numbers: ");
        int num = in.nextInt();
        
        System.out.print("Enter " + num + " numbers: ");
        
        int[] array = new int[num];
        
        for(int i = 0; i != num; i++)
        {
            int input = in.nextInt();
            array[i] = input;
        }
        
        // reverse the numbers
        System.out.print("The numbers reversed are:");
        for(int i = array.length; i != 0; i--)
        {
            System.out.print(" " + array[i - 1]);
        }
        System.out.println();
        
        // print them out
        
        // Use System.out.print(" " + num[i]); and finish with a newline.
    }
}

/*
    This code is supplied and may be used to help solve this problem.
*/
import java.util.Scanner;

public class SplitWord
{
    public static void main(String [] args)
    {
        // Create a scanner object
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a word: ");
        // Read in the word
        String word = in.next();

        // YOUR CODE HERE
        int length = word.length();
        //System.out.println(length);
        
        for(int i = 0; i < length - 1; i++)
        {
            String sub_string = word.substring(i, i + 2);
            System.out.println(sub_string);
        }
    }
}

import java.util.Scanner;

public class FirstMiddleLast
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter a word: ");
        
        String word = in.nextLine();
        
        int length = word.length();
        
        System.out.println(word.charAt(0));
        System.out.println(word.substring(1, length - 1));
        System.out.println(word.charAt(length - 1));
        
    }
}

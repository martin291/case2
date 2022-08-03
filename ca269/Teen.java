import java.util.Scanner;

public class Teen
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Enter your age: ");
        
        int age = in.nextInt();
        
        System.out.println(Teen.isTeenager(age));
    }
    
    public static boolean isTeenager(int age)
    {
        if(age > 12 && age < 20)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

import java.util.Scanner;

public class TellMeAboutYourself
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Tell me your name: ");
        
        String name = in.next();
        
        System.out.print(name + " what is your age and what is your favourite colour?");
        
        int age = in.nextInt();
        String colour = in.next();
        
        System.out.println("Hello " + name + ", you are " + age + " and your favourite colour is " + colour + ".");
    }
}

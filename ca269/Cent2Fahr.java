import java.util.Scanner;

public class Cent2Fahr
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        int T;
        T = in.nextInt(); //Centigrade
        
        double F;
        F = (T * 1.8) + 32;
        
        System.out.println(T + " " + F);
    }
}

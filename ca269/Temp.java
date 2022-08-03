/*
    Create a class with a main method.
    The method should read in a Fahrenhit Temperature
    Get the equivalent in Celsius (using the fahr2cels() method
    and print out the result.
*/
import java.util.Scanner;

public class Temp
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Give me a Fahrenheit temperature: ");
        
        double fahr = in.nextDouble();
        
        // Call the Helper.twoTimes() method to calculate the result
        double cels = Convert.fahr2cels(fahr);
        
        // prepare the user for the result
        System.out.println("In Celsius that would be: " + cels);
    }
}

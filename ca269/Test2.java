public class Test
{
    public static int largest(int a, int b, int c)
    {
        // Write the code to find the largest of these three numbers
        if(a > b)
        {
            if(a > c)
            {
                return a;
            }
            else{
                return c;
            }
        }
        else{
            if(c > b)
            {
                return c;
            }
            else
            {
                return b;
            }
        }
        
        
        // You will need a return statement to return the largest number
    }
}

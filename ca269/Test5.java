public class Test
{
    // Create a static method called countEven which returns the number of even numbers in the array
    public static void main(String [] args)
    {
        int [] num = {2, 3, 5, 4, 11, 13, 10, 5, 10, -5, 5};
        int result = Test.countEven(num);
        System.out.println(result);
    }
    
    public static int countEven(int[] num)
    {
        int count = 0;
        for(int i = 0; i != num.length; i++)
        {
            if(num[i] % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }


}

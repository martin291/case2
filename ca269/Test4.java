public class Test
{
    // Create a static method called countFives which returns the number of fives in the array
    public static void main(String [] args)
    {
        int [] num = {2, 3, 5, 7, 11, 13, 17, 5, 0, -5, 5};
        int result = Test.countFives(num);
        System.out.println(result);
    }
    
    public static int countFives(int[] num)
    {
        int count = 0;
        for(int i = 0; i != num.length; i++)
        {
            if(num[i] == 5)
            {
                count++;
            }
        }
        return count;
    }
}

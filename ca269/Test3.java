public class Test
{
    // Create a static method called getSum which sums an array of ints
    public static void main(String [] args)
    {
        int [] num = {2, 3, 5, 7, 11, 13, 17};
        System.out.println("The sum of the numbers in the array is: " + Test.getSum(num));   
    }
    
    public static int getSum(int[] num)
    {
        int size = num.length;
        int sum = 0;
        for(int i = 0; i != size; i++)
        {
            sum += num[i];
        }
        return sum;
    }
}

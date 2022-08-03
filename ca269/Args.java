public class Args
{
    public static void main(String [] args)
    {
        int i = 0;
        for(; i < args.length; i++)
        {
            System.out.println("args[" + i + "]" + " = " + args[i]);
        }
    }
}

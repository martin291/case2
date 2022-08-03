public class ReverseArgs
{
    public static void main(String [] args)
    {
        //System.out.println(args.length);
        for(int i = args.length - 1; i != -1; i--)
        {
            System.out.println("args[" + i + "]" + " = " + args[i]);
        }
        
    }
}

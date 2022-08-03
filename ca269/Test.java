public class Test
{
    // This method returns a String and receives a String
    public static String firstShallBeLast(String word)
    {
        // Reorganise the string.  Remember the '+' operator concatenates strings.
        // Needs to return the correct string.
        
        int length = word.length();

        return (word.charAt(length - 1) + word.substring(1, length - 1) + word.charAt(0) );
    }
}

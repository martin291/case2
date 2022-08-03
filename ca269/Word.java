// Create a Word class with one static method called isFirstLetter
public class Word
{
    public static boolean isFirstLetter(String word, char letter)
    {
        if(word.charAt(0) == letter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

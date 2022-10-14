// Create a Word class with one static method called containsLetter
public class Word
{
    public static boolean containsLetter(String word, char letter)
    {
        for(int i = 0; i != word.length(); i++)
        {   
            if(word.charAt(i) == letter)
            {
                return true;
            }
        }
        return false;
    }
}

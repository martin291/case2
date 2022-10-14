// Create a Word class with one static method called showLetters
public class Word
{
    public static String showLetters(String word, String guesses)
    {
        String result = "";
        for(int i = 0; i != word.length(); i++)
        {
            if(Word.containsLetter(guesses, word.charAt(i)))
            {
                result = result + word.charAt(i);
            }
            else
            {
                result = result + "_";
            }
        }
        return(result);
    }
    
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

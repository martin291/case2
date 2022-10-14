// Create a Word class with one static method called showLetter
public class Word
{
    public static String showLetter(String word, char guess)
    {
        String result = "";
        if(Word.containsLetter(word, guess))
        {
            for(int i = 0; i < word.length(); i++)
            {
                if(word.charAt(i) == guess)
                {
                    result = result + guess;
                }
                else
                {
                    result = result + "_";
                }
            }
        }
        return result;
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

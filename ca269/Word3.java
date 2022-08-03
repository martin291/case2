// Create a Word class with a static method called allDone
public class Word
{
    public static boolean allDone(String word, String guesses)
    {
        int correct_guesses = 0;
        for(int i = 0; i != word.length(); i++)
        {
            if(Word.containsLetter(guesses, word.charAt(i)))
            {
                correct_guesses++;
            }
            if(correct_guesses == word.length())
            {
                return true;
            }
        }
        return false;
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

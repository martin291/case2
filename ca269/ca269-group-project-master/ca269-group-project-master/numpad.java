import java.util.Scanner;
import java.util.Random;

/*
Authors: Conall Kavanagh, Patricija Shalkauskaite, Martin Derwin

Date: 18/2/2022

Functions: main, nums2letters, hangman, selectWord, getCount

Description: This program takes an array of numbers from stdin
it will then print out all possible words that could be made from the
letters on a phone numpad associated with those numbers.

Method:
- Map the numbers with associated letters
- Recursive function will try all the alphabets mapped to the current
digit in alphabetic order, and again call the recursive function for the
next digit, passing on current output string.

Afterwords the program allows you to play hangman, but entering keypad numbers
instead of letters
*/

public class numpad
{
	public static void main(String[] args)
	{

		Scanner in = new Scanner(System.in);
		System.out.print("Enter numbers (e.g. 123): ");

		while(!in.hasNextInt())
		{
			System.out.print("Please enter numbers: ");
			in.nextLine();  // Clear invalid input from scanner buffer.
		}

		String input = in.next();
		int length = input.length();
		int [] num_array = new int[length];  // allocating memory to array

		for(int i = 0; i < length; i += 1)
		{

			num_array[i] = Character.getNumericValue(input.charAt(i));  // convert the char to int and add it to the num_array
		}

		nums2letters(num_array, length);

		System.out.println("Starting Hangman...");
		hangman();

		in.close();  // Closing scanner so there's no memory leak.
	}

	public static void nums2letters(int[] num_array, int length)
	{
		rec_nums2letters(num_array, length, 0, ""); // curr_index and output have to be initialised to 0
		System.out.println(); // nums2letters doesn't print newline at the end
	}

	public static String rec_nums2letters(int[] num_array, int length, int curr_index, String output)
	{
		/* Approach of function:
		   -  Map the number with its string of possible letters, i.e., 2 with “abc”, 3 with
		   “def” etc.
		   - Extract the string at num_array[curr_index] from the Map,
		   - Run a loop to traverse the string from start to end
		   - For every index again call the recursive function with the output string
		   concatenated with the character of the string and the curr_index + 1.
		   - If the current index is equal to the length of the number array, then print the
		   output string.
		   */

		// map each number to their appropriate index for chars
		String[] map = {
			" ",
			" ", "abc", "def",
			"ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz"
		};

		// will be true once we have our 3 letters
		// we then print it out and return to break out of function
		if (curr_index == length){
			System.out.print(output + ' ');
			return output;
		}

		int digit = num_array[curr_index]; // which digit on the keypad we are on
		String letters = map[digit]; // what letters map to that digit
		int letters_length = letters.length();

		for (int i = 0; i < letters_length; i++){
			/* for each letter mapped to this digit, we add the letter to whatever the letter is at the next digit
			   once the function returns we then go to the next digit.
			   since the last digit will be at the top of the stack, i will increase for it first, and since
			   the last digit increases first to the next letter this preserves alphabetic order */
			rec_nums2letters(num_array, length, curr_index + 1, output + letters.charAt(i));
		}
		return output;
	}

	public static void hangman()
	{
		/* Approach of function:
		   - Map selected number and position to its letter, i.e, 2 selects the number 2 on a numpad,
		   followed by 1 selects the first letter a.
		   - Check if each guessed letter is in a randomly selected word using a loop going through
		   the word.
		   - The function selectWord() gets an element from the word list by selecting a random index.
		   - Player will have 7 attempts, an attempt will not be removed if the guess is correct.
		   - A string will output for each guess showing what letters have been found in the word, and
		   all guessed letters so far will be displayed as a string.
		   - If the player guesses wrong and has one less attempt, hangman ASCII art is displayed.
		   - The function getCount() will return how many letters in the word are correct. If this count matches
		   the length of the word the player has won.
		*/

		Scanner scanner = new Scanner(System.in);

		String[] hanged_man = {  // ASCII art for the hangman game.
			"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
			"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n",

		};

		String word = selectWord(); // select a random word from the word list

		String[] map = {
			" ",
			" ", "abc", "def",
			"ghi", "jkl", "mno",
			"pqrs", "tuv", "wxyz"
		};

		char[] correct_guess = new char[word.length()]; // keeps track of correct guesses
		int checkWrong = 0;

		System.out.print(hanged_man[0]);  // Starting hangman ASCII art.

		String letters = ""; // letters that have been guessed will output as a string

		for(int attempt = 0; attempt != 7; attempt++) // Player will have 7 attempts/guesses.
		{
			// Check if guess was wrong and output appropriate hangman ASCII art.
			if(checkWrong != attempt)
			{
				System.out.print(hanged_man[attempt]);
				System.out.println("Oops! Try again.\n");
			}

			checkWrong = attempt;

			System.out.println("You have " + (7 - attempt) + " guesses remaining");

			System.out.println("| 1        | 2 (abc)   | 3 (def)  |");
			System.out.println("|----------|-----------|----------|");
			System.out.println("| 4 (ghi)  | 5 (jkl)   | 6 (mno)  |");
			System.out.println("|----------|-----------|----------|");
			System.out.println("| 7 (pqrs) | 8 (tuv)   | 9 (wxyz) |");
			System.out.println("|----------|-----------|----------|");
			System.out.println("| \\*+      | 0 (space) | #        |");
			System.out.println();

			int guess_digit = 0;
			int guess_pos = 0;

			System.out.print("Enter a keypad number: ");

			// Checking for valid input.
			while(!scanner.hasNextInt())
			{
				System.out.print("Please enter a valid keypad number: ");
				scanner.nextLine();  // Clear invalid input from scanner buffer.
			}

			guess_digit = scanner.nextInt();

			while(guess_digit < 2 || guess_digit > 9)  // Checking if input is within the range.
			{
				System.out.print("Enter a value between 2 and 9: ");
				scanner.nextLine();
				guess_digit = scanner.nextInt();
			}


			scanner.nextLine();  // Clear invalid input from scanner buffer.

			System.out.print("Enter the amount of times it is pressed: ");

			// Checking for valid input.
			while(!scanner.hasNextInt())
			{
				System.out.print("Please enter a number: ");
				scanner.nextLine();  // Clear invalid input from scanner buffer.
			}

			guess_pos = scanner.nextInt();

			while(guess_pos > map[guess_digit].length())  // Making sure input is in the keypad's range.
			{
				System.out.print("Enter a value between 1 and " + map[guess_digit].length() + ": ");
				scanner.nextLine();  // Clear invalid input from scanner buffer.
				guess_pos = scanner.nextInt();
			}

			// For example: 7 followed by 4 would mean S

			char guess = map[guess_digit].charAt(guess_pos - 1);

			char checkDupe = '\0'; // we need to check for duplicate letters in the word

			// Building the output.
			for(int i = 0; i < word.length(); i++)
			{
				if(word.charAt(i) == guess) // check if the guessed letter is in the word
				{
					System.out.print(guess);
					correct_guess[i] = guess; // add to array of correct guesses
					if(checkDupe != guess) // check if the letter appears more than once in the word
					{
						attempt--;
					}
					checkDupe = guess;
				}
				else if(word.charAt(i) == correct_guess[i])
				{
					// this makes sure previous guesses will also be printed
					System.out.print(correct_guess[i]);
				}
				else
				{
					System.out.print("_");
				}
			}
			
			System.out.println();

			letters = letters + guess;
			System.out.println("Letters you've guessed: " + letters);

			int count = getCount(word, correct_guess); // count correct guesses
			if(count == word.length()) // compares number of correct guesses to the number of letters in the word
			{
				System.out.println("You did it!"); // you won
				break;
			}
		}

		System.out.println("The word was " + word);
		System.out.println("Thank you for playing!");

		scanner.close();
	}

	public static String selectWord() // gives us a word to guess
	{
		String[] words = {"stop", "crane", "trace", "rope", "java",
			"ant", "baboon", "badger", "bat", "bear", "beaver",
			"camel", "cat", "clam", "cobra", "cougar",
			"coyote", "crow", "deer", "dog", "donkey", "duck", "eagle", "ferret", "fox", "frog"}; // array of words that can appear in the game

		Random randnumber = new Random();
		int number = randnumber.nextInt(words.length); // picks a random word from the list

		return words[number];
	}

	public static int getCount(String word, char[] correct_guess) // we get our count of correct guesses
	{
		int count = 0;
		for(int i = 0; i < word.length(); i++)
		{
			if(correct_guess[i] == word.charAt(i)) // we increment guess count if guess is correct
			{
				count++;
			}
		}
		return count;
	}
}

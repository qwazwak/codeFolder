//Lab 06, Mastermind, by Rustan Hoffman and Rebecca Damewood

import java.util.List;
import java.util.Random;

public class MasterMindAIConsistent implements MasterMindAI {
	private MasterMind game;
	
	public MasterMindAIConsistent(MasterMind game) {
		this.game = game;
	}
	
	//DO THIS
	public Guess nextGuess(int guess_id) {
		List<Guess> guesses = game.getGuesses();
		Guess nextGuess = null;
		
		if (guesses.size() > 0) {
			
			Guess trialGuess = null;
			
			//keep obtaining a random guess until you get one that works with all previous results
			//it is cheating to keep obtaining a random guess until you match the solution make a random guess and then analyze it
			do {
				trialGuess = makeRandomGuess(guess_id);
			} while (!analyzeGuess(trialGuess));
			
			
			nextGuess = trialGuess; //found a good one
		} else {
			nextGuess = makeRandomGuess(guess_id);
		}
		
		return nextGuess;
	}
	
	//DO THIS
	//is the guess consistent with all previous results?
	//that is, if you compare your random guess to a previous guess, do you get the same number of black and white buttons?
	//don't just check your random guess against the secret guess until you get a good result
	private boolean analyzeGuess(Guess nextGuess) {
		List<Guess> guesses = game.getGuesses(); //get all previous guesses from the game
		
		//loop over all previous guesses
		//note that i is starting at 1!
		for (int i = 1; i < guesses.size(); i++) {
			//previous guess compared to the secret guess (obtain the int array through the game ref)
			
			//	int a = game.getResult(guesses.get(i - 1))[0];
			//	int b = game.getResult(guesses.get(i - 1))[1];
			Guess pastGuess = guesses.get(i - 1);
			int[] pastResult = game.getResult(pastGuess);
			
			
			//next guess is compared to previous guesses, NOT the secret guess
			
			int[] compOfNextGuess = game.getResult(pastGuess, nextGuess);
			
			//int c = game.getResult(nextGuess, guesses.get(i - 1))[0];
			//int d = game.getResult(nextGuess, guesses.get(i - 1))[1];
			
			
			//if our previous number of black buttons is not equal to the next number black buttons
			//or if our previous number of white buttons is not equal to the next number of white buttons return false
			if (pastResult[0] != compOfNextGuess[0] || pastResult[1] != compOfNextGuess[1]) {
				return false;
			}
		}
		
		return true;
	}
	
	
	
	//DO THIS
	//use the Random class to make a randomly generated guess
	private static Guess makeRandomGuess(int guess_id) {
		Guess randomGuess = new Guess(guess_id);
		Random rand = new Random();
		randomGuess.addGuess(1 + (rand.nextInt(7)));
		randomGuess.addGuess(1 + (rand.nextInt(7)));
		randomGuess.addGuess(1 + (rand.nextInt(7)));
		randomGuess.addGuess(1 + (rand.nextInt(7)));
		return randomGuess;
	}
}

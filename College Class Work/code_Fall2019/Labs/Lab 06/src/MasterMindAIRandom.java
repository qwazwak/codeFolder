//Lab 06, Mastermind, by Rustan Hoffman and Rebecca Damewood

import java.util.Random;
public class MasterMindAIRandom implements MasterMindAI {
	@SuppressWarnings("unused")
	private MasterMind game;
	private static Random rand;
	
	public MasterMindAIRandom(MasterMind game) {
		rand = new Random();
		this.game = game;		
	}
	
	public Guess nextGuess(int guess_id) {
		return makeRandomGuess(guess_id);
	}
	
	private static Guess makeRandomGuess(int guess_id) {
		Guess random_guess = new Guess(guess_id);
		//Generate a pseduo-random number from 1-8 and add that to the guesses
		random_guess.addGuess(1 + ( rand.nextInt(7)));
		random_guess.addGuess(1 + ( rand.nextInt(7)));
		random_guess.addGuess(1 + ( rand.nextInt(7)));
		random_guess.addGuess(1 + ( rand.nextInt(7)));
		return random_guess;
	}
}

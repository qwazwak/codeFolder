import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class MasterMindAIRandom implements MasterMindAI {
	private MasterMind game;
	
	public MasterMindAIRandom(MasterMind game) {
		this.game = game;
	}
	
	
	public Guess nextGuess(int guess_id) {
		return makeRandomGuess(guess_id);
	}
	
	private static Guess makeRandomGuess(int guess_id) {
		Guess random_guess = new Guess(guess_id);
		Random rand = new Random();
		for (int i = 1; i <= 4; i++) {
			//Generate a pseduo-random number from 1-8 and add that to the guesses
			random_guess.addGuess(1 + ( rand.nextInt(7)));
		}
		return random_guess;
	}
}

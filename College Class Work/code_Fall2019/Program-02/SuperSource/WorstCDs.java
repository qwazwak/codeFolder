import java.util.ArrayList;

public class WorstCDs implements Command {
	private ArrayList<CD> worst = new ArrayList<CD>();
	private int worst_rating = 10;

	public void execute(Object item) {
		CD cd = (CD) item;
		int rating = cd.getRating();

		if (rating == worst_rating) {
			// add the cd to the worst ArrayList
			worst.add(cd);

		} else if (rating < worst_rating) {
			// update worst_rating, instantiate worst to a new ArrayList, and then add the
			// cd
			worst_rating = cd.getRating();
			worst = new ArrayList<CD>();
			worst.add(cd);

		}
	}

	public ArrayList<CD> getWorstCDs() {
		return worst;
	}
}
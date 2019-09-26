import java.util.ArrayList;
import ki.KeyedItem;

public class TreeSortDriver {
	
	static Keyboard cin = Keyboard.getKeyboard();
	
	private static CD[] readMusic(String fileName) {
		//DO THIS complete this method using the FileIO class
		//create a new FileIO object for reading

		FileIO file = new FileIO(fileName, FileIO.FOR_READING);

		String str = file.readLine(); //the artist

		ArrayList<CD> cds = new ArrayList<CD>();
		
		while (false == file.EOF()) //while we are not at the end of the file
		{
			
			//file.readLine() will parse one line of the file at a time
			String title = file.readLine();
			int year = Integer.parseInt(file.readLine());
			int rating = Integer.parseInt(file.readLine());
			int numTracks = Integer.parseInt(file.readLine());
			CD cd = new CD(title, str, year, rating, numTracks);
			
			cds.add(cd);
			int tracks = 1;
			
			while (tracks <= numTracks) {
				String track_str = file.readLine();
				String[] pieces = track_str.split(","); //divide the string up into two pieces by splitting on a comma (use the String split method)
				String len = pieces[0];
				String songTitle = pieces[1];
				cd.addSong(songTitle, len);
				tracks++;
			}
			
			str = file.readLine();
		}
		
		
		//create a CD[] of the correct size (cds.size()) and populate it using a for-each statement
		CD[] cds_array = new CD[cds.size()];
		for (int i = 0; i < cds.size(); ++i) {
			cds_array[i] = cds.get(i);
		}
		
		
		
		
		return cds_array;
	}
	
	
	public static void main(String[] args) {
		CD[] cdArray = null;
		boolean filenameIsValid = false;
		String theFilename = new String("");
		while (filenameIsValid == false) {
			try {
				System.out.println("Enter the name of the archive: ");
				theFilename = cin.readString("");
				System.out.println("");
				cdArray = readMusic(theFilename);
				filenameIsValid = true;
			} catch (FileIOException e) {
				System.out.println("Invalid filename, try again");
			}
		}
		//use the Keyboard class, try-catch, and a while loop to continue calling readMusic 
		//until a valid file name is entered
		//as checked exceptions have been converted to unchecked exceptions, 
		//you must remember to do this with end user input, the compiler will not help you
		
CD[] sorted = null;
sorted = (CD[]) TreeSort.treeSort(cdArray);
		//once you have the array of CDs back from readMusic, sort them
		//and print them out to make sure that they are sorted
		for (int i = 0; i < sorted.length; ++i) {

			
			System.out.println(sorted[i].toString());
		}
	}
}

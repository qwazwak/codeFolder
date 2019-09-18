import java.util.ArrayList;
import java.util.List;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.Option.Builder;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.ParseException;

public class SudukoDriver {
	static List<List<List<Integer>>> theSquare;
	
	
	
	public static void main(String[] args) {
		
		CommandLine commandLine;
		Option option_file = Option.builder("F").required(false).desc("Suduko file to use").longOpt("opt3").build();
		Option option_debug = Option.builder("d").required(false).desc("The test option").longOpt("test").build();
		Options options = new Options();
		CommandLineParser parser = new DefaultParser();
				
		options.addOption(option_file);
		options.addOption(option_debug);
		
		try {
			commandLine = parser.parse(options, args);
			
			if (commandLine.hasOption("F")) {
				System.out.print("Option A is present.  The value is: ");
				System.out.println(commandLine.getOptionValue("A"));
			}
			
			if (commandLine.hasOption("d")) {
				System.out.println("Debug output is enabled	");
			}
			
			{
				String[] remainder = commandLine.getArgs();
				System.out.print("Remaining arguments: ");
				for (String argument : remainder) {
					System.out.print(argument);
					System.out.print(" ");
				}
				
				System.out.println();
			}
			
		} catch (ParseException exception) {
			System.out.print("Parse error: ");
			System.out.println(exception.getMessage());
		}
		
		
		theSquare = new ArrayList<>();
		for (int i = 0; i < 9; ++i) {
			theSquare.set(i, new ArrayList<>());
			for (int j = 0; j < 9; ++j) {
				theSquare.get(j).set(i, new ArrayList<>());
				for (int k = 0; k < 9; ++k) {
					theSquare.get(j).get(i).add(k);
				}
			}
		}
		
		
		
		// TODO Auto-generated method stub
		
	}
	
}

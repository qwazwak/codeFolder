//Work By Rustan Hoffman and Jonas Fornehed


import javax.lang.model.util.ElementScanner6;

public class Craps
{

   public static int playCraps(int num_rolls)
   {
      int result = 0;
      int numberOfResults = 0;

      CrapsDice dice = new CrapsDice(); 

      for(int i = 0; i <= num_rolls; i++)
      {
         result = dice.roll();

         if(result == 2 || result == 3 || result == 12)
            numberOfResults++;
      } 
	 
      return numberOfResults;
   }
   public static void main(String[] args)
   {
      int rolls = 752;
      int results = playCraps(rolls);
      double percentage = ((results + 0.0) / (rolls + 0.0)) * 100;

      System.out.println("You rolled 2, 3, and 12 " + results + " times.");
      System.out.println("That is " + percentage + " percent of the amount of times you rolled!");
   }

}
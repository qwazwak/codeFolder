//By Rustan Hoffman and Rebecca Damewood


//place this file in the ki subdirectory
package ki;

public abstract class KeyedItem
{
	//create private instance variable of type Comparable
	private Comparable theKey;
	
  
   public KeyedItem(Comparable key) 
   {
	 this.theKey = key;
	   
   }  

   public Comparable getKey() 
   {
	   return theKey;
	   
   }  

   //Use Comparable's toString() method
   public String toString()
   {
	   return theKey.toString();
   }
}
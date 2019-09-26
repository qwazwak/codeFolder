//By Rustan Hoffman and Rebecca Damewood

import java.util.Iterator;
import bst.*;
import ki.KeyedItem;

public class TreeSort
{
   //convenience method
   public static KeyedItem[] treeSort(KeyedItem[] sort)
   {
      //call below treeSort method, passing in sort and its size (use the java length variable to obtain n)
	  int n = sort.length;
	  return treeSort(sort, n);
	  
   }
   
   //easier to use a KeyedItem array than Comparable
   public static KeyedItem[] treeSort(KeyedItem[] sort, int n)
   {
	  //error checking 
      if (n > sort.length || n <= 0)
      {
         n = sort.length;
      }
	  
	  //create a new Binary Search Tree
      //a balanced tree ensures logn inserts for nlogn sort
	   
	  
      //need to use the Class class, because the actual array type may be a subtype of KeyedItem
      Class cls = sort.getClass().getComponentType();
      KeyedItem[] temp = (KeyedItem[]) java.lang.reflect.Array.newInstance(cls, n);
	  
	  
 
      // fill up the search tree
      BinarySearchTree tree = new BinarySearchTree (true, true);
	  for(int i = 0; i < n; ++i) {
		  tree.insert(sort[i]);
	  }
	  
	  
      //use a TreeIterator on your BST to call setInorder

	  TreeIterator itr = tree.iterator();
	  itr.setInorder();

      //pull sorted stuff out of the tree into temp
	  int uglyCounter = 0;
	  while(itr.hasNext())
	  {
		  temp[uglyCounter++] =  (KeyedItem) itr.next();  
	  }
	  
	  
	  return temp;
	  
   }
}


//Rustan Hoffman and Rebecca Damewood

public class Cone {
  private int typeofCone;
  public Cone(int coneTypeSetup){
    this.typeofCone = !(coneTypeSetup < 1 || coneTypeSetup > 3) ? coneTypeSetup : 3;
  }
  public double getPrice(){
    switch(this.typeofCone){
      case 1:
        return (double)0.59;
      case 2:
        return (double)0.79;
      case 3:
        return (double)0.0;
      default:
      return (double)-1;
    }
  }
  public String toString(){
    switch(this.typeofCone){
      case 1:
        return new String("Sugar Cone");
      case 2:
        return new String("Waffle Cone");
      case 3:
        return new String("Cup");
      default:
      return new String("error");
    }
  }
}

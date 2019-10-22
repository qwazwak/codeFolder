
public class RoboticWalk implements RoboticState{

	private final Robot robot;
	
	public RoboticWalk(Robot robot){
		this.robot = robot;
	}
	 
	@Override
	public void walk() {
		System.out.println("Already walking...");
		robot.setRoboticState(robot.getRoboticWalk());
	}

	@Override
	public void cook() {
		System.out.println("Can't cook while walking...");
		robot.setRoboticState(robot.getRoboticCook());
		System.out.println("Cooking I guess");
	}

	@Override
	public void off() {
		System.out.println("Cannot switched off while walking...");
		robot.setRoboticState(robot.getRoboticOff());
	}
}

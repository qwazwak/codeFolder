



public class Computer {
	
	//required parameters
	private String HDD;
	private String RAM;
	//required added parameters
	private int CPUCores;
	
	
	//optional parameters
	private boolean isGraphicsCardEnabled;
	private boolean isBluetoothEnabled;
	//optional added parameters
	private boolean isWifiEnabled;
	private boolean hasSimMulThread;
	private boolean isLanEnabled;
	private boolean hasWebcam;
	private boolean hasUSBThreePointZero;
	
	
	public String getHDD() {
		return HDD;
	}
	
	public String getRAM() {
		return RAM;
	}
	
	public int getCoreCount() {
		return this.CPUCores;
	}
	
	public boolean isGraphicsCardEnabled() {
		return isGraphicsCardEnabled;
	}
	
	public boolean isBluetoothEnabled() {
		return this.isBluetoothEnabled;
	}
	
	public boolean isWifiEnabled() {
		return this.isWifiEnabled;
	}
	
	public boolean isLanEnabled() {
		return this.hasSimMulThread;
	}
	
	public boolean isMultiThreading() {
		return this.isLanEnabled;
	}
	
	public boolean isWebcamEnabled() {
		return this.hasWebcam;
	}
	
	public boolean isThreePointZeroEnabled() {
		return this.hasUSBThreePointZero;
	}
	
	
	private Computer(ComputerBuilder builder) {
		this.HDD = builder.HDD;
		this.RAM = builder.RAM;
		this.CPUCores = builder.CPUCores;
		this.isGraphicsCardEnabled = builder.isGraphicsCardEnabled;
		this.isBluetoothEnabled = builder.isBluetoothEnabled;
		this.isWifiEnabled = builder.isWifiEnabled;
		this.isLanEnabled = builder.isLanEnabled;
		this.hasSimMulThread = builder.hasSimMulThread;
		this.hasWebcam = builder.hasWebcam;
		this.hasUSBThreePointZero = builder.hasUSBThreePointZero;
	}
	
	//Builder Class
	public static class ComputerBuilder {
		
		// required parameters
		private String HDD;
		private String RAM;
		//required added parameters
		private int CPUCores;
		
		
		//optional parameters
		private boolean isGraphicsCardEnabled;
		private boolean isBluetoothEnabled;
		//optional added parameters
		private boolean isWifiEnabled;
		private boolean isLanEnabled;
		private boolean hasSimMulThread;
		private boolean hasWebcam;
		private boolean hasUSBThreePointZero;
		
		
		public ComputerBuilder(String hdd, String ram, int coreCount) {
			this.HDD = hdd;
			this.RAM = ram;
			this.CPUCores = coreCount;
			//Continue for the other req params
		}
		
		public ComputerBuilder setGraphicsCardEnabled(boolean isGraphicsCardEnabled) {
			this.isGraphicsCardEnabled = isGraphicsCardEnabled;
			return this;
		}
		
		public ComputerBuilder setBluetoothEnabled(boolean isBluetoothEnabled) {
			this.isBluetoothEnabled = isBluetoothEnabled;
			return this;
		}
		
		public ComputerBuilder setWifiEnabled(boolean isWifiEnabled) {
			this.isWifiEnabled = isWifiEnabled;
			return this;
		}
		
		public ComputerBuilder setLanEnabled(boolean isLanEnabled) {
			this.isLanEnabled = isLanEnabled;
			return this;
		}
		
		public ComputerBuilder setMultiThreading(boolean hasMultiThreading) {
			this.hasSimMulThread = hasMultiThreading;
			return this;
		}
		
		public ComputerBuilder setWebcamEnabled(boolean hasWebcam) {
			this.hasWebcam = hasWebcam;
			return this;
		}
		
		public ComputerBuilder setThreePointZeroEnabled(boolean hasUSBThreePointZero) {
			this.hasUSBThreePointZero = hasUSBThreePointZero;
			return this;
		}
		
		public Computer build() {
			return new Computer(this);
		}
		
	}
	
}

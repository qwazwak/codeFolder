//import Computer.ComputerBuilder;

//package com.journaldev.design.test;


public class TestBuilderPattern {
	
	public static void main(String[] args) {
		//Using builder to get the object in a single line of code and 
		//without any inconsistent state or arguments management issues		
		Computer comp = new Computer.ComputerBuilder("500 GB", "2 GB", 8).setBluetoothEnabled(true).setGraphicsCardEnabled(false).setWifiEnabled(false).setLanEnabled(true).setMultiThreading(true).setWebcamEnabled(false).setThreePointZeroEnabled(false).build();
		
		
		
		System.out.println(comp.getHDD() + ", " + comp.getRAM() + ", " + comp.getCoreCount() + ", " + comp.isBluetoothEnabled() + ", " + comp.isGraphicsCardEnabled() + ", " +  comp.isWifiEnabled() + ", " +  comp.isLanEnabled() + ", " +  comp.isMultiThreading() + ", " +  comp.isWebcamEnabled() + ", " + comp.isThreePointZeroEnabled());
	}
}

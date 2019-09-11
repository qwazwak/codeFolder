package qCode;

import java.util.ArrayList;


public class MemoryTape {
	//Sets whether if attempting to move past the leftmost tape position will error or just not move
	boolean errorOnTapeBounds = true;
	//Keep track of the read/write position (0 indexed)
	long curPos = 0;
	ArrayList<Long> tape = new ArrayList<Long>();
	
	MemoryTape(){
		this.tape.add((long)0);
	}
	
	public void setPos(long position) {
		this.curPos = position;
	}
	
	public long getPos() {
		return this.curPos;
	}
	
	public void setVal(long value) {
		this.tape.set((int)this.curPos, value);
	}
	
	public long getVal() {
		return this.tape.get((int)this.curPos);
	}
	
	public void incVal() {
		this.tape.set((int)this.curPos, this.tape.get((int)this.curPos) + 1);
	}
	
	public void decVal() {
		this.tape.set((int)this.curPos, this.tape.get((int)this.curPos) - 1);
	}
	
	public void moveLeft() {
		if (this.curPos > 0) {
			--this.curPos;
		} else if(this.errorOnTapeBounds) {
			throw new NullPointerException("uhoh");
		}
	}
	
	public void moveRight() {
		++this.curPos;
		while(this.tape.size() <= this.curPos) {
			this.tape.add((long)0);
		}
	}	
}
package main;


import mathpaint.Complex;
import mathpaint.DrawXY;

public class Main {
	public static void main(String[] args){
		Complex test = new Complex(1, 2.5);
		test.iroot(4, 0);
		System.out.println("=========================================");
		System.out.println();
		test.iroot(4);
	}
}

package main;
import array.*;

public class Main {
	public static void main(String[] args) {
		double[] nArray = SimpleArray.erstelleFeld(5);
		SimpleArray.druckeFeld(nArray);
		System.out.println("=====================");
		System.out.println(SimpleArray.minElement(nArray));
		System.out.println("=====================");
		System.out.println(SimpleArray.maxElement(nArray));
		System.out.println("=====================");
		System.out.println(SimpleArray.berechneDurchschnitt(nArray));
		System.out.println("=====================");
		System.out.println(SimpleArray.bestimmeKleinstenAbstand(nArray));
		System.out.println("=====================");
		char[] bla = {'1','2','3'};
		System.out.println(SimpleArray.berechneQuersumme(bla));
		System.out.println("=====================");
		SimpleArray.sortArray(nArray);
	}
}

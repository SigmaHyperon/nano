package array;
//import java.math.*;

public class SimpleArray {

	public static double[] erstelleFeld (int laenge){
		double[] nArray = new double[laenge];
		for(int i =0; i < laenge; i++){
			nArray[i] = Math.random()*100;
		}
		return nArray;
	}
	public static double minElement (double feld[]){
		int minIndex = 0;
		for(int i = 0; i < feld.length; i++){
			if(feld[minIndex] > feld[i]){
				minIndex = i;
			}
		}
		return feld[minIndex];
	}
	 public static double maxElement(double feld[]){
		int maxIndex = 0;
		for(int i = 0; i < feld.length; i++){
			if(feld[maxIndex] < feld[i]){
				maxIndex = i;
			}
		}
		return feld[maxIndex];
	 }
	 public static void druckeFeld(double feld[]){
		 if(feld == null){
			 return;
		 }
		for(int i = 0; i < feld.length; i++){
			System.out.println(feld[i]);
		}
	 }
	 public static double berechneDurchschnitt(double feld[]){
		double sum = 0;
		for(int i = 0; i < feld.length; i++){
			sum += feld[i];
		}
		return sum/feld.length;
	 }
	 public static double bestimmeKleinstenAbstand(double feld[]){
		double minDistance = Math.abs(feld[1]-feld[0]);
		for(int i = 2; i < feld.length; i++){
			if(Math.abs(feld[i]-feld[i-1]) < minDistance){
				minDistance = Math.abs(feld[i] - feld[i-1]);
			}
		}
		return minDistance;
	 }
	 public static int berechneQuersumme(char zahl[]){
		 int sum = 0;
		 for(int i = 0; i < zahl.length; i++){
			 sum += zahl[i]-'0';
		 }
		 return sum;
	 }
	 public static void sortArray(double feld[]){
		 for(int k = 1; k < feld.length; k++){
			 for(int l = 1; l < feld.length; l++){
				 if(feld[l] < feld[l-1]){
					 double cache = feld[l];
					 feld[l] = feld[l-1];
					 feld[l-1] = cache;
				 }
			 }
		 }
		 druckeFeld(feld);
	 }
}

package main;
import matrix.*;

public class Main {
	public static void main(String[] args) {
		int a[][] = MatrixTools.createMatrix(2, 5);
		int b[][] = MatrixTools.createMatrix(5, 2);
		MatrixTools.printMatrix(a);
		MatrixTools.printMatrix(b);
		System.out.println("==================");
		MatrixTools.printMatrix(MatrixTools.matrixMul(a, b));
	}
}

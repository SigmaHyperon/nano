package matrix;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

import exception.InvalidMatrixException;
import exception.MatricesNotMultipliableException;
import exception.MatrixNotInitializedException;
import exception.MatrixSpurNotAvailableException;

import java.util.Scanner;

public class MatrixTools {
	public static int[][] createMatrix(int m, int n){
		if(m <= 0 || n <= 0) return null;
		int[][] nMatrix = new int[m][n];
		for(int k = 0; k < nMatrix.length; k++){
			for(int l = 0; l < nMatrix[k].length; l++){
				nMatrix[k][l] = (int)(Math.random()*10+1);
			}
		}
		return nMatrix;
	}
	public static void printMatrix(int[][] m){
		try{
			for(int k = 0; k < m.length; k++){
				for(int l = 0; l < m[k].length; l++){
					System.out.print(m[k][l]);
					System.out.print(" ");
				}
				System.out.println();
			}
		}catch(Exception e){
			System.out.println("null");
		}
	}
	public static int[][] getTransposedMatrix(int[][] m){
		try{
			int [][] nArray = createMatrix(m[0].length, m.length);
			for(int k = 0; k < m.length; k++){
				for(int l = 0; l < m[0].length; l++){
					nArray[l][k] = m[k][l];
				}
			}
			return nArray;
		}catch(Exception e){
			return null;
		}
		
	}
	public static boolean isSymmetric(int[][] m){
		try{
			if(!isSquare(m)) return false;
			for(int k = 0; k < m.length-1; k++){
				for(int l = k + 1; l < m[0].length; l++){
					if(m[k][l] != m[l][k]) return false;
				}
			}
			return true;
		}catch(Exception e){
			return false;
		}
	}
	public static boolean isEven(int[][] m){
		try{
			for(int k = 1; k < m.length; k++){
				if(m[k].length != m[k-1].length) return false;
			}
			return true;
		}catch(Exception e){
			return false;
		}
	}
	public static boolean isSquare(int[][] m){
		try{
			if(!isEven(m)) return false;
			if(m.length == m[0].length) return true;
			return false;
		}catch(Exception e){
			return false;
		}
	}
	public static int matrixSpur(int[][] matrix) throws InvalidMatrixException, MatrixNotInitializedException, MatrixSpurNotAvailableException{
		MatrixDimension aD = new MatrixDimension(matrix);
		if(aD.getWidth() != aD.getHeight()) throw new MatrixSpurNotAvailableException("matrix not square");
		int sum = 0;
		for(int k = 0; k < matrix.length; k++) sum += matrix[k][k];
		return sum;
	}
	public static int[][] matrixMul(int[][] a, int[][] b) throws InvalidMatrixException, MatricesNotMultipliableException, MatrixNotInitializedException{

		//if(!isEven(a) || !isEven(b)) return null;
		MatrixDimension aD = new MatrixDimension(a);
		MatrixDimension bD = new MatrixDimension(b);
		if(aD.getWidth() != bD.getHeight()) throw new MatricesNotMultipliableException("width a "+aD.getWidth()+" does not match height b "+bD.getHeight());
		try{
			int[][] nMatrix = createMatrix(a.length, b[0].length);
			for(int k = 0; k < nMatrix.length; k++){
				for(int l = 0; l < nMatrix[0].length; l++){
					int sum = 0;
					for(int o = 0; o < a[0].length; o++){
						sum += a[k][o] * b[o][l];
					}
					nMatrix[k][l] = sum;
				}
			}
			return nMatrix;
		}catch(Exception e){
			System.out.println("mmull");
			return null;
		}
	}
	public static boolean matrixCompare(int[][] a, int[][] b){
		try{
			if(a.length != b.length) return false;
			for(int i = 0; i < a.length; i++){
				if(a[i].length != b[i].length) return false;
				for(int l = 0; l < a[i].length; l++){
					if(a[i][l] != b[i][l]) return false;
				}
			}
			return true;
		}catch(Exception e){
			return false;
		}
	}
	public static int[][] getMatrixFromFile(String filename) throws IOException{
		File file = new File(filename);
		Scanner scan = new Scanner(file);
		int linecount = 0;
		while (scan.hasNextLine()){
			linecount++;
			scan.nextLine();
		}
		int[][] matrix = new int[linecount][];
		int index = 0;
		scan.reset();
		while(scan.hasNextLine()){
			String[] line = scan.nextLine().split(" ");
			for (int i = 0; i < line.length; i++){
				matrix[index][i] = Integer.parseInt(line[i]);
			}
			index++;
		}
		scan.close();
		return matrix;
	}
}

package matrix;
import exception.*;

public class MatrixDimension {
	private int height;
	private int width;
	public MatrixDimension(int[][] matrix) throws MatrixNotInitializedException, InvalidMatrixException{
		if(matrix == null) throw new MatrixNotInitializedException("Matrix not initialized");
		if(matrix.length == 0) throw new InvalidMatrixException("Matrix has no elements");
		for(int i = 0; i < matrix.length; i++){
			if(matrix[i] == null) throw new MatrixNotInitializedException("Line "+i+" is not initialized");
			if(matrix[i].length == 0) throw new InvalidMatrixException("Line "+i+" has no elements");
			if(matrix[i].length != matrix[0].length) throw new InvalidMatrixException("Line "+i+" has an invalid number of elements: "+matrix[i].length);
		}
		this.height = matrix.length;
		this.width = matrix[0].length;
	}
	
	public int getWidth(){
		return this.width;
	}
	public int getHeight(){
		return this.height;
	}
}

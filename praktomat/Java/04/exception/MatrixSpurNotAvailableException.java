package exception;

public class MatrixSpurNotAvailableException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = -393764207942356886L;
	private static final String errMsg = "Matrixspur not available";
	public MatrixSpurNotAvailableException(){
		super(errMsg);
	}
	public MatrixSpurNotAvailableException(String msg){
		super(errMsg + ":" + msg);
	}
}

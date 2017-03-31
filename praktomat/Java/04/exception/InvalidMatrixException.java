package exception;

public class InvalidMatrixException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 8309772035685097658L;
	private static final String errMsg = "Invalid matrix";
	public InvalidMatrixException() {
		super(errMsg);
	}
	public InvalidMatrixException(String msg) {
		super(errMsg + ":" + msg);
	}

}

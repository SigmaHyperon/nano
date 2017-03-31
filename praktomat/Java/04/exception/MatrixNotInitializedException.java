package exception;

//TODO
public class MatrixNotInitializedException extends Exception{

	/**
	 * 
	 */
	private static final long serialVersionUID = -9098627608315804632L;
	private static final String errMsg = "Matrix not initialised";
	public MatrixNotInitializedException(){
		super(errMsg);
	}
	public MatrixNotInitializedException(String msg) {
		super(errMsg + ":" + msg);
	}

}

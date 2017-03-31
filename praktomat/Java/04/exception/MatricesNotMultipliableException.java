package exception;

public class MatricesNotMultipliableException extends Exception{

	/**
	 * 
	 */
	private static final long serialVersionUID = -5800790363052543658L;
	private static final String errMsg = "Matrix not multipliable";
	public MatricesNotMultipliableException(){
		super(errMsg);
	}
	public MatricesNotMultipliableException(String msg){
		super(errMsg + ":" + msg);
	}

}

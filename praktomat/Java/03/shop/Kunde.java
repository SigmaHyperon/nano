package shop;

public class Kunde {
	String name;
	Warenkorb wkorb;
	public Kunde(String name){
		this.name = name;
		wkorb = new Warenkorb();
	}
	public Warenkorb getWkorb(){
		return this.wkorb;
	}
	public String getName(){
		return this.name;
	}
	public void kauft(Artikel a){
		this.wkorb.add(a);
	}
	public double bezahlt(){
		return 0.0;
	}
}

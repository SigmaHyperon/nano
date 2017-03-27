package shop;

public class Artikel {
	public String bezeichnung;
	public double preis;
	
	public Artikel(String bezeichnung, double preis){
		this.bezeichnung = bezeichnung;
		this.preis = preis;
	}
	public String getBezeichnung(){
		return this.bezeichnung;
	}
	public double getPreis(){
		return this.preis;
	}
}

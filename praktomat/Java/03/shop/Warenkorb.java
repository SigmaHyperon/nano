package shop;

public class Warenkorb {
	private int anzahl;
	private Artikel artfeld[];
	
	public Warenkorb(){
		this.anzahl = 0;
		this.artfeld = new Artikel[100];
	}
	
	public void add(Artikel a){
		if(this.anzahl < 100 && a != null)
		{
			this.artfeld[this.anzahl++] = a;
		}
	}
	public double getSumme(){
		double sum = 0;
		for(int i = 0; i < this.anzahl; i++){
			sum += this.artfeld[i].getPreis();
		}
		if(sum > 100){
			return sum;
		} else if (sum >= 30) {
			return sum * 1.03;
		} else if (sum >= 10) {
			return sum + 4;
		} else {
			return sum + 6;
		}
	}
	public int getAnzahl(){
		return this.anzahl;
	}
	public void remove(Artikel a){
		for(int i = 0; i < this.anzahl; i++){
			if(this.artfeld[i].getBezeichnung() == a.getBezeichnung() && this.artfeld[i].getPreis() == a.getPreis()){
				this.artfeld[i] = this.artfeld[--this.anzahl];
				this.artfeld[this.anzahl] = null;
				i--;
			}
		}
	}
}

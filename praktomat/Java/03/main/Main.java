package main;
import shop.*;

public class Main {
	public static void main(String[] args){
		Kunde i = new Kunde("Hans");
		i.kauft(new Artikel("Haus", 199.99));
		i.kauft(new Artikel("bla", 199.99));
		i.kauft(new Artikel("Haus", 199.99));
		i.kauft(new Artikel("Haus", 199.99));
		i.kauft(new Artikel("stuff", 199.99));
		i.getWkorb().remove(new Artikel("bla", 199.99));
		
	}
}

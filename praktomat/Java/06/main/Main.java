package main;

import gui.MyGUI;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args){
		List<String> blacklist = new ArrayList<String>();
		blacklist.add("idiot");
		blacklist.add("Depp");
		blacklist.add("haLLO");
		MyGUI test = new MyGUI(blacklist);
		//new MyGUI();
	}
}

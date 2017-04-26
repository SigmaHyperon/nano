package gui;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class MyGUI extends Frame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	TextArea text;
	List<String> blacklist;
	public MyGUI(){
		super();
		this.init();
		this.pack();
		this.setVisible(true);
	}
	public MyGUI(List<String> blacklist){
		super();
		this.init();
		this.setSize(600,300);
		if(blacklist == null){
			blacklist = new ArrayList<String>();
		}
		this.blacklist = blacklist;
		GridBagConstraints c = new GridBagConstraints();
		Button btnCensor = new Button("BTN_CENSOR");
		btnCensor.setName("BTN_CENSOR");
		btnCensor.setLabel("censor");
		btnCensor.addActionListener(this);
		c.fill = GridBagConstraints.HORIZONTAL;
		c.gridx = 1;
		c.gridy = 3;
		this.add(btnCensor, c);
		this.pack();
		this.setVisible(true);
	}
	public void init(){
		this.setSize(600 ,260);
		this.setLocationRelativeTo(null);
		this.setLayout(new GridBagLayout());
		
		text = new TextArea("TXTAREA");
		Button btnLower = new Button("BTN_TOLOWER");
		Button btnUpper = new Button("BTN_TOUPPER");
		Button btnSwap = new Button("BTN_SWAP");
		
		GridBagConstraints c = new GridBagConstraints();
		
		
		text.setText("Poi");
		text.setName("TXTAREA");
		c.fill = GridBagConstraints.BOTH;
		c.weightx = 10;
		c.weighty = 10;
		c.gridheight = 8;
		c.gridx = 0;
		c.gridy = 0;
		this.add(text, c);
		
		btnUpper.setName("BTN_TOUPPER");
		btnUpper.setLabel("toUpper");
		btnUpper.addActionListener(this);
		c.fill = GridBagConstraints.BOTH;
		c.weightx = 1;
		c.weighty = 1;
		c.gridheight = 1;
		//c.ipady = 0;
		c.ipadx = 70;
		c.gridx = 1;
		c.gridy = 0;
		this.add(btnUpper, c);
		
		btnSwap.setName("BTN_SWAP");
		btnSwap.setLabel("swap");
		btnSwap.addActionListener(this);
		c.fill = GridBagConstraints.BOTH;
		c.gridx = 1;
		c.gridy = 1;
		this.add(btnSwap, c);
		
		btnLower.setName("BTN_TOLOWER");
		btnLower.setLabel("toLower");
		btnLower.addActionListener(this);
		c.fill = GridBagConstraints.BOTH;
		c.gridx = 1;
		c.gridy = 2;
		this.add(btnLower, c);
		
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent event) {
				setVisible(false);
				dispose();
			}

			public void windowClosed(WindowEvent event) {
				System.exit(0);
			}
		});
	}
	public void toUpper(TextArea target){
		target.setText(target.getText().toUpperCase());
	}
	public void toLower(TextArea target){
		target.setText(target.getText().toLowerCase());
	}
	public void swap(TextArea target){
		char[] c = target.getText().toCharArray();
		for(int i = 0; i < c.length; i++){
			if(Character.isUpperCase(c[i])){
				c[i] = Character.toLowerCase(c[i]);
			} else if(Character.isLowerCase(c[i])){
				c[i] = Character.toUpperCase(c[i]);
			}
		}
		target.setText(new String(c));
	}
	public void censor(TextArea target){
		String text = target.getText();
		Iterator<String> it = this.blacklist.iterator();
		while(it.hasNext()){
			String badWord = it.next().toLowerCase();
			text = text.replaceAll("(?i)"+badWord, badWord.replaceAll(".", "x"));
		}
		target.setText(text);
	}
	public void actionPerformed(ActionEvent e){
		switch (e.getActionCommand()) {
		case "toUpper":
			this.toUpper(text);
			break;
		case "toLower":
			this.toLower(text);
			break;
		case "swap":
			this.swap(text);
			break;
		case "censor":
			this.censor(text);
			break;
		default:
			break;
		}
	}
}

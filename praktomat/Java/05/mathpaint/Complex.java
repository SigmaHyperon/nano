package mathpaint;

import math.graph.XYPunkt;

public class Complex implements XYPunkt{
	private double real;
	private double imag;
	public Complex(double real, double imag){
		this.real = real;
		this.imag = imag;
	}
	public double getX(){
		return this.real;
	}
	public double getY(){
		return this.imag;
	}
	public double getAbs(){
		return Math.sqrt(Math.pow(this.real, 2)+Math.pow(this.imag, 2));
	}
	public double getPhi(){
		return Math.atan2(this.imag, this.real);
	}
	public void setPolar(double radius, double phi){
		this.real = radius*Math.cos(phi);
		this.imag = radius*Math.sin(phi);
	}
	public Complex[] iroot(int n){
		if(n < 1) return null;
		Complex[] result = new Complex[n];
		for(int i = 0; i < n; i++){
			result[i] = new Complex(0, 0);
			result[i].setPolar(Math.pow(this.getAbs(), 1.0/n), (this.getPhi()+2*i*Math.PI)/n);
			result[i].print();
			System.out.println();
		}
		return result;
	}
	public Complex[] iroot(int root, int k){
		if(root <= 0){
			return null;
		}
		double tmpAbs = 0;
		double tmpPhi = 0;
		Complex[] roots = new Complex[root];
		for(int i = 0; i < root; i++){
			tmpPhi = (getPhi()+2*i*Math.PI)/(double) root;
			tmpAbs = Math.pow(Math.abs(getAbs()), 1/(double) root);
			roots[i] = new Complex(tmpAbs*Math.cos(tmpPhi), tmpAbs*Math.sin(tmpPhi));
			roots[i].print();
			System.out.println();
		}
		return roots;
	}
	public void print(){
		System.out.println(this.real+" "+this.imag);
		System.out.println(this.getAbs()+" "+this.getPhi());
	}
}

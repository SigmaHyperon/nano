package mathpaint;
import java.util.Random;

public class DrawXY {
	public static Punkt[] drawSinus(double schrittweite){
		if(schrittweite <= 0 || schrittweite >= Math.PI) return null;
		int max = (int)Math.floor(2*Math.PI / schrittweite);
		Punkt[] graph = new Punkt[max+1];
		for(int i = 0; i <= max; i++){
			graph[i] = new Punkt(i*schrittweite, Math.sin(i*schrittweite));
		}
		return graph;
	}
	public static Punkt[] drawRandomVerteilung(int max, int count){
		Punkt[] result = new Punkt[max+1];
		for(int i = 0; i < max+1; i++){
			result[i] = new Punkt(i, 0);
		}
		Random random = new Random();
		for(int i = 0; i < count; i++){
			int index = random.nextInt(max+1);
			result[index].setY(result[index].getY()+1);
		}
		return result;
	}
}

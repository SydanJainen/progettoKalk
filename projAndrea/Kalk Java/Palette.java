import java.util.Vector;

public class Palette implements ColorGroup {
	private int size;
	private Vector<Color> colori;
	
	public Palette(){
		size=0;
	}
	
	public Palette(int dim){
		size=dim;
		for(int i=0;i<dim;i++){
			colori.add(new Color());
		}
	}
	
	public Palette(int dim , Color c){
		size=dim;
		for(int i=0;i<size;i++){
			colori.add(c);
		}
	}
	
	public Palette(Palette c){
		size=c.size;
		colori=new Vector<Color>();
		for(int i=0;i<size;i++){
			colori.add(c.colori.get(i));
		}
	}
	
	public void opacity(int valore) {
		for(int i=0;i<size;i++){
			colori.get(i).setOpacity(valore);
		}
	}
	
	public void add(Color colore) {
		for(int i=0;i<size;i++){
			colori.get(i).add(colore);
		}
	}
	
	public void fill(Color colore) {
		for(int i=0;i<size;i++){
			colori.add(i, colore);
		}
	}
	
	public void sostituisci(int i , Color c){
		colori.add(i, c);
	}

	public void complementare() {
		for(int i=0;i<size;i++){
			colori.get(i).Complementare();
		}
	}

	public void findReplace(Color cerca , Color sostituisci) {
		for(int i=0;i<size;i++){
			if(colori.get(i).equals(cerca)){
				colori.add(i, sostituisci);
			}
		}
	}

	public void desat() {
		for(int i=0;i<size;i++){
			colori.get(i).Desaturazione();
		}
	}
	
	public void rimuovi(){
		size--;
		colori.remove(colori.size()-1);
	}
	
	public void inserisci(Color agg){
		size++;
		colori.add(agg);
	}
	
	public int returnIndexMax(){
		int maxLocale =0;
		for(int i=0;i<size;i++){
			if(colori.get(i).maggiore(colori.get(maxLocale))){
				maxLocale=i;
			}
		}
		return maxLocale;
	}
	
	public int returnIndexMin(){
		int minLocale =0;
		for(int i=0;i<size;i++){
			if(colori.get(i).minore(colori.get(minLocale))){
				minLocale=i;
			}
		}
		return minLocale;
	}
	
	public int getRedFrom(int i){
		return colori.get(i).getRed();
	}
	
	public int getGreenFrom(int i){
		return colori.get(i).getGreen();
	}
	
	public int getBlueFrom(int i){
		return colori.get(i).getBlue();
	}
	
	public int getOpacityFrom(int i){
		return colori.get(i).getOpacity();
	}
	
	public void setRedFrom(int i,int c){
		colori.get(i).setRed(c);
	}
	
	public void setGreenFrom(int i,int c){
		 colori.get(i).setGreen(c);
	}
	
	public void setBlueFrom(int i,int c){
		 colori.get(i).setBlue(c);
	}
	
	public void setOpacityFrom(int i,int c){
		 colori.get(i).setOpacity(c);
	}
	@Override
	public String toString(){
		String s="Colore: ";
		for(int i=0;i<size;i++){
			s=s+colori.get(i).toString();
			s=s+" Colore: ";
		}
		return s;
	}
}

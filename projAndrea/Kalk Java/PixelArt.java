
public class PixelArt implements ColorGroup {
	
	int n ,m;
	Color[][] griglia;
	
	public PixelArt(){
		n=0;
		m=0;
	}
	
	public PixelArt(int dim){
		n=dim;
		m=dim;
		griglia = new Color[n][m];
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				griglia[i][j]=new Color(255);
			}
		}
	}
	
	public PixelArt(int dim, Color f){
		n=dim;
		m=dim;
		griglia = new Color[n][m];
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				griglia[i][j]=f;
			}
		}
	}
	
	public PixelArt(int dim, int dim2){
		n=dim;
		m=dim2;
		griglia = new Color[n][m];
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				griglia[i][j]=new Color(255);
			}
		}
	}
	
	public PixelArt(int dim, int dim2 , Color f){
		n=dim;
		m=dim2;
		griglia = new Color[n][m];
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				griglia[i][j]=f;
			}
		}
	}
	
	public PixelArt(PixelArt f){
		n=f.n;
		m=f.m;
		griglia=new Color[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				griglia[i][j]=f.griglia[i][j];
			}
		}
	}
	
	public void addColore(Color c , int a ,int b){
		griglia[a][b]=c;
	}
	
	public void scabiaOrizz(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m/2;j++){
				Color appoggio = griglia[i][j];
				griglia[i][j]=griglia[i][m-1-j];
				griglia[i][m-1-j]=appoggio;
			}
		}
	}
	
	public void scabiaVert(){
		for(int i=0;i<n/2;i++){
			for(int j=0;j<m;j++){
				Color appoggio = griglia[i][j];
				griglia[i][j]=griglia[n-1-i][j];
				griglia[n-1-i][j]=appoggio;
			}
		}
	}
	
	
	public boolean isSimmetricoX(){
		for(int i=0;i<n/2;i++){
			for(int j=0;j<m;j++){
				if(griglia[i][j].notEquals(griglia[i][m-j-1])){
					return false;
				}
			}
		}
		return true;
	}
	
	public boolean isSimmetricoY(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m/2;j++){
				if(griglia[i][j].notEquals(griglia[n-1-i][j])){
					return false;
				}
			}
		}
		return true;
	}
	
	public int getN(){
		return n;
	}
	
	public int getM(){
		return m;
	}
	
	public Color getElement(int i, int j){
		return griglia[i][j];
	}

	public void opacity(int valore) {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				griglia[i][j].setOpacity(valore);
			}
		}
	}

	public void add(Color colore) {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				griglia[i][j]=griglia[i][j].add(colore);
			}
		}
	}

	public void complementare() {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				griglia[i][j]=griglia[i][j].Complementare();
			}
		}
	}

	public void findReplace(Color cerca, Color sostituisci) {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(griglia[i][j].equals(cerca)){
					griglia[i][j]=sostituisci;
				}
			}
		}
	}

	public void desat() {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				griglia[i][j]=griglia[i][j].Desaturazione();
			}
		}
	}
	
	public String toString(){
		String s="Colore: \n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				s=s+"("+i+","+j+")-> "+griglia[i][j].toString()+" ";
			}
			s=s+"\n";
		}
		return s;
	}

}


public class ImgSpeculare extends PixelArt{
	boolean oriz,vert;
	
	public ImgSpeculare(){
		super();
		oriz=true;
		vert=true;
	}
	
	public ImgSpeculare(PixelArt val){
		super(val);
		if(val.isSimmetricoX() && val.isSimmetricoY()){
			oriz=true;
			vert=true;
		}else if(val.isSimmetricoX()){
			vert=true;
			oriz=false;
		}else if(val.isSimmetricoY()){
			vert=false;
			oriz=true;
		}else{
			throw new IllegalArgumentException();
		}
	}
	
	public ImgSpeculare(ImgSpeculare val){
		super(val);
		if(val.isSimmetricoX() && val.isSimmetricoY()){
			oriz=true;
			vert=true;
		}else if(val.isSimmetricoX()){
			vert=true;
			oriz=false;
		}else if(val.isSimmetricoY()){
			vert=false;
			oriz=true;
		}else{
			throw new IllegalArgumentException();
		}
	}
	
	public void flipY(){
		if(!vert){
			for(int i=0;i<getN();i++){
				for(int j=0;j<getM()/2;j++){
					if(!(getElement(i,j).equals(getElement(i,getM()-j-1)))){
						super.addColore(getElement(i,j),i,getM()-j-1);
					}
				}
			}
		}
	}
	
	public void flipX(){
		if(!oriz){
			for(int i=0;i<getN()/2;i++){
				for(int j=0;j<getM();j++){
					if(!(getElement(i,j).equals(getElement(getN()-1-i,j)))){
						super.addColore(getElement(i,j),getN()-1-i,j);
					}
				}
			}
		}
	}
	
	public void addColore(Color a,int b , int c){
		super.addColore(a, b, c);
		if(oriz && vert){
			super.addColore(a, getN()-1-b, getM()-1-c);
		}
		if(vert){
			super.addColore(a, b, getM()-1-c);
		}
		if(oriz){
			super.addColore(a, getN()-1-b, c);
		}
	}
	
	public String toString(){
		String s=super.toString();
		s=s+" oriz: "+oriz+" vert: "+vert;
		return s;
	}
}

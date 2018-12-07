import java.util.Vector;


public class Color {
	private int r, g, b, a;
    private double[] fattore = new double[3];

    private static int hexconverter(char x,  char y){
    	int a=0, b=0, i = 0;
    	char[] index;
    	index = new char []{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E','F'};
    	boolean bo = true;
	    while(bo){
	        if(x==index[i]){
	            a=i;
	            bo=false;
	            i=0;
	        }else{
	            i++;
	        }
	    }

    	bo = true;

	    while(bo){
	        if(y==index[i]){
	            b=i;
	            bo=false;
	        }else{
	            i++;
	        }
	    }

    	return (a*(16))+(b);
    }

    private static boolean compare (double primo,  double secondo){
    	double epsilonpos = 0.000001;
	    double epsilonneg = -epsilonpos;
	    double result = primo - secondo;
	    if(result>epsilonneg && result<epsilonpos){
	        return true;
	    }
	    else if(result<0 && result>epsilonneg){
	        return true;
	    }
	    return false;
    }


    public Color(){
    	r=255;
	    g=255;
	    b=255;
	    a=255;
	    fattore[0] = 0.299;
	    fattore[1] = 0.587;
	    fattore[2] = 0.114;
    }

    public Color(int x){
    	r=g=b=x;
    	a=255;
    	fattore[0] = 0.299;
    	fattore[1] = 0.587;
    	fattore[2] = 0.114;
    }

    public Color(int red, int green, int blue){
    	r=red;
	    g=green;
	    b=blue;
	    a=255;
	    fattore[0] = 0.299;
	    fattore[1] = 0.587;
	    fattore[2] = 0.114;
    }

    public Color(int red, int green, int blue, int opacity){
    	this(red,green,blue);
	    a=opacity;
	    
    }

    public Color(Color x){
    	fattore[0] = x.fattore[0];
	    fattore[1] = x.fattore[1];
	    fattore[2] = x.fattore[2];
	    r=x.r;
	    g=x.g;
	    b=x.b;
	    a=x.a;
    }

    public void setOpacity(int opacity){
    	a=opacity;
    }

    public void setRed(int red){
    	r=red;
    }

    public void setGreen(int green){
    	g=green;
    }

    public void setBlue(int blue){
    	b=blue;
    }

    public int getOpacity(){
    	return a;
    }

    public int getRed(){
    	return r;
    }

    public int getGreen(){
    	return g;
    }

    public int getBlue(){
    	return b;
    }

    public Vector<Double> toHSV(){
    	Vector<Double> ritorno = new Vector <Double>();
	    double H = 0;
	    double S = 0;
	    double V = 0;
	    double maxRGB;
	    double minRGB;
	    double delta;
	    double erre = (double) r/255;
	    double gi = (double) g/255;
	    double bi = (double) b/255;

	    minRGB = Math.min(erre,Math.min(gi,bi));

	    maxRGB = Math.max(erre,Math.max(gi,bi));

	    delta = maxRGB-minRGB;

	    if(compare(delta, 0)==true){
	        H=0.0;
	    }
	    else{
	        if(compare(maxRGB, erre)==true){
	           H = 60* (((gi-bi)/delta)% 6);
	        }
	        else if(compare (maxRGB, gi)==true){
	            H = 60* (((bi-erre)/delta)+ 2.0);
	        }
	        else if(compare (maxRGB, bi)==true){
	            H = 60* (((erre-gi)/delta)+ 4.0);
	        }
	    }

	    if(compare(maxRGB, 0)==true){
	        S = 0;
	    }
	    else{
	        S = (delta)/maxRGB;
	    }

	    V = maxRGB;

	    ritorno.add(H);
	    ritorno.add(S);
	    ritorno.add(V);
	    return ritorno;
    }

    public static Color HSVtoRGB(Vector <Double> hsv){
	    double H = hsv.get(0);
	    double S = hsv.get(1);
	    double V = hsv.get(2);
	    double C = V*S;
	    double div = 60.0;
	    double positive;
	    if((((H / div)% 2) - 1)>0){
	        positive = (((H / div)% 2) - 1);
	    }
	    else{
	        positive = -(((H / div)% 2) - 1);
	    }
	    double X = C * (1 - positive);
	    double M = V-C;
	    double var_r = 0, var_g = 0, var_b = 0;

	    if(0<=H && H<60){
	        var_r = C;
	        var_g = X;
	        var_b = 0;
	    }
	    else if(60<=H && H<120){
	        var_r = X;
	        var_g = C;
	        var_b = 0;
	    }
	    else if(120<=H && H<180){
	        var_r = 0;
	        var_g = C;
	        var_b = X;
	    }
	    else if(180<=H && H<240){
	        var_r = 0;
	        var_g = X;
	        var_b = C;
	    }
	    else if(240<=H && H<300){
	        var_r = X;
	        var_g = 0;
	        var_b = C;
	    }
	    else if(300<=H && H<360){
	        var_r = C;
	        var_g = 0;
	        var_b = X;
	    }

       Color ritorno = new Color((int)(var_r+M) * 255, (int)(var_g+M) * 255, (int)(var_b+M) * 255, 255);
       return  ritorno;
	}

	public String toHEX(){
		char[] index;
		index = new char []{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E','F'};
	    int unor = (r/16)%16;
	    int duer = r%16;
	    int unog = (g/16)%16;
	    int dueg = g%16;
	    int unob = (b/16)%16;
	    int dueb = b%16;
	    String HEX = ""+index[unor]+index[duer]+index[unog]+index[dueg]+index[unob]+index[dueb];
	    return HEX;
	}

	public static Color HEXtoRGB(char[] hex){
		Color ritorno = new Color((hexconverter(hex[1], hex[2])), (hexconverter(hex[3], hex[4])), (hexconverter(hex[5], hex[6])), 255);
	    return ritorno;
	}

	public Color Complementare(){
		Vector<Double> HSV = new Vector<Double>();
		HSV = toHSV();
	    double primo = HSV.get(0);
	    primo+=180.0;
	    HSV.set(0, primo);
	    HSV.set(0, (HSV.get(0) %  360) );
	    Color ritorno= new Color( HSVtoRGB(HSV));
	    return ritorno;
	}

	public static Color wavelength(int londa){
		double attenuation;
	    double gamma = 0.8;
	    double R, G, B;

	    if (londa >= 380 && londa < 440) {
		    attenuation = 0.3 + 0.7 * (londa - 380) / (440 - 380);//da qui devi sistemare la funzione pow
		    R = Math.pow(((-(double)(londa - 440) / (double)(440 - 380)) * attenuation) , gamma);
		    G = 0.0;
		    B = Math.pow((1.0 * attenuation) , gamma);
	    }
	    else if (londa >= 440 && londa < 490) {
		    R = 0.0;
		    G = Math.pow(((double)(londa - 440) / (double)(490 - 440)) , gamma);
		    B = 1.0;
	    }
	    else if (londa >= 490 && londa < 510) {
		    R = 0.0;
		    G = 1.0;
		    B = Math.pow((-(double)(londa - 510) / (double)(510 - 490)) , gamma);
	    }
	    else if (londa >= 510 && londa < 580) {
		    R = Math.pow(((double)(londa - 510) / (double)(580 - 510)) , gamma);
		    G = 1.0;
		    B = 0.0;
	    }
	    else if (londa >= 580 && londa < 645) {
		    R = 1.0;
		    G = Math.pow((-(double)(londa - 645) / (double)(645 - 580)) , gamma);
		    B = 0.0;
	    }
	    else if (londa >= 645 && londa < 750) {
		    attenuation = 0.3 + 0.7 * (double)(750 - londa) / (double)(750 - 645);
		    R = Math.pow((1.0 * attenuation) , gamma);
		    G = 0.0;
		    B = 0.0;
	    }
	    else {
		    R = 0.0;
		    G = 0.0;
		    B = 0.0;
	    }
	    R = R * 255;
	    G = G * 255;
	    B = B * 255;
	    Color ritorno= new Color((int) R, (int) G, (int) B, 255);
	    return ritorno;
	}

	public Vector<Color> Analogo (int gradi){//di norma gradi 30 è l'analogo standard, ha senso di esistere anche con altri valori
		Vector<Double> hsv = new Vector <Double>();
		hsv = toHSV(); //converto il colore di invocazione in hsv
	    Vector<Double> hsv1 = new Vector <Double>();
	    hsv1 = hsv; //creo una vector di appoggio che modifico in relazione di hsv
	    double gr = ((double)gradi%360); //controllo per evitare che i gradi non siano normalizzati
	    Vector<Color> coloriAnaloghi = new Vector <Color> ();//la vector che ritorno alla fine
	    coloriAnaloghi.add(this);//inserisce una copia di this
	    //ho la creazione di 5 colori HSV con 5 H diverse (H, H+gr, H-gr, H+2gr, H-2gr)
	    if((hsv.get(0)+gr) > 360){
	        hsv1.set(0, hsv.get(0)+gr-360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }
	    else if((hsv.get(0)+gr) < 0){
	        hsv1.set(0, hsv.get(0)+gr+360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else{
	        hsv1.set(0, hsv.get(0)+gr);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    if(hsv.get(0)-gr > 360){
	        hsv1.set(0, hsv.get(0)-gr-360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else if(hsv.get(0)-gr < 0){
	        hsv1.set(0, hsv.get(0)-gr+360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else{
	        hsv1.set(0, hsv.get(0)-gr);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }
	    if(hsv.get(0)+2*gr > 360){
	        hsv1.set(0,hsv.get(0)+2*gr-360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else if(hsv.get(0)+2*gr < 0){
	        hsv1.set(0,hsv.get(0)+2*gr+360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else{
	        hsv1.set(0,hsv.get(0)+2*gr);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    if(hsv.get(0)-2*gr > 360){
	        hsv1.set(0,hsv.get(0)-2*gr-360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else if(hsv.get(0)-2*gr < 0){
	        hsv1.set(0,hsv.get(0)-2*gr+360);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    else{
	        hsv1.set(0,hsv.get(0)-2*gr);
	        coloriAnaloghi.add((HSVtoRGB(hsv1)));
	    }

	    return coloriAnaloghi;
	}

	public Vector<Color> Triade (){
		Vector<Color> coloriTriade = new Vector <Color>();
	    coloriTriade = Analogo(120);
	    coloriTriade.removeElementAt(coloriTriade.size()-1);
	    coloriTriade.removeElementAt(coloriTriade.size()-1);
	    return coloriTriade;
	}

	public Vector<Color> Tetrade(){
		Vector<Color> coloriTetrade = new Vector <Color>();
	    coloriTetrade = Analogo(90);
	    coloriTetrade.removeElementAt(coloriTetrade.size()-1);
	    return coloriTetrade;
	}

	public Color Desaturazione(){
		Color ritorno = new Color((int)(r*fattore[0]),(int)(g*fattore[1]),(int)(b*fattore[2]),255);
    	return ritorno;
	}
	
	public boolean equals(Color secondo){
		if(r==secondo.r && g==secondo.g && b==secondo.b && a==secondo.a){
			return true;
		}
		return false;
	}
	
	public boolean notEquals(Color secondo){
		if(r==secondo.r && g==secondo.g && b==secondo.b && a==secondo.a){
			return false;
		}
		return true;
	}
	
	public boolean minore(Color secondo){
		Vector <Double> hsv1 = new Vector <Double>();
		Vector <Double> hsv2 = new Vector <Double>();
		hsv1 = toHSV();
		hsv2 = secondo.toHSV();
		if(hsv1.get(2)<hsv2.get(2)){
			return true;
		}
		return false;
	}
	
	public boolean maggiore(Color secondo){
		Vector <Double> hsv1 = new Vector <Double>();
		Vector <Double> hsv2 = new Vector <Double>();
		hsv1 = toHSV();
		hsv2 = secondo.toHSV();
		if(hsv1.get(2)<hsv2.get(2)){
			return false;
		}
		return true;
	}
	
	public Color add(Color secondo){
		int red, green, blue;
		if(r+secondo.r>255){
			red=255;
		}
		else{
			red= r+secondo.r;
		}
		if(g+secondo.g>255){
			green=255;
		}
		else{
			green= g+secondo.g;
		}
		if(b+secondo.b>255){
			blue=255;
		}
		else{
			blue= b+secondo.b;
		}
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	public Color sub(Color secondo){
		int red, green, blue;
		if(r<secondo.r){
			red=0;
		}
		else{
			red= r-secondo.r;
		}
		if(g<secondo.g){
			green=0;
		}
		else{
			green= g-secondo.g;
		}
		if(b<secondo.b){
			blue=255;
		}
		else{
			blue= b-secondo.b;
		}
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	public Color mult(Color secondo){
		int red, green, blue;
		if(r*secondo.r>255){
			red=255;
		}
		else{
			red= r*secondo.r;
		}
		if(g*secondo.g>255){
			green=255;
		}
		else{
			green= g*secondo.g;
		}
		if(b*secondo.b>255){
			blue=255;
		}
		else{
			blue= b*secondo.b;
		}
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	public Color mult(int secondo){
		int red, green, blue;
		if(r*secondo>255){
			red=255;
		}
		else{
			red= r*secondo;
		}
		if(g*secondo>255){
			green=255;
		}
		else{
			green= g*secondo;
		}
		if(b*secondo>255){
			blue=255;
		}
		else{
			blue= b*secondo;
		}
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	public Color div(int secondo){
		if(secondo==0){
			throw new IllegalArgumentException("division by zero is not a good idea");
		}
		int red, green, blue;
		red=r/secondo;
		green=g/secondo;
		blue=b/secondo;
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	public Color div(Color secondo){
		if(secondo.r==0 || secondo.g==0 || secondo.b==0){
			throw new IllegalArgumentException("division by zero on r or g or b is not a good idea");
		}
		int red, green, blue;
		red=r/secondo.r;
		green=g/secondo.g;
		blue=b/secondo.b;
		Color ritorno = new Color(red, green, blue, 255);
		return ritorno;
	}
	
	@Override
	public String toString(){
		String s = "(" + r + ", " + g + ", " + b + ")";
		return s;
	}
}

	


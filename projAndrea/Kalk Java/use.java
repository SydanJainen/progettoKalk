
public class use {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Color a = new Color();
		Color b = new Color(10, 10, 10, 255);
		Color c = a.sub(b);
		System.out.println(c.toString());
		c =c.add(new Color(5));
		System.out.println(c.toString());
		PixelArt g= new PixelArt(5,new Color(20,130,2));
		g.add(new Color(30));
		System.out.println(g.toString());
		PixelArt h= new PixelArt(6,new Color(20,10,190));
		ImgSpeculare j= new ImgSpeculare(h);
		System.out.println(g.toString());
		System.out.println(j.toString());
		ImgSpeculare f= new ImgSpeculare();
		System.out.println(f.toString());
	}

}


import java.awt.Graphics;
import java.awt.Frame;

public class HelloFrame extends Frame {
	HelloFrame(String s) {
		super(s);
	}

	public void init() {
		resize(200,60);
	}

	public void paint(Graphics g) {
		g.drawString("Hello, you!",60,45);
	}

	public static void main(String args[]) {
		System.out.println("entering main...");
		HelloFrame f = new HelloFrame("HelloFrame");
		f.init();
		f.show();

		System.out.println("..leaving main");
	}


}


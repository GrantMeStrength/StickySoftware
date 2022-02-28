import java.applet.*;
import java.awt.*;
import jp2Frame;

public class jp2 extends Applet
{
	// STANDALONE APPLICATION SUPPORT:
	//		m_fStandAlone will be set to true if applet is run standalone
	//--------------------------------------------------------------------------
	private boolean m_fStandAlone = false;

	public static void main(String args[])
	{
		jp2Frame frame = new jp2Frame("jp2");

		// Must show Frame before we size it so insets() will return valid values
		//----------------------------------------------------------------------
		frame.show();
        frame.hide();
		frame.resize(frame.insets().left + frame.insets().right  + 640,
					 frame.insets().top  + frame.insets().bottom + 480);

		jp2 applet_jp2 = new jp2();

		frame.add("Center", applet_jp2);
		applet_jp2.m_fStandAlone = true;
		applet_jp2.init();
		applet_jp2.start();
        frame.show();
	}

	public jp2()
	{
	}

	public String getAppletInfo()
	{
		return "Name: jp2\r\n" +
		       "Author: John Kennedy\r\n" +
		       "Created with Microsoft Visual J++ Version 1.1";
	}


	public void init()
	{
		//add("Center","Plop");
		Panel p = new Panel();
		p.add(new Button("1"));
		p.add(new Button("2"));
		p.add(new Button("3"));
		p.add(new Button("4"));
		p.add(new Dialog(p,"4"));
		add(p);

		


	   	resize(400,400);

	}

	public void destroy()
	{
	}

	
	public void paint(Graphics g)
	{
		//g.drawString(" J++ Version 1.1", 10, 20);

		//g.drawRect(64,64,128,128);

	
		//resize(400,400);
		show();


	}

	public void start()
	{
	}
	
	public void stop()
	{
	}



}

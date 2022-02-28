//******************************************************************************
// johnjava.java:	Applet
//
//******************************************************************************
import java.applet.*;
import java.awt.*;
import johnjavaFrame;

//==============================================================================
// Main Class for applet johnjava
//
//==============================================================================
public class johnjava extends Applet
{
	// STANDALONE APPLICATION SUPPORT:
	//		m_fStandAlone will be set to true if applet is run standalone
	//--------------------------------------------------------------------------
	private boolean m_fStandAlone = false;

	// STANDALONE APPLICATION SUPPORT
	// 	The main() method acts as the applet's entry point when it is run
	// as a standalone application. It is ignored if the applet is run from
	// within an HTML page.
	//--------------------------------------------------------------------------
	public static void main(String args[])
	{
		// Create Toplevel Window to contain applet johnjava
		//----------------------------------------------------------------------
		johnjavaFrame frame = new johnjavaFrame("johnjava");

		// Must show Frame before we size it so insets() will return valid values
		//----------------------------------------------------------------------
		frame.show();
        frame.hide();
		frame.resize(frame.insets().left + frame.insets().right  + 320,
					 frame.insets().top  + frame.insets().bottom + 240);

		// The following code starts the applet running within the frame window.
		// It also calls GetParameters() to retrieve parameter values from the
		// command line, and sets m_fStandAlone to true to prevent init() from
		// trying to get them from the HTML page.
		//----------------------------------------------------------------------
		johnjava applet_johnjava = new johnjava();

		frame.add("Center", applet_johnjava);
		applet_johnjava.m_fStandAlone = true;
		applet_johnjava.init();
		applet_johnjava.start();
        frame.show();
	}

	// johnjava Class Constructor
	//--------------------------------------------------------------------------
	public johnjava()
	{
		// TODO: Add constructor code here
	}

	// APPLET INFO SUPPORT:
	//		The getAppletInfo() method returns a string describing the applet's
	// author, copyright date, or miscellaneous information.
    //--------------------------------------------------------------------------
	public String getAppletInfo()
	{
		return "Name: johnjava\r\n" +
		       "Author: John Kennedy\r\n" +
		       "Created with Microsoft Visual J++ Version 1.1";
	}


	// The init() method is called by the AWT when an applet is first loaded or
	// reloaded.  Override this method to perform whatever initialization your
	// applet needs, such as initializing data structures, loading images or
	// fonts, creating frame windows, setting the layout manager, or adding UI
	// components.
    //--------------------------------------------------------------------------
	public void init()
	{
        // If you use a ResourceWizard-generated "control creator" class to
        // arrange controls in your applet, you may want to call its
        // CreateControls() method from within this method. Remove the following
        // call to resize() before adding the call to CreateControls();
        // CreateControls() does its own resizing.
        //----------------------------------------------------------------------
    	resize(320, 240);

		// TODO: Place additional initialization code here
	}

	// Place additional applet clean up code here.  destroy() is called when
	// when you applet is terminating and being unloaded.
	//-------------------------------------------------------------------------
	public void destroy()
	{
		// TODO: Place applet cleanup code here
	}

	// johnjava Paint Handler
	//--------------------------------------------------------------------------
	public void paint(Graphics g)
	{
		g.drawString("Created with Microsoft Visual J++ Version 1.1", 10, 20);
		g.drawString("Wohoo! My first Java Program!",20,40);
	}

	//		The start() method is called when the page containing the applet
	// first appears on the screen. The AppletWizard's initial implementation
	// of this method starts execution of the applet's thread.
	//--------------------------------------------------------------------------
	public void start()
	{
		// TODO: Place additional applet start code here
	}
	
	//		The stop() method is called when the page containing the applet is
	// no longer on the screen. The AppletWizard's initial implementation of
	// this method stops execution of the applet's thread.
	//--------------------------------------------------------------------------
	public void stop()
	{
	}


	// MOUSE SUPPORT:
	//		The mouseDown() method is called if the mouse button is pressed
	// while the mouse cursor is over the applet's portion of the screen.
	//--------------------------------------------------------------------------
	public boolean mouseDown(Event evt, int x, int y)
	{
		// TODO: Place applet mouseDown code here
		return true;
	}

	// MOUSE SUPPORT:
	//		The mouseUp() method is called if the mouse button is released
	// while the mouse cursor is over the applet's portion of the screen.
	//--------------------------------------------------------------------------
	public boolean mouseUp(Event evt, int x, int y)
	{
		// TODO: Place applet mouseUp code here
		return true;
	}


	// TODO: Place additional applet code here

}

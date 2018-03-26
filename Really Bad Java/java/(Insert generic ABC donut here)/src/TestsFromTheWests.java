import javax.swing.*;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;


public abstract class TestsFromTheWests
    implements KeyListener
    {
		  public static void main(String[] args)
		  {
			  //initSpace();
			  //while (true)
			  //keyTyped(KeyEvent.KEY_TYPED);
			  //test();
		  }
		  
		  private static void keyTyped(int keyTyped) {
			  if (keyTyped == KeyEvent.VK_LEFT)
			  {
				  System.out.println("left");
			  }
			  
			  if (keyTyped == KeyEvent.VK_RIGHT)
			  {
				  System.out.println("right");
			  }
			 
			  if (keyTyped == KeyEvent.VK_UP)
			  {
				  System.out.println("up");
			  }
			  
			  if (keyTyped == KeyEvent.VK_DOWN)
			  {
				  System.out.println("down");
			  }
		}

		public static void initSpace()
		  {
			  boolean isDone = false;
			  int height=100, width=100;
			    JFrame frame = new JFrame("TestsFromTheWests.exe");
			    frame.setVisible(true);
			    frame.setSize(width, height);
			    frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
			    for (int extra = 0; extra < 900; extra++)
			    {	
			    	frame.setSize(width+extra, height+extra);
			    	frame.setLocation((1980/2)-((width+extra)/2), (1080/2)-((height+extra)/2));
			    }
			    isDone = true;
				frame.setVisible(true);
		  }
		  
		public static void rekSpace() {
		
		//Space Remover 3000
		String s = "This is a Long Drive for Someone with Nothing to Think About.";
		final String BLANK = " ";
		String str = "";
		String temp;
		for (int i = 0; i < s.length(); i++)
		{
			temp = s.substring(i,i+1);
			if(!(temp.equals(BLANK)))
				str+=temp;
		}
		System.out.println(str);
		}
		
		public static void test() {
			int tr = 0, fa = 0;
			for (int k = 1; k <= 100; k++)
			{
				int n1 = (int) (Math.random() * 10);
				int n2 = (int) (Math.random() * 10);
				boolean bool = (n1 == n2);
				if (bool)
				{
					tr++;
				}
				else
				{
					fa++;
				}
			}
			System.out.println(tr + " " + fa);
		}
	}



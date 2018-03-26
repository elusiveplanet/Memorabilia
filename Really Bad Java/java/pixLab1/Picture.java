import java.awt.*;
import java.awt.font.*;
import java.awt.geom.*;
import java.awt.image.BufferedImage;
import java.text.*;
import java.util.*;
import java.util.List; // resolves problem with java.awt.List and java.util.List

/**
 * A class that represents a picture.  This class inherits from 
 * SimplePicture and allows the student to add functionality to
 * the Picture class.  
 * 
 * @author Barbara Ericson ericson@cc.gatech.edu
 */
public class Picture extends SimplePicture 
{
  ///////////////////// constructors //////////////////////////////////
  
  /**
   * Constructor that takes no arguments 
   */
  public Picture ()
  {
    /* not needed but use it to show students the implicit call to super()
     * child constructors always call a parent constructor 
     */
    super();  
  }
  
  /**
   * Constructor that takes a file name and creates the picture 
   * @param fileName the name of the file to create the picture from
   */
  public Picture(String fileName)
  {
    // let the parent class handle this fileName
    super(fileName);
  }
  
  /**
   * Constructor that takes the width and height
   * @param height the height of the desired picture
   * @param width the width of the desired picture
   */
  public Picture(int height, int width)
  {
    // let the parent class handle this width and height
    super(width,height);
  }
  
  /**
   * Constructor that takes a picture and creates a 
   * copy of that picture
   * @param copyPicture the picture to copy
   */
  public Picture(Picture copyPicture)
  {
    // let the parent class do the copy
    super(copyPicture);
  }
  
  /**
   * Constructor that takes a buffered image
   * @param image the buffered image to use
   */
  public Picture(BufferedImage image)
  {
    super(image);
  }
  
  ////////////////////// methods ///////////////////////////////////////
  
  /**
   * Method to return a string with information about this picture.
   * @return a string with information about the picture such as fileName,
   * height and width.
   */
  public String toString()
  {
    String output = "Picture, filename " + getFileName() + 
      " height " + getHeight() 
      + " width " + getWidth();
    return output;
    
  }
  
  /** Method to set the blue to 0 */
  public void zeroBlue()
  {
    Pixel[][] pixels = this.getPixels2D();
    for (Pixel[] rowArray : pixels)
    {
      for (Pixel pixelObj : rowArray)
      {
        pixelObj.setBlue(0);
      }
    }
  }
  
  public void zeroRed()
  {
    Pixel[][] pixels = this.getPixels2D();
    for (Pixel[] rowArray : pixels)
    {
      for (Pixel pixelObj : rowArray)
      {
        pixelObj.setRed(0);
      }
    }
  }
  
  public void keepOnlyBlue()  
  {
	Pixel[][] pixels = this.getPixels2D();
	for (Pixel[] rowArray : pixels)
		for (Pixel pixelObj : rowArray)
			if (pixelObj.getRed() > 0 || pixelObj.getGreen() > 0)
				pixelObj.setColor(new Color(0,0,pixelObj.getBlue()));
  }
  
  public void negate()  
  {
	Pixel[][] pixels = this.getPixels2D();
	for (Pixel[] rowArray : pixels)
		for (Pixel pixelObj : rowArray)
			pixelObj.setColor(new Color(255-pixelObj.getRed(),
										255-pixelObj.getGreen(),
										255-pixelObj.getBlue()));
  }
  
  public void grayscale()  
  {
	Pixel[][] pixels = this.getPixels2D();
	for (Pixel[] rowArray : pixels)
		for (Pixel pixelObj : rowArray)
		{
			int div = (pixelObj.getRed() + pixelObj.getGreen() + pixelObj.getBlue()) / 3;
			pixelObj.setColor(new Color(div,
										div,
										div));
		}
  }
  
  public void fixUnderwater()  
  {
	Pixel[][] pixels = this.getPixels2D();
	for (Pixel[] rowArray : pixels)
		for (Pixel pixelObj : rowArray)
		{
			pixelObj.setColor(new Color(regulate((pixelObj.getRed() * 11) / 3),
										regulate(((pixelObj.getGreen() * 11) / 16)),
										regulate(((pixelObj.getBlue() * 11) / 16))));
		}
  }
  
  public int regulate(int val)
  {
	  if (val >= 0 && val <= 255)
		  return val;
	  else if (val > 255)
		  return regulate(val - 255);
	  else if (val < 0)
		  return regulate(val + 255);
	  return val;
  }
  
  /** Method that mirrors the picture around a 
    * vertical mirror in the center of the picture
    * from left to right */
  public void mirrorVertical()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < width / 2; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[row][width - 1 - col];
        rightPixel.setColor(leftPixel.getColor());
      }
    } 
  }
  
  public void mirrorVerticalRightToLeft()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = width / 2; col > 0 ; col--)
      {
        rightPixel = pixels[row][col];
        leftPixel = pixels[row][width - 1 - col];
        rightPixel.setColor(leftPixel.getColor());
      }
    } 
  }
  
  public void mirrorHorizontal()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < width; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[pixels.length - 1 - row][col];
        rightPixel.setColor(leftPixel.getColor());
      }
    } 
  }
  
  public void mirrorHorizontalBotToTop()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < width; col++)
      {
        rightPixel = pixels[row][col];
        leftPixel = pixels[pixels.length - 1 - row][col];
        rightPixel.setColor(leftPixel.getColor());
      }
    } 
  }
  
  public void mirrorDiagonal()
  {
	  Pixel[][] pixels = this.getPixels2D();
	  Pixel leftPixel = null;
	  Pixel rightPixel = null;
	  int width = pixels[0].length;
	    for (int row = 0; row < pixels.length; row++)
	    {
	      for (int col = 0; col < width; col++)
	      {
	    	  if (col < pixels.length) {
	    		  leftPixel = pixels[row][col];
	    	  	  rightPixel = pixels[col][row];
	    	  	  leftPixel.setColor(rightPixel.getColor());
	    	  }
	      }
	    }
  }
  
  /** Mirror just part of a picture of a temple */
  public void mirrorTemple()
  {
    int mirrorPoint = 276;
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    // loop through the rows
    for (int row = 27; row < 97; row++)
    {
      // loop from 13 to just before the mirror point
      for (int col = 13; col < mirrorPoint; col++)
      {
        
        leftPixel = pixels[row][col];      
        rightPixel = pixels[row]                       
                         [mirrorPoint - col + mirrorPoint];
        rightPixel.setColor(leftPixel.getColor());
        count++;
      }
    }
    System.out.println(count);
  }
  
  public void mirrorArms()
  {
    int mirrorPoint = 195;
    Pixel topPixel = null;
    Pixel botPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    // loop through the rows
    for (int row = 155; row < 195; row++)
    {
      // loop from 13 to just before the mirror point
      for (int col = 105; col < 170; col++)
      {
        
        topPixel = pixels[row][col];      
        botPixel = pixels[195 + (195 - row)][col];
        botPixel.setColor(topPixel.getColor());
        count++;
      }
    }
    for (int row = 170; row < 195; row++)
    {
      // loop from 13 to just before the mirror point
      for (int col = 238; col < 295; col++)
      {
        
        topPixel = pixels[row][col];      
        botPixel = pixels[195 + (195 - row)][col];
        botPixel.setColor(topPixel.getColor());
        count++;
      }
    }
    
    System.out.println(count);
  }
  
  public void mirrorGull()
  {
    Pixel topPixel = null;
    Pixel botPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    // loop through the rows
    for (int row = 235; row < 323; row++)
    {
      // loop from 13 to just before the mirror point
      for (int col = 238; col < 345; col++)
      {
        
        topPixel = pixels[row][col];      
        botPixel = pixels[row][col + (345/3)];
        botPixel.setColor(topPixel.getColor());
        count++;
      }
    }
  }
  
  /** copy from the passed fromPic to the
    * specified startRow and startCol in the
    * current picture
    * @param fromPic the picture to copy from
    * @param startRow the start row to copy to
    * @param startCol the start col to copy to
    */
  public void copy(Picture fromPic, 
                 int startRow, int startCol)
  {
    Pixel fromPixel = null;
    Pixel toPixel = null;
    Pixel[][] toPixels = this.getPixels2D();
    Pixel[][] fromPixels = fromPic.getPixels2D();
    for (int fromRow = 0, toRow = startRow; 
         fromRow < fromPixels.length &&
         toRow < toPixels.length; 
         fromRow++, toRow++)
    {
      for (int fromCol = 0, toCol = startCol; 
           fromCol < fromPixels[0].length &&
           toCol < toPixels[0].length;  
           fromCol++, toCol++)
      {
        fromPixel = fromPixels[fromRow][fromCol];
        toPixel = toPixels[toRow][toCol];
        toPixel.setColor(fromPixel.getColor());
      }
    }   
  }

  public void copy2(Picture fromPic, 
          int startRow, int startCol,
          int endRow,   int endCol)
	{
	Pixel fromPixel = null;
	Pixel toPixel = null;
	Pixel[][] toPixels = this.getPixels2D();
	Pixel[][] fromPixels = fromPic.getPixels2D();
	for (int fromRow = 0, toRow = startRow; 
	  fromRow < fromPixels.length &&
	  toRow < endRow; 
	  fromRow++, toRow++)
	{
		for (int fromCol = 0, toCol = startCol; 
		    fromCol < fromPixels[0].length &&
		    toCol < endCol;  
		    fromCol++, toCol++)
			{
			 fromPixel = fromPixels[fromRow][fromCol];
			 toPixel = toPixels[fromRow][fromCol];
			 toPixel.setColor(fromPixel.getColor());
			}
	}   
}
  
  /** Method to create a collage of several pictures */
  public void createCollage()
  {
    Picture flower1 = new Picture("flower1.jpg");
    Picture flower2 = new Picture("flower2.jpg");
    //this.copy(flower1,0,0);
    this.copy(flower2,100,0);
    this.copy(flower1,200,0);
    Picture flowerNoBlue = new Picture(flower2);
    flowerNoBlue.zeroBlue();
    this.copy(flowerNoBlue,300,0);
    this.copy2(flower1,400,0,500,50);
    this.copy2(flower2,500,0,600,50);
    this.mirrorVertical();
    //this.write("collage.jpg");
  }
  
  /** Method to create a collage of several pictures */
  public void createMyCollage()
  {
    Picture bot1 = new Picture("robot.jpg");
    Picture arch1 = new Picture("arch.jpg");
    this.copy(bot1,0,0);
    this.copy2(arch1,400,0,800,100);
    this.copy2(bot1,500,0,900,100);
    this.copy(arch1,100,0);
    Picture noRed = new Picture(arch1);
    noRed.zeroRed();
    this.copy(noRed,300,0);
    Picture bot2 = new Picture(bot1);
    bot2.zeroBlue();
    bot2.mirrorHorizontal();
    this.copy(bot2,200,0);
    this.mirrorVertical();
    //this.write("collage.jpg");
  }
  
  
  /** Method to show large changes in color 
    * @param edgeDist the distance for finding edges
    */
  public void edgeDetection(int edgeDist)
  {
    Pixel leftPixel  = null;
    Pixel rightPixel = null;
    Pixel botPixel   = null;
    Pixel[][] pixels = this.getPixels2D();
    Color rightColor = null;
    Color botColor  = null;
    for (int row = 0; row < pixels.length-1; row++)
    {
      for (int col = 0; 
           col < pixels[0].length-1; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[row][col+1];
        botPixel   = pixels[row+1][col];
        rightColor = rightPixel.getColor();
        botColor   = botPixel.getColor();
        if (leftPixel.colorDistance(rightColor) > 
            edgeDist || leftPixel.colorDistance(botColor) > 
            edgeDist)
          leftPixel.setColor(Color.BLACK);
        else
          leftPixel.setColor(Color.WHITE);
      }
    }
  }
  
  
  /* Main method for testing - each class in Java can have a main 
   * method 
   */
  public static void main(String[] args) 
  {
    Picture beach = new Picture("beach.jpg");
    beach.explore();
    beach.zeroBlue();
    beach.explore();
  }

} // this } is the end of class Picture, put all new methods before this

import java.io.File; 
import java.io.IOException; 
import java.awt.image.BufferedImage; 
import javax.imageio.ImageIO; 
  
public class Negative 
{ 
    public static void main(String args[])throws IOException 
    { 
        BufferedImage img = null; 
        File f = null; 
  
        // read image 
        try
        { 
            f = new File("G:\\Inp.jpg"); 
            img = ImageIO.read(f); 
        } 
        catch(IOException e) 
        { 
            System.out.println(e); 
        } 
  
        // Get image width and height 
        int width = img.getWidth(); 
        int height = img.getHeight(); 
  
        // Convert to negative 
        for (int y = 0; y < height; y++) 
        { 
            for (int x = 0; x < width; x++) 
            { 
                int p = img.getRGB(x,y); 
                int a = (p>>24)&0xff; 
                int r = (p>>16)&0xff; 
                int g = (p>>8)&0xff; 
                int b = p&0xff; 
  
                //subtract RGB from 255 
                r = 255 - r; 
                g = 255 - g; 
                b = 255 - b; 
  
                //set new RGB value 
                p = (a<<24) | (r<<16) | (g<<8) | b; 
                img.setRGB(x, y, p); 
            } 
        } 
  
        // write image 
        try
        { 
            f = new File("G:\\Out.jpg"); 
            ImageIO.write(img, "jpg", f); 
        } 
        catch(IOException e) 
        { 
            System.out.println(e); 
        } 
    } 
} 

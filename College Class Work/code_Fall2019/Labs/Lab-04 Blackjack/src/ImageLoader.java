import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Image;
import java.awt.Toolkit;

// 
// Decompiled by Procyon v0.5.36
// 

public class ImageLoader
{
    private static ImageLoader il;
    private Toolkit toolkit;
    
    private ImageLoader() {
        this.toolkit = Toolkit.getDefaultToolkit();
    }
    
    public static ImageLoader getImageLoader() {
        return ImageLoader.il;
    }
    
    public Image getImage(final String name) {
        name.length();
        Image image = null;
        try {
            image = this.toolkit.createImage(ImageIO.read(this.getClass().getResource(name)).getSource());
        }
        catch (IOException ex) {}
        return image;
    }
    
    static {
        ImageLoader.il = new ImageLoader();
    }
}
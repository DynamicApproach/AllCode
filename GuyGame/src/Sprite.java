import javafx.animation.KeyFrame;
import javafx.animation.Timeline;

/**
 *
 *
 *

 //https://stackoverflow.com/questions/14802374/effective-image-cropping-in-javafx
 PixelReader reader = oldImage.getPixelReader();
 WritableImage newImage = new WritableImage(reader, x, y, width, height);

 */


import javafx.scene.Node;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.PixelFormat;
import javafx.scene.image.PixelReader;
import javafx.scene.image.PixelWriter;
import javafx.scene.image.WritableImage;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;

public class Sprite extends ImageView {

    private Image spriteSheet;
    private int numOfRows;
    private int numOfCols;

    private Image currentImage;
    private int imageIndex = 0;

    private int imageOrinalWidth;
    private int imageOrinalHeight;
    private int spriteWidth;
    private int spriteHeight;
    private int numOfSprites;

    private Image[] sprites;


    private Timeline animation;



    public Sprite(String fileName,int numRows, int numCols) {

        this.numOfRows = numRows;
        this.numOfCols = numCols;
        this.numOfSprites = numRows*numCols;

        calcSizeOfImage( fileName ); //get image pixel dimensions - and set data fields
        calcSizeOfSprites(); //set sprite pixel width/height data fields


        // PixelReader is used to read each sprite from the original image
        //create the whole image, and grab the pixel reader from it .... used by WritableImage
        Image image = new Image(fileName);
        PixelReader reader = image.getPixelReader();

        setUpSprites(reader);

        setUpAnimation();
        this.imageIndex = 0;
        this.currentImage = this.sprites[ this.imageIndex ];
        this.setImage( this.currentImage );

    }

    private void setUpAnimation() {


        animation = new Timeline(new KeyFrame(Duration.millis(1000/sprites.length), e -> nextFrame() ));
        animation.setCycleCount(Timeline.INDEFINITE);
        animation.play();
    }

    public void setAnimationSpeed(double ms) {
        animation.setRate(ms);
    }
    public void setAnimationCycleSpeed(double secondsForAnimaiton) {
        animation.setRate(secondsForAnimaiton);
    }

    private void nextFrame() {


        imageIndex = ++imageIndex%sprites.length;
        //System.out.println("Showing frame #" + imageIndex);
        this.setImage( this.sprites[imageIndex]);

    }

    private void setUpSprites(PixelReader reader) {

        this.sprites = new Image[this.numOfSprites];

        //pull each sprite from the sprite sheet
        for(int i = 0; i<sprites.length; i++) {
            int x = spriteWidth * (i%this.numOfCols);
            int y = spriteHeight * (i/this.numOfCols);
            //System.out.println("Sprite #" + i + ": (" + x + ", " + y +")" );
            sprites[i] = new WritableImage(reader, x, y, spriteWidth, spriteHeight);
        }
    }

    private void calcSizeOfImage(String fileName) {

        Image image = new Image(fileName);
        imageOrinalWidth = (int) image.getWidth();
        imageOrinalHeight = (int) image.getHeight();

        //System.out.println("Image size: " + this.imageOrinalWidth + "x"
        //		+ this.imageOrinalHeight);

    }


    private void calcSizeOfSprites() {
        spriteWidth = this.imageOrinalWidth/this.numOfCols;
        spriteHeight = this.imageOrinalHeight/this.numOfRows;
    }



}

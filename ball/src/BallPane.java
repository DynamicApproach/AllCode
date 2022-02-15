

import javafx.animation.AnimationTimer;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.property.DoubleProperty;
import javafx.geometry.BoundingBox;
import javafx.geometry.Bounds;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Region;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.util.Duration;

public class BallPane extends Pane {
  public final double radius = 50;
  private double x = radius, y = radius;
  private double dx = .02, dy = .02;

  private double dx2 = .03, dy2 = .05;
  private double x1 = radius, y1 = radius;
  private Circle circle = new Circle(x, y, radius);
  private Circle ball2 = new Circle( 500,500,radius);
  private Timeline animation;

  public BallPane() {
    circle.setFill(Color.GREEN); // Set ball color

    getChildren().add(circle); // Place a ball into this pane
    getChildren().add(ball2);
    // Create an animation for moving the ball
    animation = new Timeline(
      new KeyFrame(Duration.millis(.1), e -> moveBall()));

    animation.setCycleCount(Timeline.INDEFINITE);
    animation.setRate(10);
    animation.play(); // Start animation

  }

  public void play() {
    animation.play();
  }

  public void pause() {
    animation.pause();
  }

  public void increaseSpeed() {
    animation.setRate(animation.getRate() + 0.1);
  }

  public void decreaseSpeed() {
    animation.setRate(
      animation.getRate() > 0 ? animation.getRate() - 0.1 : 0);
  }
  public DoubleProperty rateProperty() {
    return animation.rateProperty();
  }

  protected void moveBall() {
    
    // Adjust ball position
    x += dx;
    y += dy;
    circle.setCenterX(x);
    circle.setCenterY(y);

    x1 += dx2;
    y1 += dy2;
    ball2.setCenterX(x1);
    ball2.setCenterY(y1);
    // x above max
    if (x+circle.getRadius()>this.getWidth()){
      dx *= -1;
    }
    // y above max
    if (y+circle.getRadius()>this.getHeight()){
      dy *= -1;
    }
    // X less than 0
    if (x-circle.getRadius()<0){
      dx *= -1;
    }
    // Y less than 0
    if (y-circle.getRadius()<0){
      dy *= -1;
    }
    // x above max
    if (x1+ball2.getRadius()>this.getWidth()){
      dx2 *= -1;
    }
    // y above max
    if (y1+ball2.getRadius()>this.getHeight()){
      dy2 *= -1;
    }
    // X less than 0
    if (x1-ball2.getRadius()<0){
      dx2 *= -1;
    }
    // Y less than 0
    if (y1-ball2.getRadius()<0){
      dy2 *= -1;
    }

    Bounds box = (circle.getBoundsInLocal());

    //balls collide x
    if (ball2.intersects(box)){
      dx2 *=-1;
      dy2 *= -1;
    }

  }
}
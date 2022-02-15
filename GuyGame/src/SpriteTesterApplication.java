

import javafx.application.Application;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class SpriteTesterApplication extends Application{

    Sprite character;
    Sprite character2;
    Sprite character3;
    Sprite character3Copy;

    public static void main(String[] args) {

        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception {

        character = new Sprite( "file:src/sampleSprite.png", 1, 6);
        character2 = new Sprite( "file:src/sample2.png", 1, 6);
        character3 = new Sprite( "file:src/hobbit-style-sprite-sheet-walk-left.png", 1, 4);
        character3Copy = new Sprite( "file:src/hobbit-style-sprite-sheet-walk-left.png", 1, 4);

        character3.setX(200);
        character.setX(400);
        character2.setX(600);


        Pane graphics = new Pane();
        graphics.getChildren().addAll( character, character2, character3,character3Copy );


        BorderPane entirePane = new BorderPane();
        entirePane.setCenter( graphics );
        entirePane.setBottom( getUI() );
        Scene scene = new Scene( entirePane, 1600,800);



        primaryStage.setScene( scene);
        primaryStage.show();

    }


    private Pane getUI() {

        HBox controlPanel = new HBox();

        controlPanel.getChildren().addAll( getPauseButton() );

        controlPanel.getChildren().addAll( getTwiceSpeedButton() );

        return controlPanel;
    }


    private Button getTwiceSpeedButton() {
        Button doubleSpeed = new Button("2x Speed");

        doubleSpeed.setOnAction( e -> doubleSpeed() );
        return doubleSpeed;
    }


    private void doubleSpeed() {
        character3.setAnimationCycleSpeed(0.5);
    }

    private Button getPauseButton() {
        Button pause = new Button();

        pause.setOnAction( e -> stopAnimations() );
        return pause;
    }


    private void stopAnimations() {
        character.setAnimationSpeed(0);
        character2.setAnimationSpeed(0);
    }




}

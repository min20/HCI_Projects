import java.util.*;
import TUIO.*;

TuioProcessing tuioClient;
colorBox colorBoxRed;
colorBox colorBoxGreen;
colorBox colorBoxBlue;

int currentX;
int currentY;

int WIN_WIDTH = 1280;
int WIN_HEIGHT = 720;

int backgroundColor = 80;

void setup() {
	size(WIN_WIDTH, WIN_HEIGHT);
	noStroke();
	fill(255);
	background(backgroundColor);

	loop();
	frameRate(60);
	colorMode(RGB, height / 3);

	tuioClient = new TuioProcessing(this);
	colorBoxRed = new colorBox(1, 0);
	colorBoxGreen = new colorBox(2, height / 3);
	colorBoxBlue = new colorBox(3, height / 3 + height / 3);
}

void draw() {
	stroke(colorBoxRed.getColorIntensity(), colorBoxGreen.getColorIntensity(),
			colorBoxBlue.getColorIntensity());
	Vector tuioCursorList = tuioClient.getTuioCursors();

	for (int idx_cur = 0; idx_cur < tuioCursorList.size(); idx_cur++) {
		TuioCursor tuioCursor = (TuioCursor) tuioCursorList.elementAt(idx_cur);
		Vector pointList = tuioCursor.getPath();

		if (pointList.size() > 0) {
			TuioPoint startPoint = (TuioPoint) pointList.firstElement();

			for (int idx_ptn = 0; idx_ptn < pointList.size(); idx_ptn++) {
				TuioPoint endPoint = (TuioPoint) pointList.elementAt(idx_ptn);
				strokeWeight(5);
				line(startPoint.getScreenX(width), startPoint.getScreenY(height),
						endPoint.getScreenX(width), endPoint.getScreenY(height));
				startPoint = endPoint;
			}
		}
	}

	// 다 지우기
	if (currentX > width - 50 && currentY < 50) {
		background(backgroundColor);
	}

	if (tuioCursorList.size() == 0) {}

	// Color Picker 그리기
	colorBoxRed.display();
	colorBoxGreen.display();
	colorBoxBlue.display();

	fill(colorBoxRed.getColorIntensity(),
			colorBoxGreen.getColorIntensity(),
			colorBoxBlue.getColorIntensity());
	stroke(255, 255, 255);
	rect(width - 50, 0, 50, 50);
}

void addTuioObject(TuioObject tobj) {}
void removeTuioObject(TuioObject tobj) {}
void updateTuioObject(TuioObject tobj) {}

void addTuioCursor(TuioCursor tuioCursor) {
	currentX = int(width * tuioCursor.getX());
	currentY = int(height * tuioCursor.getY());
}

void removeTuioCursor(TuioCursor tuioCursor) {}

void updateTuioCursor(TuioCursor tuioCursor) {
	currentX = int(width * tuioCursor.getX());
	currentY = int(height * tuioCursor.getY());
}

void refresh(TuioTime bundleTime) {}

class colorBox {
	final int boxWidth = 50;
	final int boxHeight = height / 3;

	int boxPosition;
	int boxColor;
	int colorIntensity = 255;

	colorBox(int boxColor, int boxPosition) {
		this.boxColor = boxColor;
		this.boxPosition = boxPosition;
	}

	int getColorIntensity() {
		Vector tuioCursorList = tuioClient.getTuioCursors();

		for (int idx_cur = 0; idx_cur < tuioCursorList.size(); idx_cur++) {
			TuioCursor tuioCursor = (TuioCursor) tuioCursorList.elementAt(idx_cur);

			if (width * tuioCursor.getX() < boxWidth
					&& height * tuioCursor.getY() > boxPosition
					&& height * tuioCursor.getY() < boxPosition + boxHeight) {
				colorIntensity = (int(height * tuioCursor.getY()) - boxPosition);
				colorIntensity = colorIntensity * 255 / boxHeight;
			}
		}

		return colorIntensity;
	}

	void display() {
		stroke(0);
		noFill();
		strokeWeight(1);
		rect(0, boxPosition, boxWidth, boxHeight);

		for (int idx_bar = 0; idx_bar < boxHeight; idx_bar++) {
			switch(boxColor) {
				case 1:
					stroke(idx_bar, 0, 0);
					break;
				case 2:
					stroke(0, idx_bar, 0);
					break;
				case 3:
					stroke(0, 0, idx_bar);
					break;
			}

			line(0, idx_bar + boxPosition, boxWidth, idx_bar + boxPosition);
		}

		stroke(255, 255, 255);
		line(0, colorIntensity * boxHeight / 254 + boxPosition, boxWidth, colorIntensity * boxHeight / 254 + boxPosition);
		System.out.println(colorIntensity + ", " + boxHeight + ", " + boxPosition);
	}
}


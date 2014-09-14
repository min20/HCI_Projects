import java.util.*;
import TUIO.*;
TuioProcessing tuioClient;

colorBox cboxRed, cboxGreen, cboxBlue;
int curx;
int cury;

int WIN_WIDTH = 1280;
int WIN_HEIGHT = 720;

void setup() {
  //size(screen.width,screen.height);
  size(WIN_WIDTH, WIN_HEIGHT);
  noStroke();
  fill(255);
  background(0);
  loop();
  frameRate(75);
  colorMode(RGB, height/3);

  tuioClient = new TuioProcessing(this);
  cboxRed = new colorBox(1, 0);
  cboxGreen = new colorBox(2, height/3);
  cboxBlue = new colorBox(3, height/3 + height/3);
}

void draw() {
  stroke(cboxRed.val(), cboxGreen.val(), cboxBlue.val());
  Vector tuioCursorList = tuioClient.getTuioCursors();
  
  for (int i = 0; i < tuioCursorList.size (); i++) {
    TuioCursor tcur = (TuioCursor)tuioCursorList.elementAt(i);
    Vector pointList = tcur.getPath();
    if (pointList.size()>0) {       
      TuioPoint start_point = (TuioPoint)pointList.firstElement();
      for (int j=0; j<pointList.size (); j++) {
        TuioPoint end_point = (TuioPoint)pointList.elementAt(j);
        strokeWeight(8);           
        line(start_point.getScreenX(width), start_point.getScreenY(height), end_point.getScreenX(width), end_point.getScreenY(height));
        start_point = end_point;
      }
    }
  }
  if (curx>width-70&&cury<70) {
    background(0);
    cboxRed.init();
    cboxGreen.init();
    cboxBlue.init();
  }

  if (tuioCursorList.size()==0) {
  }

  cboxRed.display();
  cboxGreen.display();
  cboxBlue.display();
  fill(cboxRed.val(), cboxGreen.val(), cboxBlue.val());
  stroke(255);
  strokeWeight(2);
  rect(width - 62, 0, 60, 60);
}

void addTuioObject(TuioObject tobj) {
}

void removeTuioObject(TuioObject tobj) {
}

void updateTuioObject(TuioObject tobj) {
}

void addTuioCursor(TuioCursor tcur) {
}

void removeTuioCursor(TuioCursor tcur) {
}

void updateTuioCursor(TuioCursor tcur) {
  curx =int(width*tcur.getX());     
  cury =int(height*tcur.getY());
}

void refresh(TuioTime bundleTime) {
}

class colorBox {
  final int wid = 100;
  final int hei = height/3;
  int pos;
  int col;
  int colorIntensity = 255;

  colorBox(int cole, int pose) {
    col=cole;
    pos=pose;
  }

  int val() {
    Vector tuioCursorList = tuioClient.getTuioCursors();
    for (int i=0; i<tuioCursorList.size (); i++) {
      TuioCursor tcur = (TuioCursor)tuioCursorList.elementAt(i);
      if (int(width*tcur.getX())<wid&&int(height*tcur.getY())>pos&&int(height*tcur.getY())<pos+hei) {
        colorIntensity=int(height*tcur.getY())-pos;
      }
    }
    return colorIntensity;
  }

  void display() {
    stroke(0);
    noFill();
    strokeWeight(1);
    rect(0, pos, wid, hei);
    for (int i=0; i<hei; i++) {
      switch(col) {
      case 1:
        stroke(i, 0, 0);
        break;
      case 2:
        stroke(0, i, 0);
        break;
      case 3:
        stroke(0, 0, i);
        break;
      }
      line(0, i + pos, wid, i + pos);
      stroke(255);
      line(0, colorIntensity + pos, wid, colorIntensity + pos);
    }
  }

  void init() {
    colorIntensity=255;
  }
}


static int WIDTH = 720;
static int HEIGHT = 480;
float ROT_AMT = 0.0;

void setup() {
  size(WIDTH, HEIGHT);
}

void draw() {
  background(50);

  pushMatrix();
    translate(mouseX - WIDTH / 2, 100);
    rect(100, 100, 200, 200);
    fill(0, 0, 255, 100);
    translate(100, mouseY - HEIGHT / 2);
    rect(100, 100, 200, 200);
    fill(255, 255, 255, 100);
    rotate(PI * ROT_AMT);
    translate(-25, -25);
    rect(0, 0, 50, 50);
  popMatrix();
  
  translate(100, 100, 0);
  fill(255, 0, 0, 100);
  rect(250, 250, 200, 200);
  fill(0, 255, 0, 100);

  ROT_AMT += 0.01;
}

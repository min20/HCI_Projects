static int WINDOW_X = 800;
static int WINDOW_Y = 600;

void setup() {
  size(WINDOW_X, WINDOW_Y);
}

void draw() {
  background(0, 0, 0);
  for (int idx = 0; idx < 50; idx++) {
    ellipse(WINDOW_X / 2 - (WINDOW_X / 2 - mouseX) / 50.0 * idx, 
        WINDOW_Y / 2 - (WINDOW_Y / 2 - mouseY) / 50.0 * idx,
        idx * 2, idx * 2);
    fill(200, 200, 200);
  }
}


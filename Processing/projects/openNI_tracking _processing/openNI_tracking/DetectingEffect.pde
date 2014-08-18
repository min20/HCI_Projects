class DetectingEffect{
  int dt;
  boolean visible;
  float positionX;
  float positionY;
  
  int phase_1 = 20;
  int phase_2 = 40;
  
  DetectingEffect(){
    dt = 0;
    visible = false;
    positionX = 0.0f;
    positionY = 0.0f;
  }
  
  void startEffect(float x, float y){
    dt = 0;
    this.positionX = x;
    this.positionY = y;
    this.visible = true;
  }
  
  void update(){
    ++dt;
    
    // check to init instance
    if (dt >= 60){
      dt = 0;
      this.visible = false;
    }
  }
  
  void display()
  {
    if (!this.visible){
      return;
    }
    
    this.update();
    
    noStroke();
    
    fill(30, 153, 197);
    ellipse(this.positionX, this.positionY, dt, dt);
    
    if (dt >= phase_1){
      fill(196, 15, 132);
      ellipse(this.positionX, this.positionY, dt - phase_1, dt - phase_1);
    }
    
    if (dt >= phase_2){
      fill(204, 232, 36);
      ellipse(this.positionX, this.positionY, dt - phase_2, dt - phase_2);
    }
  }
  
}

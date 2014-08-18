class Ball{
  
  float m_PositionX;
  float m_PositionY;
  float m_Radius;
  boolean visible;
  float opacity;
  
  Ball(){
    this.m_PositionX = 0;
    this.m_PositionY = 0;
    this.m_Radius = 0.0f;
    this.visible = false;
    this.opacity = 0.0f;
  }
  
  void init(float x, float y){
    this.m_PositionX = x;
    this.m_PositionY = y;
    this.m_Radius = 2.0f;
    this.opacity = 1.0f;
    this.visible = true;
  }
  
  void updateAndDisplay(){
    if (this.visible){
      this.m_Radius += 2.0f;
      this.opacity -= 0.05f;
      
      if (this.opacity < 0.1f)
      {
        this.visible = false;
      }
      else
      {
        this.display();
      }
    }
  }
  
  void display(){
    fill(204, 232, 36, this.opacity * 100);
    ellipse(this.m_PositionX, this.m_PositionY, m_Radius, m_Radius);
  }
}

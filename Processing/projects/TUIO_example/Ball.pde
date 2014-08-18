class Ball{
  
  int m_Idx;
  float m_ColorIdx;

  boolean m_IsChanging;

  float m_PositionX;
  float m_PositionY;
  float m_Radius;

  float m_VelocityX;
  float m_VelocityY;

  Ball[] ballList;
  color[] colorList = new color[5];
  
  Ball(Ball[] list, int idx){
    this.ballList = list;
    this.m_Idx = idx;
    
    this.m_PositionX = 0.0f;
    this.m_PositionY = 0.0f;
    
    // does not displyed
    this.m_Radius = 0.0f;
    
    this.m_VelocityX = 0.0f;
    this.m_VelocityY = 0.0f;
    
    this.colorList[0] = color(30, 153, 197);
    this.colorList[1] = color(196, 15, 132);
    this.colorList[2] = color(204, 232, 36);
    this.colorList[3] = color(78, 183, 153);
    this.colorList[4] = color(255, 102, 0);
    
    this.m_IsChanging = false;
  }
  
  void createBall(float xPos, float yPos)
  {
    // put the ball where touched position
    this.m_PositionX = xPos;
    this.m_PositionY = yPos;
    
    // default size
    this.m_Radius = 50.0f;
    
    this.m_VelocityX = 0.0f;
    this.m_VelocityY = 0.0f;
    
    // start to change size and color
    this.m_IsChanging = true;
  }
  
  void setVelocity(){
    // start to move
    this.m_VelocityX = random(-1.0f, 1.0f);
    this.m_VelocityY = random(-1.0f, 1.0f);
  }
  
  void update(){
    if (this.m_IsChanging){
      changeBallProperties();
    }
    
    this.m_PositionX += this.m_VelocityX;
    this.m_PositionY += this.m_VelocityY;
  }
  
  void display(){
    fill(this.colorList[int(this.m_ColorIdx) % 5]);
    ellipse(this.m_PositionX, this.m_PositionY, this.m_Radius, this.m_Radius);
  }
  
  void changeBallProperties(){
    this.m_Radius += 0.5f;
    this.m_ColorIdx += 0.1f;
  }
  
  void stopChanging(){
    this.m_IsChanging = false;
  }
  
  void checkBoundary(){
    if (m_PositionX - m_Radius < 0){
      m_VelocityX *= -1;
      m_PositionX = m_Radius;
    } else if (m_PositionX + m_Radius > WINDOW_WIDTH){
      m_VelocityX *= -1;
      m_PositionX = WINDOW_WIDTH - m_Radius;
    }
    
    if (m_PositionY - m_Radius < 0){
      m_VelocityY *= -1;
      m_PositionY = m_Radius;
    } else if (m_PositionY + m_Radius > WINDOW_HEIGHT){
      m_VelocityY *= -1;
      m_PositionY = WINDOW_HEIGHT - m_Radius;
    }
  }
}


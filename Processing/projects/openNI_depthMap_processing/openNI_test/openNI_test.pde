/* --------------------------------------------------------------------------
 * SimpleOpenNI DepthMap3d Test
 * --------------------------------------------------------------------------
 * Processing Wrapper for the OpenNI/Kinect 2 library
 * http://code.google.com/p/simple-openni
 * --------------------------------------------------------------------------
 * prog:  Max Rheiner / Interaction Design / Zhdk / http://iad.zhdk.ch/
 * date:  12/12/2012 (m/d/y)
 * ----------------------------------------------------------------------------
 */

import SimpleOpenNI.*;

SimpleOpenNI context;

int     steps   = 5;  // to speed up the drawing, draw every third point
boolean[]   boolMap;
Ball[]      ballMap;

void setup()
{
  size(1024,768);

  context = new SimpleOpenNI(this);
  if(context.isInit() == false)
  {
     println("Can't init SimpleOpenNI, maybe the camera is not connected!"); 
     exit();
     return;  
  }
  
  // disable mirror
  // what is this??
  context.setMirror(false);

  // enable depthMap generation 
  context.enableDepth();
  
  int len = context.depthHeight() * context.depthWidth();
  println(len);
  
  boolMap = new boolean[len];
  ballMap = new Ball[len];
  
  for (int i = 0; i < len; ++i)
  {
    boolMap[i] = false;
    ballMap[i] = new Ball();
  }

  noStroke();
  smooth();
}

void draw()
{
  
  // update the cam
  context.update();

  background(10, 10, 10);
  
  int     index;
  int[]   depthMap = context.depthMap();
  
  // draw objects
  for(int y = 0; y < context.depthHeight(); y += steps)
  {
    for(int x = 0; x < context.depthWidth(); x += steps)
    {
      index = x + y * context.depthWidth();
      if(depthMap[index] > 0)
      {
        if (depthMap[index] > 800)
        {
          boolMap[index] = false;
          fill(32, 178, 170);
        }
        else
        {
          if (!boolMap[index])
          {
            ballMap[index].init(x * 1024 / context.depthWidth(), y * 768 / context.depthHeight());
          }
          boolMap[index] = true;
          fill(178, 32, 170);
        }
        ellipse(x * 1024 / context.depthWidth(), y * 768 / context.depthHeight(), 2, 2);
      }
      
      ballMap[index].updateAndDisplay();
    }
  }
}

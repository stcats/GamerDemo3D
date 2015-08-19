#include <Gamer.h>
#define w 8
#define h 8
#define hw 4
#define hh 4
Gamer gamer;
float rad = 2;
float fov = 1350;
float cube[8][3] = {{-rad,-rad,-rad},
                  { rad,-rad,-rad},
                  { rad,-rad, rad},
                  {-rad,-rad, rad},
                  {-rad, rad,-rad},
                  { rad, rad,-rad},
                  { rad, rad, rad},
                  {-rad, rad, rad}};
float  pyramid[5][3] = {{-rad,-rad,-rad},
                      { rad,-rad,-rad},
                      { rad,-rad, rad},
                      {-rad,-rad, rad},
                      {0,rad, 0}};
float  octohedron[6][3] = {{-rad,0,-rad},
                          { rad,0,-rad},
                          { rad,0, rad},
                          {-rad,0, rad},
                          {0,rad, 0},
                          {0,-rad, 0}};
int cubePts = 8,pyramidPts=5,octohedronPts=6;
float rx = 0;
float ry = 0;
float rs = 0.25;
int meshID = 0;
void setup(){
  gamer.begin();
}
void loop(){
  handleInput();
  gamer.clear();
  if(meshID == 0){
    for(int i = 0 ; i < cubePts; i++){
      float scale = fov/(fov + cube[i][2]);
      float x2d = (cube[i][0] * scale)+hw;
      float y2d = (cube[i][1] * scale)+hh;
      if((x2d >= 0 && x2d < w) && (y2d >= 0 && y2d < h)) {
        gamer.display[(int)x2d][(int)y2d] = 1;
      }
      rotateX(cube[i],rx); 
      rotateY(cube[i],ry); 
    }
  }
  if(meshID == 1){
    for(int i = 0 ; i < pyramidPts; i++){
      float scale = fov/(fov + pyramid[i][2]);
      float x2d = (pyramid[i][0] * scale)+hw;
      float y2d = (pyramid[i][1] * scale)+hh;
      if((x2d >= 0 && x2d < w) && (y2d >= 0 && y2d < h)) {
        gamer.display[(int)x2d][(int)y2d] = 1;
      }
      rotateX(pyramid[i],rx); 
      rotateY(pyramid[i],ry); 
    }
  }
  if(meshID == 2){
    for(int i = 0 ; i < octohedronPts; i++){
      float scale = fov/(fov + octohedron[i][2]);
      float x2d = (octohedron[i][0] * scale)+hw;
      float y2d = (octohedron[i][1] * scale)+hh;
      if((x2d >= 0 && x2d < w) && (y2d >= 0 && y2d < h)) {
        gamer.display[(int)x2d][(int)y2d] = 1;
      }
      rotateX(octohedron[i],rx); 
      rotateY(octohedron[i],ry); 
    }
  }
  gamer.updateDisplay();
  delay(40);
}
void handleInput(){
  if(gamer.isHeld(UP))   rx = -rs;
  else if(gamer.isHeld(DOWN)) rx = rs;
  else if(gamer.isHeld(LEFT))  ry = -rs;
  else if(gamer.isHeld(RIGHT)) ry = rs;
  else rx = ry = 0; 
  if(gamer.isPressed(START)) meshID = (meshID+1)%3;
}

void rotateY(float v[],float angle){
  float cosR = cos(angle);
  float sinR = sin(angle);

  float tempz = v[2];
  float tempx = v[0]; 

  v[0] = (tempx*cosR)+(tempz*sinR);
  v[2] = (tempx*-sinR)+(tempz*cosR);
}
void rotateX(float v[],float angle){
  float cosR = cos(angle);
  float sinR = sin(angle);

  float tempz = v[2];
  float tempy = v[1]; 

  v[1] = (tempy*cosR)+(tempz*sinR);
  v[2] = (tempy*-sinR)+(tempz*cosR);
}

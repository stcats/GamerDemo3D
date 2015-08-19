#Description

This demos a basic 3d rasterizer rendering the vertices(corners)
of 3 meshes: a cube, a pyramid and an octohedron

##Usage

Use the LEFT/RIGHT keys to rotate the 3D shape on the Y axis
Use the UP/DOWN    keys to rotate the 3D shape on the X axis
Use the start button to cycle through the meshes

##Improvements

The code can be tidier: use an array pointer for a generic mesh with 
an undeclared number of vertices, so the if(meshID ==) chunk can be replaced with a single block

The calculations are for perspective projection with a massive FOV.
Ideally, there would an orthogonal projection matrix used for a 'military' 45 degree view
which would allow full edges to render better on a 8x8 display.
E.g. cube


       +------+
      /      /|
     /      / |
    +------+  |
    |      |  +
    |      | /
    |      |/
    +------+
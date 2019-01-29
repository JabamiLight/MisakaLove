#version 300 es
layout (location = 0) in vec4 vPosition;
out vec2 textureCoordinate;

void main(){
   gl_Position = vPosition;
}

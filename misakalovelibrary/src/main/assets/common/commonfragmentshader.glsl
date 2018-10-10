#version 300 es
precision mediump float;
uniform sampler2D inputImageTexture;
in vec2 textureCoordinate;
out vec4 FragColor;
void main() {
  FragColor = texture(inputImageTexture, textureCoordinate);
}
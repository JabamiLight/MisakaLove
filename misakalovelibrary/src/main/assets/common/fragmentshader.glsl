#version 300 es
#extension GL_OES_EGL_image_external_essl3 : require
precision mediump float;
uniform samplerExternalOES inputImageTexture;
in vec2 textureCoordinate;
out vec4 FragColor;
void main() {
  FragColor = texture(inputImageTexture, textureCoordinate);
}
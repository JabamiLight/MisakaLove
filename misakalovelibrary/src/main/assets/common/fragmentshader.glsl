#version 300 es
#extension GL_OES_EGL_image_external_essl3 : require
precision mediump float;
uniform samplerExternalOES yuvTexSampler;
in vec2 yuvTexCoords;
out vec4 FragColor;
void main() {
  FragColor = texture(yuvTexSampler, yuvTexCoords);
}
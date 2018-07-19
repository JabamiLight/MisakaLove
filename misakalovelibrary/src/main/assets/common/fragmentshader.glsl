#version 300 es
#extension GL_OES_EGL_image_external : require

precision mediump float;
uniform samplerExternalOES yuvTexSampler;
in vec2 yuvTexCoords;

void main() {
  gl_FragColor = texture2D(yuvTexSampler, yuvTexCoords);
}
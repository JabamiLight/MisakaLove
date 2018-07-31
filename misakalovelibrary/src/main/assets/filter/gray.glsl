#version 300 es
out vec4 FragColor;
precision mediump float;
in vec2 textureCoordinate;
uniform sampler2D inputImageTexture;
void main()
 {
     vec4 textureColor = texture(inputImageTexture, textureCoordinate);
     float average=(textureColor.r+textureColor.g,textureColor.b)/3.0;
     FragColor = vec4(average,average,average,1.0);
 }
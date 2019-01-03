#version 300 es
precision mediump float;
uniform sampler2D inputImageTexture;
in vec2 textureCoordinate;
out vec4 FragColor;

uniform float scaleRatio;// 缩放系数，0无缩放，大于0则放大
uniform float radius;// 缩放算法的作用域半径
uniform vec2 leftEyeCenterPosition; // 左眼控制点，越远变形越小
uniform vec2 rightEyeCenterPosition; // 右眼控制点
uniform float aspectRatio; // 所处理图像的宽高比
uniform int faceValidate;
int flag;

highp vec2 warpPositionToUse(vec2 centerPostion, vec2 currentPosition, float radius, float scaleRatio, float aspectRatio)
{

    //0.5 0.5
    //0.6 0.6
    //aspectRatio =1.5
    vec2 positionToUse = currentPosition;

    //0.6 0.65
    vec2 currentPositionToUse = vec2(currentPosition.x, currentPosition.y * aspectRatio + 0.5 - 0.5 * aspectRatio);
    //0.5 0.5
    vec2 centerPostionToUse = vec2(centerPostion.x, centerPostion.y * aspectRatio + 0.5 - 0.5 * aspectRatio);

    float r = distance(currentPositionToUse, centerPostionToUse);

    flag=0;
    if(r < radius)
    {
        flag=1;
        float alpha = 1.0 - scaleRatio * pow(r / radius - 1.0, 2.0);
        positionToUse = centerPostion + alpha * (currentPosition - centerPostion);
    }

    return positionToUse;
}



void main() {


    if(faceValidate==1){
        vec2 positionToUse = warpPositionToUse(leftEyeCenterPosition, textureCoordinate, radius, scaleRatio, aspectRatio);
        positionToUse = warpPositionToUse(rightEyeCenterPosition, positionToUse, radius, scaleRatio, aspectRatio);

        if(flag==1){

            FragColor = vec4(1.0,1.0,1.0,1.0);
        }else{

            FragColor = texture(inputImageTexture, positionToUse);
        }

    }else if(faceValidate==0){
         FragColor = texture(inputImageTexture, textureCoordinate);
    }




}






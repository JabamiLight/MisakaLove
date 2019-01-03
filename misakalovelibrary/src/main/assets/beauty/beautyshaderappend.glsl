#version 300 es
precision mediump float;
uniform sampler2D inputImageTexture;
in vec2 textureCoordinate;
out vec4 FragColor;


//大眼数据
uniform float scaleRatio;// 缩放系数，0无缩放，大于0则放大
uniform float radius;// 缩放算法的作用域半径
uniform vec2 leftEyeCenterPosition; // 左眼控制点，越远变形越小
uniform vec2 rightEyeCenterPosition; // 右眼控制点
uniform float aspectRatio; // 所处理图像的宽高比
uniform int faceValidate;//人脸数据是否有效



int MAX_CONTOUR_POINT_COUNT=1;
//瘦脸数据
uniform highp float faceRadius;
uniform highp float aspectRatio;
uniform float leftContourPoints[MAX_CONTOUR_POINT_COUNT*2];
uniform float rightContourPoints[MAX_CONTOUR_POINT_COUNT*2];
uniform float deltaArray[MAX_CONTOUR_POINT_COUNT];
uniform int arraySize;


//圆内缩小

highp vec2 warpEyeToUse(vec2 centerPostion, vec2 currentPosition, float radius, float scaleRatio, float aspectRatio)
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

    if(r < radius)
    {
        float alpha = 1.0 - scaleRatio * pow(r / radius - 1.0, 2.0);
        positionToUse = centerPostion + alpha * (currentPosition - centerPostion);
    }else{
    }

    return positionToUse;
}



highp vec2 warpFaceToUse(vec2 currentPoint, vec2 contourPointA,  vec2 contourPointB, float radius, float delta, float aspectRatio)
 {
     vec2 positionToUse = currentPoint;

     vec2 currentPointToUse = vec2(currentPoint.x, currentPoint.y * aspectRatio + 0.5 - 0.5 * aspectRatio);
     vec2 contourPointAToUse = vec2(contourPointA.x, contourPointA.y * aspectRatio + 0.5 - 0.5 * aspectRatio);

     float r = distance(currentPointToUse, contourPointAToUse);
     if(r < radius)
     {
         vec2 dir = normalize(contourPointB - contourPointA);
         float dist = radius * radius - r * r;
         float alpha = dist / (dist + (r-delta) * (r-delta));
         alpha = alpha * alpha;
         positionToUse = positionToUse - alpha * delta * dir;
     }

     return positionToUse;

 }




void main() {

    if(faceValidate==1){
        vec2 positionToUse = warpEyeToUse(leftEyeCenterPosition, textureCoordinate, radius, scaleRatio, aspectRatio);
        positionToUse = warpEyeToUse(rightEyeCenterPosition, positionToUse, radius, scaleRatio, aspectRatio);
        for(int i = 0; i < arraySize; i++)
            {
                 positionToUse = warpPositionToUse(positionToUse, vec2(leftContourPoints[i * 2], leftContourPoints[i * 2 + 1]), vec2(rightContourPoints[i * 2], rightContourPoints[i * 2 + 1]), radius, deltaArray[i], aspectRatio);
                 positionToUse = warpPositionToUse(positionToUse, vec2(rightContourPoints[i * 2], rightContourPoints[i * 2 + 1]), vec2(leftContourPoints[i * 2], leftContourPoints[i * 2 + 1]), radius, deltaArray[i], aspectRatio);
        }
        FragColor = texture(inputImageTexture, positionToUse);
    }else if(faceValidate==0){
         FragColor = texture(inputImageTexture, textureCoordinate);
    }


}






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



//瘦脸数据
const int MAX_CONTOUR_POINT_COUNT=10;
uniform  float faceRadius;
uniform  float faceAspectRatio;
uniform float leftContourPoints[MAX_CONTOUR_POINT_COUNT*2];
uniform float rightContourPoints[MAX_CONTOUR_POINT_COUNT*2];
uniform float deltaArray[MAX_CONTOUR_POINT_COUNT];
uniform int arraySize;



//磨皮美白数据

uniform highp vec2 singleStepOffset;
uniform highp vec4 params;
uniform highp float brightness;
uniform float texelWidthOffset;
uniform float texelHeightOffset;
const highp vec3 W = vec3(0.299, 0.587, 0.114);
const highp mat3 saturateMatrix = mat3(1.1102, -0.0598, -0.061,-0.0774, 1.0826, -0.1186,-0.0228, -0.0228, 1.1772);
highp vec2 blurCoordinates[24];



//大眼算法
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

    if(r < radius) {
        float alpha = 1.0 - scaleRatio * pow(r / radius - 1.0, 2.0);
        positionToUse = centerPostion + alpha * (currentPosition - centerPostion);
    }else{

    }

    return positionToUse;
}


//瘦脸算法
int flag;
highp vec2 warpFaceToUse(vec2 currentPoint, vec2 contourPointA,  vec2 contourPointB, float radius, float delta, float aspectRatio)
 {
     vec2 positionToUse = currentPoint;

     vec2 currentPointToUse = vec2(currentPoint.x, currentPoint.y * aspectRatio + 0.5 - 0.5 * aspectRatio);
     vec2 contourPointAToUse = vec2(contourPointA.x, contourPointA.y * aspectRatio + 0.5 - 0.5 * aspectRatio);

     float r = distance(currentPointToUse, contourPointAToUse);
     if(r < radius) {
         vec2 dir = normalize(contourPointB - contourPointA);
         float dist = radius * radius - r * r;
         float alpha = dist / (dist + (r-delta) * (r-delta));
         alpha = alpha * alpha;
         positionToUse = positionToUse - alpha * delta * dir;
         flag=1;
     }else{
        flag=0;
     }

     return positionToUse;

}

//磨皮算法
highp float hardLight(highp float color) {
    if (color <= 0.5)
        color = color * color * 2.0;
    else
        color = 1.0 - ((1.0 - color)*(1.0 - color) * 2.0);
    return color;
}

highp float processColor(vec4 textureColor){
    highp vec3 centralColor = textureColor.rgb;
    vec2 singleStepOffset=vec2(texelWidthOffset,texelHeightOffset);
    blurCoordinates[0] = textureCoordinate.xy + singleStepOffset * vec2(0.0, -10.0);
    blurCoordinates[1] = textureCoordinate.xy + singleStepOffset * vec2(0.0, 10.0);
    blurCoordinates[2] = textureCoordinate.xy + singleStepOffset * vec2(-10.0, 0.0);
    blurCoordinates[3] = textureCoordinate.xy + singleStepOffset * vec2(10.0, 0.0);
    blurCoordinates[4] = textureCoordinate.xy + singleStepOffset * vec2(5.0, -8.0);
    blurCoordinates[5] = textureCoordinate.xy + singleStepOffset * vec2(5.0, 8.0);
    blurCoordinates[6] = textureCoordinate.xy + singleStepOffset * vec2(-5.0, 8.0);
    blurCoordinates[7] = textureCoordinate.xy + singleStepOffset * vec2(-5.0, -8.0);
    blurCoordinates[8] = textureCoordinate.xy + singleStepOffset * vec2(8.0, -5.0);
    blurCoordinates[9] = textureCoordinate.xy + singleStepOffset * vec2(8.0, 5.0);
    blurCoordinates[10] = textureCoordinate.xy + singleStepOffset * vec2(-8.0, 5.0);
    blurCoordinates[11] = textureCoordinate.xy + singleStepOffset * vec2(-8.0, -5.0);
    blurCoordinates[12] = textureCoordinate.xy + singleStepOffset * vec2(0.0, -6.0);
    blurCoordinates[13] = textureCoordinate.xy + singleStepOffset * vec2(0.0, 6.0);
    blurCoordinates[14] = textureCoordinate.xy + singleStepOffset * vec2(6.0, 0.0);
    blurCoordinates[15] = textureCoordinate.xy + singleStepOffset * vec2(-6.0, 0.0);
    blurCoordinates[16] = textureCoordinate.xy + singleStepOffset * vec2(-4.0, -4.0);
    blurCoordinates[17] = textureCoordinate.xy + singleStepOffset * vec2(-4.0, 4.0);
    blurCoordinates[18] = textureCoordinate.xy + singleStepOffset * vec2(4.0, -4.0);
    blurCoordinates[19] = textureCoordinate.xy + singleStepOffset * vec2(4.0, 4.0);
    blurCoordinates[20] = textureCoordinate.xy + singleStepOffset * vec2(-2.0, -2.0);
    blurCoordinates[21] = textureCoordinate.xy + singleStepOffset * vec2(-2.0, 2.0);
    blurCoordinates[22] = textureCoordinate.xy + singleStepOffset * vec2(2.0, -2.0);
    blurCoordinates[23] = textureCoordinate.xy + singleStepOffset * vec2(2.0, 2.0);
    highp float sampleColor = centralColor.g * 22.0;
    sampleColor += texture2D(vTexture, blurCoordinates[0]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[1]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[2]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[3]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[4]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[5]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[6]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[7]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[8]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[9]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[10]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[11]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[12]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[13]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[14]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[15]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[16]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[17]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[18]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[19]).g * 2.0;
    sampleColor += texture2D(vTexture, blurCoordinates[20]).g * 3.0;
    sampleColor += texture2D(vTexture, blurCoordinates[21]).g * 3.0;
    sampleColor += texture2D(vTexture, blurCoordinates[22]).g * 3.0;
    sampleColor += texture2D(vTexture, blurCoordinates[23]).g * 3.0;
    sampleColor = sampleColor / 62.0;
    highp float highPass = centralColor.g - sampleColor + 0.5;
    for (int i = 0; i < 5; i++) {
        highPass = hardLight(highPass);
    }
    highp float lumance = dot(centralColor, W);
    highp float alpha = pow(lumance, params.r);
    highp vec3 smoothColor = centralColor + (centralColor-vec3(highPass))*alpha*0.1;
    smoothColor.r = clamp(pow(smoothColor.r, params.g), 0.0, 1.0);
    smoothColor.g = clamp(pow(smoothColor.g, params.g), 0.0, 1.0);
    smoothColor.b = clamp(pow(smoothColor.b, params.g), 0.0, 1.0);
    highp vec3 lvse = vec3(1.0)-(vec3(1.0)-smoothColor)*(vec3(1.0)-centralColor);
    highp vec3 bianliang = max(smoothColor, centralColor);
    highp vec3 rouguang = 2.0*centralColor*smoothColor + centralColor*centralColor - 2.0*centralColor*centralColor*smoothColor;
    highp vec4 processedColor;
    processedColor = vec4(mix(centralColor, lvse, alpha), 1.0);
    processedColor.rgb = mix(processedColor.rgb, bianliang, alpha);
    processedColor.rgb = mix(processedColor.rgb, rouguang, params.b);
    highp vec3 satcolor = processedColor.rgb * saturateMatrix;
    processedColor.rgb = mix(processedColor.rgb, satcolor, params.a);
    processedColor.rgb = vec3(processedColor.rgb + vec3(brightness));
    return processColor;
}



void main() {

    if(faceValidate==1){
        vec2 positionToUse = warpEyeToUse(leftEyeCenterPosition, textureCoordinate, radius, scaleRatio, aspectRatio);
        positionToUse = warpEyeToUse(rightEyeCenterPosition, positionToUse, radius, scaleRatio, aspectRatio);

        for(int i = 0; i < arraySize; i++) {
             positionToUse = warpFaceToUse(positionToUse, vec2(leftContourPoints[i * 2], leftContourPoints[i * 2 + 1]), vec2(rightContourPoints[i * 2], rightContourPoints[i * 2 + 1]), faceRadius, deltaArray[i], aspectRatio);
             positionToUse = warpFaceToUse(positionToUse, vec2(rightContourPoints[i * 2], rightContourPoints[i * 2 + 1]), vec2(leftContourPoints[i * 2], leftContourPoints[i * 2 + 1]), faceRadius, deltaArray[i], aspectRatio);
        }

        FragColor = processColor(texture(inputImageTexture, positionToUse));

    }else if(faceValidate==0){
         FragColor = texture(inputImageTexture, textureCoordinate);
    }


}






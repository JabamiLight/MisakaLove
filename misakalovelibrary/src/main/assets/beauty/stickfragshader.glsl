#version 300 es
precision mediump float;
uniform sampler2D inputImageTexture;
uniform vec2 mousePoint[18];
in vec2 textureCoordinate;
out vec4 FragColor;


void main() {
//    if(r<0.1) {
//        FragColor=vec4(0.9,0.2,0.5,1.0);
//        return;
//    }
//    if(textureCoordinate.x>0.1){
//        FragColor=vec4(0.9,1.0,0.5,1.0);
//        return;
//
//    }
    vec4 textureColor = texture(inputImageTexture, textureCoordinate);
    FragColor=textureColor;
    return;

    vec2 mouthO=vec2(1.0-312.0/800.0,719.0/1067.0);
    float minDis=distance(textureCoordinate, mousePoint[0]);
    int minIndex=0;
    for(int i =0;i<18;i++){
        float r = distance(textureCoordinate, mousePoint[i]);
        if(r<minDis){
            minDis=r;
            minIndex=i;
        }
    }

    if(minDis>0.05){
         discard;
    }else{

                switch(minIndex){
                    case 0:
                     mouthO=vec2(1.0-312.0/800.0,719.0/1067.0);
                     break;
                    case 1:
                     mouthO=vec2(1.0-489.0/800.0,717.0/1067.0);
                     break;
                    case 2:
                     mouthO=vec2(1.0-335.0/800.0,743.0/1067.0);
                     break;
                    case 3:
                     mouthO=vec2(1.0-364.0/800.0,759.0/1067.0);
                     break;
                    case 4:
                     mouthO=vec2(1.0-399.0/800.0,766.0/1067.0);
                     break;
                    case 5:
                     mouthO=vec2(1.0-434.0/800.0,758.0/1067.0);
                     break;
                    case 6:
                     mouthO=vec2(1.0-464.0/800.0,741.0/1067.0);
                     break;
                    case 7:
                     mouthO=vec2(1.0-442.0/800.0,736.0/1067.0);
                     break;
                    case 8:
                     mouthO=vec2(1.0-401.0/800.0,741.0/1067.0);
                     break;
                    case 9:
                     mouthO=vec2(1.0-352.0/800.0,736.0/1067.0);
                     break;
                    case 10:
                     mouthO=vec2(1.0-346.0/800.0,713.0/1067.0);
                     break;
                    case 11:
                     mouthO=vec2(1.0-379.0/800.0,710.0/1067.0);
                     break;
                    case 12:
                     mouthO=vec2(1.0-401.0/800.0,714.0/1067.0);
                     break;
                    case 13:
                     mouthO=vec2(1.0-421.0/800.0,713.0/1067.0);
                     break;
                    case 14:
                     mouthO=vec2(1.0-454.0/800.0,713.0/1067.0);
                     break;
                    case 15:
                     mouthO=vec2(1.0-442.0/800.0,729.0/1067.0);
                     break;
                    case 16:
                     mouthO=vec2(1.0-400.0/800.0,731.0/1067.0);
                     break;
                    case 17:
                     mouthO=vec2(1.0-354.0/800.0,727.0/1067.0);
                     break;
                }
          vec2 delta=mousePoint[minIndex]-textureCoordinate;
          vec4 textureColor = texture(inputImageTexture, mouthO-delta);
          FragColor=textureColor;
    }

}
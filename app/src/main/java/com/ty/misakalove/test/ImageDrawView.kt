package com.ty.misakalove.test

import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.widget.ImageView
import com.google.gson.Gson

/**
 * Class:ImageDrawView
 * Author: TY
 * Description:
 * Date:  2019/1/31
 * 重庆锐云科技有限公司

 */

class ImageDrawView(context: Context) : ImageView(context) {




    var testBean: TestBean
    var paint: Paint = Paint()


    init {
        paint.color= Color.RED
        paint.textSize= 15F

        testBean = Gson().fromJson("{\n" +
                "    \"minAppVersion\": 400,\n" +
                "    \"blendAlpha\": 1.0,\n" +
                "    \"featureType\": 0,\n" +
                "    \"grayScale\": 0,\n" +
                "    \"blendMode\": 1,\n" +
                "    \"useMesh\": 1,\n" +
                "    \"facePoints\": [\n" +
                "        150, 468,\n" +
                "        153, 498,\n" +
                "        156, 528,\n" +
                "        162, 561,\n" +
                "        169, 595,\n" +
                "        175, 622,\n" +
                "        181, 649,\n" +
                "        186, 672,\n" +
                "        191, 695,\n" +
                "        203, 716,\n" +
                "        214, 738,\n" +
                "        238, 776,\n" +
                "        258, 793,\n" +
                "        277, 811,\n" +
                "        311, 843,\n" +
                "        351, 868,\n" +
                "        398, 876,\n" +
                "        445, 866,\n" +
                "        491, 841,\n" +
                "        528, 807,\n" +
                "        543, 788,\n" +
                "        558, 769,\n" +
                "        585, 734,\n" +
                "        595, 712,\n" +
                "        605, 690,\n" +
                "        611, 668,\n" +
                "        618, 645,\n" +
                "        624, 619,\n" +
                "        630, 592,\n" +
                "        631, 558,\n" +
                "        633, 524,\n" +
                "        636, 494,\n" +
                "        639, 464,\n" +
                "        199, 446,\n" +
                "        239, 444,\n" +
                "        280, 448,\n" +
                "        321, 456,\n" +
                "        362, 458,\n" +
                "        327, 433,\n" +
                "        283, 425,\n" +
                "        239, 425,\n" +
                "        595, 445,\n" +
                "        555, 444,\n" +
                "        515, 452,\n" +
                "        484, 457,\n" +
                "        438, 460,\n" +
                "        464, 435,\n" +
                "        508, 422,\n" +
                "        559, 422,\n" +
                "        241, 506,\n" +
                "        260, 518,\n" +
                "        285, 522,\n" +
                "        309, 520,\n" +
                "        336, 511,\n" +
                "        317, 493,\n" +
                "        287, 483,\n" +
                "        263, 489,\n" +
                "        291, 504,\n" +
                "        291, 502,\n" +
                "        558, 501,\n" +
                "        537, 516,\n" +
                "        511, 523,\n" +
                "        487, 521,\n" +
                "        460, 512,\n" +
                "        481, 492,\n" +
                "        508, 484,\n" +
                "        534, 488,\n" +
                "        508, 502,\n" +
                "        508, 500,\n" +
                "        370, 512,\n" +
                "        366, 600,\n" +
                "        340, 649,\n" +
                "        370, 668,\n" +
                "        400, 672,\n" +
                "        428, 666,\n" +
                "        458, 647,\n" +
                "        432, 601,\n" +
                "        430, 513,\n" +
                "        400, 636,\n" +
                "        312, 719,\n" +
                "        489, 717,\n" +
                "        335, 743,\n" +
                "        364, 759,\n" +
                "        399, 766,\n" +
                "        434, 758,\n" +
                "        464, 741,\n" +
                "        442, 736,\n" +
                "        401, 741,\n" +
                "        352, 736,\n" +
                "        346, 713,\n" +
                "        379, 710,\n" +
                "        401, 714,\n" +
                "        421, 713,\n" +
                "        454, 713,\n" +
                "        442, 729,\n" +
                "        400, 731,\n" +
                "        354, 727,\n" +
                "        341, 733,\n" +
                "        461, 728,\n" +
                "        400, 512,\n" +
                "        404, 460,\n" +
                "        400, 692,\n" +
                "        205, 205,\n" +
                "        398, 275,\n" +
                "        598, 197,\n" +
                "        400, 356\n" +
                "    ]\n" +
                ",\n" +
                "    \"shaderType\": 8,\n" +
                "    \"maxFaceCount\": 2,\n" +
                "    \"detectorFlag\": 2\n" +
                "\n" +
                "\n" +
                ",\n" +
                "    \"faceExchangeImage\": \"lian.png\"\n" +
                "\n" +
                ",\"itemList\":[\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[402,318],\"position\":[0,0],\"frameDuration\":83,\"frames\":24,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[89],\"width\":800,\"height\":400,\"type\":2,\"id\":\"erduo\"},\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[229,44],\"position\":[0,0],\"frameDuration\":83,\"frames\":24,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[81],\"width\":452,\"height\":472,\"type\":2,\"id\":\"xiangquan\"},\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[378,114],\"position\":[0,0],\"frameDuration\":83,\"frames\":24,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[64],\"width\":760,\"height\":520,\"type\":2,\"id\":\"xiaoyouling\"},\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[489,49],\"position\":[0,0],\"frameDuration\":83,\"frames\":24,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[81],\"width\":700,\"height\":950,\"type\":2,\"id\":\"shoupai\"},\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[0,0],\"position\":[0.1,0],\"frameDuration\":83,\"frames\":24,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[87],\"width\":580,\"height\":960,\"type\":1,\"id\":\"biankuang\"},\n" +
                "{\"scalePivots\":[0,18],\"scaleFactor\":480,\"zIndex\":0,\"anchorPoint\":[0,0],\"position\":[0,0],\"frameDuration\":6028,\"frames\":1,\"playCount\":0,\"triggerType\":2,\"alwaysTriggered\":1,\"alignFacePoints\":[87],\"width\":0,\"height\":0,\"type\":2,\"id\":\"BGM\",\"audio\":\"bgm.mp3\"}\n" +
                "]\n" +
                ",\"distortionList\":\n" +
                "[\n" +
                "    {\n" +
                "        \"radius\": 500,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.04,\n" +
                "        \"position\": 69,\n" +
                "        \"direction\": 2\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.18,\n" +
                "        \"position\": 35,\n" +
                "        \"direction\": 1\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.18,\n" +
                "        \"position\": 45,\n" +
                "        \"direction\": 3\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.2,\n" +
                "        \"position\": 41,\n" +
                "        \"direction\": 2\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.2,\n" +
                "        \"position\": 51,\n" +
                "        \"direction\": 2\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 90,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.14,\n" +
                "        \"position\": 37,\n" +
                "        \"direction\": 4\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 90,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.14,\n" +
                "        \"position\": 47,\n" +
                "        \"direction\": 4\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.12,\n" +
                "        \"position\": 42,\n" +
                "        \"direction\": 2\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 80,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.12,\n" +
                "        \"position\": 52,\n" +
                "        \"direction\": 2\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 70,\n" +
                "        \"distortion\": 1,\n" +
                "        \"strength\": 0.15,\n" +
                "        \"position\": 43,\n" +
                "        \"direction\": 0\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 70,\n" +
                "        \"distortion\": 1,\n" +
                "        \"strength\": 0.15,\n" +
                "        \"position\": 53,\n" +
                "        \"direction\": 0\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 160,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.07,\n" +
                "        \"position\": 57,\n" +
                "        \"direction\": 3\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 160,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.07,\n" +
                "        \"position\": 61,\n" +
                "        \"direction\": 1\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 120,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.05,\n" +
                "        \"position\": 56,\n" +
                "        \"direction\": 3\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 120,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.05,\n" +
                "        \"position\": 62,\n" +
                "        \"direction\": 1\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 200,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.05,\n" +
                "        \"position\": 0,\n" +
                "        \"direction\": 3\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 200,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.05,\n" +
                "        \"position\": 18,\n" +
                "        \"direction\": 1\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 220,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.06,\n" +
                "        \"position\": 2,\n" +
                "        \"direction\": 6\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 220,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.06,\n" +
                "        \"position\": 16,\n" +
                "        \"direction\": 5\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 200,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.08,\n" +
                "        \"position\": 5,\n" +
                "        \"direction\": 6\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 200,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.08,\n" +
                "        \"position\": 13,\n" +
                "        \"direction\": 5\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 220,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.07,\n" +
                "        \"position\": 7,\n" +
                "        \"direction\": 6\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 220,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.07,\n" +
                "        \"position\": 11,\n" +
                "        \"direction\": 5\n" +
                "    },\n" +
                "    {\n" +
                "        \"radius\": 260,\n" +
                "        \"distortion\": 3,\n" +
                "        \"strength\": 0.05,\n" +
                "        \"position\": 9,\n" +
                "        \"direction\": 2\n" +
                "    }\n" +
                "]}", TestBean::class.java)
    }

    override fun onDraw(canvas: Canvas?) {
        super.onDraw(canvas)
        for (i in testBean.facePoints.indices step 2) {
            canvas?.drawText("${i/2}", testBean.facePoints[i].toFloat()*width/800, testBean.facePoints[i+1].toFloat()*height/1067,paint)
        }
    }

}
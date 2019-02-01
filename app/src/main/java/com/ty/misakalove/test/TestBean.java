package com.ty.misakalove.test;

import java.util.List;

/**
 * Class:TestBean
 * Author: TY
 * Description:
 * Date:  2019/1/31
 * 重庆锐云科技有限公司
 */
public class TestBean {

    /**
     * minAppVersion : 400
     * blendAlpha : 1.0
     * featureType : 0
     * grayScale : 0
     * blendMode : 1
     * useMesh : 1
     * facePoints : [156,528,169,595,181,649,191,695,214,738,238,776,277,811,311,843,351,868,398,876,445,
     * 866,491,841,528,807,558,769,585,734,605,690,618,645,630,592,633,524,199,446,239,444,280,448,321,456,
     * 362,458,327,433,283,425,239,425,595,445,555,444,515,452,484,457,438,460,464,435,508,422,559,422,241,
     * 506,260,518,285,522,309,520,336,511,317,493,287,483,263,489,291,504,291,502,558,501,537,516,511,523,
     * 487,521,460,512,481,492,508,484,534,488,508,502,508,500,370,512,366,600,340,649,370,668,400,672,428,
     * 666,458,647,432,601,430,513,400,636,312,719,489,717,335,743,364,759,399,766,434,758,464,741,442,736,
     * 401,741,352,736,346,713,379,710,401,714,421,713,454,713,442,729,400,731,354,727,400,512,404,460,400,
     * 692,205,205,398,275,598,197,400,356]
     * shaderType : 8
     * maxFaceCount : 2
     * detectorFlag : 2
     * faceExchangeImage : lian.png
     * itemList : [{"scalePivots":[0,18],"scaleFactor":480,"zIndex":0,"anchorPoint":[402,318],
     * "position":[0,0],"frameDuration":83,"frames":24,"playCount":0,"triggerType":2,"alwaysTriggered":1,
     * "alignFacePoints":[89],"width":800,"height":400,"type":2,"id":"erduo"},{"scalePivots":[0,18],
     * "scaleFactor":480,"zIndex":0,"anchorPoint":[229,44],"position":[0,0],"frameDuration":83,"frames":24,
     * "playCount":0,"triggerType":2,"alwaysTriggered":1,"alignFacePoints":[81],"width":452,"height":472,
     * "type":2,"id":"xiangquan"},{"scalePivots":[0,18],"scaleFactor":480,"zIndex":0,"anchorPoint":[378,
     * 114],"position":[0,0],"frameDuration":83,"frames":24,"playCount":0,"triggerType":2,
     * "alwaysTriggered":1,"alignFacePoints":[64],"width":760,"height":520,"type":2,"id":"xiaoyouling"},{
     * "scalePivots":[0,18],"scaleFactor":480,"zIndex":0,"anchorPoint":[489,49],"position":[0,0],
     * "frameDuration":83,"frames":24,"playCount":0,"triggerType":2,"alwaysTriggered":1,
     * "alignFacePoints":[81],"width":700,"height":950,"type":2,"id":"shoupai"},{"scalePivots":[0,18],
     * "scaleFactor":480,"zIndex":0,"anchorPoint":[0,0],"position":[0.1,0],"frameDuration":83,"frames":24,
     * "playCount":0,"triggerType":2,"alwaysTriggered":1,"alignFacePoints":[87],"width":580,"height":960,
     * "type":1,"id":"biankuang"},{"scalePivots":[0,18],"scaleFactor":480,"zIndex":0,"anchorPoint":[0,0],
     * "position":[0,0],"frameDuration":6028,"frames":1,"playCount":0,"triggerType":2,"alwaysTriggered":1,
     * "alignFacePoints":[87],"width":0,"height":0,"type":2,"id":"BGM","audio":"bgm.mp3"}]
     * distortionList : [{"radius":500,"distortion":3,"strength":0.04,"position":69,"direction":2},{"radius
     * ":80,"distortion":3,"strength":0.18,"position":35,"direction":1},{"radius":80,"distortion":3,
     * "strength":0.18,"position":45,"direction":3},{"radius":80,"distortion":3,"strength":0.2,
     * "position":41,"direction":2},{"radius":80,"distortion":3,"strength":0.2,"position":51,"direction":2}
     * ,{"radius":90,"distortion":3,"strength":0.14,"position":37,"direction":4},{"radius":90,
     * "distortion":3,"strength":0.14,"position":47,"direction":4},{"radius":80,"distortion":3,"strength":0
     * .12,"position":42,"direction":2},{"radius":80,"distortion":3,"strength":0.12,"position":52,
     * "direction":2},{"radius":70,"distortion":1,"strength":0.15,"position":43,"direction":0},{"radius
     * ":70,"distortion":1,"strength":0.15,"position":53,"direction":0},{"radius":160,"distortion":3,
     * "strength":0.07,"position":57,"direction":3},{"radius":160,"distortion":3,"strength":0.07,
     * "position":61,"direction":1},{"radius":120,"distortion":3,"strength":0.05,"position":56,
     * "direction":3},{"radius":120,"distortion":3,"strength":0.05,"position":62,"direction":1},{"radius
     * ":200,"distortion":3,"strength":0.05,"position":0,"direction":3},{"radius":200,"distortion":3,
     * "strength":0.05,"position":18,"direction":1},{"radius":220,"distortion":3,"strength":0.06,
     * "position":2,"direction":6},{"radius":220,"distortion":3,"strength":0.06,"position":16,"direction":5
     * },{"radius":200,"distortion":3,"strength":0.08,"position":5,"direction":6},{"radius":200,
     * "distortion":3,"strength":0.08,"position":13,"direction":5},{"radius":220,"distortion":3,
     * "strength":0.07,"position":7,"direction":6},{"radius":220,"distortion":3,"strength":0.07,
     * "position":11,"direction":5},{"radius":260,"distortion":3,"strength":0.05,"position":9,"direction":2}]
     */

    public List<Integer> facePoints;

    public static class ItemListBean {
        /**
         * scalePivots : [0,18]
         * scaleFactor : 480
         * zIndex : 0
         * anchorPoint : [402,318]
         * position : [0,0]
         * frameDuration : 83
         * frames : 24
         * playCount : 0
         * triggerType : 2
         * alwaysTriggered : 1
         * alignFacePoints : [89]
         * width : 800
         * height : 400
         * type : 2
         * id : erduo
         * audio : bgm.mp3
         */

        public int scaleFactor;
        public int zIndex;
        public int frameDuration;
        public int frames;
        public int playCount;
        public int triggerType;
        public int alwaysTriggered;
        public int width;
        public int height;
        public int type;
        public String id;
        public String audio;
        public List<Integer> scalePivots;
        public List<Integer> anchorPoint;
        public List<Integer> position;
        public List<Integer> alignFacePoints;
    }

    public static class DistortionListBean {
        /**
         * radius : 500
         * distortion : 3
         * strength : 0.04
         * position : 69
         * direction : 2
         */

        public int radius;
        public int distortion;
        public double strength;
        public int position;
        public int direction;
    }
}

//
// Created by TY on 2019/1/31.
//



namespace faceConstant {

    int convert2FacePPSize=106;

    unsigned char convert2FacePPIndex[] = {
            11, 10, 9,  8,  7,  6,  5,  102,66, 82,//0-9
            81, 80, 57, 78, 77, 76, 0,  97, 95, 96,//10-19
            100,101,98, 99, 49, 56, 18, 68, 16, 17,//20-29
            14, 15, 13, 19,  84, 29, 79, 28, 24, 73,//30-39
            70, 75, 74, 21, 23, 22, 69, 88, 89, 46,//40-49
            87, 86, 94, 1,  53, 59, 67, 12, 27, 104,//50-59
            85, 20, 47, 51, 62, 83, 58, 60, 44, 54,//60-69
            71, 48, 34, 3,  55, 41, 43, 52, 35, 91,//70-79
            90, 92, 31, 93, 45, 37, 39, 38,  26, 33,//80-89
            50, 4,  30, 32, 64, 65, 61, 40, 36, 25,//90-99
            42, 2, 103, 63, 72, 105
    };
    int colorIndexSize=106;

    char colorIndex[] = {
            //脸边框
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,   /*0-15*/
            16,                                                                 //16
            17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,     //17-32
            33, 40, 39, 39, 38, 46, 47, 48, 48, 41, 99, 99, 78, 78, 72, 72,     //33-48
            73, 74, 74, 49, 56, 54, 53, 52, 50, 63, 64, 66, 69, 60, 62, 34,     //49-64
            35, 36, 37, 44, 43, 42, 42, 55, 51, 57, 66, 61, 68, 69, 77, 70,      //65-80
            76, 71, 75, 79, 89, 90, 91, 92, 93, 80, 85, 84, 83, 82, 81, 97,     //81-96
            96, 95, 94, 98, 86, 87, 88, 72, 105                                 //97-105
    };


   int textureCoordSize=106*2;

    float textureCoord[] = {
            150, 468,
            153, 498,
            156, 528,
            162, 561,
            169, 595,
            175, 622,
            181, 649,
            186, 672,
            191, 695,
            203, 716,
            214, 738,
            238, 776,
            258, 793,
            277, 811,
            311, 843,
            351, 868,
            398, 876,
            445, 866,
            491, 841,
            528, 807,
            543, 788,
            558, 769,
            585, 734,
            595, 712,
            605, 690,
            611, 668,
            618, 645,
            624, 619,
            630, 592,
            631, 558,
            633, 524,
            636, 494,
            639, 464,
            199, 446,
            239, 444,
            280, 448,
            321, 456,
            362, 458,
            327, 433,
            283, 425,
            239, 425,
            595, 445,
            555, 444,
            515, 452,
            484, 457,
            438, 460,
            464, 435,
            508, 422,
            559, 422,
            241, 506,
            260, 518,
            285, 522,
            309, 520,
            336, 511,
            317, 493,
            287, 483,
            263, 489,
            291, 504,
            291, 502,
            558, 501,
            537, 516,
            511, 523,
            487, 521,
            460, 512,
            481, 492,
            508, 484,
            534, 488,
            508, 502,
            508, 500,
            370, 512,
            366, 600,
            340, 649,
            370, 668,
            400, 672,
            428, 666,
            458, 647,
            432, 601,
            430, 513,
            400, 636,
            312, 719,
            489, 717,
            335, 743,
            364, 759,
            399, 766,
            434, 758,
            464, 741,
            442, 736,
            401, 741,
            352, 736,
            346, 713,
            379, 710,
            401, 714,
            421, 713,
            454, 713,
            442, 729,
            400, 731,
            354, 727,
            325, 726,//97
            473, 726,
            400, 512,
            404, 460,
            400, 692,
            205, 205,
            398, 275,
            598, 197,
            400, 356
    };

     int mouseIndexSize=44*3;
     int mouthIndex[] = {
            // 上嘴唇部分 10个
            84, 85, 96,
            96, 85, 97,
            97, 85, 86,
            86, 97, 98,
            86, 98, 87,
            87, 98, 88,
            88, 98, 99,
            88, 99, 89,
            89, 99, 100,
            89, 100, 90,
            // 下嘴唇部分 10个
            90, 100, 91,
            100, 91, 101,
            101, 91, 92,
            101, 92, 102,
            102, 92, 93,
            102, 93, 94,
            102, 94, 103,
            103, 94, 95,
            103, 95, 96,
            96, 95, 84,
            // 嘴巴与下巴之间的部分(关键点7 到25 与嘴巴鼻翼围起来的区域) 24个
            7, 84, 8,
            8, 84, 9,
            9, 84, 10,
            10, 84, 95,
            10, 95, 11,
            11, 95, 12,
            12, 95, 94,
            12, 94, 13,
            13, 94, 14,
            14, 94, 93,
            14, 93, 15,
            15, 93, 16,
            16, 93, 17,
            17, 93, 18,
            18, 93, 92,
            18, 92, 19,
            19, 92, 20,
            20, 92, 91,
            20, 91, 21,
            21, 91, 22,
            22, 91, 90,
            22, 90, 23,
            23, 90, 24,
            24, 90, 25
    };

    int triangleIndexSize=116*3;
    int triangleIndex[] = {

            // 左眼 21个三角形
            0, 33, 52,
            33, 52, 64,
            52, 64, 53,
            64, 53, 65,
            65, 53, 72,
            65, 72, 66,
            66, 72, 54,
            66, 54, 67,
            54, 67, 55,
            67, 55, 78,
            67, 78, 43,
            52, 53, 57,
            53, 72, 74,
            53, 74, 57,
            74, 57, 73,
            72, 54, 104,
            72, 104, 74,
            74, 104, 73,
            73, 104, 56,
            104, 56, 54,
            54, 56, 55,
            // 右眼 21个三角形
            68, 43, 79,
            68, 79, 58,
            68, 58, 59,
            68, 59, 69,
            69, 59, 75,
            69, 75, 70,
            70, 75, 60,
            70, 60, 71,
            71, 60, 61,
            71, 61, 42,
            42, 61, 32,
            61, 60, 62,
            60, 75, 77,
            60, 77, 62,
            77, 62, 76,
            75, 77, 105,
            77, 105, 76,
            105, 76, 63,
            105, 63, 59,
            105, 59, 75,
            59, 63, 58,
            // 鼻子部分 16个
            78, 43, 44,
            43, 44, 79,
            78, 44, 80,
            79, 81, 44,
            80, 44, 45,
            44, 81, 45,
            80, 45, 46,
            45, 81, 46,
            80, 46, 82,
            81, 46, 83,
            82, 46, 47,
            47, 46, 48,
            48, 46, 49,
            49, 46, 50,
            50, 46, 51,
            51, 46, 83,
            //鼻子和嘴巴中间三角形 14个
            7, 82, 84,
            82, 84, 47,
            84, 47, 85,
            85, 47, 48,
            48, 85, 86,
            86, 48, 49,
            49, 86, 87,
            49, 87, 88,
            88, 49, 50,
            88, 50, 89,
            89, 50, 51,
            89, 51, 90,
            51, 90, 83,
            83, 90, 25,
            // 上嘴唇部分 10个
            84, 85, 96,
            96, 85, 97,
            97, 85, 86,
            86, 97, 98,
            86, 98, 87,
            87, 98, 88,
            88, 98, 99,
            88, 99, 89,
            89, 99, 100,
            89, 100, 90,
            // 下嘴唇部分 10个
            90, 100, 91,
            100, 91, 101,
            101, 91, 92,
            101, 92, 102,
            102, 92, 93,
            102, 93, 94,
            102, 94, 103,
            103, 94, 95,
            103, 95, 96,
            96, 95, 84,
            // 嘴巴与下巴之间的部分(关键点7 到25 与嘴巴鼻翼围起来的区域) 24个
            7, 84, 8,
            8, 84, 9,
            9, 84, 10,
            10, 84, 95,
            10, 95, 11,
            11, 95, 12,
            12, 95, 94,
            12, 94, 13,
            13, 94, 14,
            14, 94, 93,
            14, 93, 15,
            15, 93, 16,
            16, 93, 17,
            17, 93, 18,
            18, 93, 92,
            18, 92, 19,
            19, 92, 20,
            20, 92, 91,
            20, 91, 21,
            21, 91, 22,
            22, 91, 90,
            22, 90, 23,
            23, 90, 24,
            24, 90, 25
    };


}
//
//switch (i) {
//case 0:
//case 1:
//case 2:
//case 3:
//case 4:
//case 5:
//case 6:
//index = 11-i;
//break;
//case 7:
//index=102;
//break;
//case 8:
//index=66;
//case 9:
//case 10:
//case 11:
//case 13:
//case 14:
//case 15:
//index=91-i;
//break;
//case 12:
//index=57;
//break;
//case 16:
//index=0;
//break;
//case 17:
//index=97;
//break;
//case 18:
//index=95;
//break;
//case 19:
//index=96;
//break;
//case 20:
//case 21:
//index=80+i;
//break;
//case 22:
//case 23:
//index=76+i;
//break;
//case 24:
//index=49;
//break;
//case 25:
//index=56;
//break;
//case 26:
//index=18;
//break;
//case 27:
//index=68;
//break;
//case 28:
//case 29:
//index=-12+i;
//break;
//case 30:
//index=14;
//break;
//case 31:
//index=15;
//break;
//case 32:
//index=13;
//break;
//case 34:
//index=84;
//break;
//case 35:
//index=29;
//break;
//case 36:
//index=79;
//break;
//case 37:
//index=28;
//break;
//case 38:
//index=24;
//break;
//case 39:
//index=73;
//break;
//case 40:
//index=70;
//break;
//case 41:
//index=75;
//break;
//case 42:
//index=74;
//break;
//case 43:
//index=21;
//break;
//case 44:
//index=23;
//break;
//case 45:
//index=22;
//break;
//case 46:
//index=69;
//break;
//case 47:
//index=88;
//break;
//case 48:
//index=89;
//break;
//case 49:
//index=46;
//break;
//case 50:
//index=87;
//break;
//case 51:
//index=86;
//break;
//case 52:
//index=94;
//break;
//case 53:
//index=1;
//break;
//case 54:
//index=83;
//break;
//case 55:
//index=59;
//break;
//case 56:
//index=67;
//break;
//case 57:
//index=12;
//break;
//case 58:
//index=27;
//break;
//case 59:
//index=104;
//break;
//case 60:
//index=85;
//break;
//case 61:
//index=20;
//break;
//case 62:
//index=47;
//break;
//case 63:
//index=51;
//break;
//case 64:
//index=62;
//break;
//case 65:
//index=83;
//break;
//case 66:
//index=58;
//break;
//case 67:
//index=60;
//break;
//case 68:
//index=44;
//break;
//case 69:
//index=54;
//break;
//case 70:
//index=52;
//break;
//case 71:
//index=48;
//break;
//case 72:
//index=34;
//break;
//case 73:
//index=3;
//break;
//case 74:
//index=55;
//break;
//case 75:
//index=41;
//break;
//case 76:
//index=43;
//break;
//case 77:
//index=52;
//break;
//case 78:
//index=35;
//break;
//case 79:
//index=91;
//break;
//case 80:
//index=90;
//break;
//case 81:
//index=92;
//break;
//case 82:
//index=31;
//break;
//case 83:
//index=93;
//break;
//case 84:
//index=45;
//break;
//case 85:
//index=37;
//break;
//case 86:
//index=39;
//break;
//case 88:
//index=26;
//break;
//case 89:
//index=33;
//break;
//case 90:
//index=50;
//break;
//case 91:
//index=4;
//break;
//case 92:
//index=30;
//break;
//case 93:
//index=32;
//break;
//case 94:
//index=64;
//break;
//case 95:
//index=65;
//break;
//case 96:
//index=61;
//break;
//case 97:
//index=40;
//break;
//case 98:
//index=36;
//break;
//case 99:
//index=25;
//break;
//case 100:
//index=42;
//break;
//case 101:
//index=2;
//break;
//case 102:
//index=103;
//break;
//case 103:
//index=63;
//break;
//case 104:
//index=72;
//break;
//case 105:
//index=105;
//break;
//}


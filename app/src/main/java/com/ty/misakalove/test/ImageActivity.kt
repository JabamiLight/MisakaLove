package com.ty.misakalove.test

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.util.Log
import com.ty.misakalove.R
import org.jetbrains.anko.wrapContent
import java.util.*


class ImageActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val view=ImageDrawView(this)
        view.setImageResource(R.mipmap.lian)
        setContentView(view)
        view.layoutParams.height= wrapContent
        view.layoutParams.width= wrapContent
        val array=IntArray (106)
        for(i in 0 until  106){
            array[i]   =Test.getIndex(i)
        }
        Log.d("tedu", Arrays.toString(array));
    }
}

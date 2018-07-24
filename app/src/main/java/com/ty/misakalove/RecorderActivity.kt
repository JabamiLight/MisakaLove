package com.ty.misakalove

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.view.View
import android.view.Window
import android.view.WindowManager
import com.ty.misakalovelibrary.camera.ChangbaRecordingPreviewScheduler
import com.ty.misakalovelibrary.camera.ChangbaVideoCamera
import kotlinx.android.synthetic.main.activity_recorder.*


class RecorderActivity : AppCompatActivity(), View.OnClickListener {

    private var previewScheduler: ChangbaRecordingPreviewScheduler? = null
    private lateinit var videoCamera: ChangbaVideoCamera
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        window.setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_recorder)
        videoCamera = ChangbaVideoCamera(this)
        previewScheduler = ChangbaRecordingPreviewScheduler(surface, videoCamera);
        initView();
    }

    private fun initView() {
        iv_close.setOnClickListener(this)
        cb_rotate.setOnClickListener(this)
    }

    override fun onDestroy() {
        super.onDestroy()
        previewScheduler?.stop()
    }

    override fun onClick(v: View?) {
        when(v?.id){
            R.id.iv_close->finish()
            R.id.cb_rotate-> previewScheduler?.switchCameraFacing()
        }
    }

}

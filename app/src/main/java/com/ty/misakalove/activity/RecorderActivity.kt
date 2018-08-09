package com.ty.misakalove.activity

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import android.view.Window
import android.view.WindowManager
import com.ty.misakalove.R
import com.ty.misakalove.adapter.FilterAdapter
import com.ty.misakalove.common.MagicFilterType
import com.ty.misakalovelibrary.camera.ChangbaRecordingPreviewScheduler
import com.ty.misakalovelibrary.camera.ChangbaVideoCamera
import kotlinx.android.synthetic.main.activity_recorder.*
import kotlinx.android.synthetic.main.include_filter_layout.*


class RecorderActivity : AppCompatActivity(), View.OnClickListener {

    private var previewScheduler: ChangbaRecordingPreviewScheduler? = null
    private lateinit var videoCamera: ChangbaVideoCamera
    private var types: Array<MagicFilterType>? = null
    private var adapter: FilterAdapter? = null
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
        iv_filter.setOnClickListener(this)
        types = arrayOf<MagicFilterType>(MagicFilterType.NONE, MagicFilterType.FAIRYTALE, MagicFilterType.SUNRISE, MagicFilterType.SUNSET, MagicFilterType.WHITECAT, MagicFilterType.BLACKCAT, MagicFilterType.SKINWHITEN, MagicFilterType.HEALTHY, MagicFilterType.SWEETS, MagicFilterType.ROMANCE, MagicFilterType.SAKURA, MagicFilterType.WARM, MagicFilterType.ANTIQUE, MagicFilterType.NOSTALGIA, MagicFilterType.CALM, MagicFilterType.LATTE, MagicFilterType.TENDER, MagicFilterType.COOL, MagicFilterType.EMERALD, MagicFilterType.EVERGREEN, MagicFilterType.CRAYON, MagicFilterType.SKETCH, MagicFilterType.AMARO, MagicFilterType.BRANNAN, MagicFilterType.BROOKLYN, MagicFilterType.EARLYBIRD, MagicFilterType.FREUD, MagicFilterType.HEFE, MagicFilterType.HUDSON, MagicFilterType.INKWELL, MagicFilterType.KEVIN, MagicFilterType.LOMO, MagicFilterType.N1977, MagicFilterType.NASHVILLE, MagicFilterType.PIXAR, MagicFilterType.RISE, MagicFilterType.SIERRA, MagicFilterType.SUTRO, MagicFilterType.TOASTER2, MagicFilterType.VALENCIA, MagicFilterType.WALDEN, MagicFilterType.XPROII)
        adapter = FilterAdapter(this, types)
        var manager = rv_filter.layoutManager as LinearLayoutManager
        manager.orientation=RecyclerView.HORIZONTAL
        rv_filter.adapter=adapter
    }

    override fun onDestroy() {
        super.onDestroy()
    }

    override fun onBackPressed() {
        previewScheduler?.stop()
        super.onBackPressed()
    }

    override fun onClick(v: View?) {
        when (v?.id) {
            R.id.iv_close -> {
                previewScheduler?.stop()
                finish()
            }
            R.id.cb_rotate -> previewScheduler?.switchCameraFacing()
            R.id.iv_filter->{
                fl_config.visibility=View.GONE
                ll_filter.visibility=View.VISIBLE
            }
        }
    }

}

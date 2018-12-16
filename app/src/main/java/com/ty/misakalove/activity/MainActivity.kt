package com.ty.misakalove.activity

import android.Manifest
import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import com.tbruyelle.rxpermissions2.RxPermissions
import com.ty.misakalove.MyApplication
import com.ty.misakalove.R
import com.ty.misakalovelibrary.utils.FileUtils
import io.reactivex.Observable
import io.reactivex.Observer
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.disposables.Disposable
import io.reactivex.schedulers.Schedulers
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.startActivity
import org.jetbrains.anko.toast


class MainActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val rxPermissions = RxPermissions(this); // where this is an Activity or Fragment instance
        tv_record.setOnClickListener {
            rxPermissions
                    .request(Manifest.permission.CAMERA,
                            Manifest.permission.RECORD_AUDIO,
                            Manifest.permission.READ_EXTERNAL_STORAGE,
                            Manifest.permission.WRITE_EXTERNAL_STORAGE
                    )
                    .flatMap {
                        if (it) {
                            Observable.create<String> {
                                FileUtils.copyFileFromRawToOthers(MyApplication.instance, "detfaces/shape_predictor_68_face_landmarks.dat", "/sdcard/misakaLove/shape_predictor_68_face_landmarks.dat")
                                it.onNext("复制文件成功")
                            }.subscribeOn(Schedulers.io())
                                    .observeOn(AndroidSchedulers.mainThread())
                        } else {
                            Observable.error(IllegalAccessException("复制失败"))
                        }
                    }.subscribe(object : Observer<String?> {
                        override fun onComplete() {
                        }

                        override fun onSubscribe(d: Disposable) {
                        }

                        override fun onNext(t: String) {
                            toast(t)
                            startActivity<RecorderActivity>()
                        }
                        override fun onError(e: Throwable) {
                            e.message?.let { it1 -> toast(it1) }
                        }
                    })
        }


    }

}

package com.example.app;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class MyActivity extends Activity
{

    static {
        System.loadLibrary("hello");
    }


    public native String invokeNativeFunction(); /**
    * Called when the activity is first created.
    */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        String Hello=invokeNativeFunction(); // String Hello=" TOTO";
        Log.d("TEST", Hello);
    }
}
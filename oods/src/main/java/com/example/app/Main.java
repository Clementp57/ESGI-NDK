package com.example.app;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class Main extends Activity
{

    static {
        System.loadLibrary("oods");
    }

    public native int[] gift();

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        int[] test = gift();
        if(test == null) {
            Log.d("DEBUG", "IMPOSSIBLE");
        } else {
            for(int i = 0; i < test.length; i++) {
                Log.d("DEBUG", "Ood " + (i + 1) + " : " + test[i]);
            }
        }

    }




}

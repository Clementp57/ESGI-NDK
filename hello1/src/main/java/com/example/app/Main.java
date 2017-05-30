package com.example.app;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.util.Log;

public class Main extends Activity
{

    static {
        System.loadLibrary("hello");
    }

    public native String invokeNativeFunction();
    public native int computeFibo(int n);

    public int fiboJAVA(int n) {
        if (n <= 1)
            return n;
        return computeFibo(n-1) + computeFibo(n-2);
    }

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.main);
        TextView helloText=(TextView) findViewById(R.id.tv);

        long startTime = System.currentTimeMillis();
        fiboJAVA(40);
        long endTime = System.currentTimeMillis();
        long totalTimeJAVA = endTime - startTime;

        startTime = System.currentTimeMillis();
        computeFibo(40);
        endTime = System.currentTimeMillis();
        long totalTimeC = endTime - startTime;


        helloText.setText("Java Time for 40 : " + totalTimeJAVA + " \n" + "C Time for 40 : " + totalTimeC);

        //TextView helloText=(TextView) findViewById(R.id.textView);
//        String Hello = invokeNativeFunction();
//        System.out.prinln(Hello);
        //String Hello=" TOTO";
        //helloText.setText(Hello);
    }

}

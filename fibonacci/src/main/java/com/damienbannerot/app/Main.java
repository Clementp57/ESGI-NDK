package com.damienbannerot.app;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import java.util.Date;

public class Main extends Activity
{

    static {
        System.loadLibrary("helloNDK");
    }

    public native String invokeNativeFunction();
    public native int fibonacci(int n);
    public native int fibonacciWithCallback(int n);

    long time1CB, time2CB;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        TextView helloText = (TextView) findViewById(R.id.logview);
        int index = 40;
        /*java*/
        long time1 = System.currentTimeMillis();
        javaFibonacci(index);
        long time2 = System.currentTimeMillis();
        /*native*/
        long time3 = System.currentTimeMillis();
        fibonacci(index);
        long time4 = System.currentTimeMillis();

        time1CB = System.currentTimeMillis();
        fibonacciWithCallback(index);

        String Hello = "fibonacci("+index+") -> native time : "+(time4-time3)+"  |  java time : "+(time2-time1);
        //String Hello = " TOTO";
        helloText.setText(Hello);


    }

    public int javaFibonacci(int n) {
      if (n<=1)
        return n;
      return (fibonacci(n-1))+(fibonacci(n-2));
    }

    public void fibonacciCallback(int n) {
      time2CB = System.currentTimeMillis();
      TextView cbText = (TextView) findViewById(R.id.logview2);
      cbText.setText("callback time : "+(time2CB-time1CB));
    }

}

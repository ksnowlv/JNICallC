package com.ksnowlv.jnicallc;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JavaPerson person = new JavaPerson();
        person.setAge(10);
        Log.i("------JNICallC++: Android person age =  ","" + person.getAge());
        person.setName("ksnowlv(律威)");
        Log.i("------JNICallC++: Android person name =  ","" + person.getName());
    }
}

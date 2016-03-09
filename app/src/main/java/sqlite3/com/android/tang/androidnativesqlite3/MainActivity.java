package main.java.sqlite3.com.android.tang.androidnativesqlite3;

import android.database.Cursor;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.LinearLayout;
import android.widget.Toast;

import java.io.File;

import sqlite3.com.android.tang.androidnativesqlite3.R;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    DbNative dbNative;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        findViewById(R.id.button).setOnClickListener(this);
        findViewById(R.id.button2).setOnClickListener(this);
        findViewById(R.id.button3).setOnClickListener(this);
        findViewById(R.id.button4).setOnClickListener(this);
        findViewById(R.id.button5).setOnClickListener(this);

        File externalFolder = this.getFilesDir();
        File dbFile = new File(externalFolder.getAbsolutePath(),"temp.db");



        dbNative = new DbNative();
        Log.i("@@@@@",dbNative.test());
        dbNative.createDB(dbFile.getAbsolutePath());
    }

    @Override
    public void onClick(View v) {
        int viewID = v.getId();
        boolean ret = false ;
        if(viewID == R.id.button){
            for(int i = 0; i < 10 ; i++){
                if(!dbNative.addObject("INSERT INTO customers(name) VALUES('roman10')")) break;
            }

        }else if(viewID == R.id.button2){
            ret = dbNative.deleteObject("");
        }else if(viewID == R.id.button3){
            ret = dbNative.updateObject("");
        }else if(viewID == R.id.button4){
            ret = dbNative.createTableNative("CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY,name TEXT NOT NULL)");
        }else if(viewID == R.id.button5){
            CursorNative cNative = dbNative.queryObject("SELECT * from customers");
            while (cNative.next()){
                int index = cNative.getColumnIndex("id");
                int id = cNative.getInt(index);
                Log.i("@@@@@",String.valueOf(id).toString());
            }
            cNative.release();
        }

        if(ret){
            Toast.makeText(MainActivity.this,"suc!",Toast.LENGTH_SHORT).show();
        }
    }
}

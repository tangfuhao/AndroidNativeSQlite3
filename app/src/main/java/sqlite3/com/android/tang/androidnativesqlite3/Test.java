package main.java.sqlite3.com.android.tang.androidnativesqlite3;

/**
 * Created by tang on 16/3/4.
 */
public class Test {
    static {
        System.loadLibrary("native");
    }

    public native String test();
}

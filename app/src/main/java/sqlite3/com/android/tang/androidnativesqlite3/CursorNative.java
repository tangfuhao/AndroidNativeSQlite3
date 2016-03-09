package main.java.sqlite3.com.android.tang.androidnativesqlite3;

/**
 * Created by tang on 16/3/8.
 */
public class CursorNative {
    private int cppObject;

    public CursorNative(int cppObject) {
        this.cppObject = cppObject;
    }

    public void release(){
        releaseNative(cppObject);
    }


    int getColumnCount(){
        return getColumnCountNative(cppObject);
    }
    int getColumnIndex(String columName){
        return getColumnIndexNative(cppObject,columName);
    }
    int getCount(){
        return getCountNative(cppObject);
    }

    public int getInt(int index) {
        return getIntNative(cppObject,index);
    }

    public boolean next(){
        return nextNative(cppObject);
    }

    public boolean reset(){
        return resetNative(cppObject);
    }

    private native boolean releaseNative(int cppObject);
    private native int getIntNative(int cppObject,int index);
    private native int getColumnCountNative(int cppObject);
    private native int getColumnIndexNative(int cppObject,String columName);
    private native int getCountNative(int cppObject);
    private native boolean nextNative(int cppObject);
    private native boolean resetNative(int cppObject);



}

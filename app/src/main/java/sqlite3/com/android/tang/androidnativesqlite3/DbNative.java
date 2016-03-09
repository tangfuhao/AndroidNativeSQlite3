package main.java.sqlite3.com.android.tang.androidnativesqlite3;

/**
 * Created by tang on 16/3/4.
 */
public class DbNative {
    private int cppObject = 0;
    static {
        System.loadLibrary("native");
    }

    public native String test();

    private native int openDB(String dbPath);
    private native boolean releaseDB(int cppObject);
    private native boolean createTable(int cppObject,String sql);
    private native boolean add(int cppObject,String sql);
    private native boolean delete(int cppObject,String sql);
    private native boolean update(int cppObject,String sql);
    private native int query(int cppObject,String sql);




    public boolean createDB(String dbName){
        int error = -1;
        do{
            if(cppObject!=0){
                if(!release()){
                    error = 1;
                    break;
                }
            }

            String dbPath = dbName;
            cppObject = openDB(dbPath);

            if(cppObject == 0){
                error = 2;
                break;
            }
        }while(false);
        return error < 0;
    }

    public boolean release(){
        if(cppObject != 0){
            boolean ret = releaseDB(cppObject);
            cppObject = 0;
            return ret;
        }
        return false;
    }

    public boolean createTableNative(String sql){
        if (cppObject != 0){
            return createTable(cppObject,sql);
        }
        return false;
    }

    public boolean addObject(String sql){
        if(cppObject != 0) {
            return add(cppObject, sql);
        }
        return false;
    }

    public boolean deleteObject(String sql){
        if(cppObject != 0) {
            return delete(cppObject, sql);
        }
        return false;
    }

    public boolean updateObject(String sql){
        if(cppObject != 0) {
            return update(cppObject, sql);
        }
        return false;
    }

    public CursorNative queryObject(String sql){
        if(cppObject != 0) {
            int cursorObject = query(cppObject, sql);
            return cursorObject != 0? new CursorNative(cursorObject) : null;
        }
        return null;
    }





}

#include "databaseWrapper.h"
#include <stdio.h>
#include <malloc.h>

DatabaseWrappper::DatabaseWrappper(){
    _db = NULL;
}

DatabaseWrappper::~DatabaseWrappper(){
    if(_db){
        sqlite3_close(_db);
        _db = NULL;
    }
}


bool DatabaseWrappper::excSqlNoCallBack(const char *sqlString){
    do{
        if(!_db) break;

        int rv;
        char *errMsg;

        rv = sqlite3_exec(_db, sqlString, 0, 0, &errMsg);
        if (rv != SQLITE_OK) {
            printf("SQLite statement execution error: %s\n", errMsg);
            break;
        }

        return true;
    }while (0);

    return false;
}


bool DatabaseWrappper::create(const char* dbPath){
    int rv;
    rv = sqlite3_open(dbPath, &_db);
    if (rv != SQLITE_OK) {
        char *error;
        sprintf(error,"Cannot open database: %s\n", sqlite3_errmsg(_db));
        printf("Cannot open database: %s\n", sqlite3_errmsg(_db));
        sqlite3_close(_db);
        return false;
    }

    return true;
}

bool DatabaseWrappper::createTable(const char *sqlString){
    return excSqlNoCallBack(sqlString);
}


bool DatabaseWrappper::add(const char *sqlString) {
    return excSqlNoCallBack(sqlString);
}

bool DatabaseWrappper::del(const char *sqlString) {
    return excSqlNoCallBack(sqlString);
}

bool DatabaseWrappper::update(const char *sqlString) {
    return excSqlNoCallBack(sqlString);
}

CursorWrapper* DatabaseWrappper::query(const char *sqlString){
    do{
        if(!_db) break;


        sqlite3_stmt* stmt;
        int rc;
        char *errMsg;
        //查询数据
        rc = sqlite3_prepare_v2(_db, sqlString, -1, &stmt, 0);
        if (rc != SQLITE_OK)
        {

            char *error;
            sprintf(error,"%s: %s\n", sqlString,sqlite3_errmsg(_db));
//            sqlite3_close(_db);
            break;
        }
        return new CursorWrapper(stmt);
    }while (0);

    return NULL;
}

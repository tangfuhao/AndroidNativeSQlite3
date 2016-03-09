//
// Created by tang on 16/3/8.
//
#include "cursorWrapper.h"
#include <malloc.h>
#include <string.h>

CursorWrapper::CursorWrapper(sqlite3_stmt* stmt){
    _stmt = stmt;
}
CursorWrapper::~CursorWrapper(){
    if(_stmt){
        sqlite3_finalize(_stmt);
        free(_stmt);
        _stmt = NULL;
    }
}


int CursorWrapper::getColumnCount(){
    if(_stmt){
        return sqlite3_column_count(_stmt);
    }

    return -1;
}
int CursorWrapper::getColumnIndex(const char* columName){
    if(_stmt){
        int column_count = sqlite3_column_count(_stmt);
        for(int i = 0; i < column_count; i ++){
            const char * temp = sqlite3_column_name(_stmt,i);
            if(strcmp(temp,columName) == 0)
                return i;
        }
    }

    return -1;
}
int CursorWrapper::getCount(){
    if(_stmt){
        return sqlite3_data_count(_stmt);
    }
    return -1;
}

int CursorWrapper::getInt(int index) {
    if(_stmt && SQLITE_INTEGER == sqlite3_column_type(_stmt , index)){
        return sqlite3_column_int(_stmt,index);
    }
    return -1;
}

bool CursorWrapper::next() {
    if(_stmt){
        return  sqlite3_step(_stmt) == SQLITE_ROW;
    }

    return false;
}

bool CursorWrapper::reset() {
    if(_stmt){
        return sqlite3_reset(_stmt) == SQLITE_OK;
    }
    return false;
}

//
// Created by tang on 16/3/8.
//

#ifndef ANDROIDNATIVESQLITE3_CURSORWRAPPER_H
#define ANDROIDNATIVESQLITE3_CURSORWRAPPER_H

#include "sqlite3.h"

class CursorWrapper {

public:
    CursorWrapper(sqlite3_stmt* stmt);
    ~CursorWrapper();

    int getColumnCount();
    int getColumnIndex(const char* columName);
    int getCount();

    int getInt(int index);

private:
    sqlite3_stmt* _stmt;
};

#endif //ANDROIDNATIVESQLITE3_CURSORWRAPPER_H


//        while (sqlite3_step(stmt) == SQLITE_ROW)
//        {
//            for(i = 0 ; i < ncolumn ; i++ )
//            {
//                vtype = sqlite3_column_type(stmt , i);
//                column_name = sqlite3_column_name(stmt , i);
//                switch( vtype )
//                {
//                    case SQLITE_NULL:
//                        fprintf(stdout, "%s: null\n", column_name);
//                        break;
//                    case SQLITE_INTEGER:
//                        fprintf(stdout, "%s: %d\n", column_name,sqlite3_column_int(stmt,i));
//                        break;
//                    case SQLITE_FLOAT:
//                        fprintf(stdout, "%s: %f\n", column_name,sqlite3_column_double(stmt,i));
//                        break;
//                    case SQLITE_BLOB: /* arguably fall through... */
//                        fprintf(stdout, "%s: BLOB\n", column_name);
//                        break;
//                    case SQLITE_TEXT:
//                        fprintf(stdout, "%s: %s\n", column_name,sqlite3_column_text(stmt,i));
//                        break;
//                    default:
//                        fprintf(stdout, "%s: ERROR [%s]\n", column_name, sqlite3_errmsg(_db));
//                        break;
//                }
//            }
//        }
//
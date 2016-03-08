#ifndef Database_Wrapper_FH
#define Database_Wrapper_FH

#include "sqlite3.h"
#include "cursorWrapper.h"

class DatabaseWrappper {
public:
    DatabaseWrappper();
    ~DatabaseWrappper();

    bool create(const char* dbPath);

    bool createTable(const char *sqlString);

    bool add(const char *sqlString);

    bool del(const char *sqlString);

    bool update(const char *sqlString);

    CursorWrapper* query(const char *sqlString);
private:

    bool excSqlNoCallBack(const char *sqlString);

    sqlite3 *_db;


};


#endif


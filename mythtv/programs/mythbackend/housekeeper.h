#ifndef HOUSEKEEPER_H_
#define HOUSEKEEPER_H_

class QSqlDatabase;

#include <qmutex.h>
#include <qobject.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qprocess.h>

using namespace std;

class HouseKeeper
{
  public:
    HouseKeeper(bool runthread, bool master);
   ~HouseKeeper();

  protected:
    void RunHouseKeeping(void);
    static void *doHouseKeepingThread(void *param);

  private:

    bool wantToRun(const QString &dbTag, int period, int minhour, int maxhour);
    void updateLastrun(const QString &dbTag);
    void flushLogs();
    void runFillDatabase();
    bool threadrunning;
    bool filldbRunning;
    bool isMaster;
};

#endif

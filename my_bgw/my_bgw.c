#include "postgres.h"
#include "fmgr.h"
#include "postmaster/bgworker.h"
#include "storage/latch.h"
#include "pgstat.h"

PG_MODULE_MAGIC;

PGDLLEXPORT void bgw_main(Datum main_arg);

void
_PG_init(void)
{
    BackgroundWorker bgw;
    memset(&bgw, 0, sizeof(bgw));
    bgw.bgw_flags = BGWORKER_SHMEM_ACCESS;
    sprintf(bgw.bgw_function_name, "bgw_main");
    sprintf(bgw.bgw_library_name, "my_bgw");
    sprintf(bgw.bgw_name, "my_bgw");
    bgw.bgw_restart_time = BGW_NEVER_RESTART;
    bgw.bgw_start_time = BgWorkerStart_RecoveryFinished;
    sprintf(bgw.bgw_type, "bgw");

    elog(LOG, "bgw has been registered");
    RegisterBackgroundWorker(&bgw);
}

void
bgw_main(Datum main_arg)
{
    BackgroundWorkerUnblockSignals();
    for (;;)
    {
        elog(LOG, "MY_BGW is still working!!");
        /*
		 * Background workers mustn't call usleep() or any direct equivalent:
		 * instead, they may wait on their process latch, which sleeps as
		 * necessary, but is awakened if postmaster dies.  That way the
		 * background process goes away immediately in an emergency.
		 */
		(void) WaitLatch(MyLatch,
						 WL_LATCH_SET | WL_TIMEOUT | WL_EXIT_ON_PM_DEATH,
						 1000L,
						 PG_WAIT_EXTENSION);
		ResetLatch(MyLatch);

		CHECK_FOR_INTERRUPTS();
    }
}

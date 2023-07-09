#include "postgres.h"
#include "fmgr.h"


static emit_log_hook_type prev_emit_log_hook = NULL;

static void
my_mess(ErrorData *edata)
{
    if (prev_emit_log_hook)
        (*prev_emit_log_hook) (edata);

    ereport(INFO, (errcode(ERRCODE_WARNING), errmsg("You are wrong pal!!")));
}

/* Module entry point */
void
_PG_init(void)
{
    // Save the original hook value.
    prev_emit_log_hook = emit_log_hook;
    // Register our handler.
    emit_log_hook = my_mess;
}

void _PG_fini(void)
{
    // Return back the original hook value.
    emit_log_hook = prev_emit_log_hook;
}
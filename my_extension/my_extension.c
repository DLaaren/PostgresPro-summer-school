#include "postgres.h"
#include "fmgr.h"

//This allows the server to detect obvious 
//incompatibilities, such as code compiled 
//for a different major version of PostgreSQL.
PG_MODULE_MAGIC;

//It is required for dynamically-loaded functions.
PG_FUNCTION_INFO_V1(my_sum);

//suppress most of the complexity of passing arguments and results
Datum
my_sum(PG_FUNCTION_ARGS)
{
    //check if args are null
    bool isnull0 = PG_ARGISNULL(0);
    bool isnull1 = PG_ARGISNULL(1);
    if (isnull0 || isnull1)
    {
        ereport(ERROR,
                errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
                errmsg("args are requred as input"));
    }

    int32 a = PG_GETARG_INT32(0);
    int32 b = PG_GETARG_INT32(1);
    int32 sum = a + b;
    PG_RETURN_INT32(sum);
}
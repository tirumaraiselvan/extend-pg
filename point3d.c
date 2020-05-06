#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

typedef struct
{
    double  x, y, z;
} Point3d;


PG_FUNCTION_INFO_V1(point3d_in);
Datum
point3d_in(PG_FUNCTION_ARGS)
{

	char *str = PG_GETARG_CSTRING(0);
    double  x, y, z;

    if (sscanf(str, "(%lf, %lf, %lf)", &x, &y, &z) != 3)
        ereport(ERROR,
                (errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),
                 errmsg("invalid input syntax for type %s: \"%s\"",
                        "point3d", str)));    

    Point3d  *new_point3d = (Point3d *) palloc(sizeof(Point3d));

    new_point3d->x = x;
    new_point3d->y = y;
    new_point3d->z = z;

    PG_RETURN_POINTER(new_point3d);
}

PG_FUNCTION_INFO_V1(point3d_out);
Datum
point3d_out(PG_FUNCTION_ARGS)
{
    Point3d *point3d = (Point3d *) PG_GETARG_POINTER(0);
    char       *result;

    result = psprintf("(%g, %g, %g)", point3d->x, point3d->y, point3d->z);
    PG_RETURN_CSTRING(result);
}

PG_FUNCTION_INFO_V1(point3d_eq);
Datum
point3d_eq(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result = point3d_left->x == point3d_right->x &&
    			  point3d_left->y == point3d_right->y &&
    			  point3d_left->z == point3d_right->z;

    PG_RETURN_BOOL(result);
}

PG_FUNCTION_INFO_V1(point3d_cmp);
Datum
point3d_cmp(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result_bool = point3d_left->x == point3d_right->x &&
    			  point3d_left->y == point3d_right->y &&
    			  point3d_left->z == point3d_right->z;

    int32 result;
    if (result_bool)
    	result = 0;
    else if (point3d_left->x < point3d_right->x)
    	result = -1;
    else result = 1;

    PG_RETURN_INT32(result);
}

PG_FUNCTION_INFO_V1(point3d_lt);
Datum
point3d_lt(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result = point3d_left->x < point3d_right->x;

    PG_RETURN_BOOL(result);
}

PG_FUNCTION_INFO_V1(point3d_gt);
Datum
point3d_gt(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result = point3d_left->x > point3d_right->x;

    PG_RETURN_BOOL(result);
}

PG_FUNCTION_INFO_V1(point3d_lte);
Datum
point3d_lte(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result = point3d_left->x <= point3d_right->x;

    PG_RETURN_BOOL(result);
}

PG_FUNCTION_INFO_V1(point3d_gte);
Datum
point3d_gte(PG_FUNCTION_ARGS)
{
    Point3d *point3d_left  = (Point3d *) PG_GETARG_POINTER(0);
    Point3d *point3d_right = (Point3d *) PG_GETARG_POINTER(1);

    bool result = point3d_left->x >= point3d_right->x;

    PG_RETURN_BOOL(result);
}


PG_FUNCTION_INFO_V1(point3d_hash);
Datum
point3d_hash(PG_FUNCTION_ARGS)
{
    Point3d *point3d = (Point3d *) PG_GETARG_POINTER(0);

    int32 hash;
    hash = (int32) point3d->x * point3d->y * point3d->z;

    PG_RETURN_INT32(hash);
}
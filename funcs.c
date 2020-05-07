#include "postgres.h"
#include "fmgr.h"
#include "executor/executor.h"  /* for GetAttributeByName() */

#include "point3d.c"

/*
    TODO: create a function that given a radius of sphere,
    finds the point that lies farthest from the sphere.

    Since, the only input arg is radius, we need to fetch the points
    from a fixed table. This will involve using SPI (server programming interface)
    to fetch all the points from a table.

PG_FUNCTION_INFO_V1(point_farthest_from_sphere);
Datum
point_farthest_from_sphere(PG_FUNCTION_ARGS)
{
}

*/


/*
    TODO: create a function that given a radius of sphere,
    finds all tuples (of point3d) that lie within the sphere.

    Since, the only input arg is radius, we need to fetch the points
    from a fixed table. This will involve using SPI (server programming interface)
    to fetch all the points from a table and using SRF (set returning function)
    to return the set of points that satisfy the criteria.

PG_FUNCTION_INFO_V1(points_inside_sphere);
Datum
points_inside_sphere(PG_FUNCTION_ARGS)
{
}

*/

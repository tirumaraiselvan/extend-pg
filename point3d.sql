CREATE TYPE point3d; # shell type

CREATE FUNCTION point3d_in(cstring)
RETURNS point3d
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_out(point3d)
RETURNS cstring
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE TYPE point3d (
	internallength = 24,
	input = point3d_in,
	output = point3d_out,
	alignment = double
);

CREATE FUNCTION point3d_eq(point3d, point3d)
RETURNS bool
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_lt(point3d, point3d)
RETURNS bool
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_gt(point3d, point3d)
RETURNS bool
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_lte(point3d, point3d)
RETURNS bool
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_gte(point3d, point3d)
RETURNS bool
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE OPERATOR = (
    leftarg = point3d,
    rightarg = point3d,
    function = point3d_eq,
    commutator = =
);

CREATE OPERATOR < (
    leftarg = point3d,
    rightarg = point3d,
    function = point3d_lt,
    commutator = >,
    negator = >=
);

CREATE OPERATOR > (
    leftarg = point3d,
    rightarg = point3d,
    function = point3d_gt,
    commutator = <,
    negator = <=
);

CREATE OPERATOR <= (
    leftarg = point3d,
    rightarg = point3d,
    function = point3d_lte,
    commutator = >=,
    negator = >
);

CREATE OPERATOR >= (
    leftarg = point3d,
    rightarg = point3d,
    function = point3d_gte,
    commutator = <=,
    negator = <
);

CREATE FUNCTION point3d_cmp(point3d, point3d)
RETURNS int4
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION point3d_hash(point3d)
RETURNS int4
AS 'point3d'
LANGUAGE C IMMUTABLE STRICT;

CREATE OPERATOR CLASS point3d_ops
    DEFAULT FOR TYPE point3d USING hash AS
        OPERATOR        1       = ,
        FUNCTION        1       point3d_hash;

CREATE OPERATOR CLASS point3d_ops
    FOR TYPE point3d USING btree AS
        OPERATOR        1       < ,
        OPERATOR        2       <= ,
        OPERATOR        3       = ,
        OPERATOR        4       >= ,
        OPERATOR        5       > ,
        FUNCTION        1       point3d_cmp;

/*

TODO: see funcs.c, point_farthest_from_sphere

This is a STABLE function as the result depends on rows in table

CREATE FUNCTION point_farthest_from_sphere(int4)
RETURNS point3d
AS 'point3d'
LANGUAGE C STABLE STRICT;

*/

/*

TODO: see funcs.c, points_inside_sphere

This is a STABLE function as the result depends on rows in table

CREATE FUNCTION points_inside_sphere(int4)
RETURNS SETOF point3d
AS 'point3d'
LANGUAGE C STABLE STRICT;

*/
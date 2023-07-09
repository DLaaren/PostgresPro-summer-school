/* contrib/my_extension/my_extension.sql */

-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION my_extension" to load this file. \quit

--
-- my_sum()
--
CREATE OR REPLACE FUNCTION my_sum(int, int)
RETURNS int
AS 'MODULE_PATHNAME', 'my_sum'
LANGUAGE C IMMUTABLE STRICT;
# contrib/my_extension/Makefile

MODULE_big = my_extension
OBJS = \
		my_extension.o \
	    my_log.o		                    # the shared object can be used in psql
EXTENSION = my_extension       			    # the extersion's name
DATA = my_extension--1.0.sql  				# script file to install
REGRESS = my_extension_test 				# the test script file 

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/my_extension
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
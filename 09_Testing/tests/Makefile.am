TESTS = init_free clear_noop push trunc_grow pop
check_PROGRAMS = init_free clear_noop push trunc_grow pop
CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@

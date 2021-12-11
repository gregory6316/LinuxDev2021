bin_PROGRAMS=simple_guesser
pkgdata_DATA=ru/LC_MESSAGES/simple_guesser.mo

@DX_RULES@
ru/LC_MESSAGES/simple_guesser.mo: ru.po dox
	mkdir -p `dirname $@`
	msgfmt --no-hash $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	simple_guesser.pot simple_guesser.c
	xgettext -k_ -c simple_guesser.c -o messages.new.pot
	cp simple_guesser.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
	

dox:
	-$(HELP2MAN) --no-info --output='simple_guesser.1' --name='simple_guesser' ./simple_guesser
	doxygen Doxyfile.in
	
gitclean:
	git clean -fd

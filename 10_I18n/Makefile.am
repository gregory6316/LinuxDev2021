bin_PROGRAMS=simple_guesser
pkgdata_DATA=ru/LC_MESSAGES/simple_guesser.mo

ru/LC_MESSAGES/simple_guesser.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	simple_guesser.pot simple_guesser.c
	xgettext -k_ -c simple_guesser.c -o messages.new.pot
	cp simple_guesser.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

gitclean:
	git clean -fd

Сборка:  
```
autoreconf -fisv && ./configure && make
```
man:
```
man -l simple_guesser.1
```
help:
```
LC_ALL=ru_RU.utf8 ./simple_guesser - на русском
LC_ALL=C ./simple_guesser - на английском
```
Doxygen:
```
browse html/index.html
```
Опции(принимается только 1):
```
-r - римские числа
--help - помощь
--version - версия
```
Удаление генератов:
```
make gitclean
```

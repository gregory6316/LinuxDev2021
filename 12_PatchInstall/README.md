Стандартная сборка и установка в произвольную директорию:
```
autoreconf -fisv && ./configure --prefix=/usr && make
make install DESTDIR=<произвольная директория>
```

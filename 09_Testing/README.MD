Сборка и тесты:  
```
autoreconf -fisv
./configure 
make check
```
Сборка и тесты с тестовым покрытием:  
```
autoreconf -fisv
./configure --enable-gcov
make check
make gcov
```

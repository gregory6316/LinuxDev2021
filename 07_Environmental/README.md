Сборка по умолчанию(без lreadline):  
autoreconf -fisv && ./configure
Сборка с lreadline:  
autoreconf -fisv && ./configure --enable-readline 
Запуск
make && ./rhasher 
Тесты 
make check  
sample_text.txt - текст для тестов


### Задача

Дана заготовка класса `PCAPReader` в `PCAP.h`. Подразумевается, что данный класс будет парсить `.pcap` файлы и выводить некоторую информацию о них. Необходимо реализовать две функции:
 - ```uint64_t packetsCount() const;``` которая должна выводить количество пакетов, которое содержится в файле
 - ```uint64_t payloadSize() const;``` которая должна выводить количество полезной нагрузки в файле (без заголовков)

В папке `examples` лежит несколько примеров `.pcap` файлов
К заданию так же прилагается `main.cpp`  и ```tests.cpp```, которые запускает несколько тестов для проверки работы вашей реализации (с помощью `catch.hpp`)

Проект для вашей IDE можете собрать как сами из исходников, так и используя прилагаемый файл CMake. 

Вся необходимая документация по формату PCAP есть по ссылке https://wiki.wireshark.org/Development/LibpcapFileFormat

При сборке tests.cpp у меня возникает ошибка связанная с использованием MinGW g++.
Вывод результатов производиться в PCAP.cpp и совпадает с заданными в тестах.

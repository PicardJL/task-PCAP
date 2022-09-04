#pragma once

#include <string>
#include <fstream>
#include <iostream>

using std::ifstream;
using std :: ios_base;
using std :: ios;
using std :: cout;


uint32_t reverse_bytes(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte;
    int i;

    for(i = 0; i < 32; i+=8)
    {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return aux;
}

class PCAPReader {
    const std::string fileName;
public:
    uint64_t count_p;//счетчик кол-ва пакетов
    uint64_t sum_lenp;//сумма памяти,занимаемой пакетами

    explicit PCAPReader(const std::string &fileName)
    {
        ifstream myFile (fileName, ios::binary);

        myFile.seekg(0,ios_base::end);
        int fileLength = myFile.tellg();//находим общий объем файла для условия цикла
        myFile.seekg(0,ios_base::beg);
        uint32_t magic_number;
        myFile.read(reinterpret_cast <char * >(&magic_number), sizeof(magic_number));//достаем magic_number из заголовка
        int start = 6*4;//объем в байтах глобального заголовка
        count_p = 0;
        sum_lenp = 0;
//16 count это объем заголовка пакета
//12 количество байт, занимаемых полями заголовка до orig_len
        while(start + 16*count_p + 12 + sum_lenp  < fileLength){
            myFile.seekg(start + 16*count_p + 12 + sum_lenp ,ios_base::beg);
            uint32_t lenp;//объем одного пакета
            myFile.read(reinterpret_cast < char *>(&lenp), sizeof(lenp));
            if (magic_number == 3569595041) {// проверка  магического числа для оперделения порядка байтов
            lenp = reverse_bytes(lenp);   
            }
            count_p++;
            sum_lenp+=lenp;
        }
        myFile.close();
    };
    // Количество пакетов в файле
    uint64_t packetsCount() const{
        return count_p;
    };

    // Общий объём полезной нагрузки (без учёта заголовков)
    uint64_t payloadSize() const{
        return sum_lenp;
    };
};

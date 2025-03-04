#include <stdio.h>
#include <sys/stat.h>
#include "library.h"

int main(int argc, char* argv[]){
        if (argc == 1){      //Обработка запуска без аргументов
                printf("hint: %s <filename>\n", argv[0]);
                return -1;
        }
        int checker = 0;
        for (int i = 1; i < argc; i++)
        {
                checker = output(argv[i]);      
                if (checker != 0)           //Обработка ошибок (например неправильное имя файла)
                        return checker;
        }
        return 0;
}

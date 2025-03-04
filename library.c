#include <stdio.h>
#include <sys/stat.h>
#include "library.h"

int output(const char* filename){
        struct stat file_info;
        if (stat(filename, &file_info) == -1) {
                printf("hint: wrong filename %s\n", filename);  //Обработка неккоректного запуска
                return 1;
        }
        printf("File: %s\n", filename);
        output_file_type(file_info.st_mode);        //Тип файла
        output_permissions(file_info.st_mode);      //Разрешения
        output_base(file_info);                     //Остальная информация
        return 0;
}

void output_file_type(mode_t mode){
        printf("Type: ");
        if (S_ISREG(mode))              printf("Regular file\n");
        else if (S_ISDIR(mode))         printf("Directory\n");
        else if (S_ISBLK(mode))         printf("Block device\n");
        else if (S_ISFIFO(mode))        printf("FIFO/pipe\n");
        else if (S_ISSOCK(mode))        printf("Socket\n");
        else                            printf("Unknown\n");
}

void output_permissions(mode_t mode) {
    printf("Permissions: ");
    printf((mode & S_IRUSR) ? "r" : "-");   //Разрешения для пользователя-владельца
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");   //Разрешения для группы пользователей, связанных с файлом
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");   //Для остальных пользователей
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

void output_base(const struct stat file_info){
        printf("Size: %lld bytes\n", (long long)file_info.st_size);
        printf("Device: %lu\n", (unsigned long)file_info.st_dev);   //Устройство, на котором файл
        printf("Links: %lu\n", (unsigned long)file_info.st_nlink);  //Количество жестких ссылок, связанных с файлом
        printf("User ID: %u\n", file_info.st_uid);
        printf("Group ID: %u\n", file_info.st_gid);
}

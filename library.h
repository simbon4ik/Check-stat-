#ifndef LIBRARY
#define LIBRARY

int output(const char* filename);
void output_base(const struct stat file_info);
void output_file_type(mode_t mode);
void output_permissions(mode_t mode);

#endif

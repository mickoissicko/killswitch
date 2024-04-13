#ifndef COMMON_H
    #define COMMON_H
#endif

void DispUnknownErr();
void CheckLockFile();
void RemoveFolders();
void MakeLockFile();
void DispErrMsg();
void Reinstall();
void Install();
void Menu();

char* Posix_Path();
char* Win32_Path();


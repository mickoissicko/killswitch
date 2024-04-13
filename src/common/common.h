#ifndef COMMON_H
    #define COMMON_H
#endif

int main(int argc, char** argv);

void GetProc(int argc, char** argv);
void DispUnknownErr();
void CheckLockFile();
void RemoveFolders();
void MakeLockFile();
void DispErrMsg();
void Install();
void Menu();

char* Posix_Path();
char* Win32_Path();


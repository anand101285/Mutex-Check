#include <Windows.h>;
#include <stdio.h>;

char checkMutex()
{
    const WCHAR* v1 = L"{8761ABBD - 7F85 - 42EE - B272 - A76179687C63}";
    const WCHAR* v2 = L"{8761ABBD - 7F85 - 42EE - B272 - A76179687C63}";

    if (OpenMutexW(0x1F0001u, 0, v1))
        return 1;
    
    CreateMutexW(0, 0, v2);
    return 0;
}



int main() {
    if (checkMutex()) {
        printf("Process is already running");
        Sleep(3000);
        return 0;
    }
    printf("New Processs started");
    Sleep(10000);
	return 0;
}
#include <windows.h>
#include <stdio.h>;


int copyExeToAppData() {
    char sourceFilePath[MAX_PATH];
    char destinationFilePath[MAX_PATH];

    // Get the path of the currently running executable
    DWORD pathLength = GetModuleFileName(NULL, sourceFilePath, MAX_PATH);
    if (pathLength == 0 || pathLength >= MAX_PATH) {
        printf("Failed to retrieve the source file path\n");
        return 0;
    }

    // Specify the destination directory and file name
    snprintf(destinationFilePath, MAX_PATH, "C:\\Users\\anand\\AppData\\Roaming\\svhost.exe");

    // Attempt to copy the current process to the destination
    if (CopyFile(sourceFilePath, destinationFilePath, FALSE)) {
        printf("Process copied successfully to %s\n", destinationFilePath);
    }
    else {
        printf("Failed to copy process. Error code: %d\n", GetLastError());
    }

    return 1;
}

int main() {
    copyExeToAppData();
	return 0;
}
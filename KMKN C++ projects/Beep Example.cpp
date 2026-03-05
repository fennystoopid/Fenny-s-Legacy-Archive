#include <iostream>  
#include <windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

//buat funtion utk calculation
void music(){
	PlaySound("C:\\menu.wav", NULL , SND_FILENAME | SND_ASYNC |  SND_LOOP) ;
}

void stopaudio(){
	PlaySound(NULL, NULL, SND_PURGE);
}

int main() {
	PlaySound("C:\\menu.wav", NULL , SND_FILENAME | SND_SYNC |  SND_LOOP) ;
}


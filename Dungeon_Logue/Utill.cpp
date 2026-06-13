#include "Utill.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


int GetRandomRange(int Min, int Max)
{
    return Min + rand() % (Max - Min + 1);  // Min ~ Max(양끝 포함)
}

void SetColor(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

bool IsConfirm(int key)
{
    return key == 'Z' || key == 'z';
}

bool IsCancel(int key)
{
    return key == 'X' || key == 'x' || key == KEY_ESC;
}

// 메뉴 선택 커서 이동 (각각, 커서/메뉴갯수/입력받을 변수)
int MoveCursor(int cur, int count, int key)
{
    if(key == KEY_UP)
    {
		return (cur + count - 1) % count;  // 위 방향키: 커서 위치 감소
    }
    else if(key == KEY_DOWN)
    {
        return (cur + 1) % count;  // 아래 방향키: 커서 위치 증가
    }
    return cur;
}


// ===== BGM 제어 =====
static std::string ExtractResourceToTemp(const char* ResName, const char* OutFileName)
{
    // 1) 리소스 찾기 (RCDATA 타입)
    HRSRC hRes = FindResourceA(NULL, ResName, MAKEINTRESOURCEA(10));
    if (!hRes) return "";

    HGLOBAL hData = LoadResource(NULL, hRes);
    if (!hData) return "";

    DWORD size = SizeofResource(NULL, hRes);
    void* pData = LockResource(hData);
    if (!pData || size == 0) return "";

    // 2) 임시폴더 경로 얻기 (%TEMP%)
    char tempDir[MAX_PATH];
    GetTempPathA(MAX_PATH, tempDir);
    std::string outPath = std::string(tempDir) + OutFileName;

    // 3) 리소스 데이터를 그 경로에 파일로 저장
    HANDLE hFile = CreateFileA(outPath.c_str(), GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return "";

    DWORD written = 0;
    WriteFile(hFile, pData, size, &written, NULL);
    CloseHandle(hFile);

    return outPath;
}

void PlayBGM(const char* ResName, int volume)
{
    // ResName: "Main_BGM" / "Enemy_Battle_BGM" / "BOSS_Battle_BGM"
    std::string fullPath = ExtractResourceToTemp(ResName, (std::string(ResName) + ".mp3").c_str());
    if (fullPath.empty()) return;   // 추출 실패 시 그냥 무음

    mciSendStringA("close bgm", NULL, 0, NULL);
    std::string openCmd = std::string("open \"") + fullPath + "\" type mpegvideo alias bgm";
    mciSendStringA(openCmd.c_str(), NULL, 0, NULL);
    std::string volumeCmd = "setaudio bgm volume to " + std::to_string(volume);
    mciSendStringA(volumeCmd.c_str(), NULL, 0, NULL);
    mciSendStringA("play bgm repeat", NULL, 0, NULL);    // 무한 반복 재생
}

void StopBGM()
{
    mciSendStringA("close bgm", NULL, 0, NULL);
}
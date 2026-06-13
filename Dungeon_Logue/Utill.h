#pragma once

int GetRandomRange(int Min, int Max);
void SetColor(int Color);

enum Key {
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	KEY_ESC = 27
};
bool IsConfirm(int key);	// Z키
bool IsCancel(int key);		// X키 또는 ESC
int MoveCursor(int cur, int count, int key); // 메뉴 선택 커서 이동 (각각, 커서/메뉴갯수/입력받을 변수)

void PlayBGM(const char* Path, int volume);   // 이전 BGM을 멈추고 새 BGM을 무한 반복 재생
void StopBGM();                   // BGM 정지
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// SetGraphMode(1280, 720, 16);
	// ChangeWindowMode(TRUE);
	// SetWindowInitPosition(0, 0);
	if (DxLib_Init() == -1 || SetMouseDispFlag(TRUE) == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	while (-1 != ProcessMessage() && 0 == CheckHitKey(KEY_INPUT_ESCAPE)) {
		ClearDrawScreen();
		DxLib::DrawBox(0, 0, 100, 100, GetColor(128, 128, 128), true);
		int x, y;
		GetMousePoint(&x, &y);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%d, %d", x, y);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}

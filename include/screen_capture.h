#pragma once

#include <windows.h>
#include <string>
#include <vector>

class ScreenCapture {
public:
    // Захватить весь экран
    static bool CaptureFullScreen(const std::string& outputPath);

    // Захватить конкретный монитор
    static bool CaptureMonitor(int monitorIndex, const std::string& outputPath);

    // Получить разрешение экрана
    static void GetScreenResolution(int& width, int& height);

private:
    // Вспомогательные методы
    static HBITMAP CreateScreenBitmap(int& width, int& height);
    static bool SaveBitmapToFile(HBITMAP hBitmap, int width, int height, const std::string& path);
};

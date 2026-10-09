#pragma once

#include <string>

class OCREngine {
public:
    // Запустить OCR на изображении и получить текст
    static std::string RecognizeText(const std::string& imagePath);

    // Проверить, установлен ли Tesseract
    static bool IsTesseractInstalled();

    // Установить путь к Tesseract (если он не в PATH)
    static void SetTesseractPath(const std::string& path);

private:
    static std::string tesseractPath;
    static std::string ExecuteCommand(const std::string& cmd);
};

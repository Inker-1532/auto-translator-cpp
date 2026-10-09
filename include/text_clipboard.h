#pragma once

#include <string>

class TextClipboard {
public:
    // Скопировать текст в буфер обмена
    static bool CopyToClipboard(const std::string& text);

    // Получить текст из буфера обмена
    static std::string GetFromClipboard();

    // Вставить текст в активное окно (Ctrl+V)
    static void PasteText();

    // Вставить текст в буфер обмена и вставить его
    static bool CopyAndPaste(const std::string& text);
};

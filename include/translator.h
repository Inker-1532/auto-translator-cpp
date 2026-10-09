#pragma once

#include <string>

class Translator {
public:
    enum class TranslationService {
        DEEPL,
        LIBRETRANSLATE,
        GOOGLE
    };

    // Установить сервис перевода и ключ API
    static void SetService(TranslationService service, const std::string& apiKey = "");

    // Перевести текст с английского на русский
    static std::string TranslateEnglishToRussian(const std::string& englishText);

    // Перевести любой текст между языками
    static std::string Translate(const std::string& text, const std::string& sourceLang, const std::string& targetLang);

private:
    static TranslationService currentService;
    static std::string apiKey;

    static std::string TranslateWithDeepL(const std::string& text, const std::string& source, const std::string& target);
    static std::string TranslateWithLibreTranslate(const std::string& text, const std::string& source, const std::string& target);
    static std::string TranslateWithGoogle(const std::string& text, const std::string& source, const std::string& target);
    
    static std::string ExecuteCommand(const std::string& cmd);
    static std::string UrlEncode(const std::string& str);
};

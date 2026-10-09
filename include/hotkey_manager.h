#pragma once

#include <windows.h>
#include <functional>
#include <map>

typedef std::function<void()> HotKeyCallback;

class HotKeyManager {
public:
    HotKeyManager();
    ~HotKeyManager();

    // Зарегистрировать глобальную горячую клавишу
    // modifiers: MOD_CONTROL, MOD_ALT, MOD_SHIFT, MOD_WIN
    // key: виртуальный код клавиши (например, 'T', VK_F1)
    bool RegisterHotKey(UINT id, UINT modifiers, UINT key, HotKeyCallback callback);

    // Отменить регистрацию горячей клавиши
    bool UnregisterHotKey(UINT id);

    // Главный цикл обработки сообщений
    void StartMessageLoop();

    // Остановить обработку сообщений
    void StopMessageLoop();

private:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    
    HWND hWnd;
    bool running;
    std::map<UINT, HotKeyCallback> callbacks;
};

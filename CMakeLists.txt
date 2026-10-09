cmake_minimum_required(VERSION 3.10)
project(AutoTranslator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исходные файлы
add_executable(AutoTranslator
    src/main.cpp
    src/screen_capture.cpp
    src/ocr_engine.cpp
    src/translator.cpp
    src/hotkey_manager.cpp
    src/text_clipboard.cpp
)

# Подключаем Windows API (уже встроена в Visual Studio)
if(WIN32)
    target_link_libraries(AutoTranslator 
        user32
        gdi32
        kernel32
        ole32
    )
endif()

# Подключаем директорию include
target_include_directories(AutoTranslator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Если нужны внешние библиотеки (curl, json), добавьте их:
# find_package(CURL REQUIRED)
# target_link_libraries(AutoTranslator CURL::libcurl)

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <wininet.h>
#include <urlmon.h>
#include <conio.h>
#include <curl/curl.h>
#include <cstdio>
#include <Shlobj.h>
#include <shellapi.h>
#include <Lmcons.h>
#include "CHOOO LOADER.h"

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void HideFile(const std::string& filePath) {
    if (SetFileAttributesA(filePath.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM) != 0) {
        std::cout << "Файл " << filePath << " успешно скрыт." << std::endl;
    }
    else {
        DWORD error = GetLastError();
        std::cerr << "Ошибка " << error << " при скрытии файла " << filePath << std::endl;
    }
}

void loadingAnimation(int duration) {
    int count = 0;
    while (count <= duration) {
        std::cout << "" << std::endl;
        std::cout << "            Проверка";
        for (int i = 0; i < count; i++) {
            std::cout << ".";
        }
        Sleep(200);  // Задержка в миллисекундах
        system("cls");  // Очистка экрана
        count++;
    }
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "            Проверка Завершена!" << std::endl;
}

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

bool directoryExists(const std::wstring& path) {
    DWORD attrib = GetFileAttributes(path.c_str());
    return (attrib != INVALID_FILE_ATTRIBUTES && (attrib & FILE_ATTRIBUTE_DIRECTORY));
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleTitle(TEXT("CHP - NL (site: cheats-pack.ru)"));

    void CheckIthernetToSite(); {
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "            Идет проверка соединения с сайтом. Пожалуйста подождите." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "" << std::endl;

        if (InternetCheckConnectionA("https://cheats-pack.ru", FLAG_ICC_FORCE_CONNECTION, 0)) {
            std::cout << "" << std::endl;
            std::cout << "            Подключение." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "" << std::endl;
            system("cls");
        }
        else {
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "          Не удалось подключиться к сайту. Пожалуйста проверьте соединение с интернетом и перезапустите лоудер." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 1;
        }
    }

    void chpdownloadsdirectory(); {
        std::wstring folderPath = L"C:\\CHP";
        if (directoryExists(folderPath)) {
            std::cout << "" << std::endl;
        }
        else {
            if (!CreateDirectory(folderPath.c_str(), NULL)) {
                DWORD error = GetLastError();
                std::cout << "" << std::endl;
                std::cout << "" << std::endl;
                std::cerr << "            Ошибка при загрузки необходимых файлов." << std::endl;
                return 1;
            }
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "           Файлы успешно загруженны." << std::endl;
        }
    }

    void mainmenu(); {
        ShellExecuteA(NULL, "open", "https://vk.com/cheatspack", NULL, NULL, SW_SHOWNORMAL);
        ShellExecuteA(NULL, "open", "https://t.me/cheatspack", NULL, NULL, SW_SHOWNORMAL);
        ShellExecuteA(NULL, "open", "https://t.me/fusurthvh", NULL, NULL, SW_SHOWNORMAL);
        ShellExecuteA(NULL, "open", "https://www.youtube.com/@fusurt", NULL, NULL, SW_SHOWNORMAL);
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "             $$$$$$\\  $$\\   $$\\ $$$$$$$\\ " << std::endl;
        std::cout << "            $$  __$$\\ $$ |  $$ |$$  __$$\\ " << std::endl;
        std::cout << "            $$ /  \\__|$$ |  $$ |$$ |  $$ |" << std::endl;
        std::cout << "            $$ |      $$$$$$$$ |$$$$$$$  |" << std::endl;
        std::cout << "            $$ |      $$  __$$ |$$  ____/ " << std::endl;
        std::cout << "            $$ |  $$\\ $$ |  $$ |$$ |      " << std::endl;
        std::cout << "            \\$$$$$$  |$$ |  $$ |$$ |      " << std::endl;
        std::cout << "             \\______/ \\__|  \\__|\\__|      " << std::endl;
        std::cout << "" << std::endl;
        std::cout << "            Добро пожаловать в лаунчер CHEATS PACK - NL!" << std::endl;
        std::cout << "            Нажми пробел для продолжения." << std::endl;
        while (_getch() != ' ');
        system("cls");  // Очистка экрана

        int loadingDuration = 2;
        loadingAnimation(loadingDuration);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("cls");
        while (true) {
            void downloadchp(); {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "" << std::endl;
                std::cout << "" << std::endl;
                std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                std::cout << "" << std::endl;
                std::cout << "            1. CHEATS PACK (NEW) - Читы 1.16.5" << std::endl;
                std::cout << "            2. CHEATS PACK (OLD) - Читы 1.12.2" << std::endl;
                std::cout << "            3. CHEATS PACK (ДОП) - РП/Шeйдеры" << std::endl;
                std::cout << "            4. CHEATS PACK (CFG) - Конфиги для Читов." << std::endl;
                std::cout << "            5. CHEATS PACK (LEGIT) - Легит-читы, Легит-моды и DLL." << std::endl;
                std::cout << "            ?. CHEATS PACK (???) - Soon..." << std::endl;
                std::cout << "" << std::endl;
                std::cout << "            Остальное." << std::endl;
                std::cout << "            6. HIDER - Скрытие читов на ПК" << std::endl;
                std::cout << "            7. BRYTVAMYST BETA - Помощник для лутания мистиков на FunTime." << std::endl;
                std::cout << "" << std::endl;
                std::cout << "            8. Анти-проверка. (Вкл)" << std::endl;
                std::cout << "            9. Анти-проверка. (Выкл)" << std::endl;
                std::cout << "" << std::endl;
                std::cout << "            10. Закрыть программу." << std::endl;
                std::cout << std::endl;
                std::string xuii;
                std::cin >> xuii;
                if (xuii == "1") {
                    system("cls");  // Очистка экрана
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Крякнутые Читы." << std::endl;
                    std::cout << "            1. Celestial 1.01b Crack" << std::endl;
                    std::cout << "            2. Excellent Dev.b Crack" << std::endl;
                    std::cout << "            3. Expensive 2.0 Crack" << std::endl;
                    std::cout << "            4. Nursultan 1.16.5 Crack" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Бесплатные Читы." << std::endl;
                    std::cout << "            6. Adaptive Client" << std::endl;
                    std::cout << "            7. Dark Client" << std::endl;
                    std::cout << "            8. Elysium Client" << std::endl;
                    std::cout << "            9. Resolute Client" << std::endl;
                    std::cout << "            10. Exclusive Client" << std::endl;
                    std::cout << "            11. Rockstar Free" << std::endl;
                    std::cout << "            12. ThunderHack Client" << std::endl;
                    std::cout << "            13. Verist Client" << std::endl;
                    std::cout << "            14. KwishFree Client" << std::endl;
                    std::cout << "            15. Wissend Client" << std::endl;
                    std::cout << "            16. NewCode Client" << std::endl;
                    std::cout << "            17. Stellar Client" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            18. Вернуться обратно" << std::endl;
                    std::string key1;
                    std::cin >> key1;
                    if (key1 == "1") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Скачиваю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Celestial 1.01b Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/crackcheats/celka1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/crackcheats/assetscelka.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "2") {
                        std::cout << "            Скачиваю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Excellent Dev.b Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/crackcheats/excellent1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "3") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Expensive 2.0 Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/crackcheats/expensive1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "4") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Nursultan 1.16.6 Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/crackcheats/nursultan1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "5") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Adaptive Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/adaptive1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "6") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Dark Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/dark1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "7") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Elysium Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/elysium1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "8") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Epfirium Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/epfirium1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "9") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Exclusive Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/exclusive1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "10") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Rockstar Free!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/rockstar1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "11") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку ThunderHack Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/thunderhack1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "12") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Verist Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/verist1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "13") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку KwishFree Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/kwish1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "14") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Wissend Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/wissend1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "15") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку NewCode Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/newcode1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "16") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Netta Client!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/freecheats/netta1165.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key1 == "17") {
                        std::cout << "            Выхожу." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        void downloadchp();
                    }
                }
                else if (xuii == "2") {
                    system("cls");  // Очистка экрана
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Крякнутые Читы." << std::endl;
                    std::cout << "            1. Celestial 0.6.7 Crack" << std::endl;
                    std::cout << "            2. Expensive Reloaded Crack" << std::endl;
                    std::cout << "            3. Nursultan 1.12.2 Crack" << std::endl;
                    std::cout << "            4. Sirius 1.2 Crack " << std::endl;
                    std::cout << "            5. Minced 0.4 Crack " << std::endl;
                    std::cout << "            6. Wexside 1.0 Crack " << std::endl;
                    std::cout << "            7. Meteor 0.1b Crack " << std::endl;
                    std::cout << "            8. Future Client Crack " << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            Бесплатные Читы." << std::endl;
                    std::cout << "            Нету :( " << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "" << std::endl;
                    std::cout << "            9. Вернуться обратно." << std::endl;
                    std::string key3;
                    std::cin >> key3;
                    if (key3 == "1") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Celestial 0.6.7 Crack !" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/celka1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "2") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Expensive Reloaded Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/expensive1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "3") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Nursultan 1.12.2 Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/nursultan1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "4") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Sirius 1.2 Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/sirius1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "5") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Minced Prem Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/minced1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "6") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку WexSide 1.0 Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/wexside1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "7") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Meteor Premium Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/meteor1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "8") {
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку Future Client Crack!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cheats1122/future1122.rar", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    if (key3 == "9") {
                        std::cout << "            Выхожу." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        void downloadchp();
                    }

                }
                else if (xuii == "3") {
                        system("cls");  // Очистка экрана
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            1. Приватные/Неприватные РП." << std::endl;
                        std::cout << "            2. Шейдеры. (Некоторые используют Ютуберы)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            3. Вернуться обратно." << std::endl;
                        std::string key6;
                        std::cin >> key6;
                        if (key6 == "1") {
                            system("cls");  // Очистка экрана
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            РП Ютуберов." << std::endl;
                            std::cout << "            1. РП BRO9I" << std::endl;
                            std::cout << "            2. РП GTSKA" << std::endl;
                            std::cout << "            3. РП RIKER" << std::endl;
                            std::cout << "            4. РП AKYLIN" << std::endl;
                            std::cout << "            5. РП FLUGER" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            РП Обычных Пользователей." << std::endl;
                            std::cout << "            6. РП (Пока так, потос сделаю меню выбора)" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            3. Вернуться обратно." << std::endl;
                            std::string key7;
                            std::cin >> key7;
                            if (key7 == "1") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП BRO9I!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/privat/bro9i.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "2") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП GTSKA!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/privat/gtska.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "3") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП RIKER!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/privat/riker.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "4") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП AKYLIN!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/privat/akylin.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "5") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП FLUGER!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/privat/fluger.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "6") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку РП!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/noprivat/noprivat.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key7 == "7") {
                                std::cout << "            Выхожу." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                void downloadchp();
                            }
                        }
                        if (key6 == "2") {
                            system("cls");  // Очистка экрана
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Шейдеры." << std::endl;
                            std::cout << "            1. Motion Blur." << std::endl;
                            std::cout << "            2. Snowimagined (GTSKA)" << std::endl;
                            std::cout << "            3. Complementary Reimagined" << std::endl;
                            std::cout << "            4. Spooklementary" << std::endl;
                            std::cout << "            5. SEUS-Renewed" << std::endl;
                            std::cout << "            6. Sora" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            7. Вернуться обратно." << std::endl;
                            std::cout << "" << std::endl;
                            std::string key8;
                            std::cin >> key8;
                            if (key8 == "1") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Motion Blur!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/blur1.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "2") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Snowimagined!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/snowimagined.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "3") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Complementary Reimagined!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/сomplementary.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "4") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Spooklementary!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/spooklementary.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "5") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку SEUS-Renewed!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/seusr.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "6") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Открываю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Sora!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/rpandsh/shader/sora.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key8 == "7") {
                                std::cout << "            Выхожу." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                void downloadchp();
                            }
                        }
                        else
                            if (key6 == "3") {
                                std::cout << "            Выхожу." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                void downloadchp();
                            }
                    }
                else if (xuii == "4") {
                        system("cls");  // Очистка экрана
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Конфиги на Премиум софт." << std::endl;
                        std::cout << "            1. Celestial (07.01.24)" << std::endl;
                        std::cout << "            2. Excellent (21.02.24)" << std::endl;
                        std::cout << "            3. Expensive (21.02.24)" << std::endl;
                        std::cout << "            4. Nursultan (21.02.24)" << std::endl;
                        std::cout << "            5. Akrien (14.01.24)" << std::endl;
                        std::cout << "            6. Nova (21.02.24)" << std::endl;
                        std::cout << "            7. Wild (31.01.24)" << std::endl;
                        std::cout << "            8. Wex$ide (21.02.24)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Конфиги на Бесплатные софт." << std::endl;
                        std::cout << "            9. Arbuz (09.12.23)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            10. Вернуться обратно." << std::endl;
                        std::cout << "" << std::endl;
                        std::string key2;
                        std::cin >> key2;
                        if (key2 == "1") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/celestial/Celestialcfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "2") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/excellent/Excellentcfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "3") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/expensive/Expensivecfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "4") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/nursultan/Nursultancfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "5") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/akrien/Akriencfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "6") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/nova/Novacfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "7") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/wild/Wildcfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "8") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/wexside/wexsidecfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "9") {
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Скачиваю." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "            Спасибо за установку наших конфигов :3" << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ShellExecuteA(NULL, "open", "https://cheats-pack.ru/cfg/arbuz/arbuzcfg.zip", NULL, NULL, SW_SHOWNORMAL);
                            std::cout << "" << std::endl;
                            std::cout << "            Нажми пробел для выхода." << std::endl;
                            while (_getch() != ' ');
                        }
                        if (key2 == "10") {
                            std::cout << "            Выхожу." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            void downloadchp();
                        }
                    }
                                        else if (xuii == "?") {
                                        system("cls");  // Очистка экрана
                                        std::this_thread::sleep_for(std::chrono::seconds(1));
                                        std::cout << "" << std::endl;
                                        std::cout << "" << std::endl;
                                        std::cout << "            Тут пока ничего нету, в будущем тут что-то обязательно будет." << std::endl;
                                        std::cout << "" << std::endl;
                                        std::this_thread::sleep_for(std::chrono::seconds(5));
                                        std::cout << "            Нажми пробел для выхода." << std::endl;
                                        while (_getch() != ' ');
                    }
                    else if (xuii == "5") {
                        system("cls");  // Очистка экрана
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            Выбери что хочешь открыть. (Напиши цифру.)" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            DLL или Легит читы/моды." << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            1. Легитные читы/моды." << std::endl;
                        std::cout << "            2. DLL." << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "" << std::endl;
                        std::cout << "            3. Вернуться обратно." << std::endl;
                        std::string key4;
                        std::cin >> key4;
                        if (key4 == "1") {
                            system("cls");  // Очистка экрана
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Легитные читы." << std::endl;
                            std::cout << "            1. Doomsday 1.16.5 [ЧИТ] (Лучший из всех!)" << std::endl;
                            std::cout << "            2. DreamPool Prem Crack [ЧИТ]" << std::endl;
                            std::cout << "            3. NightLight Legit [ЧИТ]" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Легитные Моды." << std::endl;
                            std::cout << "            4. AutoAttack (Недо TriggerBot) [МОД]" << std::endl;
                            std::cout << "            5. Elytra Swap [МОД]" << std::endl;
                            std::cout << "            6. FreeCam [МОД]" << std::endl;
                            std::cout << "            7. Hitbox (No DLL and External) [МОД]" << std::endl;
                            std::cout << "            8. InvTotem (Недо автототем) [МОД]" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            9. Вернуться обратно." << std::endl;
                            std::string key5;
                            std::cin >> key5;
                            if (key5 == "1") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку DoomsDay!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/doomsday.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "2") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку DreamPool Prem Crack!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/dreampoolcrack.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "3") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку NightLight BETA!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/nightlight.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "4") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку AutoAttack!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/nedotriggerbot.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "5") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку ElytraSwap!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/elytraswap.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "6") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку FreeCam!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/freecam.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "7") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку Hitbox!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/modshb.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "8") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку InvTotem!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/legitcheatsandmods/nedoautototem.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key5 == "9") {
                                std::cout << "            Выхожу." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                void downloadchp();
                            }
                        }
                        if (key4 == "2") {
                            system("cls");  // Очистка экрана
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            Выбери что хочешь скачать. (Напиши цифру.)" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            DLL читы." << std::endl;
                            std::cout << "            1. External Hitbox" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "" << std::endl;
                            std::cout << "            2. Вернуться обратно." << std::endl;
                            std::string key6;
                            std::cin >> key6;

                            if (key6 == "1") {
                                std::cout << "" << std::endl;
                                std::cout << "" << std::endl;
                                std::cout << "            Скачиваю." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                std::cout << "            Спасибо за установку External HitBox!" << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(2));
                                ShellExecuteA(NULL, "open", "https://cheats-pack.ru/dll/externalhb.rar", NULL, NULL, SW_SHOWNORMAL);
                                std::cout << "" << std::endl;
                                std::cout << "            Нажми пробел для выхода." << std::endl;
                                while (_getch() != ' ');
                            }
                            if (key6 == "2") {
                                std::cout << "            Выхожу." << std::endl;
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                                void downloadchp();
                            }
                        }
                        if (key4 == "3") {
                            std::cout << "            Выхожу." << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(1));
                            void downloadchp();
                        }
                    }
                    //
                    // Тут начинаются программы с разделения "Остальное"
                    //
                    else if (xuii == "6") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        ShellExecuteA(NULL, "open", "https://www.youtube.com/@helsithebust", NULL, NULL, SW_SHOWNORMAL);
                        ShellExecuteA(NULL, "open", "https://t.me/helsithebust", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "            Спасибо за установку HIDER!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        ShellExecuteA(NULL, "open", "https://moneyz.fun/cSSETB", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    else if (xuii == "7") {
                        std::cout << "            Открываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "            Спасибо за установку BritvaMyst Beta!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        ShellExecuteA(NULL, "open", "https://moneyz.fun/sLTSYS", NULL, NULL, SW_SHOWNORMAL);
                        std::cout << "" << std::endl;
                        std::cout << "            Нажми пробел для выхода." << std::endl;
                        while (_getch() != ' ');
                    }
                    else if (xuii == "8") {
                        std::cout << "            Скрываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        char username[UNLEN + 1];
                        DWORD size = UNLEN + 1;
                        if (!GetUserNameA(username, &size)) {
                            std::cerr << "Ошибка при получении имени пользователя." << std::endl;
                            return 1;
                        }

                        // Папки, которые нужно скрыть
                        const char* folderPaths[] = {
                            "C:\\CHP",
                            "C:\\Nurik",
                            "C:\\Nursultan",
                            "C:\\Wexside",
                            "C:\\Expensive",
                            "C:\\Celka",
                            "C:\\Celestial",
                            "C:\\Rockstar",
                            "C:\\RockAntiLeak",
                            "C:\\RockGuard",
                            "C:\\Deadcode",
                            "C:\\Akrien",
                            "C:\\AkrienAntiLeak",
                            "C:\\Minced",
                            "C:\\Excellent",
                            "C:\\Wild",
                            "C:\\WILD",
                            "C:\\Sirius",
                            "C:\\Wave",
                            "C:\\Nova",
                        };

                        // Папка загрузок
                        std::string downloadFolder = "C:\\Users\\";
                        downloadFolder += username;
                        downloadFolder += "\\Downloads\\";

                        // Файлы для скрытия
                        const char* fileNames[] = {
                            "Nursultan.exe",
                            "Celestial.exe",
                            "Expensive.exe"
                        };

                        // Скрытие файлов
                        for (const auto& fileName : fileNames) {
                            std::string filePath = downloadFolder + fileName;
                            HideFile(filePath);
                        }

                        // Скрытие папок
                        for (const char* folderPath : folderPaths) {
                            DWORD attributes = GetFileAttributesA(folderPath);
                            if (attributes == INVALID_FILE_ATTRIBUTES) {
                                std::cerr << "Ошибка при получении атрибутов " << folderPath << std::endl;
                                continue;
                            }
                            attributes |= FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM;
                            if (!SetFileAttributesA(folderPath, attributes)) {
                                DWORD error = GetLastError();
                                std::cerr << "Ошибка " << error << " при скрытии папки " << folderPath << std::endl;
                            }
                            else {
                                std::cout << "Папка успешно скрыта " << folderPath << std::endl;
                            }
                        }
                        const char* oldName = "CHP - NL.exe"; // Старое имя исполняемого файла
                        const char* newName = "SoundPad.exe"; // Новое имя исполняемого файла

                        if (!MoveFileA(oldName, newName)) { // Функция для переименования файла
                            std::cerr << "Ошибка при переименовании файла: " << std::endl;
                        }

                        std::cout << "            Имя файла успешно изменено" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        void downloadchp();
                    }
                    //
                             ///
                                                    ///
                    else if (xuii == "9") {
                        std::cout << "            Показываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        const char* folderPaths[] = {
                            "C:\\CHP",
                            "C:\\Nurik",
                            "C:\\Nursultan",
                            "C:\\Wexside",
                            "C:\\Expensive",
                            "C:\\Celka",
                            "C:\\Celestial",
                            "C:\\Rockstar",
                            "C:\\RockAntiLeak",
                            "C:\\RockGuard",
                            "C:\\Deadcode",
                            "C:\\Akrien",
                            "C:\\AkrienAntiLeak",
                            "C:\\Minced",
                            "C:\\Excellent",
                            "C:\\Wild",
                            "C:\\WILD",
                            "C:\\Sirius",
                            "C:\\Wave",
                            "C:\\Nova",
                        };

                        for (const char* folderPath : folderPaths) {
                            DWORD attributes = GetFileAttributesA(folderPath);
                            if (attributes == INVALID_FILE_ATTRIBUTES) {
                                std::cerr << "Ошибка при получении атрибутов " << folderPath << std::endl;
                                continue;
                            }
                            attributes &= ~(FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM); // Сбрасываем атрибуты
                            if (!SetFileAttributesA(folderPath, attributes)) {
                                std::cerr << "Ошибка при показе папки " << folderPath << std::endl;
                            }
                            else {
                                std::cout << "Папки успешно показаны " << folderPath << std::endl;
                            }
                        }
                        const char* oldName = "SoundPad.exe";
                        const char* newName = "CHP - NL.exe";

                        if (!MoveFileA(oldName, newName)) {
                            std::cerr << "            Ошибка при переименовании файла." << std::endl;
                        }
                        std::cout << "            Имя файла успешно изменено!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                        void downloadchp();
                    }
                    //
                    //
                    //
                    else if (xuii == "10") {
                        std::cout << "            Закрываю." << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        exit(0);
                    }
                }
                system("cls");
            }
            return(0);
        }
    }
    

# в гите
git clone https://github.com/achebykin1/ssyp26_ws04/tree/main

# в CMake
# Конфигурируем проект, явно указывая генератор для VS 2019 и инструменты v142
# Узнать версию в VS2019 какая
cmake -G "Visual Studio 16 2019" -A x64 -T v142 -B build 

# Собираем проект
cmake --build build --config Debug

# В Relese
cmake --build build --config Release

# путь к exe
$Папка_с_проектом$/build/bin/Release/main.exe
# dxfviewer

Просмотрщик чертежей DXF на C++20 и Qt6: открытие файла, навигация по чертежу, слои, объектные привязки и измерения расстояний и углов.

## Статус

Проект в разработке. Сейчас готова основа: модель примитивов и отрисовка сцены.

- [x] Сборка через CMake, окно Qt6
- [x] Сцена `QGraphicsView` с осью Y вверх, как в CAD
- [x] Модель примитивов (`Line`, `Circle`, ...) на `std::variant` без зависимостей от Qt
- [ ] Чтение DXF через libdxfrw (LINE, ARC, CIRCLE, LWPOLYLINE, TEXT)
- [ ] Масштаб к курсору, панорамирование, «показать всё»
- [ ] Панель слоёв, выделение, панель свойств
- [ ] Привязки (конец, середина, центр) и измерение расстояний и углов
- [ ] Плавная работа на чертежах от 50 000 примитивов
- [ ] Модульные тесты геометрии (GoogleTest) и CI на GitHub Actions

## Сборка

Нужны компилятор с поддержкой C++20 (GCC 11+ или Clang 14+), CMake 3.28+ и Qt 6.

Ubuntu 24.04:

```bash
sudo apt install build-essential cmake qt6-base-dev libgl1-mesa-dev
```

Сборка и запуск:

```bash
git clone --recursive https://github.com/Kundyukov/dxfviewer.git
cd dxfviewer
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/dxfviewer
```

## Структура

- `core/` — геометрические примитивы и модель чертежа. Не зависит от Qt, поэтому её можно покрыть модульными тестами и использовать отдельно от интерфейса.
- корень проекта (`main.cpp`, `mainwindow.*`) — интерфейс на Qt: окно и отрисовка модели на `QGraphicsScene`. Позже переедет в `app/`.

Планируется:

- `io/` — загрузка DXF: адаптер `DRW_Interface` из libdxfrw, который переводит сущности файла в модель `core`.
- `tests/` — тесты на GoogleTest.

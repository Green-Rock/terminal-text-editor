# Консольный текстовый редактор

[Архитектура](https://github.com/Green-Rock/terminal-text-editor/blob/main/docs/architecture.md)

[Процессы](https://github.com/Green-Rock/terminal-text-editor/blob/main/docs/process.md)

[Команда](https://github.com/Green-Rock/terminal-text-editor/blob/main/docs/team.md)

Редактор имеет следующие возможности:

- ввод текста
- удаление текста
- копирование и вставка текста
- чтение и запись текстового файла

## Сборка проекта

Для сборки проекта используется утилита [cmake](https://cmake.org/download/).

Стандартный способ сборки проекта утилитой cmake:

```bash
mkdir text-editor
cd text-editor
cmake ..
cmake --build
```

## Руководство пользователя

Окно редактора содержит 3 зоны:

- информация о текущем файле
- рабочая область
- область с подсказками для пользователя

![image_1](https://raw.githubusercontent.com/Green-Rock/terminal-text-editor/main/image/image_3.png)



Синее поле - поле работы с текстом. Редактор позволяет набирать строчные и заглавные буквы латинского и русского алфавитов, цифры, знаки пунктуации и другие печатные символы. Перемещение курсора осуществляется стрелками на клавиатуре.

Клавиша `Enter` обрабатывается как перевод каретки и вставляет в текст новую строку. Если клавиша `Enter` была нажата в середине строки, то конец строки начиная с символа в позиции курсора будет перенесен на новую строку.

Вверху расположен полный путь с именем открытого файла. Снизу располагается панель подсказок для пользователя.

### Функциональные клавиши

- При нажатии клавиши `F2` редактируемый текст сохраняется в файле.
- При нажатии клавиши `F3` выделенный блок текста копируется. Скопированный блок может быть многократно вставлен в разные места текста.
- При нажатии клавиши `F4` включается режим выделения текста. Блок начинается со строки, в которой впервые была нажата клавиша `F4` и заканчивается там, где была нажата клавиша `F3` или `F4`. Стрелки вправо и влево выделяют текст посимвольно. Стрелки вверх и вниз позволяют выделять текст построчно, на строку вверх и вниз от курсора соответственно.
- При нажатии клавиши `F5` скопированный блок вставляется в текст в позицию курсора.
- При нажатии клавиши `F6` программа завершит свою работу.

![image_2](https://raw.githubusercontent.com/Green-Rock/terminal-text-editor/main/image/image_4.png)

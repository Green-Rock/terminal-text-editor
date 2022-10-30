# Консольный текстовый редактор

Редактор имеет следующие возможности:

- ввод текста
- удаление текста
- копирование и вставка текста
- чтение и запись текстового файла в формате `.txt`

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

![image_1](https://s145vlx.storage.yandex.net/rdisk/9c222eb543ba336967bd9a3b7104735daed629741ef56bd5a64157af29c6f69a/635f2ca1/o-mBvfsM75BGqTWuFLDcSLGSxigpk1jvySDDd7IarZex0Ui5-6gdsOWXgJaLp9VQgjx2alpA7NePhrh7BaIXLw==?uid=0&filename=image_1.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&owner_uid=0&fsize=15038&hid=bf5b8b12c8e5d54cd2e14bee420224ec&media_type=image&tknv=v2&etag=9b617ceac0203f8d021752df055331d5&rtoken=ijtFYGur9Mo7&force_default=no&ycrid=na-407b68d948a7a42665814996ed26be9a-downloader21h&ts=5ec4afebbaa40&s=1d1dc20637f1ef86b889e928d100b0485d1462cc11075b01c4c86282d5e3aba0&pb=U2FsdGVkX19FMPqwIerZ7qEuy2BoZmhKkKOwF51v-edL4j9IPf5NsBU-xvvyhJuTjp0YMxRoY-ooaZXf3ChadpymtNyGMYiKAJ_OmvTLWjc)



Синее поле - поле работы с текстом. Редактор позволяет набирать строчные и заглавные буквы латинского и русского алфавитов, цифры, знаки пунктуации и другие печатные символы. Перемещение курсора осуществляется стрелками на клавиатуре.

Клавиша `Enter` обрабатывается как перевод каретки и вставляет в текст новую строку. Если клавиша `Enter` была нажата в середине строки, то конец строки начиная с символа в позиции курсора будет перенесен на новую строку.

Вверху расположен полный путь с именем открытого файла. Снизу располагается панель подсказок для пользователя.

### Функциональные клавиши

- При нажатии клавиши `F2` редактируемый текст сохраняется в файле.
- При нажатии клавиши `F3` выделенный блок текста копируется. Скопированный блок может быть многократно вставлен в разные места текста.
- При нажатии клавиши `F4` включается режим выделения текста. Блок начинается со строки, в которой впервые была нажата клавиша `F4` и заканчивается там, где была нажата клавиша `F3` или `F4`. Стрелки вправо и влево выделяют текст посимвольно. Стрелки вверх и вниз позволяют выделять текст построчно, на строку вверх и вниз от курсора соответственно.

![image_2](https://s374vla.storage.yandex.net/rdisk/d2461bb89e1a9804abc4aa3c91fd47cd17f7b43b8a6c963e205d5dad951d68ad/635f2cf1/o-mBvfsM75BGqTWuFLDcSCSqbW2gv0lEelnDDFF74dluSb-Daq2rM2_PZjYCqRr1XSB_g8skLC2obmk11-rqiQ==?uid=0&filename=image_2.png&disposition=inline&hash=&limit=0&content_type=image%2Fpng&owner_uid=0&fsize=92404&hid=2b8dcf679f58ba1c73fe8c61910e747c&media_type=image&tknv=v2&etag=606c4935ab01a2babbfac5154773a3e7&rtoken=07NAp4vFakkq&force_default=no&ycrid=na-795819999723834ed88e8c35bc78e8b6-downloader21h&ts=5ec4b03805e40&s=f7ac9553dbdba4fe8eb4ec978e1550293095ac71665059463a1b710624686b56&pb=U2FsdGVkX1_LS36U1X2vvEnh5EjNYYBPuSZuvJxnsjFqRx4yqw3nvY34cWXbgJGZuSHKKD8P1blv0Y7rlXXPQLccrpLkIXjuEkEyClHNHlE)

- При нажатии клавиши `F5` скопированный блок вставляется в текст в позицию курсора.
- При нажатии клавиши `F6` программа завершит свою работу.

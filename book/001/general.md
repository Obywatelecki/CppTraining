# Struktura programu

Kod źródłowy programu w języku C++ zapisuje się w **zwykłych plikach tekstowych** (ang: plain text files).

## Pliki tekstowe

Pliki mogą być zapisane w zwykłym ASCII, większość kompilatorów dobrze rozumie też UTF-8 i UTF-16.

Podstawowy zestaw znaków języka obejmuje:
* 5 równoważnych rodzajów spacji: spacja ('\0x20'), tabulator poziomy (HT, '\0x09'), tabulator pionowy (VT, '\0x0B'), znak nowej strony (FF, '\0x0C'), znak nowej linii (LF, '\0x0A').
* 10 cyfr: '0' do '9'
* 52 litery alfabetu łacińskiego: od 'a' do 'z' oraz od 'A' do 'Z'
* 29 znaków interpunkcyjnych: _ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '  
Wszystkie inne znaki są zastępowane znakami z zestawu rozszerzonego, zależnie od użytego kodowania.

Bezpiecznie jest wystrzegać się stosowania znaków spoza podstawowego zestawu, nawet naszego polskiego "ąćęłńóśźż":
- w kodzie programu pojawią się nieoczywiste interpretacje i konwersje, zależne od tego jak plik jest zakodowany, wyszukiwanie związanych z tym prpblemów jest bardzo trudne,
- język pozwala takie znaczki zapisać explicite razem z pożądanym kodowaniem,
- można wprawić w zakłopotanie inne narzędzia pracujące z naszym kodem.

Większość kompilatorów i narzędzi dobrze sobie radzi z niekonsekwentnym stosowaniem znaku końca linii (DOS/Unix/Mac).

Zawsze **rozróżniane są małe i wielkie litery** (ang: case sensitive).

## Pliki z kodem

Używane są dwa podstawowe rodzaje plików z kodem:

* **pliki z treścią programu**: **\*.cpp** (C++) i **\*.c** (C). Można spotkać się też z plikami o rozszerzeniach: .c++, .cc, .cxx., .C, obecnie zazwyczaj są niezalecane.
* pliki z deklaracjami (obiektów, funkcji, klas, typów itp), zwane  też **plikami nagłówkowymi** (ang: header files): **\*. (bez rozszerzenia)** (C++) i **\*.h** (C/C++). Można też spotkać (obecnie niezalecane) .hpp i .hxx
* można spotkać pliki 
  * .ii, .ixx, .ipp, .inl (nagłówki zawierające fragmenty kodu ```inline```)
  * .txx, .tpp, .tpl - definicje wzorców (ang: templates).
  * wprowadzanie sztucznych formalizmów (jak te powyżej) nakłada na programistę dodatkowe obowiązki administracyjne:
  > Ach! zmieniłem klasę na wzorzec klasy, to teraz muszę ten wzorzec wynieść do innego pliku o rozszerzeniu .tpp, pamiętać muszę o tym, żeby te wzorce właściwie dołączać do kodu, mam nadzieję, że mi się zależności w kodzie nie posypią).  
Te formalne reguły nie są sprawdzane przez kompilator ani żadne narzędzie, nic od nich nie zależy.
  * pliki z kodem generowane maszynowo (jakieś tablice konwersji, definicje gramatyk itp): nie ma reguły nazewnictwa, rozsądnym wyborem jest .inc.

Kompilator nie ingeruje w wielkość znaków w nazwach plików, obsługa systemu plików pozostawiona jest podsystemowi plików systemu operacyjnego. Linux i Unix zazwyczaj rozróżniają wielkie i małe litery ("myFile.cpp" i "myfile.cpp" to dwa różne pliki), Windows zazwyczaj ich nie rozróżnia ("myFile.cpp" i "myfile.cpp" to ten sam plik).

Bezpiecznie jest **używać nazw plików takich, jakimi są** (wielkie/małe litery):

* ```#include <stdio.h>           // przenośne, zawsze działa```
* ```#include <stdIO.h>           // ładnie wygląda, nie zawsze działa```

W rozbudowanych systemach kompilacji: pliki z kodem będą przetwarzane przez całkiem sporą liczbę narzędzi, na wielu komputerach, pod kontrolą wielu systemów operacyjnych. Dla uniknięcia problemów z przenośnością warto przestrzegać zalecenia: jedyne dopuszczalne znaki w nazwach **plików i katalogów**(!) to: **litery alfabetu łacińskiego, cyfry i znaki: podkreślenie, plus i minus** \[a-zA-Z0-9\_+\\-]. No i jedna kropka jako separator nazwy i rozszerzenia.

## Komentarze

Komentarze w kodzie są wykrywane i usuwane na bardzo wczesnym etapie kompilacji.

Są dostępne dwa rodzaje komentarzy: jednoliniowe ```\\ Lorem ipsum``` i blokowe ```\* Lorem ipsum *\```

```C++
  auto i = 0;   // Treść od tego miejsca do końca linii jest ignorowana
  auto          // j = 1; <- to też jest komentarz
       j = 2;   // a to jest kontynuacja linii po usunięciu komentarza
```
jest równoważne:
```C++
  auto i = 0;
  auto
       j = 2;
```

```C++
  auto i =    /* 0;   Od tego miejsca aż do końca komentarza wszystko jest ignorowane
  auto j = 0; // j = 9; <- to też jest komentarz
              /* to nie jest początek komentarza, bo już jest wewnątrz innego
       j = 0; // a to jest kontynuacja linii po usunięciu komentarza
  Poprzednie linie są w całości wewnątrz komentarza wieloliniowego
  A tu jest jego koniec => */ 2;
  auto z = /* 11 */ 9;
```
jest równoważne (komentarz zastąpiony spacją):
```C++
    auto i =      2;
    auto z =   9;
```

Komentarz ```\*  *\``` nie jest zagnieżdzony
```
\*       początek komentarza
\*       te znaki są ignorowane, bo już są wewnątrz komentarza
*\       // te znaki kończą komentarz
*\       // te znaki spowodują błąd, bo nie ma żadnego komentarza blokowego do zakończenia
```

(idiom) Język udostepnia jeszcze jeden mechanizm podobny do komentarza na poziomie preprocesora (o którym będzie za chwilę):
```C++
  auto i = 0;
  #if 0
    Blok od ```#if 0``` do ```#endif``` jest ignorowany
    Ten pseudo-komentarz też nie jest zagnieżdzany - działa do najbliższej linii ```#endif```
  #endif
```

Warto rozważyć propozycję używania na co dzień wyłącznie komentarzy jednoliniowych ```\\```.
```C++
  auto i = 0; // Lorem ipsum dolor sit amet, consectetur adipiscing elit.
              // Phasellus ut lorem ut ante gravida tincidunt.
              // Etiam et tellus a velit molestie posuere.
              // Curabitur accumsan facilisis nulla, a varius urna iaculis et.
  auto j = 2;
```
Dzięki temu - (na przykład w czasie uruchamiania) będzie możliwe objęcie komentarzem blokowym ```\*  *\``` fragmentu kodu z komentarzami.
```C++
/*
  auto i = 0; // Lorem ipsum dolor sit amet, consectetur adipiscing elit.
              // Phasellus ut lorem ut ante gravida tincidunt.
              // Etiam et tellus a velit molestie posuere.
              // Curabitur accumsan facilisis nulla, a varius urna iaculis et.
  auto j = 2;
*/
```
















# Struktura programu

Kod źródłowy programu w języku C++ zapisuje się w **zwykłych plikach tekstowych** \(ang: plain text files\).

## Język

Mimo, że kurs jest prowadzony po polsku, należy pamiętać, że językiem "urzędowym" jest angielski. Gorąco zachęcam do używania angielskiego w komentarzach, nazwach identyfikatorów, nazwach plików. Wystarczający jest [Basic English](http://www2.educ.fukushima-u.ac.jp/~ryota/word-list.html).

## Pliki tekstowe

Pliki mogą być zapisane w zwykłym ASCII, większość kompilatorów dobrze rozumie też UTF-8 i UTF-16.

Podstawowy zestaw znaków języka obejmuje:

* 5 równoważnych rodzajów spacji: spacja \('\0x20'\), tabulator poziomy \(HT, '\0x09'\), tabulator pionowy \(VT, '\0x0B'\), znak nowej strony \(FF, '\0x0C'\), znak nowej linii \(LF, '\0x0A'\).
* 10 cyfr: '0' do '9'
* 52 litery alfabetu łacińskiego: od 'a' do 'z' oraz od 'A' do 'Z'
* 29 znaków interpunkcyjnych: \_ { } \[ \] \# \( \) &lt; &gt; % : ; . ? \* + - / ^ & \| ~ ! = , \ " '  
  Wszystkie inne znaki są zastępowane znakami z zestawu rozszerzonego, zależnie od użytego kodowania.

Bezpiecznie jest wystrzegać się stosowania znaków spoza podstawowego zestawu, nawet naszego polskiego "ąćęłńóśźż":

* w kodzie programu pojawią się nieoczywiste interpretacje i konwersje, zależne od tego jak plik jest zakodowany, wyszukiwanie związanych z tym prpblemów jest bardzo trudne,
* język pozwala takie znaczki zapisać explicite razem z pożądanym kodowaniem,
* można wprawić w zakłopotanie inne narzędzia pracujące z naszym kodem.

Większość kompilatorów i narzędzi dobrze sobie radzi z niekonsekwentnym stosowaniem znaku końca linii \(DOS/Unix/Mac\).

Zawsze **rozróżniane są małe i wielkie litery** \(ang: case sensitive\).

## Pliki z kodem

Używane są dwa podstawowe rodzaje plików z kodem:

* **pliki z treścią programu**: **\*.cpp** \(C++\) i **\*.c** \(C\). Można spotkać się też z plikami o rozszerzeniach: .c++, .cc, .cxx., .C, obecnie zazwyczaj są niezalecane.
* pliki z deklaracjami \(obiektów, funkcji, klas, typów itp\), zwane  też **plikami nagłówkowymi** \(ang: header files\): **\*. \(bez rozszerzenia\)** \(C++\) i **\*.h** \(C/C++\). Można też spotkać \(obecnie niezalecane\) .hpp i .hxx
* można spotkać pliki 
  * .ii, .ixx, .ipp, .inl \(nagłówki zawierające fragmenty kodu `inline)`
  * .txx, .tpp, .tpl - definicje wzorców \(ang: templates\).
  * wprowadzanie sztucznych formalizmów \(jak te powyżej\) nakłada na programistę dodatkowe obowiązki administracyjne:
    > Ach! zmieniłem klasę na wzorzec klasy, to teraz muszę ten wzorzec wynieść do innego pliku o rozszerzeniu .tpp, pamiętać muszę o tym, żeby te wzorce właściwie dołączać do kodu, mam nadzieję, że mi się zależności w kodzie nie posypią\).  
    > Te formalne reguły nie są sprawdzane przez kompilator ani żadne narzędzie, nic od nich nie zależy.

  * pliki z kodem generowane maszynowo \(jakieś tablice konwersji, definicje gramatyk itp\): nie ma reguły nazewnictwa, rozsądnym wyborem jest .inc.


Kompilator nie ingeruje w wielkość znaków w nazwach plików, obsługa systemu plików pozostawiona jest podsystemowi plików systemu operacyjnego. Linux i Unix zazwyczaj rozróżniają wielkie i małe litery \("myFile.cpp" i "myfile.cpp" to dwa różne pliki\), Windows zazwyczaj ich nie rozróżnia \("myFile.cpp" i "myfile.cpp" to ten sam plik\).

Bezpiecznie jest **używać nazw plików takich, jakimi są** \(wielkie/małe litery\):

* `#include <stdio.h>           // Portable. It always works.`
* `#include <stdIO.h>           // Pretty. It does not always work.`

W rozbudowanych systemach kompilacji: pliki z kodem będą przetwarzane przez całkiem sporą liczbę narzędzi, na wielu komputerach, pod kontrolą wielu systemów operacyjnych. Dla uniknięcia problemów z przenośnością warto przestrzegać zalecenia: jedyne dopuszczalne znaki w **nazwach plików i katalogów**\(!\) to: **litery alfabetu łacińskiego, cyfry i znaki: podkreślenie, plus i minus** \[a-zA-Z0-9\_+\-\]. No i jedna kropka jako separator nazwy i rozszerzenia.

## Komentarze

Komentarze w kodzie są wykrywane i usuwane na bardzo wczesnym etapie kompilacji.

Są dostępne dwa rodzaje komentarzy: jednoliniowe `\\ Lorem ipsum` i blokowe `\* Lorem ipsum *\`

```C++
  auto i = 0;   // <- Ignored from this point
  auto          // j = 1; <- It is a comment, too
       j = 2;   // previous line of code "auto" is continued
```

jest równoważne:

```C++
  auto i = 0;
  auto
       j = 2;
```
(_kolorowanie składni pogubiło się_)
```C++
  auto i =    /* 0;   Everything form this point is ignored
  auto j = 0; // j = 9; Whole line is a comment
              /* This is not the beginning of a comment
       j = 1; // Whole line is a comment
                 Comment ends -> */ 2;
  auto z = /* 11 */ 9;   // 11 was commented out
```

jest równoważne \(komentarz zastąpiony spacją\):

```C++
  auto i =      2;
  auto z =   9;
```

Komentarz `\*  *\ nie jest zagnieżdzony`

```C++
\*       Comment begins
\*       Comment does not begin, comment was started in previous line
*\       // Comment ends
*\       // Syntax error
```

\(idiom\) Język udostepnia jeszcze jeden mechanizm podobny do komentarza - na poziomie preprocesora \(o którym będzie za chwilę\):

```C++
  auto i = 0;
  #if 0
    Pseudo-comment:
    whole block ```#if 0```  ```#endif``` is ignored
    i = 2;
  #endif
  auto z = 9;
```

### Styl komentowania

Warto rozważyć propozycję używania na co dzień wyłącznie komentarzy jednoliniowych `\\.`

```C++
  auto i = 0; // Lorem ipsum dolor sit amet, consectetur adipiscing elit.
              // Phasellus ut lorem ut ante gravida tincidunt.
              // Etiam et tellus a velit molestie posuere.
              // Curabitur accumsan facilisis nulla, a varius urna iaculis et.
  auto j = 2;
```

Dzięki temu - \(na przykład w czasie uruchamiania\) będzie możliwe objęcie komentarzem blokowym `\*Lorem*\ fragmentu kodu z komentarzami.`

```C++
/*
  auto i = 0; // Lorem ipsum dolor sit amet, consectetur adipiscing elit.
              // Phasellus ut lorem ut ante gravida tincidunt.
              // Etiam et tellus a velit molestie posuere.
              // Curabitur accumsan facilisis nulla, a varius urna iaculis et.
  auto j = 2;
*/
```

### Wsparcie edytora

Dobre edytory udostępniają tryb edycji w kilku liniach jednocześnie \(multiline edit, multicaret edit, block mode\).

> Visual Studio:
>
> * należy ustawić kursor na początku bloku
> * wcisnąć Alt-Shift-Down kilkukrotnie
> * zacząć pisać \(na przykład znaki "// "\)

### Po co komu komentarz?

Są dwie szkoły, każda ma swoje racje.

1. Komentarzy należy pisac dużo. Co najmniej 20% linii programu to powinny byc komentarze \(dokładniej: na 100 linii czystego kodu powinno przypdać 20 linii komentarzy z jakąś treścią\).
2. Język wysokiego poziomu \(takim jest C++\) pozwala pisać kod samo-dokumentujący się. Jeśli kod wymaga dodatkowego opisu, to znaczy, że jest napisany źle. Poprawności komentarzy nic nie sprawdza, w szczególności kompilator. Jeśli w kodzie jest komentarz stary, taki, który jest z kodem sprzecznym, to on jest nie tyle, że bezwartościowy, a szkodliwy. 

### Doxygen, JavaDoc

Istnieją narzędzia, które na podstawie komentarzy w kodzie \(komentarzy w specyficznie zdefiniowanej formie\) tworzą dokumentację kodu.

W poprzednim punkcie wybór padł na "kod należy pisać tak, aby było zbędne komentowanie go". Ale gdyby jednak, to niech kometarze będą zgodne z jakimś przemysłowym standardem. Niech to będzie  [Doxygen](http://www.stack.nl/~dimitri/doxygen/manual/commands.html). Przykład dokumentacji wyprodukowanej przez Doxygen: biblioteka [ICU4C](https://ssl.icu-project.org/apiref/icu4c/).

```C++
//! \brief Copies bytes from a source memory area to a destination memory area, 
//! where both areas may not overlap.
//! \param[out] dest The memory area to copy to.
//! \param[in]  src  The memory area to copy from.
//! \param[in]  n    The number of bytes to copy
void memcpy(void *dest, const void *src, size_t n);
```

# Gotowy kod

Komentarze na Coliru.

Solucja jest dostępna na [githubie](https://github.com/jbanaszczyk/CppTraining/tree/master/examples/001/Comments)


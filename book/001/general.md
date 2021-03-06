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

* w kodzie programu pojawią się nieoczywiste interpretacje i konwersje, zależne od tego jak plik jest zakodowany, wyszukiwanie związanych z tym problemów jest bardzo trudne,
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

W rozbudowanych systemach kompilacji: pliki z kodem będą przetwarzane przez całkiem sporą liczbę narzędzi, na wielu komputerach, pod kontrolą wielu systemów operacyjnych. Dla uniknięcia problemów z przenośnością warto przestrzegać zalecenia: jedyne dopuszczalne znaki w **nazwach plików i katalogów**\(!\) to: **litery alfabetu łacińskiego, cyfry i znaki: podkreślenie, plus i minus** \[a-ßzA-Z0-9\_+\-\]. No i jedna kropka jako separator nazwy i rozszerzenia.


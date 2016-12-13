# Preprocesor

Jedną z najwcześniejszych faz kompilacji jest wstępne przetwarzanie kodu źródłowego przez preprocesor \(ang: preprocessor\). Jest to bardzo silne narzędzie, o niewielkiej liczbie reguł, które nic nie wie o gramatyce języka C++.

Przy pomocy preprocesora można uzyskać spektakularne efekty \(przykłady: standardowe biblioteki języka albo mój faworyt: bibilioteka [Google Test](https://github.com/google/googletest)\), można też wprowadzić do kodu błędy trudne do uchwycenia.

Dyrektywy preprocesora pozwalają dopasowac funkcje biblioteczne do konkretnej platformy \(np. x86 i ARM\), architektury \(np. 32 i 64 bity\) albo nawet języka \(C i C++\) czy kompilatora \(np. Visual Studio albo gcc\). Oznacza to, że można **bez żadnych modyfikacji** użyć tej samej biblioteki kompilując kod w języku C dla ARMa 32-bitowego, jak i w C++ dla Windows.

## Szybki przykład

Weźmy taki kod:

```C++
  #define N 100
  auto x = N;
  auto y = N;
  auto z = N5;
```
Linia ```#define N 100``` mówi kompilatorowi: od tej pory każde wystąpienie słowa ```N``` należy zastępować słowem ```100```. Jako słowo rzoumie się: dokładnie taka grupa znaków alfanumerycznych \(małe/wielkie litery, cyfry i znak podkreślenia\). ```N``` jest zastępowane przez ```100```, ale ```N5``` to nie jest ```1005```.  
Do kompilacji jest kierowany taki kod:
```C++
  auto x = 100;
  auto y = 100;
  auto z = N5;
```

## Ostrożnie

Preprocesor nie sygnalizuje żadnych błędów składni, po prostu wykonuje proste operacje na kodzie źródłowym kierowanym do kompilacji. Kontrole poprawnosci realizuje kompilator, który operuje na wynikach działania preprocesora, których zazwyczaj nawet nie widzimy \(widzimy kod źrodłowy przed przetworzeniem przez preprocesor\).

## Dyrektywy

Preprocesor definiuje swój własny język, który:

* operuje własnymi symbolami \(tworzonymi przez ```#define ```, usuwanymi przez ```#undef```\),
    * niektóre z symboli mają związek z procesem kompilacji \(np. _\_func__\),
    * zna wyrażenia operujące na tych symbolach,
* wybiera, które fragmenty kodu kierowac do kompilacji, a które nie \(```#if``` \ ```#ifdef``` \ ```#ifndef```, ```#elif``` \ ```#else```, ```#endif```\),
* dołącza do kompilowanego pliku zawartość innych plików \(```#include```\),
* potrafi przerwać proces kompilacji \(`#error`\),
* potrafi wykonać inne, niestandardowe (zdefiniowane przez kompilator) akcje \(`#pragma`\).

### Składnia

Dyrektywa preprocesora składa się z:  
* znaku `#`
* nazwy dyrektywy
* argumentów \(zależnie od dyrektywy\)
* znaku końca linii.

#### Jedna linia

Z powyższego wynika, że dyrektywy preprocesora są wyłącznie jednoliniowe - w odróżnieniu od całej reszty \(język C i C++ traktuje, poza bardzo nielicznymi wyjątkami, znak nowej linii jak spację, podział kodu programu na linie służy wyłącznie zwiększeniu czytelności kodu\).

A jeśli dyrektywa jest bardzo długa? Z pomocą przychodzi jedna \(z nielicznych\) faz kompilacji przed preprocesorem:  
> Jeśli na końcu linii jest znak `\`, to znak `\` i znak przejścia do nowej linii są usuwane i kolejna linia jest dołączana do poprzedniej.

Można tak "skleić" wiele kolejnych linii. Działanie to nie ma żadnego innego zastosowania.

```C++
#define NUMBERS                                                                    \
  00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,  \
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,  \
  40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  \
  60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,  \
  80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
```










\#define  
\#elif  
\#else  
\#endif  
\#error  
\#if  
\#ifdef  
\#ifndef  
\#include  
\#line  
\#pragma  
\#undef  





 














# Komentarze

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
\(_kolorowanie składni pogubiło się_\)
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

Komentarz `\*  *\ nie jest zagnieżdżony`

```C++
\*       Comment begins
\*       Comment does not begin, comment was started in previous line
*\       // Comment ends
*\       // Syntax error
```

\(idiom\) Język udostępnia jeszcze jeden mechanizm podobny do komentarza - na poziomie preprocesora \(o którym będzie za chwilę\):

```C++
  auto i = 0;
  #if 0
    Pseudo-comment:
    whole block ```#if 0```  ```#endif``` is ignored
    i = 2;
  #endif
  auto z = 9;
```

## Styl komentowania

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

## Wsparcie edytora

Dobre edytory udostępniają tryb edycji w kilku liniach jednocześnie \(multiline edit, multicaret edit, block mode\).

> Visual Studio:
>
> * należy ustawić kursor na początku bloku
> * wcisnąć Alt-Shift-Down kilkukrotnie
> * zacząć pisać \(na przykład znaki "// "\)

## Po co komu komentarz?

Są dwie szkoły, każda ma swoje racje.

1. Komentarzy należy pisać dużo. Co najmniej 20% linii programu to powinny być komentarze \(dokładniej: na 100 linii czystego kodu powinno przypadać 20 linii komentarzy z jakąś treścią\).
2. Język wysokiego poziomu \(takim jest C++\) pozwala pisać kod samo-dokumentujący się. Jeśli kod wymaga dodatkowego opisu, to znaczy, że jest napisany źle. Poprawności komentarzy nic nie sprawdza, w szczególności kompilator. Jeśli w kodzie jest komentarz stary, taki, który jest z kodem sprzecznym, to on jest nie tyle, że bezwartościowy, a szkodliwy. 

## Doxygen, JavaDoc

Istnieją narzędzia, które na podstawie komentarzy w kodzie \(komentarzy w specyficznie zdefiniowanej formie\) tworzą dokumentację kodu.

W poprzednim punkcie wybór padł na "kod należy pisać tak, aby było zbędne komentowanie go". Ale gdyby jednak, to niech komentarze będą zgodne z jakimś przemysłowym standardem. Niech to będzie  [Doxygen](http://www.stack.nl/~dimitri/doxygen/manual/commands.html). Przykład dokumentacji wyprodukowanej przez Doxygen: biblioteka [ICU4C](https://ssl.icu-project.org/apiref/icu4c/).

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

Rozwiązanie jest dostępne na [githubie](https://github.com/jbanaszczyk/CppTraining/tree/master/examples/001/Comments)

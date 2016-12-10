# Preprocesor

Jedną z najwcześniejszych faz kompilacji jest wstępne przetwarzanie kodu źródłowego przez preprocesor \(ang: preprocessor\). Jest to bardzo silne narzędzie, o niewielkiej liczbie reguł, które nie wie nic o gramatyce języka C++. 

Dyrektywy preprocesora pozwalają dopasowac funkcje biblioteczne do konkretnej platformy \(np. x86 i ARM\), architektury \(np. 32 i 64 bity\) albo nawet języka \(C i C++\) czy kompilatora \(Visual Studio i gcc\). Oznacza to, że można **bez żadnych modyfikacji** użyć tej samej biblioteki kompilując kod w języku C dla ARMa 32-bitowego, jak i w C++ dla Windows.

Przy pomocy preprocesora można uzyskać spektakularne efekty \(przykłady: biblioteki języka albo mój faworyt: bibilioteka [Google Test](https://github.com/google/googletest)\), można też wprowadzić do kodu błędy trudne do uchwycenia. 

## Szybki przykład

Weźmy taki kod:

```C++
  #define N 100
  auto x = N;
  auto y = N;
  auto z = N1;
```
Linia ```#define N 100``` mówi kompilatorowi: od tej pory każde wystąpienie słowa ```N``` należy zastępować slowem ```100```. Jako słowo rzoumie się - dokładnie taka grupa znaków alfanumerycznych \(małe/wielkie litery, cyfry i znak podkreślenia\). ```N``` jest zastępowane przez ```100```, ale ```N5``` to nie jest ```1005```.  
Do kompilacji jest kierowany taki kod:
```C++
  auto x = 100;
  auto y = 100;
  auto z = N1;
```

## Ostrożnie

Preprocesor nie sygnalizuje żadnych błędów składni, po prostu wykonuje proste operacje na kodzie źródłowym kierowanym do kompilacji. Kontrole poprawnosci realizuje kompilator, który operuje na wynikach działania preprocesora, których my nawet nie widzimy (widzimy kod źrodłowy przed przetworzeniem przez preprocesor).

W językach C++ oraz C99 wprowadzono słowa kluczowe


 














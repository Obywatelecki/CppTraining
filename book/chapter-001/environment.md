# Środowisko

## Komputer

Widziałem komputer służący do kompilacji programów, który miał 128 gigbajtów pamięci i kilka procesorów XEON. Widziałem program (system), który kompilował się na tym potworze kilka godzin. Czasem słaby laptop może nie wystarczyć.

Nie ma potrzeby zaczynać od jakiegoś superkomputera, ale:
* wydajny dysk znakomicie przyspiesza naukę (w czasie kompilacji nawet małego programu kompilator odczytuje i zapisuje setki plików).
* kompilator zużywa trochę pamięci, większość kompilatorów dobrze wykorzystuje wiele rdzeni i procesorów, nie ma sensu przesadzać, to nie musi być komputer dla gracza.

Przykładowe [minimalne wymagania](https://www.visualstudio.com/en-us/productinfo/vs2015-sysrequirements-vs) dla Visual Studio (one są naprawdę minimalne a nie komfortowe):
- 1.6 GHz processor
- 1 GB of RAM
- 4 GB of available hard disk space
- 5400 RPM hard disk drive
- DirectX 9-capable video card (1024 x 768)
- Windows 7

## Kompilator

Dostępnych, aktualnych i rozwiajanych kompilatorów języka C++ jest na rynku ... kilkadziesiąt, może więcej. Różnią się dostępnością (komercyjne, darmowe, darmowe warunkowo), platformą na której działają i platformą dla której tworzą programy.

Spośród kompilatorów działających na komputerach osobistych (Windows, Linux, MacOs), tworzących programy dla komputerów osobistych warto wspomnieć o:
- Visual C++, wchodzący w skład Visual Studio. Działa pod kontrolą systemu Windows, wspiera C++14 i częściowo C++17, produkt komercyjny, są różne darmowe wersje (dla małych firm - edycja Express, dla społeczności Open Source - edycja Community), znakomity. Przy pomocy Visual C++ jest skompilowany cały system Windows.
- gcc/g++ - rewelacyjny kompilator i kompilator skrośny, przede wszystkim dla Linuxa, wspiera C++14 i C++17, wprowadza rozszerzenia inspirujące powstawanie kolejnych wersji języka. Przy pomocy gcc jest skompilowany cały system Linux. Wersja gcc dla Windows to MinGW, raczej niszowa. Dostępny na licencji GPL i LGPL (najgorsza możliwa licencja, wymysł diabła, jeszcze o tym będzie).
- clang - kolejny świetny kompilator, stoi za nim Apple. Konkuruje z gcc (w wielu zastosowaniach można użyć clanga wymiennie z gcc), motywacją napisania clanga była potrzeba stworzenia kompilatora na licencji liberalnej (BSD). Wspiera C++14, C++17 i podobnie jak gcc wprowadza rozszerzenia inspirujące powstawanie kolejnych wersji języka. Wersja dla Windows raczej nie działa, plotka głosi, że Microsoft planuje migrację do clanga (któraś kolejna wersja Windows ma być skompilowana clangiem).

## Środowisko zintegrowane (IDE)

Można programy pisać w notepadzie albo VI i kompilować z linii poleceń. Można furmanką pojechać do Paryża, tylko po co? Przemyślane, dobrze skonfigurowane zintegrowane środowisko projektowe znakomicie odciąża programistę, nie trzeba dbać o drobiazgi, zapewnia harmonijną współpracę dobrego edytora, kompilatora, środowiska uruchomieniowego (debuggera czyli odpluskwiacza, będzie o nim więcej) i kilku innych narzędzi. Po to ludzkość wymyśliła komputery, żeby pracowały za nas i żebyśmy mogli skoncentrować się na pracy.


 


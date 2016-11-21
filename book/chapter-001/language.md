# Język C++

## Paradygmaty C++

Do tego rozdziału warto będzie wrócic co jakiś czas.

Wiki określa język C++ jako język o wielu paradygmatach. Paradygmat to styl programowania. Będzie mowa o obiektowości. Typy danych w C++ są konkretne i niezmienne, a zarazem C++ umożliwia programowanie generyczne - algorytmy mogą być uniezależnione od typów danych na których operują. C++ oddaje bardzo sprawne i elastyczne abstrakcje danych - tablice, listy, stosy i inne kontenery, na których można operować niezależnie od tego, co mają w środku. A jeśli klasy, interfejsy, kontenery w konkretnym zastosowaniu są niepotrzebne, a ważna jest wydajnośći  mozliwość napisania programu który operuje blisko krzemu - C++ sprawdzi się znakomicie jako trochę lepszy asembler.

Połączenie wielu paradygmatów w jednym języku daje programiście do ręki bardzo wszechstronne narzędzie.

Język C++ jest wyposażony w mechanizmy bardzo silne i niespotykane w innych językach: destruktory i dziedziczenie po wielu klasach jednocześnie (dziedziczenie wielokrotne powoduje u wielu programistów silny ból głowy).

Cechą wzmacniającą uniwersalność jest fakt, że kompilatory potrafą wyprodukować "program" naturalny (ang: native) dla docelowej platformy, taki który na platformie uruchamia się bezpośrednio, nie wymagając żadnych maszyn wirtualnych ani innych dodatków. Wiele kompilatorów wspiera także kompilację skrośną - na przykład na komputerze z systemem Windows i procesorem Intela można wyprodukować program działający pod Linuxem z procesorem ARM. Albo jakoś inaczej.

## Trochę historii

Pierwsza wersja języka C++ powstała w 1983 jako rozszerzenie do dziś bardzo popularnego języka C. Początkowo język funkcjonował jako "C z klasami". Dziś lista rozszerzeń w stosunku do C jest bardzo długa, trudno C++ traktować jako "trochę lepsze C", to jest inny język.

### C++98, C++03, TR1, C++11, C++14, C++17, ...

Z tymi terminami warto się zapoznać, bo często przewijają się w literaturze i na forach.

Z jednej strony C++ jest językiem żywym, stale rozwijanym, podlega ciągłym zmianom i ulepszeniom. Z drugiej - najnowsze wersje nadal są w ogromnej części zgodne z poprzednimi, a nawet z pierwowzorem czyli językiem C. Jako zgodność rozumiem "program napisany w starożytnym C++98 da się bez kłopotów skompilować najnowszymi kompilatorami i będzie poprawnie działać".

Za przykład konserwatywności języka niech posłuży sprawa [trigraphów](https://en.wikipedia.org/wiki/Digraphs_and_trigraphs). Prehistoryczny standard kodowania [EBCDIC](https://en.wikipedia.org/wiki/EBCDIC) nie zawierał tak elementarnych i kluczowych dla języka znaków jak { } | itp. Kłopot rozwiązano wprowadzając symbole zastępcze: ```??<``` zamiast ```{```, ```??>``` zamiast ```}```, ```??!``` jako ```|``` itp. Od dawna używamy co najmniej [ASCII](https://en.wikipedia.org/wiki/ASCII), a niedoświadczeni programiści czasem wpadają w pułapkę: czemu instrukcja ```printf "Why ??!";``` produkuje napis ```Why |```. Uunięcie trigraphów zaproponowano przy okazji wprowadzenia C++11, IBM oprotestował. Wszystko wskazuje na to, że w C++17 poprawka zmierzająca do usunięcia trigraphów zostanie w końcu zaakceptowana.

#### C++98, C++03

Gramatyka, semantyka oraz biblioteka standardowa języka C++ jest podmiotem standaryzacji [ISO](http://www.iso.org)  oraz [IEC](http://www.iec.ch/). W ramach ISO standardem języka C++ opiekuje się komitet [WG21](https://isocpp.org/std/the-committee). 

Pierwsza norma opisująca język C++ została opublikowana w 1998, dziś określamy go mianem C++98. Niedługo potem powstał standard C++03. Nie wnosił wiele nowego, naprawiał tylko błędy wersji C++98.

#### TR, TS

Prace nad normalizacją utknęły w miejscu - za dużo pomysłow na raz, nie dało się wprowadzić jakiegoś fajnego, dobrze ograniczonego standardu. Komitet opublikował wiele raportów technicznych (TR) i specyfikacji (TS), większość kompilatorów wspierała poszczególne TR i TS (choć każdy po swojemu), ale nie miały one mocy prawnej.

#### C++11, C++14

Kłopot rozwiązano przez zmianę trybu procedowania: kolejne wersje języka będą powstawały co trzy lata. Jeśli jakiś pomysł zostanie wystarczająco przedyskutowany i zaakceptowany, to wejdzie do standardu, a jak nie, to musi poczekać do kolejnej edycji. To trochę jak z pociągiem: spóźniłeś się na dworzec - pojedziesz następnym.

Standard C++11 definiuje w zasadzie całkiem nowy język, a C++14 wprowadza niewiele zmian i poprawia dużo błędów i nieścisłości.

#### C++17

Propozycja wersji C++17 została określona na konferencji w Oulu (czerwiec 2016), do końca marca 2017 pracować będzie komisja balotażowa.

### C99, C11

Język C też jest normalizowany przez ISO, rozwija się znacznie wolniej, aktualny standard powstał w 2011 i niewiele różni się od oryginału z roku 1978 (sprzed prawie 40 lat). Widziałem gdzieś porównanie sposobu kodowania sprzed 25 kat i współcześnie (ówczesna wersja Linuxa i jedno z pierwszych wydań Worda): bardzo niewiele uległo zmianie (nie potrafię odtworzyć źródeł informacji).

## Która wersja?

Niniejszy kurs opiera się na wersji języka **C++14**, być może będzie coś o C++17.

Od programisty C++ oczekuje sie też umiejętności pisania w C, C++ jest nadzbiorem C, wobec tego język C będzie podmiotem tego kursu. Na zakończenie.

## Osoby i autorytety

Warto spojrzeć na publikacje:

* [Bjarne Stroustrup](http://www.stroustrup.com/): Autor języka. Z jego strony domowej: "zaprojektowałem i zaimplementowałem język C++, napisałem kilka książek, [...]". 
* [Scott Mayers](http://www.aristeia.com/): niestety już emeryt.
* [Herb Sutter](http://www.gotw.ca/): pracuje w Microsofcie, współodpowiada za rozwój Visual Studio (C++ i CLI)
* Andrei Alexandrescu: autorzy kompilatorów traktują jego bibliotekę [Loki](http://loki-lib.sourceforge.net/) jako sprawdzian kompatybilności z językiem (czyli "jeśli kompilator prawidłowo skompiluje Loki, to może aspirować do bycia kompilatorem")
* Banda Czworga (Gang Of Four, GoF) - Erich Gamma, Richard Helm, Ralph Johnson oraz John Vlissides: autorzy "Inżynieria oprogramowania: Wzorce projektowe".
* [StackOverflow](https://stackoverflow.com/): absolutnie najważniejsze, wiarygodne forum wymiany wiedzy.
* [boost](http://www.boost.org/): społeczność i kolekcja bibliotek. To oni implementują większość nowości w C++; to nad czym głosuje ISO w nowych wersjach C++ jest zazwyczaj już zaimplementowane przez boost. Będzie o tym cały rozdział.

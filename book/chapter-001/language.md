# Język C++

## Trochę historii

Pierwsza wersja języka C++ powstała w 1983 jako rozszerzenie, do dziś bardzo popularnego języka C.Początkowo język funkcjonował jako "C z klasami". Dziś lista rozszerzeń w stosunku do C jest bardzo długa, trudno C++ traktować jako trochę lepsze C. 

### C++98, C++03, TR1, TR2, C++11, C++14, C++17, ...

Z tymi terminami warto się zapoznać, bo często przewijają się w literaturze i na forach.

Z jednej strony C++ jest językiem żywym, stale rozwijanym, podlega ciągłym zmianom i ulepszeniom. Z drugiej - najnowsze wersje nadal są w ogromnej części zgodne z poprzednimi, a nawet z pierwowzorem czyli językiem C. Jako zgodność rozumiem "program napisany w C++98 da się bez kłopotów skompilować najnowszymi kompilatorami i będzie poprawnie działać".

Za przykład konserwatywności języka niech posłuży sprawa [trigraphów](https://en.wikipedia.org/wiki/Digraphs_and_trigraphs). Prehistoryczny standard kodowania [EBCDIC](https://en.wikipedia.org/wiki/EBCDIC) nie zawierał tak elementarnych i kluczowych dla języka znaków jak {, }, | itp. Kłopot rozwiązano wprowadzając symbole zastępcze: ??< zamiast {, ??> zamiast }, ??! jako | itp. Od dawna używamy co najmniej [ASCII](https://en.wikipedia.org/wiki/ASCII), a niedoświadczeni programiści czasem wpadają w pułapkę: czemu instrukcja ```printf "Why ??!";``` produkuje napis ```Why |```. Uunięcie trigraphów zaproponowano przy okazji wprowadzenia C++11, IBM oprotestował. Wszystko wskazuje na to, że w C++17 poprawka zmierzająca do usunięcia trigraphów zostanie zaakceptowana.

Od roku 1998 gramatyka, semantyka oraz biblioteka standardowa języka C++ jest podmiotem standaryzacji ISO (International Organization for Standardization). 









Ten kurs jest zaprojektowany jako kurs C++.








Autorem języka jest [Bjarne Stroustrup](http://www.stroustrup.com/). Z jego strony domowej: "zaprojektowałem i zaimplementowałem język C++, napisałem kilka książek, [...]".






### Windows?

Od czegoś trzeba zacząć. Kurs będzie prowadzony w oparciu o narzędzia działające pod kontrolą systemu operacyjnego Windows. Nie będzie żadnych odniesień "a jak to zrobić pod Linuksem?" (to nie jest kurs używania komputera).

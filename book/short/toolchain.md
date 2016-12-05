## Łańcuch narzędzi (ang: toolchain)

Podstawowy zestaw działań nad kodem źródłowym to:

* kompilacja (**compiler**): po jednej kompilacja dla każdego pliku źródłowego (\*.cpp albo \*.c), produkuje  plik pośredni (ang: object file) (zazwyczaj \*.obj albo \*.o).
* linkowanie (**linker**): jeden raz na cały projekt, integruje uprzednio wygenerowane pliki pośrednie oraz pliki bibliotek i tworzy plik gotowy do eksploatacji (gotowy do uruchomienia albo gotowy do zapisania w urządzeniu, albo …),
* opcjonalnie: tworzenie bibliotek (**librarian**): łączenie wielu wielu plików pośrednich w jedną zwartą bibliotekę - dla ułatwienia pracy linkera. Librarian nic nie integruje, po prostu tworzy archiwum plików i opatruje je metadanymi, nic szczególnego

Można też spotkać narzędzia związane nie tyle z językiem C++, co z docelową platformą:

* wstepne przetwarzanie:
  * powszechnym podejściem jest "kompilowanie tylko tego, co się zmieniło". 
* postprodukcja: dodawania manifestów, podpisywanie kodu
* przetwarzanie dodatkowych zasobów: dodawanie metdanych do kodu (ikony, menu itp),
 

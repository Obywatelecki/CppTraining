# Wymagania funkcjonalne i niefunkcjonalne

Na temat "jak bardzo rozminęła się wizja klienta i dostarczone klientowi oprogramowanie" powstało dziesiątki memów i dowcipów. Rozdział nie będzie o tym.  
Nie będzie też o testowaniu realizacji wymagań.

## Tłusty proces, tłuste wymagania

Książek na temat inżynierii wymagań powstało wiele, nie jedna, nie dwie - całe setki. Firmy szkoleniowe kształcą z inżynierii wymagań, wydają certyfikaty, inżynierowie zrzeszają się, naukowcy prowadzą badania, produkują zalecenia i modele jakości samych wymagań.

Język opisu wymagań często przypomina język prawniczy czy urzędniczy - wszystko mądrze wygląda, i [nijak nie daje się go zrozumieć](https://pl.wikipedia.org/wiki/Wymaganie_%28in%C5%BCynieria%29#Dobre_wymagania). Nic dziwnego, że w nowoczesnych [metodykach zarządzania procesami](../_placeholder_.md) ustępuje pola dokumentom odchudzonym i łatwiejszym do czytania.

To było na marginesie.

## Funkcjonalne, niefunkcjonalne i ograniczenia

Wymagania wobec systemu informatycznego można podzielić na trzy grupy:  
* funkcjonalne (ang: functional requirements): co system ma robić. Według nich system będzie oceniony "czy w ogóle działa".
* niefunkcjonalne (ang: non functional requirements): kryteria jakościowe, według nich system będzie oceniony "jak dobrze działa".
* ograniczenia (ang: constraints): ograniczenia, których nie należy przekroczyć.

Klasyfikowanie wymagań wymaga odrobiny wprawy. Weźmy takie wymaganie niefunkcjonalne:  
- system ma być szybki.
- ale jak szybki?
- system ma uruchamiać się w 5 sekund (należałoby jeszcze zdefiniować "czas uruchamiania").

To wygląda całkiem jak "ograniczenie". Więcej: można napisać test akceptacyjny, który będzie mierzyć czas uruchomienia systemu i sprawdzać, czy jest wystarczająco dobry. Mała jest różnica między testami akceptacyjnymi a testami funkcjonalnymi (o [testach jeszcze będzie](../_placeholder_.md)), testy funkcjonalne sprawdzają spełnienie wymagań funkcjonalnych, to wygląda trochę jak wymaganie funkcjonalne.  
Mimo to - mamy do czynienia z wymaganiem niefunkcjonalnym w kategorii "szybkie uruchomienie" (ang: performance/latency).

Przykłady wymagań:
* funkcjonalne: użytkownik wciska guzik i pojawia się animowany bałwanek.
* niefunkcjonalne: bałwanek ma się pojawić jak najszybciej.
* ograniczenia: komercjalizacja produktu musi nastąpić w ciągu miesiąca (potem będzie po Świętach i będzie czas na nowy projekt: bałwanek ze śmigłem - żeby odlecieć do zimnych krajów).

### Wymagania funkcjonalne

Wymagania funkcjonalne dość jednoznacznie przekładają się na kod programu. Mając już pomysł jak będzie wyglądać architektura, z opisu wymagania dość często wynika - jak je zaimplementować.

```C++
  guzik.onKeypress( showBalwanek( animowany ) );
```
W przypadku niepowodzenia kopiowania pliku należy wyświetlić stosowny komunikat:

```C++
  if ( copyFailed() ) { sendAlert( msgCopyFailed ); };
```
Wymagania funkcjonalne prawie nie mają wpływu na architekturę systemu. Z wymagania "użytkownik wciska guzik i pojawia się animowany bałwanek" nie wynika "system musi mieć jakąś reprezentację guzika", ani nie wynika, że system ma graficzny interfejs użytkownika (GUI). Takie rzeczy definiuje się w ograniczeniach.

Kolejne (nowe) wymaganie funkcjonalne często jest względnie łatwe w implementacji i zazwyczaj nie powoduje konieczności zmiany całego systemu (choć czasem zmianę trzeba wprowadzić w bardzo wielu miejscach).

```
  [ guzik ]
                        [=(:^)
```

### Wymagania niefunkcjonalne

Wymagania niefunkcjonalne (zwane też wymaganiami jakościowymi) opisują pożądane cechy systemu w różnych kategoriach: testowalność, wydajność, skalowalność, czytelność kodu, użyteczność, …. [Tych kategorii](https://en.wikipedia.org/wiki/Non-functional_requirement) (-ość, ang: -ity) opisano i dogłębnie przeanalizowano około 50 (plus sporo podkategorii jak: szybkość/czas uruchomienia, szybkość/czas trwania operacji, szybkość/przepustowość, itd). Dla każdej z nich można znaleźć podpowiedzi: jak projektować system (ang: design principle), aby sprzyjać realizacji wymagania.

> Przykład: kod programu ma być dobrze przetestowany. Realizację wymagania z kategorii "testowalność" (ang: testability) promują zasady projektowania:  
> * Odwrócenie sterowania (ang: inversion of control).  
> * Segregacja interfejsów (ang: interface segregation).  
> Projektowanie systemu bez przestrzegania tych zasad doprowadzi do realizacji projektu, który nie spełnia wymagania "testowalność".

Może się zdarzyć, że wymagania niefunkcjonalne są wewnętrznie sprzeczne.  
> Dobrze, tanio i szybko - wybierz dwa.

Można szukać analogii w architekturze (budownictwo): miejsce do zamieszkania ma mieć cechę niefunkcjonalną "dobry dostęp do świeżych warzyw". Realizację tego wymagania ułatwiają wzorce:

* dom z ogródkiem,
* mieszkanie w bloku blisko bazaru,
* dom niedaleko działki (+rower).

Dodanie nowego wymagania niefunkcjonalnego zazwyczaj skutkuje dużą zmianą projektu. Jeśli jakaś cecha nie została uwzględniona w projekcie, to system prawdopodobnie jej nie ma.

> * Mamy domek z ogródkiem, chcielibyśmy dodać "energooszczędny".  
> * Mamy system, chcielibyśmy dodać "skalowalny (ang: scalability)".

### Ograniczenia

Ograniczenia wobec systemu zazwyczaj mają wpływ na proces wytwarzania.

* budżet: 10kPLN,
* czas realizacji: dwa miesiące,
* platforma: aplikacja dla Androida.

Ograniczenia zazwyczaj nie mają wpływu na architekturę ani szczegóły implementacji, a jeśli taki związek jest, to powinien być oddzielnie wyspecyfikowany.

> Przykład: system Tizen ułatwia użycie wzorca Model-View-Controler.  
> Określenie ograniczenia "aplikacja dla Tizena" nie implikuje utworzenia wymagania funkcjonalnego "architektura Model-View-Controler".  
> Należy je określić niezależnie.

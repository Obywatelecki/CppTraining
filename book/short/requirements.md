# Wymagania funkcjonalne i niefunkcjonalne

Na temat "jak bardzo rozminęła się wizja klienta i dostarczone klientowi oprogramowanie" powstało dziesiątki memów i dowcipów.

## Tłusty proces, tłuste wymagania

Książek na temat inżynierii wymagań powstało wiele, nie jedna, nie dwie - całe setki. Firmy szkoleniowe kstałcę z inżynierii wymagań, wydają certyfikaty, inżynierowie zrzeszają się, naukowcy prowadzą badania, produkują zalecenia i modele jakości samych wymagań.

Język opisu wymagań często przypomina język prawniczy czy urzędniczy - wszystko mądrze wygląda, i [nijak nie daje się go zrozumieć](https://pl.wikipedia.org/wiki/Wymaganie_%28in%C5%BCynieria%29#Dobre_wymagania). Nic dziwnego, że w nowoczesnych [metodykach zarządzania](../_placeholder_.md) procesami ustepuje pola dokumentom odchudzonym i łatwiejszym do czytania.

To było na marginesie.

## Funkcjonalne, niefunkcjonalne i ograniczenia

Wymagania wobec systemu informatycznego można podzielić na trzy grupy:  
* funkcjonalne (ang: functional requirements): co system ma robić. Wg nich system będzie oceniony "czy w ogole działa".
* niefunkcjonalne (ang: non functional requirements): kryteria jakościowe, według nich system będzie oceniony "jak dobrze działa".
* ograniczenia (ang: constraints): ograniczenie, których nie należy przekroczyć.

Niektóre z wymagań nie jest łatwo odpowiednio zakwalifikować. Na przykład: wymaganie niefunkcjonalne:  
- system ma być szybki.
- ale jak szybki?
- system ma uruchamiać się w 5 sekund (bez znaczenia w tym miejscu jest co to znaczy "czas uruchamiania").  
To wygląda całkiem jak "ograniczenie". Więcej: można napisac test akceptacyjny, który będzie mierzyć czas uruchomienia systemu i sprawdzać, czy jest wystarczająco dobry. Mała jest różnica między testami akceptacyjnymi a testami funkcjonalnymi (o [testach jeszcze będzie](../_placeholder_md)), testy funkcjonalne sprawdzają spełnienie wymagań funkcjonalnych, to wygląda trochę jak wymaganie funkcjonalne.  
Mimo to - to jest wymaganie niefunkcjonalne w kategorii "szybkie uruchomienie" (ang: performance/latency)

Przykłady wymagań:
* funkcjonalne: użytkownik wciska guzik i pojawia się animowany bałwanek.
* niefunkcjonalne: bałwanek ma się pojawić jak najszybciej.
* ograniczenia: komercjalizacja produktu musi nastąpić w ciągu miesiąca (potem będzie po świętach i bałwanek będzie musiał mieć śmigła - żeby odlecieć do zimnych krajów).

### Wymagania funkcjonalne

Wymagania funkcjonalne dość jednoznacznie przekładają się na kod programu. Mając już pomysł jak będzie wyglądać architektura z opisu wymagania dość często wynika jak go zaimplementować.

```C++
  guzik.onKeypress( showBalwanek( animowany ) );
```

```C++
  if ( copyFailed() ) { sendAlert( copyFailedMessage ); };
```
Wymagania funkcjonalne prawie nie mają wpływu na architekturę systemu. Z wymagania "użytkownik wciska guzik i pojawia się animowany bałwanek" nie wynika "system musi mieć jakąś reprezentację guzika", ani nie wynika, że system ma jakiś graficzny interfejs użytkownika (GUI). Takie rzeczy definuje się w ograniczeniach.

```
  [ guzik ]

                                  [=(:^)(*)(*)
```

### Wymagania niefunkcjonalne


### Ograniczenia








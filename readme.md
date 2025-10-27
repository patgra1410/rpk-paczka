# 🧩 Paczka do zadania Rozwiązanie pokojowe
## Autor: Patryk Grabowski

Wersja 1.02, 19.10.2025

Ten pakiet zawiera **zestaw testów**, **weryfikator wyjścia** oraz **narzędzia pomocnicze** do lokalnego testowania rozwiązań dla zadania **Rozwiązanie pokojowe**.

## 📁 Zawartość paczki

```
.
├── tests/               # Pliki testów wejściowych i wyjściowych
│   ├── in/              # Pliki wejściowe (.in)
│   ├── out/             # Oczekiwane wyjścia (.out) (tylko pierwsza linia)
│   └── grouped/         # Zgrupowane testy (te same co wyżej)
├── chk.cpp              # Program weryfikujący poprawność wyjścia
├── spr.sh               # Skrypt bashowy do lokalnego testowania
├── spr/                 # Różne pliki używane przez spr.sh
├── sinolowe             # Konfiguracja dla sinol-make
│   ├── config.yml       # Plik konfiguracyjny
│   └── rpkchk.cpp       # Checkerka jak wyżej, tylko w formatce sinola
└── README.md            # Ten plik
````

---

## 🚀 Szybki start

Aby przetestować swoje rozwiązanie lokalnie, przygotuj plik wykonywalny (przykładowo ./rpk), a następnie uruchom:

```bash
./spr.sh ./tests/in ./rpk ./tests/out
```

Skrypt:

* uruchomi program na podanych testach (pierwszy argument to katalog z inputami, drugi to program, trzeci to katalog z outputami),
* sprawdzi poprawność wyników przy użyciu `chk.cpp`,
* wyświetli nazwę pierwszego testu, który nie przeszedł (lub informację, że wszystkie przeszły).

---

## 🧪 Checkerka

Plik `chk.cpp` to program weryfikujący.
Na wejściu (stdin) przyjmuje po kolei input testu, pierwszą linijkę poprawnego wyjścia, oraz wyjście twojego programu

Zwraca kod wyjścia:

* `0` — wynik poprawny ✅
* `1` — wynik błędny ❌

W przypadku błędnego wyniku na stdout zostaną wypisane trochę bardziej szczegółowe informacje co do błędu.

---

## ⚙️ Integracja z `sinol-make`

Jeśli z jakiegoś powodu chcesz przetestować używając [`sinol-make`](https://github.com/sinol-project/sinol-make), w paczce znajdziesz gotowy plik konfiguracyjny `config.yml` oraz tą samą checkerkę przepisaną na formatkę sinola.

Po wrzuceniu swojego solva do `prog/rpk.cpp` oraz testów do `in`/`out` możesz odpalić:

```bash
sinol-make run
```

żeby wykorzystać dużo zasobów komputera ale mieć ładne kolorki (i parę innych nie rzeczy, które nie są aż tak fajne jak kolorki).

---

## 💡 Uwagi

* Testy są przygotowane zgodnie ze specyfikacją zadania i pogrupowane w grupy według tabelki.
* Grupa testów 0 to nie są testy przykładowe, ale dodatkowa grupa z warunkiem `n <= 10`, żeby mieć wciąż względnie małe testy, ale ciekawsze niż te z podzadania 1.
* Liczebności grup wynoszą kolejno: `1460 280 1070 1008 1980`
* Starałem się aby testy były różnorodne, jest trochę takich z wynikiem `TAK` i `NIE`, a także parzyste i nieparzyste wartości `n`, czy inne zależności.
* Jeśli zauważysz błąd w testach lub checkerce to fajnie jakbyś się podzielił ze wszystkimi.
* Skrypt `spr.sh` wymaga środowiska bash (Linux / WSL / macOS).

---


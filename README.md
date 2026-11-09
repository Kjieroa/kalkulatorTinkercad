
# 🧮 Kalkulator Arduino UNO

Projekt kalkulatora zbudowanego na platformie **Arduino UNO**, wykorzystującego wyświetlacz LCD 16x2 z modułem I2C oraz klawiaturę membranową 4x4.

Kalkulator umożliwia wykonywanie podstawowych działań matematycznych, a wynik wyświetlany jest na ekranie LCD.

## 📸 Schemat projektu

![Schemat podłączenia kalkulatora Arduino](schemat.png)

## ⚙️ Wykorzystywane komponenty

- Arduino UNO
- Wyświetlacz LCD 16x2 z modułem I2C
- Klawiatura membranowa 4x4
- Przewody połączeniowe
- Kabel USB do programowania Arduino

## 🔌 Podłączenie elementów

### Klawiatura 4x4

| Pin klawiatury | Pin Arduino UNO |
|---|---|
| R1 | D9 |
| R2 | D8 |
| R3 | D7 |
| R4 | D6 |
| C1 | D5 |
| C2 | D4 |
| C3 | D3 |
| C4 | D2 |

### Wyświetlacz LCD 16x2 I2C

| Pin LCD | Pin Arduino UNO |
|---|---|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

## 🧮 Funkcje kalkulatora

Kalkulator obsługuje cztery podstawowe działania matematyczne:

| Przycisk | Działanie |
|---|---|
| A | Dodawanie (+) |
| B | Odejmowanie (-) |
| C | Mnożenie (*) |
| D | Dzielenie (/) |
| 0–9 | Wprowadzanie liczb |
| # | Obliczanie wyniku |
| * | Czyszczenie kalkulatora |

### Przykład działania

Aby wykonać działanie `12 + 8`:

1. Naciśnij `1`.
2. Naciśnij `2`.
3. Naciśnij `A`, aby wybrać dodawanie.
4. Naciśnij `8`.
5. Naciśnij `#`, aby wyświetlić wynik.

Wynik: **20.00**

## 💻 Wykorzystane biblioteki

Do prawidłowego działania projektu wymagane są następujące biblioteki Arduino:

- `Adafruit_LiquidCrystal`
- `Keypad`

Biblioteki można zainstalować za pomocą Library Manager w Arduino IDE.

## 🚀 Uruchomienie projektu

1. Podłącz wszystkie komponenty zgodnie z tabelami powyżej.
2. Zainstaluj wymagane biblioteki.
3. Otwórz Arduino IDE.
4. Wklej kod źródłowy kalkulatora.
5. Wybierz płytkę **Arduino UNO**.
6. Wybierz odpowiedni port COM.
7. Wgraj program na Arduino.
8. Po uruchomieniu kalkulator jest gotowy do użycia.

## 🛠️ Technologie

- Arduino
- C++
- Arduino IDE
- LCD 16x2 I2C
- Keypad 4x4

## 📋 Ograniczenia

- Maksymalna długość każdej wprowadzanej liczby wynosi 8 cyfr.
- Kalkulator obsługuje dodawanie, odejmowanie, mnożenie i dzielenie.
- Wyniki wyświetlane są z dokładnością do dwóch miejsc po przecinku.
- Dzielenie przez zero jest zabezpieczone komunikatem o błędzie.

## 👨‍💻 Autor

Projekt edukacyjny wykonany z wykorzystaniem Arduino UNO.

---

⭐ Jeśli projekt Ci się podoba, zostaw gwiazdkę na GitHubie!

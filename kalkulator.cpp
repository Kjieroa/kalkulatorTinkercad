
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

// Wyswietlacz LCD
Adafruit_LiquidCrystal lcd_1(0);

// Klawiatura 4x4
const byte WIERSZE = 4;
const byte KOLUMNY = 4;

char klawisze[WIERSZE][KOLUMNY] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Piny klawiatury
byte pinyWierszy[WIERSZE] = {9, 8, 7, 6};
byte pinyKolumn[KOLUMNY] = {5, 4, 3, 2};

Keypad klawiatura = Keypad(
  makeKeymap(klawisze),
  pinyWierszy,
  pinyKolumn,
  WIERSZE,
  KOLUMNY
);

// Zmienne kalkulatora
String liczba1 = "";
String liczba2 = "";

char dzialanie = '\0';

bool drugaLiczba = false;
bool wynikPokazany = false;

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  lcd_1.clear();

  lcd_1.setCursor(0, 0);
  lcd_1.setCursor(0, 1);

  delay(1500);
  lcd_1.clear();


}

void loop()
{
  char klawisz = klawiatura.getKey();

  if (klawisz)
  {
    // Czyszczenie kalkulatora
    if (klawisz == '*')
    {
      liczba1 = "";
      liczba2 = "";
      dzialanie = '\0';
      drugaLiczba = false;
      wynikPokazany = false;

      lcd_1.clear();

    }

    // Wybieranie dzialania
    else if (klawisz == 'A' ||
             klawisz == 'B' ||
             klawisz == 'C' ||
             klawisz == 'D')
    {
      if (liczba1 != "" && !drugaLiczba)
      {
        if (klawisz == 'A') dzialanie = '+';
        if (klawisz == 'B') dzialanie = '-';
        if (klawisz == 'C') dzialanie = '*';
        if (klawisz == 'D') dzialanie = '/';

        drugaLiczba = true;

        lcd_1.clear();
        lcd_1.print(liczba1);
        lcd_1.print(dzialanie);
      }
    }

    // Obliczanie wyniku
    else if (klawisz == '#')
    {
      if (liczba1 != "" && liczba2 != "" &&
          dzialanie != '\0')
      {
        double a = liczba1.toDouble();
        double b = liczba2.toDouble();
        double wynik = 0;

        bool poprawny = true;

        switch (dzialanie)
        {
          case '+':
            wynik = a + b;
            break;

          case '-':
            wynik = a - b;
            break;

          case '*':
            wynik = a * b;
            break;

          case '/':
            if (b != 0)
              wynik = a / b;
            else
              poprawny = false;
            break;
        }

        lcd_1.clear();

        if (poprawny)
        {
          lcd_1.setCursor(0, 1);
          lcd_1.print(wynik, 2);
        }
        else
        {
          lcd_1.print("ERROR");
          lcd_1.setCursor(0, 1);
        }

        wynikPokazany = true;
      }
    }

    // Wprowadzanie cyfr
    else if (klawisz >= '0' && klawisz <= '9')
    {
      if (wynikPokazany)
      {
        liczba1 = "";
        liczba2 = "";
        dzialanie = '\0';
        drugaLiczba = false;
        wynikPokazany = false;
        lcd_1.clear();
      }

      if (!drugaLiczba)
      {
        if (liczba1.length() < 8)
          liczba1 += klawisz;
      }
      else
      {
        if (liczba2.length() < 8)
          liczba2 += klawisz;
      }

      // Wyswietlanie wpisywanej liczby
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print(liczba1);

      if (dzialanie != '\0')
      {
        lcd_1.print(dzialanie);
        lcd_1.print(liczba2);
      }
    }
  }
}

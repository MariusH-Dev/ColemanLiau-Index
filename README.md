# Coleman-Liau Index Berechnung

Dieses Projekt berechnet die Lesbarkeit eines Textes mithilfe des **Coleman-Liau-Indexes**. Dieser Index bewertet die Lesestufe eines Textes basierend auf der durchschnittlichen Anzahl von Buchstaben und Sätzen pro 100 Wörter.

## Funktionsweise

1. Der Benutzer gibt einen Text ein.
2. Das Programm zählt die Anzahl der Zeichen, Wörter und Sätze im Text.
3. Der Coleman-Liau-Index wird berechnet und die geschätzte Lesestufe des Textes wird ausgegeben.

## Testbeispiele
![Checks](https://github.com/user-attachments/assets/ae5fd7f6-a1a0-4a27-b974-f09d1f918b58)

## Berechnung des Coleman-Liau-Indexes

Der Coleman-Liau-Index wird durch folgende Formel berechnet:

LIX = 0.0588 \times L - 0.296 \times S - 15.8

- **L** ist die durchschnittliche Anzahl von Buchstaben pro 100 Wörtern.
- **S** ist die durchschnittliche Anzahl von Sätzen pro 100 Wörtern.
- Der Index ergibt die geschätzte Klassenstufe, die benötigt wird, um den Text zu verstehen.

## Erweiterungsmöglichkeiten

- Implementierung anderer Lesbarkeitsindizes wie **Flesch-Kincaid** oder **Gunning Fog**.
- Erweiterung des Programms zur Analyse großer Textdateien.

## Lizenz

Dieses Projekt steht unter der MIT-Lizenz. Weitere Informationen finden Sie in der [LICENSE](LICENSE)-Datei.

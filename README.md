# JUCE 2 Seminar – Einheit 2

## Thema: Parameter-Integration – Float, Bool & Choice

### Lerninhalte

- **Implementierung dreier Parameterarten:**
  - **Float-Parameter** (z. B. Delay Time in ms)
    - Anlegen im Konstruktor
    - Anbindung an Slider mit `SliderAttachment`
  - **Bool-Parameter** (z. B. Sync to BPM)
    - Anlegen und UI mit `ToggleButton`
  - **Choice-Parameter** (z. B. Time Select mit „1/1, 1/2, 1/4, 1/8, 1/16“)
    - Drop-down-Menü via `ComboBox`
    - Verwendung von `ChoiceParameterAttachment`

- **Einführung in `AudioProcessorValueTreeState`**
  - Zentrale Verwaltung von Parametern
  - Vorteil UndoManager

- **Test & Kontrolle in der DAW**
  - Automationsfähigkeit überprüfen
  - Default-Werte und Grenzwerte testen

- **Advanced Float-Parameter**
  - Überschreiben der Methoden getLabel und getText / getValueForText

### Ziel der Einheit

Die Teilnehmer sind in der Lage, **drei unterschiedliche Parameterarten** korrekt zu implementieren und mit passenden grafischen UI-Komponenten zu verbinden. Sie verstehen das Zusammenspiel von DSP, Parameterverwaltung und grafischer Oberfläche innerhalb des JUCE-Frameworks.
//Plays the main riff of Interstate 8 by Modest Mouse using a Piezo Element on digital pin 9.
//Code written and debugged by Alexis Renderos
//https://tabs.ultimate-guitar.com/f/fun/the_gambler_tab.htm
//Try and do this one for Jessie :)

const int buzzerPin = 9;
const int songLength = 18;

char notes[] = "  Gbfdbfdbfdbffgf";
int beats[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4};

int tempo = 145;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
}


void loop()
{
  int i, duration;

  for (i = 0; i < songLength; i++)
  {
    duration = beats[i] * tempo;

    if (notes[i] == ' ')
    {
      delay(duration);
    }
    else
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo / 10);
  }
}


int frequency(char note)
{/
  int i;
  const int numNotes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'G' };
  int frequencies[] = {262, 294, 330, 370, 392, 988, 494, 392};

  for (i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return (frequencies[i]);
    }
  }
  return (0);
}

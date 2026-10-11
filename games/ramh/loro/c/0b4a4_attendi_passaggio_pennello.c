/* $0b4a4 attendi_passaggio_pennello: attesa base del gioco: aspetta che il pennello passi per la riga 0/256 (circa mezzo quadro); corretta da patch_velocita.py */

/* attesa base del gioco: aspetta che il pennello passi per la riga 0/256 (circa mezzo quadro);
   corretta da patch_velocita.py */

void attendi_passaggio_pennello(void)

{
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  attendi_riga_zero();
  return;
}


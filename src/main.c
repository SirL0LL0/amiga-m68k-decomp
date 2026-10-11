#include "amiga_hardware.h"

/*
 * Esempio di funzione da gioco Amiga M68k.
 *
 * VHPOSTR ($006): bit 15-8 = riga raster bassa, VPOSR ($004) bit 0 = bit 8.
 * Per semplicita' si confronta solo la parte bassa in VHPOSTR.
 */

static uint16_t CurrentRaster(void) {
    return (uint16_t)((CUSTOM.vhposr >> 8) & 0xFF);
}

void WaitRaster(uint16_t raster_line) {
    while (CurrentRaster() != (raster_line & 0xFF)) {
        /* Busy wait */
    }
}

void SetBackgroundColor(uint16_t color_val) {
    CUSTOM.color[0] = color_val;
}

void GameLoop(void) {
    SetBackgroundColor(0x0F00); /* Rosso */
    WaitRaster(100);
    SetBackgroundColor(0x0000); /* Nero */
}

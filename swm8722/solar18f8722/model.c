/* Framework for the two well model */
#include "model.h"

uint8_t model_learn(uint8_t mode) // constructs model data for battery state matching after a full-charge
{
	static uint8_t lmode = 0, x, y;

	for (x = 0; x < HISTBATTNUM; x++) { // count from 0 to 1
		for (y = 0; y <= 3; y++) {
			if (bmt[x].soc[y].flags & BMT_FLAG_7) { // check full charge flag
				lmode++;
				if (bmt[x].soc[y].soc == hist[x + 1].bsoc) { // scan for bsoc matches
					if (!(bmt[x].soc[y].flags & (1 << y))) { // check soc done flag
						bmt[x].soc[y].flags |= (1 << y); // set the flag
						hist[x + 1].btest = 0;
						cell[x + 1].date = 0;
						ChargeBatt(x + 1, TRUE, TRUE); // check battery
						noload_soc();
						update_hist();
						bmt[x].soc[y].cef = (uint8_t) hist[x + 1].cef * 100.0;
						bmt[x].soc[y].esr = hist[x + 1].esr;
						bmt[x].soc[y].voltage = cell[x + 1].voltage;
						bmt[x].soc[y].ah = hist[x + 1].rate;
						//			if ((x + 1) == CCS.boi) {
						//			    bmt[x].soc[y].current = C.currentload;
						//			} else {
						bmt[x].soc[y].current = cell[x + 1].current;
						//			}
						bmt[x].soc[y].temp = R.thermo_batt;
						model_data();
					}
				}
			}
		}
	}
	return lmode;
}

void model_data(void) // display model data on terminal
{
	static uint8_t x = 0, z = 0;

	ClrWdt(); // reset the WDT timer
	sprintf(bootstr2, "\r\n");
	puts2USART(bootstr2);
	term_time();
	putrs2USART(modelheader0);
	ClrWdt(); // reset the WDT timer

	for (z = 0; z < HISTBATTNUM; z++) { // create, battery
		for (x = 0; x < MODEL_SLOTS; x++) { // create, data slot
			sprintf(bootstr2,
				" Battery #%i: SOC %4i, ESR %5i, Current %5i, Volts %5i, Ah %5i, CEF %4i,Temp %4i, FLAGS %4i\n\r",
				z + 1, bmt[z].soc[x].soc, bmt[z].soc[x].esr, bmt[z].soc[x].current, bmt[z].soc[x].voltage, bmt[z].soc[x].ah, bmt[z].soc[x].cef, bmt[z].soc[x].temp, bmt[z].soc[x].flags);
			puts2USART(bootstr2);
			ClrWdt(); // reset the WDT timer
		}
		putrs2USART(modelheader1);
	}
}

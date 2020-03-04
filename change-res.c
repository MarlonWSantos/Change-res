#include "contiki.h"
#include <stdio.h> 


unsigned int range=1;


/*---------------------------------------------------------------------------*/
PROCESS(change_res_process, "Change-res");
AUTOSTART_PROCESSES(&change_res_process);
/*---------------------------------------------------------------------------*/


PROCESS_THREAD(change_res_process, ev, data)
{
	PROCESS_BEGIN();
	static struct etimer et;
	while(1) {
		etimer_set(&et, CLOCK_SECOND*5);
		PROCESS_WAIT_EVENT();
		printf("Range: %d\n", range);
		if(etimer_expired(&et)) {
			etimer_reset(&et);
		}
	}
	PROCESS_END();
}
/*---------------------------------------------------------------------------*/

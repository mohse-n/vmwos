#include <stddef.h>
#include <stdint.h>

#ifdef VMWOS
#include "syscalls.h"
#include "vlibc.h"
#include "vmwos.h"
#else
#include <stdio.h>
#include <unistd.h>
#endif

#include "svmwgraph.h"
#include "pi-graphics.h"
#include "demosplash2019.h"

	/* Do the VMW Software Production Logo */
void vmwos_open(unsigned char *buffer, struct palette *pal) {

	int x;

	/* set up RGB palette */
	for(x=0;x<=40;x++) {
		/* red */
		pal->red[100+x]=((x+20)*4);
		pal->green[100+x]=0;
		pal->blue[100+x]=0;

		/* blue */
		pal->red[141+x]=0;
		pal->green[141+x]=0;
		pal->blue[141+x]=((x+20)*4);

		/* green */
		pal->red[182+x]=0;
		pal->green[182+x]=((x+20)*4);
		pal->blue[182+x]=0;
	}

	/* Set the white color */
	pal->red[15]=0xff;
	pal->green[15]=0xff;
	pal->blue[15]=0xff;

	/* Actually draw the stylized VMW */
	for(x=0;x<=40;x++) {
		/* red, left */
		vmwVlin(2*(45),   2*(45+2*x),   2*(x+40),100+x,buffer);
		vmwVlin(2*(45),   2*(46+2*x), 1+2*(x+40),100+x,buffer);

		/* blue 1st, left */
		vmwVlin(2*(45),   2*(45+2*x),   2*(x+120),141+x,buffer);
		vmwVlin(2*(45),   2*(46+2*x), 1+2*(x+120),141+x,buffer);
		/* blue 2nd, left */
		vmwVlin(2*(45),   2*(45+2*x),   2*(x+200),141+x,buffer);
		vmwVlin(2*(45),   2*(46+2*x), 1+2*(x+200),141+x,buffer);

		/* green 1st, left */
		vmwVlin(  2*(126-(2*x)), 2*(125),   2*(x+80),182+x,buffer);
		vmwVlin(  2*(125-(2*x)), 2*(125), 1+2*(x+80),182+x,buffer);

		/* green 2nd, left */
		vmwVlin(  2*(126-(2*x)), 2*(125),   2*(x+160),182+x,buffer);
		vmwVlin(  2*(125-(2*x)), 2*(125), 1+2*(x+160),182+x,buffer);
	}
	for(x=40;x>0;x--){
		/* red, right */
		vmwVlin(2*(45),   2*(46+80-(2*x)),   2*(x+80),140-x,buffer);
		vmwVlin(2*(45),   2*(45+80-(2*x)), 1+2*(x+80),140-x,buffer);

		/* blue, 1st, right */
		vmwVlin(2*(45),   2*(46+80-(2*x)),   2*(x+160),181-x,buffer);
		vmwVlin(2*(45),   2*(45+80-(2*x)), 1+2*(x+160),181-x,buffer);

		/* blue, 2nd, right */
		vmwVlin(2*(45),   2*(46+80-(2*x)),   2*(x+240),181-x,buffer);
		vmwVlin(2*(45),   2*(45+80-(2*x)), 1+2*(x+240),181-x,buffer);

		/* green, 1st, right */
		vmwVlin(  2*(44+(2*x)), 2*(125),   2*(x+120),222-x,buffer);
		vmwVlin(  2*(45+(2*x)), 2*(125), 1+2*(x+120),222-x,buffer);

		/* green, 2nd, right */
		vmwVlin(  2*(44+(2*x)), 2*(125),   2*(x+200),222-x,buffer);
		vmwVlin(  2*(45+(2*x)), 2*(125), 1+2*(x+200),222-x,buffer);
	}

	/* hack to clear over-extend line */
	vmwHlin( 0, 639, 250, 0, buffer);
	vmwHlin( 0, 639, 251, 0, buffer);


	vmwTextXYx2("A VMW SOFTWARE PRODUCTION",60*2,140*2,
			15,15,0,DEFAULT_FONT,buffer);

	vmwFadeFromBlack(buffer,pal);

//	while(1) {
//
//		ch=pi_graphics_input();
//		if (ch=='q') break;
//		if (ch==27) break;
//		pi_graphics_update(buffer,pal);
//		usleep(10000);
//	}

	pi_graphics_update(buffer,pal);
	sleep(2);

	vmwFadeToBlack(buffer,pal);

//	while(1) {
//
//		ch=pi_graphics_input();
//		if (ch=='q') break;
//		if (ch==27) break;
//		pi_graphics_update(buffer,pal);
//		usleep(10000);
//	}

	sleep(1);

	return;
}



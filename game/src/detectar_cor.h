#ifndef DETECTAR_COR_h
#define DETECTAR_COR_h

	#include "camera.h"

	void rgb_to_hsv(camera *cam, int largura, int altura, unsigned char ***matriz, int vetor_pos[2], int color);
	void overlay_frame(camera *cam, unsigned char ***primeiro, int frame_limite);

#endif

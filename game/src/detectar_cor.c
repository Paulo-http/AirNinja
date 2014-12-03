#include "header.h"
#include "detectar_cor.h"

void rgb_to_hsv(camera *cam, int largura, int altura, unsigned char ***matriz, int vetor_pos[2], int color) {
	
	int cy = 0;
	int cx = 0;
    int cn = 0;

    float r, g, b;
    float hue, saturation, value;

    for(int y = 0; y < altura; y++)	{
		for(int x = 0; x < largura; x++) {

            r = cam->quadro[y][x][0];
            g = cam->quadro[y][x][1];
            b = cam->quadro[y][x][2];

	  		al_color_rgb_to_hsv(r, g, b, &hue, &saturation, &value);
    		
            float hmin, hmax, smed, vmed;
        	
            if(color == 1) {   
                hmin = 45;
                hmax = 64;
                smed = 0.15;
                vmed = 0.1;
            }  
            if(color == 2) {   
                hmin = 64;
                hmax = 150;
                smed = 0.15;
                vmed = 0.1;
            }
            if(color == 3) {   
                hmin = 180;
                hmax = 255;
                smed = 0.15;
                vmed = 0.1;
            } 
            else if(color == 4) {   
                hmin = 11;
                hmax = 351;
                smed = 0.7;
                vmed = 0.1;
            }            
          
            if(hue > hmin && hue < hmax && saturation > smed && value >= vmed) {
                cx += x;
                cy += y;
                cn++;

                matriz[y][x][0] = cam->quadro[y][x][0];
                matriz[y][x][1] = cam->quadro[y][x][1];
                matriz[y][x][2] = cam->quadro[y][x][2];
          	} else {
                matriz[y][x][0] = 0;
                matriz[y][x][1] = 0;
                matriz[y][x][2] = 0;
            }
		}
	}
    //  pegar um ponto medio perante a detecção 
	if(cn>0) {
		vetor_pos[0] = cx/cn;
		vetor_pos[1] = cy/cn;
	}

}

void overlay_frame(camera *cam, unsigned char ***primeiro, int frame_limite) {
    int x, y;
    unsigned char hue, saturation, value;

    for(x = 0; x < cam->altura; x++) {
        for(y = 0; y < cam->largura; y++) {
            hue = cam->quadro[x][y][0];
            saturation = cam->quadro[x][y][1];
            value = cam->quadro[x][y][2];

            hue -= primeiro[x][y][0];
            saturation -= primeiro[x][y][1];
            value -= primeiro[x][y][2];

            hue *= hue;
            saturation *= saturation;
            value *= value;

            hue = hue + saturation + value;
            frame_limite *= frame_limite;

            cam->quadro[x][y][0] = (hue > frame_limite) ? cam->quadro[x][y][0] : 0;
            cam->quadro[x][y][1] = (hue > frame_limite) ? cam->quadro[x][y][1] : 0;
            cam->quadro[x][y][2] = (hue > frame_limite) ? cam->quadro[x][y][2] : 0;

        }
    }
}

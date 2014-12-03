#ifndef LOAD_GAME_h
#define LOAD_GAME_h
    
    #include "camera.h"

    #define FPS 60
    
    ALLEGRO_BITMAP *buffer, *esquerda, *direita;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_COLOR cor, cor2, font_color;
    ALLEGRO_FONT *font, *font2;

    ALLEGRO_BITMAP *blue_nvl_1, *red_nvl_1, *green_nvl_1, *white_nvl_1, *bonus_nvl_1, *dead_nvl_1;
    ALLEGRO_BITMAP *blue_nvl_2, *red_nvl_2, *green_nvl_2, *white_nvl_2, *bonus_nvl_2, *dead_nvl_2;
    ALLEGRO_BITMAP *blue_nvl_3, *red_nvl_3, *green_nvl_3, *white_nvl_3, *bonus_nvl_3, *dead_nvl_3;
    ALLEGRO_BITMAP *bg1, *bg2, *bg3, *bg4, *bg5;
    ALLEGRO_BITMAP *timer_up, *point_detect;

	void erro(char *mensagem);
  	bool start_game();
    bool init_menu();
  	bool load_bitmap();

#endif
    
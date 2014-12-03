#include "header.h"
#include "load_game.h"

//  criado para auxiliar as tratativas de erros

void erro(char *mensagem) {
  fputs(mensagem, stderr);

  exit(EXIT_FAILURE);
}

//  carrega recursos iniciais do jogo - evita poluição visual em codigo main

bool start_game() {

    cam = camera_inicializa(0);
  	if(!cam)
    	erro("erro na inicializacao da camera\n");
  	
  	int largura = cam->largura;
  	int altura = cam->altura;

  	if(!al_init())
    	erro("erro na inicializacao do allegro\n");

  	if(!al_init_image_addon())
    	erro("erro na inicializacao do adicional de imagem\n");

    al_init_font_addon();

    al_init_ttf_addon();

  	if(!al_init_primitives_addon())
        erro("erro na inicializacao do adicional de primitivas\n");

    font_color = al_map_rgb(0, 0, 0);
    cor = al_map_rgb_f(255, 0, 255);
    
    font = al_load_ttf_font("res/font/architectsdaughter.ttf", 20, 0);
    if(!font)
        erro("erro ao localizar fonte secundaria!\n");

	  timer = al_create_timer(1.0 / FPS);	
  	if(!timer)
    	erro("erro na criacao do relogio\n");

  	display = al_create_display(2 * largura, altura);
  	if(!display)
    	erro("erro na criacao da janela\n");

  	queue = al_create_event_queue();
  	if(!queue)
    	erro("erro na criacao da fila\n");

  	al_register_event_source(queue, al_get_timer_event_source(timer));
  	al_register_event_source(queue, al_get_display_event_source(display));

  	al_start_timer(timer);

  	matriz = camera_aloca_matriz(cam);

  	buffer = al_get_backbuffer(display);

  	esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);

	direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    // Configura o título do display
    al_set_window_title(display, "Air Ninja Adventure!");

    return true;
}
 
//  carrega imagens a serem usadas durante o jogo
bool load_bitmap() {

    //  nivel 1 Bitmaps
    red_nvl_1 = al_load_bitmap("res/img/nivel1/redNv1.png");
    if(!red_nvl_1)
        erro("Falha ao carregar imagem! [!redNv1]\n");

    green_nvl_1 = al_load_bitmap("res/img/nivel1/greenNv1.png");
    if(!green_nvl_1)
        erro("Falha ao carregar imagem! [!greenNv1]\n");

    blue_nvl_1 = al_load_bitmap("res/img/nivel1/blueNv1.png");
    if(!blue_nvl_1)
        erro("Falha ao carregar imagem! [!blueNv1]\n");

    white_nvl_1 = al_load_bitmap("res/img/nivel1/whiteNv1.png");
    if(!white_nvl_1)
        erro("Falha ao carregar imagem! [!whiteNv1]\n");

    bonus_nvl_1 = al_load_bitmap("res/img/nivel1/bonusNv1.png");
    if(!bonus_nvl_1)
        erro("Falha ao carregar imagem! [!bonusNv1]\n");

    dead_nvl_1 = al_load_bitmap("res/img/nivel1/deadNv1.png");
    if(!dead_nvl_1)
        erro("Falha ao carregar imagem! [!deadNv1]\n");

    //  nivel 2 Bitmaps
    red_nvl_2 = al_load_bitmap("res/img/nivel2/redNv2.png");
    if(!red_nvl_2)
        erro("Falha ao carregar imagem! [!redNv2]\n");

    green_nvl_2 = al_load_bitmap("res/img/nivel2/greenNv2.png");
    if(!green_nvl_2)
        erro("Falha ao carregar imagem! [!greenNv2]\n");

    blue_nvl_2 = al_load_bitmap("res/img/nivel2/blueNv2.png");
    if(!blue_nvl_2)
        erro("Falha ao carregar imagem! [!blueNv2]\n");

    white_nvl_2 = al_load_bitmap("res/img/nivel2/whiteNv2.png");
    if(!white_nvl_2)
        erro("Falha ao carregar imagem! [!whiteNv2]\n");

    bonus_nvl_2 = al_load_bitmap("res/img/nivel2/bonusNv2.png");
    if(!bonus_nvl_2)
        erro("Falha ao carregar imagem! [!bonusNv2]\n");

    dead_nvl_2 = al_load_bitmap("res/img/nivel2/deadNv2.png");
    if(!dead_nvl_2)
        erro("Falha ao carregar imagem! [!deadNv2]\n");

    //  nivel 3 Bitmaps
    red_nvl_3 = al_load_bitmap("res/img/nivel3/redNv3.png");
    if(!red_nvl_3)
        erro("Falha ao carregar imagem! [!redNv3]\n");

    green_nvl_3 = al_load_bitmap("res/img/nivel3/greenNv3.png");
    if(!green_nvl_3)
        erro("Falha ao carregar imagem! [!greenNv3]\n");

    blue_nvl_3 = al_load_bitmap("res/img/nivel3/blueNv3.png");
    if(!blue_nvl_3)
        erro("Falha ao carregar imagem! [!blueNv3]\n");

    white_nvl_3 = al_load_bitmap("res/img/nivel3/whiteNv3.png");
    if(!white_nvl_3)
        erro("Falha ao carregar imagem! [!whiteNv3]\n");

    bonus_nvl_3 = al_load_bitmap("res/img/nivel3/bonusNv3.png");
    if(!bonus_nvl_3)
        erro("Falha ao carregar imagem! [!bonusNv3]\n");

    dead_nvl_3 = al_load_bitmap("res/img/nivel3/deadNv3.png");
    if(!dead_nvl_3)
        erro("Falha ao carregar imagem! [!deadNv3]\n");

    //  background Bitmaps
    bg1 = al_load_bitmap("res/img/bg/bg1.png");
    if(!bg1)
        erro("Falha ao carregar imagem! [!bg1]\n");

    bg2 = al_load_bitmap("res/img/bg/bg2.png");
    if(!bg2)
        erro("Falha ao carregar imagem! [!bg2]\n");

    bg3 = al_load_bitmap("res/img/bg/bg3.png");
    if(!bg3)
        erro("Falha ao carregar imagem! [!bg3]\n");

    bg4 = al_load_bitmap("res/img/bg/bg4.png");
    if(!bg4)
        erro("Falha ao carregar imagem! [!bg4]\n");

    bg5 = al_load_bitmap("res/img/bg/bg5.png");
    if(!bg5)
        erro("Falha ao carregar imagem! [!bg5]\n");

    //  geral Bitmaps
    timer_up = al_load_bitmap("res/img/geral/timerUp.png");
    if(!timer_up)
        erro("Falha ao carregar imagem! [!timerUp]\n");

    point_detect = al_load_bitmap("res/img/geral/pointDetect.png");
    if(!point_detect)
        erro("Falha ao carregar imagem! [!point_detect]\n");

  	return true;
}

bool init_menu() {

    int largura = cam->largura;
    int altura = cam->altura;

    cor2 = al_map_rgb(255, 255, 255);
    font2 = al_load_ttf_font("res/font/architectsdaughter.ttf", 60, 0);
    
    //  Fundo da primeira tela
    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, largura, 0, largura, altura, 0);
    
    //  Primeira tela
    al_draw_text(font2, cor2, largura/2, 0, 0, "Air Ninja Adventure!");
    al_flip_display();
    al_rest(2);

    //  Fundo da primeira tela
    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, largura, 0, largura, altura, 0);

    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg3, 0, 0, 1024, 768, largura, 0, largura, altura, 0);

    al_draw_text(font2, cor2, 0.6*largura, altura/1.5, 0, "Carregando...");
    al_flip_display();
    al_rest(5);
    
    //  Fundo da segunda tela
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, largura, 0, largura, altura, 0);

    cor2 = al_map_rgb(0, 0, 0);

    al_draw_text(font2, cor2, largura/1.8, 0, 0, "Entenda o Air Ninja");
    
    //  Desloca e realoca definições da fonte    
    al_destroy_font(font2);
    font2 = al_load_ttf_font("res/font/architectsdaughter.ttf", 20, 0);
   
     //  Segunda tela  
    al_draw_text(font2, cor2, largura/7, altura/2, 0, "Ganhe Pontos * Garanta os Bonus * Fuja das Trevas * Aumente seu Tempo * Use esta Cor"); 
    
    al_draw_bitmap(blue_nvl_1, largura/5, altura/4, 0); 
    al_draw_bitmap(bonus_nvl_1, 0.53*largura, altura/4, 0);
    al_draw_bitmap(dead_nvl_3, 0.9*largura, altura/4, 0);
    al_draw_bitmap(timer_up, 1.25*largura, altura/4, 0);
    al_draw_circle(1.7*largura, altura/2.8, 10, al_map_rgb(255, 255, 0), 70);
    al_flip_display();
    al_rest(10);

    //  Fundo da segunda tela
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, largura, 0, largura, altura, 0);
    
    al_destroy_font(font2);

    font2 = al_load_ttf_font("res/font/architectsdaughter.ttf", 40, 0);

    al_draw_text(font2, cor2, 0.7*largura, altura/1.5, 0, "Iniciando o Jogo...");
    al_flip_display();
    al_rest(5);

    //  Fundo da segunda tela
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
    al_draw_scaled_bitmap(bg5, 0, 0, 1024, 768, largura, 0, largura, altura, 0);

    al_clear_to_color(cor2);
    al_destroy_font(font2);
    
    al_flip_display();
    
    return true;
}

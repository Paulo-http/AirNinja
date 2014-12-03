#include "header.h"
#include "rand_game.h"

void rand_bitmap(int m_size[4][2], int v_bitmap[4], int v_dados[2]) {
    
    //  guarda as imagens carregadas em um vetor conforme o nivel
    ALLEGRO_BITMAP *nvl_1[] = {red_nvl_1, green_nvl_1, blue_nvl_1, white_nvl_1, dead_nvl_1, bonus_nvl_1, timer_up};
    ALLEGRO_BITMAP *nvl_2[] = {red_nvl_2, green_nvl_2, blue_nvl_2, white_nvl_2, dead_nvl_2, bonus_nvl_2, timer_up};
    ALLEGRO_BITMAP *nvl_3[] = {red_nvl_3, green_nvl_3, blue_nvl_3, white_nvl_3, dead_nvl_3, bonus_nvl_3, timer_up};

    //  pega o tamanho da camera
    int largura = cam->largura;
    int altura = cam->altura;
    
    //  guarda sub-larguras e sub-alturas
    int rlarg[4], ralt[3];

    //  evita vicio de randomização e usa o tempo para randomizar
    srand( (unsigned)time(NULL) );     
  	
    //  randomiza largura conforme o quadrante determinado 
    rlarg[0] = rand() % ((largura/4) - 100);
    rlarg[1] = rand() % ((largura/4) - 100)+(largura/4);
    rlarg[2] = rand() % ((largura/4) - 100)+(largura/2);      
    rlarg[3] = rand() % ((largura/4) - 100)+(3*(largura/4));   

    //  randomiza altura conforme o quadrante determinado 
    ralt[0] = rand() % ((altura/3) - 100);
    ralt[1] = rand() % ((altura/3) - 100)+(altura/3);  
    ralt[2] = rand() % ((altura/3) - 100)+(2*(altura/3));

    //  randomiza sub-larguras e sub-alturas a serem usada na rodada
    int i, larg[4], alt[4];

    for(i=0; i<4; i++)
        larg[i] = i;
    
    for(i=0; i<4; i++)
        alt[i] = rand() % 3;

    //  randomiza imagens a serem desenhadas na rodada
    int img[4];
    img[0] = rand() % 7;  
    img[1] = rand() % 5;  
    img[2] = rand() % 5;  
    img[3] = rand() % 7;

    //  guarda imagens desenhadas - usado em outras funções
    for(i=0; i<4; i++)
        v_bitmap[i] = img[i];

    //  guarda posição das imagens desenhadas - usado em outras funções
    for(i=0; i<4; i++) {
        m_size[i][0] = rlarg[larg[i]];
        m_size[i][1] = ralt[alt[i]];
    }

    //  desenha imagens conforme o nivel de pontuação
    if(v_dados[0] < 50000) {
        al_draw_scaled_bitmap(bg2, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
            for(i=0; i<4; i++)
                al_draw_bitmap(nvl_1[img[i]], rlarg[larg[i]], ralt[alt[i]], 0);
    } 
    else if(v_dados[0] > 50000 && v_dados[0] < 100000) {
        al_draw_scaled_bitmap(bg1, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
            for(i=0; i<4; i++)
                al_draw_bitmap(nvl_2[img[i]], rlarg[larg[i]], ralt[alt[i]], 0);
    } 
    else if(v_dados[0] > 100000) {
        al_draw_scaled_bitmap(bg4, 0, 0, 1024, 768, 0, 0, largura, altura, 0);
            for(i=0; i<4; i++)
                al_draw_bitmap(nvl_3[img[i]], rlarg[larg[i]], ralt[alt[i]], 0);
    }
}

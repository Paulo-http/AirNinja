#include "header.h"
#include "camera.h"
#include "load_game.h"
#include "rand_game.h"
#include "detectar_cor.h"
#include "calc_pontos.h"

#define TAM 1000

int main() {
  
    //  inicializa os recursos do jogo
    start_game();
    load_bitmap(); 
    init_menu();
    
    al_set_target_bitmap(esquerda);
    al_set_target_bitmap(buffer);
  
    //  captura o tamanho da tela  
    int largura = cam->largura;
    int altura = cam->altura;

    //  variaveis de controle usadas para verificar se jogo continua rodando conforme o evento registrado
    int desenhar = 0;
    int terminar = 0;
   
    //  guarda posição detectada, imagens randomizadas da rodada e local onde serão desenhadas
    int v_pos[2];
    int v_bitmap[4];
    int m_size[4][2];
    
    //  verifica as flags da rodada 
    bool flag[] = {false, false, false, false};

    //  guarda pontos e segundos em um vetor
    int fps = 0;
    int v_dados[] = {0, 202};

    //  usado para desenhar pontuação e tempo na tela
    char pontos[TAM];
    char tempo[TAM];

    //  guarda o primeiro quadro para usar na sobreposição de frames
    unsigned char ***primeiro = camera_aloca_matriz(cam);

    int y , x;
    camera_atualiza(cam);
    for(y = 0; y < altura; y++) {
        for(x = 0; x < largura; x++) {
            primeiro[y][x][0] = cam->quadro[y][x][0];
            primeiro[y][x][1] = cam->quadro[y][x][1];
            primeiro[y][x][2] = cam->quadro[y][x][2];
        }
    }

    //  laço principal do jogo
    while(1) {
    
        //  controle de tempo em relação ao FPS
        fps += 1;
        if(fps>=60) {
            fps=0;
            if(v_dados[1]>0)
                v_dados[1]-=1;
            for(int i=0; i<4; i++)    
                flag[i] = false;
        }
        
        ALLEGRO_EVENT event;

        al_wait_for_event(queue, &event);

        //  verifica o evento atual, se continua o jogo, se fecha o display ou se é algum evento não tratado 
        switch(event.type) {
            case ALLEGRO_EVENT_TIMER:
                desenhar = 1;
            break;
            
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                terminar = 1;
            break;
            
            default:
                printf("Evento desconhecido...\n");
        }

        if(terminar || v_dados[1] == 0) {
            printf("%d\n", v_dados[0]);
            break;
        }

        if(desenhar && al_is_event_queue_empty(queue)) {

            desenhar = 0;

            camera_atualiza(cam);
            camera_copia(cam, cam->quadro, esquerda);

            //  detecta movimento pela cor (1-yellow 2-green 3-blue 4-red)
            rgb_to_hsv(cam, largura, altura, matriz, v_pos, 1);
            overlay_frame(cam, primeiro, 30);
            rand_bitmap(m_size, v_bitmap, v_dados);
            
            //  calcula pontuação do jogo
            calc_pts(v_pos, m_size, v_bitmap, v_dados, flag);

            // transforma um tipo int segundos em um tipo char tempo e desenha em tela
            sprintf(tempo, "TEMPO: %d", v_dados[1]);    
            al_draw_text(font, font_color, largura-140, 0, 0, tempo);
                        
            // transforma um tipo int pts em um tipo char pontos e desenha em tela
            sprintf(pontos, "PONTOS: %d", v_dados[0]);    
            al_draw_text(font, font_color, 0, 0, 0, pontos);

            //  confirma se houve a detecção das imagens desenhadas
            if(flag[0] == false && flag[1] == false && flag[2] == false && flag[3] == false) { 
                al_draw_circle(v_pos[0], v_pos[1], 5, cor, 15);
            } else
                al_draw_circle(v_pos[0], v_pos[1], 5, font_color, 15);

            camera_copia(cam, matriz, direita);

            al_flip_display();
      
        }
    }

  al_destroy_bitmap(direita);

  al_destroy_bitmap(esquerda);

  camera_libera_matriz(cam, matriz);

  al_stop_timer(timer);

  al_unregister_event_source(queue, al_get_display_event_source(display));
  al_unregister_event_source(queue, al_get_timer_event_source(timer));

  al_destroy_event_queue(queue);
  al_destroy_display(display);
  al_destroy_timer(timer);

  al_shutdown_primitives_addon();
  al_shutdown_image_addon();
  al_uninstall_system();

  camera_finaliza(cam);

  return EXIT_SUCCESS;

}

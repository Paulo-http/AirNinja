#include "header.h"
#include "load_game.h"
#include "calc_pontos.h"

void calc_pts(int v_pos[4], int m_size[4][2], int v_bitmap[4], int v_dados[2], bool flag[4]) {

    // tratando a imagem de numero 1, verifica se ja houve a flag, se não, verifica se a posição detectada acertou a imagem e altera a flag
    int i;
    for(i=0; i<4; i++) {
        if(flag[i] == false) {
            if(v_pos[0] >= m_size[i][0] && v_pos[0] <= m_size[i][0] + 100 &&
               v_pos[1] >= m_size[i][1] && v_pos[1] <= m_size[i][1] + 100) {
            
                flag[i] = true;

                //  tratamento de erros
                if(v_bitmap[i] < 0 || v_bitmap[i] > 6) {
                    erro("erro ao acessar vetor de imagens.\n");
                }
                
                //  tratando imagens de pontos conforme o nivel que se encontra
                else if(v_bitmap[i] <= 3) {
                    if(v_dados[0] <= 200000) {
                        v_dados[0] += 1009;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 1009");
                    } else if(v_dados[0] > 200000 && v_dados[0] < 600000) {
                        v_dados[0] += 2503;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 2503");
                    } else if(v_dados[0] > 600000) {
                        v_dados[0] += 10007;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 10007");
                    }
                } 
                
                //  tratando imagens de azar conforme o nivel que se encontra
                else if(v_bitmap[i] == 4) {
                    if(v_dados[0] <= 200000) {
                        if(v_dados[0] >= 5045) {
                            v_dados[0] -= 5045;
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 5045");
                        } else {
                            v_dados[0] = 0;
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 5045");
                        }
                    } else if(v_dados[0] > 200000 && v_dados[0] < 600000) {
                        if(v_dados[0] >= 12515) {
                            v_dados[0] -= 12515;
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 12515");
                        } else {
                            v_dados[0] = 0;
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 12515");
                        }
                    } else if(v_dados[0] > 600000) {
                        if(v_dados[0] >= 50035) {
                            v_dados[0] -= 50035;
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 50035");
                        } else {
                            v_dados[0] = 0; 
                            al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "- 50035");
                        }                            
                    }
                }

                //  tratando imagem de tempo
                else if(v_bitmap[i] == 6) {
                    v_dados[1] += 15;
                    al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 15s");
                }
            
                //  tratando imagens de bonus conforme o nivel que se encontra
                else if(v_bitmap[i] == 5) {
                    if(v_dados[0] <= 200000) {
                        v_dados[0] += 5003;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 5003");
                    } else if(v_dados[0] > 200000 && v_dados[0] < 600000) {
                        v_dados[0] += 12007;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 12007");
                    } else if(v_dados[0] > 600000) {
                        v_dados[0] += 25013;
                        al_draw_text(font, font_color, m_size[i][0]-30, m_size[i][1]-30, 0, "+ 25013");
                    }
                }
            }
        }
    }
}

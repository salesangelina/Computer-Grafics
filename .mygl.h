#ifndef _MYGL_H_
#define _MYGL_H_

#include "math.h"
#include "definitions.h"


void PutPixel( int x, int y, color cor){
	int offset = 4*x + 4*y*IMAGE_WIDTH;
	if( x < 0 || y < 0 || x > IMAGE_WIDTH || y > IMAGE_HEIGHT ){
        return;
    }
    FBptr[offset + 0] = cor.R;
    FBptr[offset + 1] = cor.G;
    FBptr[offset + 2] = cor.B;
    FBptr[offset + 3] = cor.A;    
}

void DrawLine (point ponto1, point ponto2, color cor1, color cor2){

	point pontoAux = ponto1;
	color cor = cor1;
	int dx = ponto2.x - ponto1.x;
	int dy = ponto2.y - ponto1.y;

	float variacaoX_R = ((float) cor2.R - cor1.R + 0.5)/dx;
	float variacaoX_G = ((float) cor2.G - cor1.G + 0.5)/dx;
	float variacaoX_B = ((float) cor2.B - cor1.B + 0.5)/dx;
	float variacaoX_A = ((float) cor2.A - cor1.A + 0.5)/dx;

	float variacaoY_R = ((float) cor2.R - cor1.R + 0.5)/dy;
	float variacaoY_G = ((float) cor2.G - cor1.G + 0.5)/dy;
	float variacaoY_B = ((float) cor2.B - cor1.B + 0.5)/dy;
	float variacaoY_A = ((float) cor2.A - cor1.A + 0.5)/dy;

	if(dx == 0){//coluna
		if(ponto2.y > ponto1.y){
			PutPixel(pontoAux.x, pontoAux.y, cor);
			for(int i = ponto1.y; i <= ponto2.y; i++){
				cor.R += (char)variacaoY_R;
	            cor.G += (char)variacaoY_G;
	            cor.B += (char)variacaoY_B;
	            cor.A += (char)variacaoY_A;
				PutPixel(pontoAux.x, i, cor);
			}
		}else{
			PutPixel(pontoAux.x, pontoAux.y, cor);
			for(int i = ponto2.y; i <= ponto1.y; i++){
				cor.R += (char)variacaoY_R;
	            cor.G += (char)variacaoY_G;
	            cor.B += (char)variacaoY_B;
	            cor.A += (char)variacaoY_A;
				PutPixel(pontoAux.x, i, cor);
		    }
		}
		return;
	}
	if(dy == 0){//horizontal
		if(ponto2.x > ponto1.x){
			PutPixel(pontoAux.x, pontoAux.y, cor);
			for(int i = ponto1.y; i <= ponto2.y; i++){
				cor.R += (char)variacaoX_R;
	            cor.G += (char)variacaoX_G;
	            cor.B += (char)variacaoX_B;
	            cor.A += (char)variacaoX_A;
				PutPixel(i, pontoAux.y, cor);
			}
		 }else{
	 	    PutPixel(pontoAux.x, pontoAux.y, cor);
	 	    for(int i = ponto2.x; i <= ponto1.x; i++){
				cor.R += (char)variacaoX_R;
	            cor.G += (char)variacaoX_G;
	            cor.B += (char)variacaoX_B;
	            cor.A += (char)variacaoX_A;
				PutPixel(i, pontoAux.y, cor);
			}
	    }
	    return;
	}

	int changeY = 0;
	int aux;
	int swap = 0;
	if(fabs(dy) > fabs(dx)){
		swap = 1;

		aux = ponto1.x;
		ponto1.x = ponto2.y;
		ponto2.y = aux;

		aux = ponto2.x;
		ponto2.x = ponto2.y;
		ponto2.y = aux;

	}

	if(dx < 0){
		aux = ponto1.x;
		ponto1.x = ponto2.x;
		ponto2.x = aux;

		aux = ponto1.y;
		ponto1.y = ponto2.y;
		ponto2.y = aux; 

		dx = -dx;
		dy = -dy;
	}

	if(dy < 0){
		changeY = -1;
		dy = -dy;
	}

	if(swap == 1){
		PutPixel(pontoAux.y, pontoAux.x, cor);
	}else{
		PutPixel(pontoAux.x, pontoAux.y, cor);
	}


     /** VariaÃ§ao do algoritmo de Bresenham */
	int d = 2*dy - dx;//Calcular o o pixel
	int E = 2*dy; //Se o ultimo pixel foi no norte
	int NE = 2* (dy - dx); //Se o ultimo pixel foi no nordeste

	PutPixel(pontoAux.x, pontoAux.y, cor);

	while(pontoAux.x < ponto2.x){
	cor.R += (char)variacaoY_R;
	cor.G += (char)variacaoY_G;
	cor.B += (char)variacaoY_B;
	cor.A += (char)variacaoY_A;
		if(d <= 0){
			d = d + E; //proximo pixel destacado eh ao oeste
			pontoAux.x ++;
		}else{
			d = d + NE; //proximo pixel destacado eh ao nordeste
			pontoAux.x ++;
			pontoAux.y ++;
		}
		PutPixel(pontoAux.x, pontoAux.y, cor);
	}

}

void DrawTriangle( point ponto1, point ponto2, point ponto3){
	DrawLine(ponto1, ponto2, green, red);
	DrawLine(ponto2, ponto3, red, blue);
	DrawLine(ponto3, ponto1, blue, green);
}


#endif // _MYGL_H_


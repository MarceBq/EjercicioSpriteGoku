#include "CJugador.h"

CJugador::CJugador()
{
}

CJugador::~CJugador()
{
}

//Constructor
CJugador::CJugador(int x, int y)
{
	this->x = x;
	this->y = y;
	
	//Como el jugador estara dentro de un timer el jugador no se debe 
	//mover
	dx = 0;
	dy = 0;

	//mirando hacia abajo
	ultimaTecla = Direcciones::Abajo;

	//no inicia en ninguna
	direccion = Direcciones::Ninguna;

	//Delimitando el tamaño de la imagen
	ancho = 25;
	alto = 39;
	
	//En que imagen va a inciar
	indiceX = 0;
	indiceY = 0;
}

void CJugador::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp)
{
	//Dibujando y delimitando 
	//Si el indice en X e Y es 0, se mostrara el (0,0)
	//Ancho y alto es el tamaño que se le dará en px 
	Rectangle porcionUsando = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	//Aumentar de tamaño al personaje
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 1.5, alto * 1.5);
	
	//Graficar al jugador
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionUsando, GraphicsUnit::Pixel);
	
	//va ir aumentando
	x += dx;
	y += dy;
}

void CJugador::mover(BufferedGraphics^ buffer, Bitmap^ bmp)
{
	switch (direccion)
	{

		//*ARRIBA*
	case Direcciones::Arriba:
		indiceX = 2;
		//Haciendo que el Y aumente
		if (indiceY >= 0 && indiceY <= 2) {
			//aumenta
			indiceY++;
		}
		else {
			//vuelve a la primera imagen
			indiceY = 0;
		}

		//Como me estoy moviendo en Y
		dx = 0;

		//Si me estoy moviendo para la parte 
		//superior, mi movimiento en Y es negativo
		dy = -10;
		
		ultimaTecla = Arriba;
		break;

		//*ABAJO*
	case Direcciones::Abajo:
		indiceX = 0;
		//Haciendo que el Y aumente
		if (indiceY >= 0 && indiceY <= 2) {
			//aumenta
			indiceY++;
		}
		else {
			//vuelve a la primera imagen
			indiceY = 0;
		}

		//Como me estoy moviendo en Y
		dx = 0;

		//Si me estoy moviendo para la parte 
		//de abajo, mi movimiento en Y es positivo
		dy = 10;

		ultimaTecla = Abajo;
		break;
	
		//*IZQUIERDA*
	case Direcciones::Izquierda:
		indiceX = 1;
		//Haciendo que el Y aumente
		if (indiceY >= 0 && indiceY < 2) {
			//aumenta
			indiceY++;
		}
		else {
			//vuelve a la primera imagen
			indiceY = 0;
		}

		//Si me estoy moviendo para la parte 
		//izquieda, mi movimiento en X es negativo		
		dx =-10;

		//Como me estoy moviendo en X
		dy = 0;

		ultimaTecla = Izquierda;
		break;
		
		//*DERECHA*
	case Direcciones::Derecha:
		indiceX = 3;
		//Haciendo que el Y aumente
		if (indiceY >= 0 && indiceY < 2) {
			//aumenta
			indiceY++;
		}
		else {
			//vuelve a la primera imagen
			indiceY = 0;
		}

		//Si me estoy moviendo para la parte 
		//derecha, mi movimiento en X es positivo		
		dx = 10;

		//Como me estoy moviendo en X
		dy = 0;

		ultimaTecla = Derecha;
		break;


		//*NINGUNO(SIN MOV)*
	case Direcciones::Ninguna:
		
		dx = 0;
		dy = 0;

		switch (ultimaTecla)
		{
		case Direcciones::Abajo:
			indiceX = 0;
			indiceY = 0;
			break;
		case Direcciones::Izquierda:
			indiceX = 1;
			indiceY = 0;
			break;
		case Direcciones::Arriba:
			indiceX = 2;
			indiceY = 0;
			break;
		case Direcciones::Derecha:
			indiceX = 3;
			indiceY = 0;
			break;
		default:
			break;
		}
		break;
	}

	//Llamando a dibujar
	Dibujar(buffer, bmp);

}

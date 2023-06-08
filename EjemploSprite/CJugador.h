#pragma once
using namespace System::Drawing;
//captura la ultima tecla
enum Direcciones {
	Ninguna, Abajo, Arriba, Izquierda, Derecha
};

class CJugador
{

private:
	//Coordenadas donde aparecera el jugador
	int x, y;
	//Movimiento 
	int dx, dy;
	//Ancho y alto del Sprite
	int ancho, alto;
	//Indices
	int indiceX, indiceY;
	//Guardar ultima tecla
	Direcciones ultimaTecla;

public:
	CJugador();
	~CJugador();

	//direccion->se va ir modificando
	Direcciones direccion;
	
	CJugador(int x, int y);

	//Bitmap -> captura el png
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp);
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp);
};


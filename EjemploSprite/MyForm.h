#pragma once
#include "CJugador.h"

namespace EjemploSprite {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		//Uso el iniciador con parametros para que dibuje en una parte del form
		CJugador* objJugador = new CJugador(50,50);

		//Llamando bitmap
		Bitmap^ bmpJugador = gcnew Bitmap("Goku.png");

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 625);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	//Aqui funcionará todo
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		//Fondo blanco
		buffer->Graphics->Clear(Color::White);

		objJugador->mover(buffer,bmpJugador);
		//Renderizado
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}

	//Cuando no esté presionanado ninguna tecla :v
	private: System::Void soltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objJugador->direccion = Direcciones::Ninguna;
	}

	//Cuando estoy moviendo al jugador :v
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
			//IZQ
		case Keys::A:
			objJugador->direccion = Direcciones::Izquierda;
			break;
			//DERC
		case Keys::D:
			objJugador->direccion = Direcciones::Derecha;
			break;
			//ARRIBA
		case Keys::W:
			objJugador->direccion = Direcciones::Arriba;
			break;
			//ABAJO
		case Keys::S:
			objJugador->direccion = Direcciones::Abajo;
			break;
		}
	}
	};
}

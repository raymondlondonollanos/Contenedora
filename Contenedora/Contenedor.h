
#pragma once
#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <cstddef>
#include <cassert>
#include <optional>

namespace contenedor
{
	//class contenedor
	class Contenedor
	{
	private:
		double* m_ptr{ nullptr };
		std::size_t m_tamanho{};

	public:
		//Creacion de constructor basico explicito
		Contenedor() = default;

		//Creacion de constructor que solicita dos datos
		Contenedor(double* ptr, std::size_t tamano);

		//constructor de copias
		Contenedor(const Contenedor& copy);

		//operador de asignacion
		Contenedor& operator=(const Contenedor& copy);

		//sobrecarga del operador[] modificable
		double& operator[](std::size_t indice)
		{
			assert(indice >= 0 && indice < m_tamanho);

			return m_ptr[indice];
		}

		//sobrecarga del operador[] no modificable
		const double& operator[](std::size_t indice)const
		{
			assert(indice >= 0 && indice < m_tamanho);

			return m_ptr[indice];
		}

		//sematica de movimiento
		//sobrecarga del constructor con la semantica de movimiento
		Contenedor(Contenedor&& move)noexcept;

		//sobrecarga del operador de asignacion mediante la semantica de momvimiento
		Contenedor& operator=(Contenedor&& move)noexcept;

		//destructor
		~Contenedor()
		{
			delete[] m_ptr;
		}

		//metodo para realizar copia profunda
		void deep_copy(const Contenedor& copy);

		void mostrarDatos();

		friend std::optional<contenedor::Contenedor> validacionObjContenedor(double* ptr, std::size_t tamano);
			
	};

	std::optional<Contenedor> validacionObjContenedor(double* ptr, std::size_t tamano);
}

#endif // !CONTENEDOR_H


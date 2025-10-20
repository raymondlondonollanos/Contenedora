#include "Contenedor.h"
#include <iostream>
#include <optional>

namespace contenedor
{
	//inicializamos el puntero ptr
	Contenedor::Contenedor(double* ptr, std::size_t tamano)
	{
		if (ptr && tamano > 0)
		{
			m_tamanho = tamano;

			m_ptr = new double[m_tamanho];

			for(std::size_t i{0};i<m_tamanho;++i)
			{ 
				m_ptr[i] = ptr[i];
			}
		}
	}

	Contenedor::Contenedor(const Contenedor& copy)
	{
		deep_copy(copy);
	}

	Contenedor& Contenedor::operator=(const Contenedor& copy)
	{
		if (this != &copy)
		{
			deep_copy(copy);
		}

		return *this;
	}

	Contenedor::Contenedor(Contenedor&& move)noexcept
	{
		m_tamanho = move.m_tamanho;
		m_ptr = move.m_ptr;
		move.m_ptr = nullptr;
		move.m_tamanho = 0;
	}

	Contenedor& Contenedor::operator=(Contenedor&& move)noexcept
	{
		if (this == &move)
		{
			return *this;
		}
		delete[] m_ptr;
		m_tamanho = move.m_tamanho;
		m_ptr = move.m_ptr;
		move.m_ptr = nullptr;
		move.m_tamanho = 0;

		return *this;
	}


	void Contenedor::deep_copy(const Contenedor& copy)
	{
		delete[] m_ptr;
		m_ptr = nullptr;
		m_tamanho = 0;

		if (copy.m_ptr)
		{
			m_tamanho = copy.m_tamanho;

			m_ptr = new double[m_tamanho];

			for (std::size_t i{ 0 }; i < m_tamanho; ++i)
			{
				m_ptr[i] = copy.m_ptr[i];
			}
		}
	}
	void Contenedor::mostrarDatos()
	{
		for (std::size_t i{ 0 }; i < m_tamanho; ++i)
		{
			std::cout << "Array " << m_ptr[i] << '\n';
		}
	}
	std::optional<contenedor::Contenedor> validacionObjContenedor(double* ptr , std::size_t tamano)
	{
		if (ptr && tamano > 0)
		{
			return contenedor::Contenedor{ ptr, tamano };
		}
		std::cerr << "Error revisa el tamano del array o si es puntero es nulo.\n";
		return std::nullopt;
	}
	
}

